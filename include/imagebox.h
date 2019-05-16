#pragma once

#include "element.h"
#include "graphics.h"
#include "imovable.h"
#include "aliases.h"

using namespace graphics;
using uint = unsigned int;

class imagebox: public element, public imovable {
	sptr<image> inner_img;
	uptr<drawer> drwr;
public:
	imagebox(const uint w, const uint h);
	imagebox(const uint w, const uint h,
		 const sptr<bit_image> &img);
	virtual ~imagebox();
	void set_image(sptr<image> img);
	sptr<image> get_inner_img();
	virtual void update()override;
	virtual void move(int x, int y)override;
};
