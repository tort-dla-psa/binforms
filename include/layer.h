#pragma once

#include "aliases.h"
#include "element.h"
#include "iholding.h"
#include "event.h"

namespace binforms{

using uint = unsigned int;

class layer:public element{
protected:
	vec_s<element> elements;
public:
	layer(const uint w, const uint h);
	//bool get_changed()const override;
	void update()override;
	virtual vec_s<element> get_elements()const;
	virtual sptr<element> get_element(const uint place)const;
	virtual sptr<element> get_element(const int x, const int y)const;
	virtual void add_element(const sptr<element> &el);
};
}
