//==============================================================================
// Notes
//==============================================================================
// mcu::mod.rs

//==============================================================================
// Crates and Mods
//==============================================================================
use cortex_m;
use cc2640r2f_pac;

pub mod gpio;
pub mod systick;

//==============================================================================
// Enums, Structs, and Types
//==============================================================================
pub enum McuState {
	Idle
}

#[allow(dead_code)]
pub struct SystemClock{
	pub a_clk: u32,
	pub m_clk: u32,
	pub hsm_clk: u32,
	pub sm_clk: u32,
	pub b_clk: u32
}

//==============================================================================
// Variables
//==============================================================================
#[allow(dead_code)]
pub enum Port{
	PortA,
	PortB,
	PortC,
	PortD,
	PortE,
	PortJ
}

//==============================================================================
// Public Functions
//==============================================================================
pub fn init() {
	let peripherals = cc2640r2f_pac::Peripherals::take().unwrap();
	let cortex_peripherals = cortex_m::Peripherals::take().unwrap();

	systick::init(cortex_peripherals.SYST);

	init_clock(peripherals.PRCM);
	
	// adc::init(peripherals.SAADC);
	gpio::init(peripherals.GPIO, peripherals.IOC);
	// input::init(peripherals.GPIOTE);
	// i2c::init(peripherals.TWI1);
	// rtc::init(peripherals.RTC0, &peripherals.CLOCK, wake_interval);
	// spi::init(peripherals.SPI0);
	// spim::init(peripherals.SPIM0);
	// timer::init(peripherals.TIMER0);
}

#[allow(dead_code)]
pub fn get_busy() -> McuState {
	McuState::Idle
}

#[allow(dead_code)]
pub fn restart() {
	cortex_m::peripheral::SCB::sys_reset();
}

//==============================================================================
// Private Functions
//==============================================================================
fn init_clock(pcrm: cc2640r2f_pac::PRCM) {

}

//==============================================================================
// Task Handler
//==============================================================================
pub fn task_handler() {

}
