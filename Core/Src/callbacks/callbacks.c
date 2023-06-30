#include "main.h"

extern key_next_func next_func;
extern key_prev_func prev_func;

extern key_enter_func enter_func;
extern key_enterlong_func enterlong_func;
extern key_back_func back_func;

extern key_stop_func stop_func;
extern key_start_func start_func;

extern key_prevlong_func prevlong_func;
extern key_nextlong_func nextlong_func;
extern key_backshort_func backshort_func;




/*
 * STOPWATCH
 * */

//void INFO_MODE_refresh(void);

void INFO_MODE_next(void) {

	INFO_MODE_refresh();

}


void INFO_MODE_refresh(void) {
	LCD_print_big("INFO", 19, 2);


}

void VIR_MODE_refresh(void) {
	LCD_print_big("VIR", 25, 2);


}

void COM_MODE_refresh(void) {
	LCD_print_big("COM", 25, 2);


}


void INFO_MODE_callback(void) {
	next_func = PAR_MODE_next;
//	key_next_func = PAR_MODE_next;
//	key_prev_func = PAR_MODE_prev;
//	key_enter_func = NULL;
//	key_back_func = PAR_MODE_back;
//	key_start_func = PAR_MODE_start;
//	key_stop_func = PAR_MODE_stop;

	//INFO_MODE_refresh();

}



