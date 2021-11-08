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
use cc2640r2f_pac;

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

//==============================================================================
// Variables
//==============================================================================
static GPIO_HANDLE: Mutex<RefCell<Option<cc2640r2f_pac::GPIO>>> = 
	Mutex::new(RefCell::new(None));

//==============================================================================
// Public Functions
//==============================================================================
#[allow(dead_code)]
pub fn init(gpio: cc2640r2f_pac::GPIO){
	free(|cs| GPIO_HANDLE.borrow(cs).replace(Some(gpio)));
}

#[allow(dead_code)]
pub fn get_pin_state(pin: u8) -> PinState {
	let read = free(|cs|
		if let Some(ref mut gpio) = GPIO_HANDLE.borrow(cs).borrow_mut().deref_mut() {
			gpio.din31_0.read().bits()
		}
		else {
			0
		}
	);
	match read & (1 << pin) {
		0 => PinState::PinLow,
		_ => PinState::PinHigh
	}
}

#[allow(dead_code)]
pub fn pin_disable(pin: u8) {

}

#[allow(dead_code)]
pub fn pin_setup(pin: u8){

}

#[allow(dead_code)]
pub fn set_pin_state(pin: u8, _state: PinState){

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
