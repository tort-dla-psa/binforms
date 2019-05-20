#ifndef ELEMENT_H
#define ELEMENT_H
#include "aliases.h"
#include "event.h"

using uint = unsigned int;

class bit_image;

class element{
private:
	bool changed;
protected:
	int x, y;
	sptr<bit_image> img;
public:
	element(const uint w, const uint h);
	virtual ~element();
	uint get_w()const;
	uint get_h()const;
	//void set_changed(const bool status);
	//virtual bool get_changed()const;
	virtual void update()=0;
	sptr<bit_image> get_image();
	virtual int get_x();
	virtual int get_y();

	virtual void on_press_e(sptr<event> e){}
	virtual void on_tap_e(sptr<event> e){}
	virtual void on_release_e(sptr<event> e){}
	virtual void on_focus_enter_e(sptr<event> e){}
	virtual void on_focus_leave_e(sptr<event> e){}
	virtual void on_swipe_left_e(sptr<event> e){}
	virtual void on_swipe_right_e(sptr<event> e){}
	virtual void on_swipe_up_e(sptr<event> e){}
	virtual void on_swipe_down_e(sptr<event> e){}
	virtual void on_create_e(sptr<event> e){}
	virtual void on_delete_e(sptr<event> e){}
	virtual void on_move_e(sptr<event> e){}
};

#endif // ELEMENT_H
