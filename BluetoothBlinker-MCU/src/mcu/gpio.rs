//==============================================================================
// Notes
//==============================================================================
// mcu::gpio.rs
// Basic control over gpio pins

//==============================================================================
// Crates and Mods
//==============================================================================
use core::cell::RefCell;
use core::ops::DerefMut;
use cortex_m::interrupt::{free, Mutex};
// use msp432p401r;

//==============================================================================
// Enums, Structs, and Types
//==============================================================================
#[allow(dead_code)]
#[derive(Copy, Clone, PartialEq)]
pub enum PinDirection{
	Input,
	Output
}

#[allow(dead_code)]
#[derive(Copy, Clone, PartialEq)]
pub enum PinPull{
	PullUp,
	PullDown,
	PullDisabled
}

#[allow(dead_code)]
#[derive(Copy, Clone, PartialEq)]
pub enum PinState{
	PinLow,
	PinHigh
}

#[allow(dead_code)]
#[allow(non_camel_case_types)]
pub struct PortConfig{
	Pin: u8
}

//==============================================================================
// Variables
//==============================================================================
// static GPIO_HANDLE: Mutex<RefCell<Option<cc2640r2f::GPIO>>> = 
// 	Mutex::new(RefCell::new(None));

//==============================================================================
// Public Functions
//==============================================================================
pub fn init(){

}

#[allow(dead_code)]
pub fn get_pin_state(pin: u8) -> PinState {
	PinState::PinLow
}

#[allow(dead_code)]
pub fn pin_disable(pin: u8) {

}

#[allow(dead_code)]
pub fn pin_setup(config: PortConfig){

}

#[allow(dead_code)]
pub fn set_pin_state(pin: u8, state: PinState){

}

pub fn set_port_id(pin: u8) {
	
}

//==============================================================================
// Private Functions
//==============================================================================


//==============================================================================
// Interrupt Handler
//==============================================================================


//==============================================================================
// Task Handler
//==============================================================================
