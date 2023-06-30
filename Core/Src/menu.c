#include "main.h"
// definition of menu's components: (*name, *next, *prev, *child, *parent, (*menu_function), (*menu_refresh))
menu_t par = { "PAR", &comstock, &info, NULL, NULL, NULL, PAR_MODE_refresh };
menu_t comstock = { "COM", &virginia, &par, NULL, NULL, NULL, COM_MODE_refresh };
menu_t virginia =
		{ "VIR", &info, &comstock, NULL, NULL, NULL, VIR_MODE_refresh };
menu_t info = { "INFO", &train, &virginia, NULL, NULL, NULL, INFO_MODE_refresh };
menu_t train =
		{ "TRAIN", &par, &info, &train1_2, NULL, NULL, TRAIN_MODE_refresh };
menu_t train1_2 = { "TRAIN2", NULL, NULL, NULL, &train, TRAIN2_MODE_callback, TRAIN2_MODE_refresh };

/*
 menu_t big = { "BIG", &small, &small, NULL, &solder, NULL };
 menu_t small = { "SMALL", &big, &big, NULL, &solder, NULL };
 menu_t settings = { "SETTINGS", &info, &work, &led, NULL, NULL };
 menu_t led = { "LED BRIGHTNESS", &screen, &sub_menu2_4, NULL, &settings, NULL };
 menu_t screen = { "SCREN ORIENTATION", &sub_menu2_3, &led, NULL, &settings, NULL };
 menu_t sub_menu2_3 = { "Stop Bits : 1bit", &sub_menu2_4, &screen, NULL, &settings, NULL };
 menu_t sub_menu2_4 = { "Parity    : none", NULL, &sub_menu2_3, NULL, &settings, NULL };
 */

key_next_func next_func = &menu_next;
key_prev_func prev_func = &menu_prev;

key_enterlong_func enterlong_func = &system_esc;
key_enter_func enter_func = &menu_enter;
key_back_func back_func = &menu_back;

key_stop_func stop_func = &menu_back;
key_start_func start_func = &menu_back;

key_prevlong_func prevlong_func = NULL;
key_nextlong_func nextlong_func = NULL;
key_backshort_func backshort_func = NULL;

menu_t *currentPointer = &info;

uint8_t menu_index;
uint16_t time = 0;

//key_next_func fun1 = &menu_next;

//extern next_func;

//void (*key_next_func)(void) = &menu_next;
//void (*key_prev_func)(void) = &menu_prev;
//void (*key_enter_func)(void) = &menu_enter;
//void (*key_enterlong_func)(void) = &system_esc;
//void (*key_stop_func)(void) = &menu_back;
//void (*key_start_func)(void) = &menu_back;
//void (*key_backshort_func)(void) = NULL;

uint8_t menu_get_index(menu_t *q) {

	menu_t *temp;
	uint8_t i = 0;

	if (q->parent)
		temp = (q->parent)->child;
	else
		temp = &par;

	while (temp != q) {
		temp = temp->next;
		i++;
	}

	return i;
}

void menu_next(void) {

	if (currentPointer->next) {
		currentPointer = currentPointer->next;
		menu_index++;

	} else {
		menu_index = 0;

		if (currentPointer->parent)
			currentPointer = (currentPointer->parent)->child;
		else
			currentPointer = &par;
	}

	menu_refresh();

}

void menu_prev(void) {

	currentPointer = currentPointer->prev;

	if (menu_index) {
		menu_index--;

	} else {
		menu_index = menu_get_index(currentPointer);

	}

	menu_refresh();
}

void menu_enter(void) {

	if (currentPointer->menu_function)
		currentPointer->menu_function();

	if (currentPointer->child) {

		menu_index = 0;

		currentPointer = currentPointer->child;

		menu_refresh();
	}
}

void menu_back(void) {

	if (currentPointer->parent) {

		currentPointer = currentPointer->parent;
		menu_index = menu_get_index(currentPointer);

		menu_refresh();

	}
}

void system_esc(void) {

	LL_GPIO_ResetOutputPin(POWER_ALL_GPIO_Port, POWER_ALL_Pin);
}

void menu_refresh(void) {
	//LCD_refreshScr();
	LCD_clrScr();
	menu_t *temp;
	uint8_t i;

	currentPointer->menu_refresh();

	if (currentPointer->parent)
		temp = (currentPointer->parent)->child;

	else
		temp = &par;

	for (i = 0; i != menu_index; i++) {
		temp = temp->next;
	}

	//LCD_print(temp->name, 0, 0);
	/*LCD_print("SPLIT 00:00", 0, 0);
	 LCD_print("TRYB", 46, 0);*/
	//LCD_print(currentPointer->name, 67, 0);
	/*LCD_print("PAR 00:00", 0, 9);
	 LCD_print("shoot 00", 46, 9);*/

	//LCD_print("00:00:00", 0, 18);
	uint32_t bat;
	ADC1->CHSELR = ADC_CHSELR_CHSEL1;
	ADC1->CR |= ADC_CR_ADSTART;
	while (ADC1->CR & ADC_CR_ADSTART)
		;
	bat = ADC1->DR;

	uint16_t bat1 = (uint16_t) (bat * 3300 / 4096 * 2);

	char buffer[5];
	itoa((bat1 * 100 / 4200), buffer, 10);
	LCD_print(buffer, 22, 45);
	//LCD_print("shoot 00", 0, 36);

	LCD_print("batt:", 0, 45);
	LCD_print("%", 35, 45);

	temp = temp->next;

}

void key_next_press(void) {

	if (BUTTON_1) {
		uint16_t timer = 0;

		while (BUTTON_1) {
			timer++; // count how long button is pressed
			Delay_ms(1);
		}

		if (timer < 500UL) { //unsigned long
							 //single click
			if (next_func != NULL) {
				next_func();
			}
		} else {
			if (nextlong_func != NULL) {
				nextlong_func();
			}
		}
	}
}
void key_prev_press(void) {

	if (BUTTON_2) {
		uint16_t timer = 0;

		while (BUTTON_2) {
			timer++; // count how long button is pressed
			Delay_ms(1);
		}
		if (timer < 500UL) { //unsigned long
			//single click
			if (prev_func != NULL) {
				prev_func();
			}
		} else {
			if (prevlong_func != NULL) {
				prevlong_func();
			}
		}

	}

}

void key_ok_press(void) {

	if (BUTTON_MAIN) {

		uint16_t timer = 0;
		if (backshort_func)
					{backshort_func();}

		while (BUTTON_MAIN) {
			timer++;
			Delay_ms(1);
		}
		if (timer < 500UL) {	                   //unsigned long
			//single click
			if (enter_func != NULL) {
				enter_func();
			}
		} else {
			//button hold
			if (enterlong_func != NULL) {
				enterlong_func();
			}
		}

	}

}

void key_esc_press(void) {

	if (BUTTON_3) {

		uint16_t timer = 0;
		if (backshort_func)
					{backshort_func();}

		while (BUTTON_3) {
			timer++;
			Delay_ms(1);
		}
		if (timer < 500UL) {                  //unsigned long
			//single click
			if (enter_func != NULL) {
				enter_func();
			}
		} else {
			//button hold
			if (back_func != NULL) {
				back_func();
			}
		}

	}

}
void key_stop_press(void) {

	if (BUTTON_STOP) {

		uint16_t timer = 0;
		if (backshort_func)
					{backshort_func();}

		while (BUTTON_STOP) {
			timer++;
			Delay_ms(1);
		}
		if (timer < 500UL) {                  //unsigned long
			//single click
			if (stop_func != NULL) {
				stop_func();
			}
		} else {
			//button hold
			if (back_func != NULL) {
				back_func();
			}
		}

	}

}
void key_start_press(void) {

	if (BUTTON_START) {

		uint16_t timer = 0;
		if (backshort_func)
			{backshort_func();}

		while (BUTTON_START) {
			timer++;
			Delay_ms(1);
		}
		if (timer < 500UL) {                  //unsigned long
			//single click
			if (start_func != NULL) {
				start_func();
			}
		} else {
			//button hold
			if (back_func != NULL) {
				back_func();
			}
	}

}

}
