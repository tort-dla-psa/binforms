#ifndef ELEMENT_H
#define ELEMENT_H
#include "aliases.h"
#include "event.h"

class bit_image;
class element{
private:
	bool changed;
protected:
	unsigned int x,y;
	sptr<bit_image> img;
public:
	element(const unsigned int w,
		const unsigned int h);
	virtual ~element();
	unsigned int get_w()const;
	unsigned int get_h()const;
	void set_changed(const bool status);
	virtual bool get_changed()const;
	virtual void update()=0;
	sptr<bit_image> get_image()const;
	virtual void move(const unsigned int x, const unsigned int y);
	virtual unsigned int get_x()const;
	virtual unsigned int get_y()const;

	virtual void on_press_e(sptr<event> e){}
	virtual void on_tap_e(sptr<event> e){}
	virtual void on_release_e(sptr<event> e){}
	virtual void on_focus_enter_e(sptr<event> e){}
	virtual void on_focus_leave_e(sptr<event> e){}
	virtual void on_swipe_left_e(sptr<event> e){}
	virtual void on_swipe_right_e(sptr<event> e){}
	virtual void on_swipe_up_e(sptr<event> e){}
	virtual void on_swipe_down_e(sptr<event> e){}
};

#endif // ELEMENT_H
