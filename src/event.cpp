#include "event.h"

event::event(event_type type){}

cursor_event::cursor_event(event_type type, int x, int y):
	event(type), x(x), y(y)
{}

int cursor_event::get_x()const{	return x; }
int cursor_event::get_y()const{	return y; }

key_event::key_event(event_type type, int key):
	event(type), key(key)
{}

int key_event::get_key()const{	return key; }
