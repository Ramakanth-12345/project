#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage


void simple01_exit(void)
{
	printk(KERN_ALERT"Leaving the Kernel %s\n",__FUNCTION__);
}
module_exit(simple01_exit);
