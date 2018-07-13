#include <linux/kernel.h>
#include <linux/module.h>
#include "device.h"



MODULE_LICENSE("GPL");

static int fiber_init(void){
  //register the device as /dev/fibers
  register_fiber_device();
  return 0;
}

static void fiber_cleanup(void){
  unregister_fiber_device();
}

module_init(fiber_init);
module_exit(fiber_cleanup);
