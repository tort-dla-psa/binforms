#pragma once
#include <vector>
#include <memory>
#include "element.h"

using namespace binforms;

class container:public element{
protected:
	std::vector<std::shared_ptr<element>> elements;
public:
	container(unsigned int w, unsigned int h);
	virtual ~container();

	virtual void update()override;
	bool contains(std::shared_ptr<element> el)const;
	virtual void add_element(std::shared_ptr<element> el);
	virtual void set_elements(const std::vector<std::shared_ptr<element>> &elements);
	size_t get_size()const;
	std::shared_ptr<element> get_element(const int place)const;
	virtual std::shared_ptr<element> get_element(int x, int y)const;
	std::vector<std::shared_ptr<element>> get_elements()const;
	virtual std::vector<std::shared_ptr<element>> get_elements(int x, int y)const;

	virtual void on_press_e(std::shared_ptr<event> e)override;
	virtual void on_tap_e(std::shared_ptr<event> e)override;
	virtual void on_release_e(std::shared_ptr<event> e)override;
	virtual void on_focus_enter_e(std::shared_ptr<event> e)override;
	virtual void on_focus_leave_e(std::shared_ptr<event> e)override;
	virtual void on_swipe_left_e(std::shared_ptr<event> e)override;
	virtual void on_swipe_right_e(std::shared_ptr<event> e)override;
	virtual void on_swipe_up_e(std::shared_ptr<event> e)override;
	virtual void on_swipe_down_e(std::shared_ptr<event> e)override;
};
