//kernel headers
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

//mah headers
#include "gpio.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Benjamin Benetti");
MODULE_DESCRIPTION("GPIO driver for Raspberry Pi 3");
MODULE_VERSION("0.5");

//TODO shit here

static int __init initFunction(void){
  allocateGPIO();

  return 0;
}

static void __exit exitFunction(void){
  releaseGPIO();

}

module_init(initFunction);
module_exit(exitFunction);
