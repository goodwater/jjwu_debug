CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)gcc -E
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)ld
NM = $(CROSS_COMPILE)nm
STRIP = $(CROSS_COMPILE)strip

JJWU_DEBUG += -DJJWU_DEBUG
INCLUDES += -I$(PWD)/../../../include
EXTRA_CFLAGS = $(INCLUDES) $(JJWU_DEBUG)

obj-m += test.o

KVERSION := $(shell uname -r)

.PHONY: all

all: test

.PHONY: test

test:
	@$(MAKE) -C /lib/modules/$(KVERSION)/build M=$(PWD) modules

clean:
	@$(MAKE) -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
