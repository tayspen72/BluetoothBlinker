#!/bin/zsh

JLinkGDBServer -select USB -device CC2640R2F -endian little -if JTAG -speed 4000 -noir -noLocalhostOnly
