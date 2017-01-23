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
#include <linux/highmem.h>


MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define FIRST_MINOR 0	
#define NR_DEVS 1		//Number of device numbers

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl (struct file *fi, unsigned int a, unsigned long b);

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
	int i;
	int j;
	int cnt = 0;
	int lowmem = 0;
	int highmem = 0;

	unsigned long int p_addr;
	unsigned long int pg_num;
	unsigned long int *v_addr = NULL;
	extern struct page *mem_map;

	struct task_struct *my_task = current;
	pgd_t * pgd_ptr = my_task->mm->pgd;

	
	for(i = 1023; i >= 0; i--){
		if((p_addr =pgd_ptr[i].pgd) ){
			
			p_addr = ((p_addr >> 12) << 12); //masking last 3 nibbles
			
//			v_addr = (void *)phys_to_virt(p_addr);

			printk("PGD[%4d] : %8lx \t", i, p_addr);//printing pgd entries (i.e physical memory)
			
			pg_num = p_addr >> 12; //calculating pg_num (i.e index to mem_map array)
			
			//coverting physical to virtual memory
		
			if(p_addr <= 0x38000000){ //if phy_addr is in LOW MEM

				v_addr = (void *)(p_addr + 0xc0000000);
				lowmem++; //counting no. of entries in lowmem region

				printk("vertual address is : %p \n", v_addr);//printing virtual address 
		
				for(j = 0; j < 1024; j++){ //printing pt values
					if(v_addr[j]){
						printk(" --0x%3x--	PT[0x%3x] : 0x%08lx \n", i , j, ((v_addr[j] >> 12) << 12));
					}
				}//for loop ends

			}else{

				v_addr = kmap(&mem_map[pg_num]);
				highmem++;	//counting no. of entries highmem region

				printk("vertual address is : %p \n", v_addr);//printing virtual address 
		
				for(j = 0; j < 1024; j++){ //printing pt values
					if(v_addr[j]){
						printk(" --0x%3x--	PT[0x%3x] : 0x%08lx \n", i, j, ((v_addr[j] >> 12) << 12));
					}
				}//for loop ends
			} 

			cnt++;
		}
	}
	
	printk(KERN_INFO "count : %d \n", cnt);
	printk(KERN_INFO "lowmem : %d \n", lowmem);
	printk(KERN_INFO "highmem : %d \n", highmem);

	return 0;
}


module_init(myInit);
module_exit(myExit);
