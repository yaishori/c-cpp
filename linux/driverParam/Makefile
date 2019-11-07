# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=param.o #how to call the module
param-objs:=main.o #list of c file when we change .c to .o
V?=0 #0 or 1 ... use 1 only if build dont work
KDIR?=/lib/modules/$(shell uname -r)/build #the path of the kernel maker
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1 #0 or 1
.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules 
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp
