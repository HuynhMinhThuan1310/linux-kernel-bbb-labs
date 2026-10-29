ifneq ($(KERNELRELEASE),)
obj-m := hello_version.o
else 
KDIR ?=/home/thuan131004/bbb_workspace/buildroot/output/build/linux-custom
CROSS ?= /home/thuan131004/bbb_workspace/buildroot/output/host/bin/arm-linux-

all:
	$(MAKE) -C $(KDIR) M=$$PWD ARCH=arm CROSS_COMPILE=$(CROSS) modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD ARCH=arm CROSS_COMPILE=$(CROSS) clean
endif

