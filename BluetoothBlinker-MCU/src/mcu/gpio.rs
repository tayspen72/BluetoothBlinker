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
use crate::mcu;
use msp432p401r;

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
pub struct PinConfig{
	port: mcu::Port,
	pin: u8
}

//==============================================================================
// Variables
//==============================================================================
static GPIO_HANDLE: Mutex<RefCell<Option<msp432p401r::DIO>>> = 
	Mutex::new(RefCell::new(None));

//==============================================================================
// Public Functions
//==============================================================================
#[allow(dead_code)]
pub fn init(dio: msp432p401r::DIO){
	free(|cs| GPIO_HANDLE.borrow(cs).replace(Some(dio)));
}

#[allow(dead_code)]
pub fn get_pin_state(config: PinConfig) -> PinState {
	let read = free(|cs|
		if let Some(ref mut dio) = GPIO_HANDLE.borrow(cs).borrow_mut().deref_mut() {
			match config.port {
				mcu::Port::PortA => dio.pain.read().bits(),
				mcu::Port::PortB => dio.pain.read().bits(),
				mcu::Port::PortC => dio.pain.read().bits(),
				mcu::Port::PortD => dio.pain.read().bits(),
				mcu::Port::PortE => dio.pain.read().bits(),
				mcu::Port::PortJ => dio.pain.read().bits(),
			}
		}
		else {
			0
		}
	);
	match read & (1 << config.pin) {
		0 => PinState::PinLow,
		_ => PinState::PinHigh
	}
}

#[allow(dead_code)]
pub fn pin_disable(_config: PinConfig) {

}

#[allow(dead_code)]
pub fn pin_setup(_config: PinConfig){

}

#[allow(dead_code)]
pub fn set_pin_state(_config: PinConfig, _state: PinState){

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
