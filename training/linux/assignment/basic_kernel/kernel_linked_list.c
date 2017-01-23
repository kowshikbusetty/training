#include <stdio.h>
#include <stdlib.h>

#define getaddress(tsk, type, member, address_mem) tsk = (type *)0;\
					offset = (int) ((char *)&(tsk -> member) - (char *)tsk);\
					tsk = (type *)((char *)(address_mem) - offset)

struct link {
	struct link *next;
	struct link *prev;
}head;

struct task {
	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[16];
	unsigned int rt_prio;
};

int main(void)
{
	int offset;

	struct task *tsk = NULL;
	struct task tsk1, tsk2;

//	struct link *head = NULL;

	/*if (NULL == (tsk1 = (struct task *) malloc(sizeof(struct task)))){
			perror ("Malloc failed.. \n");
			exit(1);
	}*/
	head.next = &tsk1.tasks;
	tsk1.tasks.next = &tsk2.tasks;
	tsk1.pid = 2016;
	tsk2.pid = 2017;

	getaddress(tsk, struct task, tasks, head.next);
	
//	printf ("%d \n", offset);
//	printf ("%p \n", &tsk1.tasks);
//	printf ("%p \n", tsk);
	printf ("%d \n", tsk -> pid);
	getaddress(tsk, struct task, tasks, tsk1.tasks.next);
	printf ("%d \n", tsk -> pid);

	return 0;
}
