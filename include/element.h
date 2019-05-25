#pragma once
#include <memory>
#include "event.h"

namespace binforms{
class bit_image;

class element{
private:
	bool changed;
protected:
	int x, y;
	std::shared_ptr<bit_image> img;
public:
	element(const unsigned int w, const unsigned int h);
	virtual ~element();

	unsigned int get_w()const;
	unsigned int get_h()const;
	virtual void update()=0;
	std::shared_ptr<bit_image> get_image();
	virtual int get_x();
	virtual int get_y();

	virtual void on_press_e(std::shared_ptr<event> e);
	virtual void on_tap_e(std::shared_ptr<event> e);
	virtual void on_release_e(std::shared_ptr<event> e);
	virtual void on_focus_enter_e(std::shared_ptr<event> e);
	virtual void on_focus_leave_e(std::shared_ptr<event> e);
	virtual void on_swipe_left_e(std::shared_ptr<event> e);
	virtual void on_swipe_right_e(std::shared_ptr<event> e);
	virtual void on_swipe_up_e(std::shared_ptr<event> e);
	virtual void on_swipe_down_e(std::shared_ptr<event> e);
};
}
