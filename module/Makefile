obj-m += fiber.o

fiber-y := ioctl.o fibers.o device.o fiber_module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
