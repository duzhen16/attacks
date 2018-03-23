#include <linux/sched.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/rbtree.h>
#include <linux/string.h>
#include <asm/kvm_para.h>

#include "/usr/src/linux-4.10/kernel/sched/sched.h"


static int lab_main(void)
{
	printk("come in lab_main");
	struct task_struct * target;
	for_each_process(target){
		if ((target->pid == 5769 )) { 
			printk("it is %s stack is 0x%p,state is %d, at cpu %d. current is @ cpu %d\n",target->comm,target->stack, target->state,target->cpu, current->cpu);
			unsigned long * p = (unsigned long *)target->stack;
			unsigned long ori = *(p + 2);
			unsigned long load = 0x1212121212;
			printk("p+2 %p now is %lx\n",p + 2,*(p + 2));
			*(p + 2) = load;
			printk("p+2 %p now is %lx\n",p + 2,*(p + 2));
			*(p + 2) = ori;
			printk("p+2 %p now is %lx\n",p + 2,*(p + 2));
			printk("alter succeed\n");
		}
	}
	
	return 0;
}


static int __init lab_init(void) 
{
	printk("inserting module ...");
	lab_main();
	return 0;
}

static void __exit lab_exit(void)
{
	printk("module lab will be removed\n");
}

module_init(lab_init);
module_exit(lab_exit);

MODULE_AUTHOR("xSun");
MODULE_DESCRIPTION("lab module");
MODULE_LICENSE("GPL");
