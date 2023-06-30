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


void TRAIN_MODE_refresh(void) {
	LCD_print_big("TRAIN", 13, 2);


}

void TRAIN2_MODE_refresh(void) {
	LCD_print_big("TRAIN2", 13, 2);


}


void TRAIN_MODE_next(void) {



}
void TRAIN_MODE_start(void) {

}
void TRAIN_MODE_stop(void) {

}
void TRAIN_MODE_prev(void) {

}

void TRAIN_MODE_back(void) {

}


void TRAIN_MODE_callback(void) {
//	key_next_func = NULL;
//	key_prev_func = NULL;
//	key_enter_func = NULL;
//	//key_back_func = menu_back;
//	key_start_func = NULL;
//	key_stop_func = NULL;

	//PAR_MODE_refresh();

}

void TRAIN2_MODE_callback(void) {
//	key_next_func = NULL;
//	key_prev_func = NULL;
//	key_enter_func = NULL;
    back_func = menu_back;
//	key_start_func = NULL;
//	key_stop_func = NULL;

	//PAR_MODE_refresh();

}

