#include "event.h"

event::event(int x, int y):
	x(x), y(y)
{}

int event::get_x()const{	return x; }
int event::get_y()const{	return y; }
