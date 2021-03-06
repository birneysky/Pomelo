######################################
#
# Generic makefile mould
#
# Copyright (c) 2017 Pomelo Corp.
# All rights reserved.
#
######################################

PROGRAMS := libPomeloBase.a

CROSS_COMPILE_PLATFORM :=
CROSS_COMPILE :=
CROSS_COMPILE_INCLUDE :=
CROSS_COMPILE_LIB :=
CROSS_COMPILE_BIN :=
CFLAGS :=

DEBUG := y


##########################################
#init cross compile platform here
ifeq ($(CROSS_COMPILE_PLATFORM),android)
	NDKPATH = /cygdrive/f/android-ndk-r7b
	CROSS_COMPILE = $(NDKPATH)/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-
	CROSS_COMPILE_INCLUDE = -I../../../android-ndk-r7b/platforms/android-9/arch-arm/usr/include/
	CROSS_COMPILE_BIN = ../lib/android
	CFLAGS += -DPROJECT_FOR_ANDROID
else ifeq ($(CROSS_COMPILE_PLATFORM),mac)
	CROSS_COMPILE_BIN = ../lib/mac      
else ifeq ($(CROSS_COMPILE_PLATFORM),linux)
	CROSS_COMPILE_BIN = ../lib/linux
	CFLAGS += -D_EVENT_HAVE_FD_MASK -D_GNU_SOURCE 
endif

###############################################################
#check bin && lib dir is created
ifneq ($(CROSS_COMPILE_PLATFORM),)
    ifneq ($(wildcard $(CROSS_COMPILE_BIN)),)
        MDBIN :=
    else
        MDBIN := $(shell mkdir -p $(CROSS_COMPILE_BIN))
    endif
endif

################################################################
#init compile environment
AS	:= $(CROSS_COMPILE)as
LD	:= $(CROSS_COMPILE)ld
CC	:= $(CROSS_COMPILE)gcc
CXX	:= $(CROSS_COMPILE)gcc
CPP	:= $(CC) -E
AR	:= $(CROSS_COMPILE)ar
NM	:= $(CROSS_COMPILE)nm
STRIP	:= $(CROSS_COMPILE)strip
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump
RANLIB	:= $(CROSS_COMPILE)RANLIB

CFLAGS += -c -Wall -DPROJECT_FOR_LINUX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $(CROSS_COMPILE_INCLUDE) -O2 -fPIC -fno-short-enums -std=gnu99 
LDFLAGS := -O2 $(CROSS_COMPILE_LIB)

ifeq ($(DEBUG),y)
	CFLAGS += -g
	LDFLAGS += -g
endif
CXXFLAGS := $(CFLAGS)
#CPPFLAGS += -MD


################################################################
# You shouldn't need to change anything below this point.
#SOURCE := $(wildcard *.c)
SOURCE := $(wildcard ./src/*.c)
SOURCE += $(wildcard ./jsonc/*.c)

OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

DEPENDINFO := .depend

.PHONY : ALL

ALL : $(DEPENDINFO) $(PROGRAMS) 

$(DEPENDINFO) : $(SOURCE)
	$(CC) $(CFLAGS) -M $^ > $@

$(PROGRAMS): $(OBJS)
	$(AR) -r $@ $^
	@-cp -vuf $(PROGRAMS) $(CROSS_COMPILE_BIN)

########################################################
.PHONY : clean distclean
clean :
	@$(RM) *.o core core.* *.a
	@$(RM) $(OBJS)
    
distclean: clean
	@$(RM) $(PROGRAMS) *.bak *.bck *.d .depend
  
