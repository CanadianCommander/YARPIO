obj-m := yarpioModule.o
yarpioModule-objs := yarpio.o gpio.o

ccflags-y := -std=gnu99

all:
	make -C /lib/modules/`uname -r`/build/ M=`pwd` modules
clean:
	make -C /lib/modules/`uname -r`/build/ M=`pwd` clean
