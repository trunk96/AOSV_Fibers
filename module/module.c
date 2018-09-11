#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hashtable.h>
#include "device.h"



MODULE_LICENSE("GPL");

static int fiber_init(void){
        //register the device as /dev/fibers
        register_fiber_device();
        return 0;
}

static void fiber_cleanup(void){
        unregister_fiber_device();
        printk(KERN_DEBUG "%s successfully removed!\n", KBUILD_MODNAME);
}

module_init(fiber_init);
module_exit(fiber_cleanup);
