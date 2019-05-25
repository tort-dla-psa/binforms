#pragma once

#include "container.h"
#include "imovable.h"
#include "aliases.h"

namespace binforms{

class drawer;
class stack:public container, public imovable {
protected:
	std::unique_ptr<drawer> drwr;
	stack();
	virtual void align_items()=0;
public:
	virtual ~stack();
	std::shared_ptr<element> get_next_of(std::shared_ptr<element> el)const;
	std::shared_ptr<element> get_prev_of(std::shared_ptr<element> el)const;
	virtual void update_size()=0;
	int get_place(std::shared_ptr<element> el)const;
	void move(int x, int y)override;
};

class v_stack:public stack{
	void align_items()override;
public:
	v_stack();

	void update()override;
	void update_size()override;
	void add_element(std::shared_ptr<element> el)override;
	void set_elements(const std::vector<std::shared_ptr<element>> &elements)override;
};

class h_stack:public stack{
	void align_items()override;
public:
	h_stack();

	void update()override;
	void update_size()override;
	void add_element(std::shared_ptr<element> el)override;
	void set_elements(const std::vector<std::shared_ptr<element>> &elements)override;
};
}
