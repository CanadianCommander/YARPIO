#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#include "gpio.h"

bool safePinGrab(int pin);

bool allocateGPIO(void){
  int i = GPIO_2;
  int errCount = 0;
  int errMax = 4;

  //grab all gpio pins >:)
  for(;i <= GPIO_END; i ++){
    if(!safePinGrab(i)){
      //error.
      printk(KERN_ERR "Could not allocate GPIO pin %d\n", i);
      errCount ++;

      if(errCount > errMax){
        printk(KERN_CRIT "%d GPIO allocation errors giving up!\n", errCount);
        releaseGPIO();
        return false;
      }
    }
  }

  return true;
}

bool releaseGPIO(void){
  int i = GPIO_2;

  for(;i < GPIO_END; i++){
    gpio_free(i);
  }

  return true;
}

bool setGPIODirection(int pin,int direc){
  if(direc == GPIO_DIRECTION_IN){
    //in
    if(gpio_direction_input(pin) < 0){
      printk(KERN_ERR "Could not change direction of GPIO pin %d", pin);
      return false;
    }
    return true;
  }
  else{
    //must be out
    if(gpio_direction_output(pin, false) < 0){
      printk(KERN_ERR "Could not change direction of GPIO pin %d", pin);
      return false;
    }
    return true;
  }
}

//sets the specified pin (HIGH) (return true on success)
bool setGPIO(int pin){
  //HIGH
  gpio_set_value(pin, true);
  return true;
}

//clears the specified pin (Low) (return true on success)
bool clearGPIO(int pin){
  //LOW
  gpio_set_value(pin, false);
  return true;
}

int getGPIO(int pin){
  return gpio_get_value(pin);
}


//"grab" a gpio pin w/ safty checks an what not
//return:
//  true on success
//  false otherwise
bool safePinGrab(int pin){
  if(gpio_request(pin, "sysfs") < 0){
    //error
    return false;
  }
  //success
  return true;
}
