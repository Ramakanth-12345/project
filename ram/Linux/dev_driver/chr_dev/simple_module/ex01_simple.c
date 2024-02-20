#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage

int simple01_init(void)
{
	printk(KERN_ALERT"Entering into Kernel %s\n",__FUNCTION__);
	return 0;
}
void simple01_exit(void)
{
	printk(KERN_ALERT"Leaving the Kernel %s\n",__FUNCTION__);
}
module_init(simple01_init);
module_exit(simple01_exit);
