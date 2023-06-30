/*
 * MENU.h
 *
 *  Created on: 16 cze 2022
 *      Author: Ollie
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_

typedef struct menu_struct menu_t;

struct menu_struct {

	char *name;
	menu_t *next;
	menu_t *prev;
	menu_t *child;
	menu_t *parent;
	void (*menu_function)(void);
	void (*menu_refresh)(void);


};

extern menu_t par;
extern menu_t comstock;
extern menu_t virginia;
extern menu_t info;
extern menu_t train;
extern menu_t train1_2;


typedef void (*key_next_func)(void);
typedef void (*key_prev_func)(void);
typedef void (*key_enter_func)(void);
typedef void (*key_enterlong_func)(void);
typedef void (*key_back_func)(void);
typedef void (*key_stop_func)(void);
typedef void (*key_start_func)(void);
typedef void (*key_backshort_func)(void);
typedef void (*key_prevlong_func)(void);
typedef void (*key_nextlong_func)(void);

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

void menu_next(void);
void menu_prev(void);
void menu_refresh(void);
void menu_enter(void);
void menu_back(void);
void system_esc(void);
void key_next_press(void);
void key_prev_press(void);
void key_ok_press(void);
void key_esc_press(void);
void key_stop_press(void);
void key_start_press(void);
void disp_brightness_callback(void);

#endif /* INC_MENU_H_ */
