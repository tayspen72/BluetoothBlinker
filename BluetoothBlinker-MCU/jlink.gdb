target remote localhost:2331

set print asm-demangle on

file ./target/thumbv7m-none-eabi/debug/app

#Initially reset the target
monitor reset

break main
break DefaultHandler
break HardFault
break rust_begin_unwind

#Load the application
load

si