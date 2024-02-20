#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage


static int simple01_init(void)
{
	printk(KERN_ALERT"Entering into Kernel %s\n",__FUNCTION__);
	return 0;
}
module_init(simple01_init);

