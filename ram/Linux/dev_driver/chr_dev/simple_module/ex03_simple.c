#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage

MODULE_LICENSE("GPL");

__initdata int count=5;

__init int simple03_start(void)
{
	printk(KERN_ALERT"Entering into start %s\n",__FUNCTION__);
	return 0;
}

int simple01_stop(void)
{
	printk(KERN_ALERT"Entering into stop %s\n",__FUNCTION__);
	return 0;
}



__init int simple03_init(void)
{
	int index=0;
	printk(KERN_ALERT"Entering into Kernel %s\n",__FUNCTION__);
	for(index=0;index<count;index++)
	{
		printk(KERN_ALERT"index value = %d\n",index);
	}

	simple03_start();
	simple03_stop();
	return 0;
}
void simple03_exit(void)
{
	printk(KERN_ALERT"Leaving the Kernel %s\n",__FUNCTION__);
	simple03_stop();
}
module_init(simple03_init);
module_exit(simple03_exit);
