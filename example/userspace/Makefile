CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)gcc -E
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)ld
NM = $(CROSS_COMPILE)nm
STRIP = $(CROSS_COMPILE)strip

SOURCE= \
	test.c

JJWU_DEBUG = -DJJWU_DEBUG

INCLUDES = -I$(PWD)/../../include
CFLAGS = -O2 -Wall -Wno-unused-result $(INCLUDES) $(JJWU_DEBUG)

.PHONY: all

all: test

.PHONY: test

test:
	@$(CC) $(SOURCE) $(CFLAGS) -o $@
	@$(STRIP) $@

clean:
	@find . -executable -delete
	@rm -rf *.o
