#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage
#include<linux/moduleparam.h> //for varabile initilization in kernel space

int count=1;
module_param(count,int,0644);
//module_param_cb(count,int,&count,0644);

int simple05_init(void)
{
	int index=0;
	printk(KERN_ALERT"Entering into Kernel %s\n",__FUNCTION__);
	for(index=0;index<count;index++)
	{
		printk(KERN_ALERT"helloworld index value = %d\n",index);
	}
	return 0;
}
void simple05_exit(void)
{
	int index=0;
	printk(KERN_ALERT"Leaving the Kernel %s\n",__FUNCTION__);
	for(index=0;index<count;index++)
	{
		printk(KERN_ALERT"goodbye world index value = %d\n",index);
	}
}
module_init(simple05_init);
module_exit(simple05_exit);
