#pragma once
#include "container.h"
#include "element.h"

namespace binforms{

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

class binform:public container{
	void add_element(std::shared_ptr<element> el)override{};
protected:
	std::vector<std::shared_ptr<container>> layers;
public:
	binform(unsigned int w, unsigned int h);
	virtual ~binform();

	void update()override;
	void add_layer(std::shared_ptr<container> l);
	size_t get_layers_count()const;
	virtual std::shared_ptr<element> get_layer(unsigned int place)const;
	virtual std::vector<std::shared_ptr<container>> get_layers()const;
	virtual std::vector<std::shared_ptr<element>> get_elements()const;
	virtual std::vector<std::shared_ptr<element>> get_elements(int x,int y)const override;
	virtual std::shared_ptr<element> get_element(int x, int y)const override;
	virtual void add_element(std::shared_ptr<element> el, unsigned int layer);
};
}
