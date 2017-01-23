/** System Includes **/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/fdtable.h>
#include <linux/kdev_t.h>                                                       
#include <linux/mount.h>

MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define FIRST_MINOR 0	
#define NR_DEVS 1		//Number of device numbers
#define VM_READ 0x00000001	
#define VM_WRITE 0x00000002
#define VM_EXEC 0x00000004
#define VM_SHARED 0x00000008


//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl (struct file *fi, unsigned int a, unsigned long b);
void print_directory (struct dentry* d_entry);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};

/* GLobal variables */
char *devname;	//contains device name
int majNo;	
static dev_t mydev;	//encodses major number and minor number 
struct cdev *my_cdev;//holds character device driver discriptor

/* TO accept input from the command line */
module_param(devname, charp, 0000);

//class and device structure
static struct class *mychar_class;
static struct device *mychar_device;

/*
 * myOpen: open function of the pseudo driver
 */

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");

	return 0;
}

/*
 * myRelease: close function of the pseudo driver
 */

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

/*
 * myInit: init function of the kernel module\
 */

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");

	// Allocation Device Numbers
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_INFO "Device number allocation failed: %d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();	//Allocate memory for my_cdev
	if(my_cdev == NULL) {
		printk(KERN_INFO "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);	//Initialize my_cdev with fops
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add (my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	//Create a class and an entry in sysfs
	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	//create mychar_device in sysfs and an
	//device entry will be made in /dev directory
	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}

	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;

}

/*
 * myExit: cleanup function of the kernel module
 */

static void myExit(void)
{
	printk(KERN_INFO "Exiting the character driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

/*
*myIoctl : function  manipu lates the underlying device parameters of
special files.
*/

long myIoctl (struct file * fi, unsigned int a, unsigned long b)
{
	struct task_struct *my_task = current;
	struct vm_area_struct *vm = my_task->mm->mmap;
	struct super_block *ptr = NULL;

	printk(KERN_INFO "address \t\t\t offset\t\t inode\t flags\t magic\t path \n");
	
	
	while (vm != NULL){

		//printing the strat, end & offset values
		printk(KERN_INFO "%p - %p \t %05x000 \t",
							(void *)vm->vm_start, (void *)vm->vm_end,(unsigned)vm->vm_pgoff);

		//printing inode values

		if(vm->vm_file != NULL)	{
			printk("%8lu ", vm->vm_file->f_inode->i_ino);
		}else{
			printk(" 0000000 ");
		}

		/*
		 * prinitng the permissions
		 * in flags field last 3 lsb bits gives about permissions
		 */

		if(vm->vm_flags & VM_READ){
			printk("r");
		}

		if(vm->vm_flags & VM_WRITE){
			printk("w");
		}else
			printk("_");

		if(vm->vm_flags & VM_EXEC){
			printk("x");
		}else
			printk("_");

		if(vm->vm_flags & VM_SHARED){
			printk("s");
		}else{
			printk("p");
		}//printing permissions ended

		printk("\t");

		//printing device number(Major & minor)
					
		if(vm->vm_file){
			ptr = ((vm -> vm_file -> f_path).mnt) -> mnt_sb;

			printk ("%02d:%02d  ", (ptr -> s_dev) >> 20, ((ptr -> s_dev) << 12) >> 12);
			print_directory (((vm -> vm_file -> f_path).dentry));          
            printk ("\n");
	
		}else{
			printk("00:00  ");
		}


			vm = vm->vm_next;//pointing to next segment
	}	

	printk("\n");

	return 0;
}

void print_directory (struct dentry* d_entry)                                   
{                                                                               
    if (!strcmp (d_entry -> d_iname, "/")) {                                    
        return;                                                                 
    }                                                                           
    print_directory (d_entry -> d_parent);                                      
    printk ("/%s", d_entry -> d_iname);                                         
}  


module_init(myInit);
module_exit(myExit);
