#pragma once

#include "layer.h"
#include "aliases.h"
#include "element.h"
#include "iholding.h"

using uint = unsigned int;

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

	virtual void on_key_press_e(sptr<event> e){}
	virtual void on_key_tap_e(sptr<event> e){}
	virtual void on_key_release_e(sptr<event> e){}
};
