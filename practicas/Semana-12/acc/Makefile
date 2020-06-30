################################################################################
#
# Copyright (c) 2017, NVIDIA Corporation.  All rights reserved.
#
# Please refer to the NVIDIA end user license agreement (EULA) associated
# with this source code for terms and conditions that govern your use of
# this software. Any use, reproduction, disclosure, or distribution of
# this software and related documentation outside the terms of the EULA
# is strictly prohibited.
#
################################################################################

PATH := /opt/pgi/linux86-64-llvm/19.10/bin/:$(PATH)

PREC     = FP64
CC       = pgcc
CPP      = pgc++
OBJ     = o
EXE	= out
RUN     =

CCFLAGS  = -D$(PREC) -fast -Minline
ACCFLAGS = -Minfo -acc $(OPT)

all: build run verify

%: %.c
	@echo $@
	$(CC) $(CCFLAGS) $(ACCFLAGS) $< -o $@.$(EXE)

%: %.cc
	@echo $@
	$(CPP) $(CCFLAGS) $(ACCFLAGS) $< -o $@.$(EXE)

clean:
	@echo 'Cleaning up...'
	@rm -rf *.$(EXE) *.$(OBJ) *.dwf *.pdb prof

