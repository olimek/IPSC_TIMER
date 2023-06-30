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


void PAR_MODE_refresh(void) {
	/*LCD_print_big("00:00:00", 0, 27);*/

	LCD_print_big("PAR", 25, 2);

}


void PAR_MODE_next(void) {



}
void PAR_MODE_start(void) {

}
void PAR_MODE_stop(void) {

}
void PAR_MODE_prev(void) {

}

void PAR_MODE_back(void) {

}


void PAR_MODE_callback(void) {
//	key_next_func = PAR_MODE_next;
//	key_prev_func = PAR_MODE_prev;
//	key_enter_func = NULL;
//	key_back_func = PAR_MODE_back;
//	key_start_func = PAR_MODE_start;
//	key_stop_func = PAR_MODE_stop;

	//PAR_MODE_refresh();
}

