#pragma once

#include "element.h"
#include "imovable.h"
#include "aliases.h"

using uint = unsigned int;

namespace binforms{

class drawer;
class stack:public element, public imovable {
protected:
	uptr<drawer> drwr;
	stack();
	vec_s<element> elements;
	virtual void align_items()=0;
public:
	virtual ~stack();
	uint get_size()const;
	sptr<element> get_next_of(const sptr<element> &el)const;
	sptr<element> get_prev_of(const sptr<element> &el)const;
	virtual void update_size()=0;
	vec_s<element> get_elements()const;
	sptr<element> get_element(const uint place)const;
	uint get_place(const sptr<element> &el)const;
	virtual void add_element(const sptr<element> &el)=0;
	virtual void set_elements(const vec_s<element> &elements)=0;
	virtual void set_element(const uint place, const sptr<element> &el)=0;
	void move(int x, int y)override;
};

class v_stack:public stack{
	void align_items()override;
public:
	v_stack();
	void update()override;
	void update_size()override;
	void add_element(const sptr<element> &el)override;
	void set_elements(const vec_s<element> &elements)override;
	void set_element(const uint place, const sptr<element> &el)override;
};

class h_stack:public stack{
	void align_items()override;
public:
	h_stack();
	void update()override;
	void update_size()override;
	void add_element(const sptr<element> &el)override;
	void set_elements(const vec_s<element> &elements)override;
	void set_element(const uint place, const sptr<element> &el)override;
};
}
