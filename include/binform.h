#pragma once

#include "layer.h"
#include "aliases.h"
#include "element.h"
#include "iholding.h"

using uint = unsigned int;

enum class BINFORM_EVENTS{
	press,
	release,
	tap,
	focus_enter,
	focus_leave,
	swipe_left,
	swipe_right,
	swipe_up,
	swipe_down,
};

class binform:public element{
protected:
	vec_s<layer> layers;
public:
	binform(const uint w, const uint h);
	//bool get_changed()const override;
	void update()override;
	//add new layer
	void add_layer(const sptr<layer> &l);
	//return all layers
	virtual vec_s<layer> get_layers()const;
	//return desired layer
	virtual sptr<element> get_layer(const uint place)const;
	//return all elements
	virtual vec_s<element> get_elements()const;
	//return all elements at coodrdinates
	virtual vec_s<element> get_elements(const int x, const int y)const;
	//return upper element at coodrdinates
	virtual sptr<element> get_element(const int x, const int y)const;
	//add element to layer
	virtual void add_element(const sptr<element> &el, const uint layer);
};
