#include<linux/init.h> //for init system entry in kernel
#include<linux/kernel.h> // registring for kernel
#include<linux/module.h> //to access for kernel  module
#include<linux/fs.h>  //for filesystem access of kernel usage

int simple04_start(void);

int simple04_init(void)
{
	printk(KERN_ALERT"Entering into Kernel %s\n",__FUNCTION__);
	simple04_start();
	return 0;
}
void simple04_exit(void)
{
	printk(KERN_ALERT"Leaving the Kernel %s\n",__FUNCTION__);
}
module_init(simple04_init);
module_exit(simple04_exit);
