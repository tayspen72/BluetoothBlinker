/******************************************************************************/
/* Notes */
/******************************************************************************/


/******************************************************************************/
/* Includes */
/******************************************************************************/


/******************************************************************************/
/* Definitions */
/******************************************************************************/


/******************************************************************************/
/* Enumerations and Structures */
/******************************************************************************/


/******************************************************************************/
/* Prototypes */
/******************************************************************************/
static void main_init();
static void main_task_handler();

/******************************************************************************/
/* Static Variables */
/******************************************************************************/


/******************************************************************************/
/* Main */
/******************************************************************************/
int main() {

	main_init();

	while(1) {
		main_task_handler();
	}

	return 0;
}

/******************************************************************************/
/* Private Functions */
/******************************************************************************/
static void main_init() {

}

/******************************************************************************/
/* Task Handler */
/******************************************************************************/
static void main_task_handler() {

}

