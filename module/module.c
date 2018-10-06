#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hashtable.h>
#include "device.h"


extern int register_kprobe_do_exit(void);
extern int unregister_kprobe_do_exit(void);
extern int register_kretprobe_finish_task_switch(void);
extern int unregister_kretprobe_finish_task_switch(void);
extern int register_kretprobe_proc_fiber_dir(void);
extern int unregister_kretprobe_proc_fiber_dir(void);



MODULE_LICENSE("GPL");

static int fiber_init(void){
        //register the device as /dev/fibers
        register_fiber_device();
        register_kprobe_do_exit();
        register_kretprobe_proc_fiber_dir();
        register_kretprobe_finish_task_switch();
        return 0;
}

static void fiber_cleanup(void){
        unregister_kprobe_do_exit();
        unregister_kretprobe_finish_task_switch();
        unregister_kretprobe_proc_fiber_dir();
        unregister_fiber_device();
        printk(KERN_DEBUG "[%s] successfully removed!\n", KBUILD_MODNAME);
}

module_init(fiber_init);
module_exit(fiber_cleanup);
