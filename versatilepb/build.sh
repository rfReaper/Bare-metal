#!/bin/bash


arm-none-eabi-as -o boot.o boot.S

arm-none-eabi-gcc -c -o kernel.o kernel.c -mcpu=arm926ej-s -fno-builtin -nostdlib -nostartfiles -nodefaultlibs

arm-none-eabi-ld -T linker.ld -o kernel.elf boot.o kernel.o

arm-none-eabi-objcopy -O binary kernel.elf kernel.bin
