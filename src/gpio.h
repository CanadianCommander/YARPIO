#ifndef GPIO_H
#define GPIO_H
#include <stdbool.h>

//allocate (request) all gpio pins on the R pi 3
extern bool allocateGPIO(void);

//release all gpio pins on the R pi 3
extern bool releaseGPIO(void);

//change direction of io pin.
//args:
//  int pin num
//  int direction (one of GPIO_DIRECTION_[IN | OUT])
//return: true on success
extern bool setGPIODirection(int,int);

//sets the specified pin (HIGH) (return true on success)
extern bool setGPIO(int);

//clears the specified pin (Low) (return true on success)
extern bool clearGPIO(int);

//get the state of the GPIO pin (HIGH or LOW < 1 or 0 >)
extern int getGPIO(int);

//direction that the io pin is to be set to.
#define GPIO_DIRECTION_IN 0
#define GPIO_DIRECTION_OUT 1

//GPIO pin numbers (as bcm2837 sees it).
//only includes usable pins (note secondary function comments may be incorrect)
#define GPIO_2 2
#define GPIO_3 3
#define GPIO_4 4
#define GPIO_5 5
#define GPIO_6 6
#define GPIO_7 7
#define GPIO_8 8
#define GPIO_9 9 // SPI
#define GPIO_10 10 // SPI
#define GPIO_11 11 // SPI
#define GPIO_12 12 // PWM chan 0
#define GPIO_13 13 // PWM chan 1
#define GPIO_14 14 // TX
#define GPIO_15 15 // RX
#define GPIO_16 16
#define GPIO_17 17
#define GPIO_18 18 // PWM chan 0
#define GPIO_19 19 // SPI
#define GPIO_20 20 // SPI
#define GPIO_21 21 // SPI
#define GPIO_22 22
#define GPIO_23 23
#define GPIO_24 24
#define GPIO_25 25
#define GPIO_26 26
#define GPIO_27 27
#define GPIO_END 28

#endif
