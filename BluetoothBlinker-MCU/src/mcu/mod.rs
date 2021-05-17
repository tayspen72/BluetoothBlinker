//==============================================================================
// Notes
//==============================================================================
// mcu::mod.rs

//==============================================================================
// Crates and Mods
//==============================================================================
use cortex_m;
use cc2640r2f;

pub mod systick;

//==============================================================================
// Enums, Structs, and Types
//==============================================================================
pub enum McuState {
	Idle
}

//==============================================================================
// Variables
//==============================================================================


//==============================================================================
// Public Functions
//==============================================================================
pub fn init() {
	let peripherals = cc2640r2f::Peripherals::take().unwrap();
	let cortex_peripherals = cortex_m::Peripherals::take().unwrap();

	init_clock(peripherals.AON_WUC, peripherals.AUX_DDI0_OSC);

	systick::init(cortex_peripherals.SYST);
	
	// adc::init(peripherals.SAADC);
	// gpio::init(peripherals.P0);
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
fn init_clock(aon_wuc:cc2640r2f::AON_WUC, aux_ddi0_osc: cc2640r2f::AUX_DDI0_OSC) {
	// SCLK_HF: High Frequency Clock
	// SCLK_LF: Low Frequency Clock
	// SCLK_LF_AUX: Low Frequency Clock for peripherals in the AUX power domain
	// ACLK-ADC: Clock source for ADC operations
	// ACLK-REF: 
	// ACLK-TDCLK: Time-to-digital clock

	// Following some obscure procedure on section 6.5.1.1
	// Force power on the AUX power domain
	aon_wuc.auxctl.write( |w| w
		.aux_force_on().set_bit()
	);

	// Wait for the power domain to start up
	while aon_wuc.pwrstat.read().aux_pd_on().bit_is_set() {}

	// Configure the clocks
	aux_ddi0_osc.ctl0.write(|w| unsafe { w
		.sclk_hf_src_sel().xosc()
		.sclk_lf_src_sel().xosclf()
		.aclk_ref_src_sel().bits(0x3) /* XOSC_LF */
		.aclk_tdc_src_sel().bits(0x2) /* XOSC_HF */

	} );
}

//==============================================================================
// Task Handler
//==============================================================================
pub fn task_handler() {

}