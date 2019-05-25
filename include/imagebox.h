#pragma once
#include "element.h"
#include "imovable.h"

namespace binforms{
class image;
class drawer;
class imagebox: public element, public imovable {
	std::shared_ptr<image> inner_img;
	std::unique_ptr<drawer> drwr;
public:
	imagebox(unsigned int w, unsigned int h);
	imagebox(unsigned int w, unsigned int h,
		 std::shared_ptr<bit_image> img);
	virtual ~imagebox();
	void set_image(std::shared_ptr<image> img);
	std::shared_ptr<image> get_inner_img();
	virtual void update()override;
	virtual void move(int x, int y)override;
};
}
