#ifndef IMAGEBOX_H
#define IMAGEBOX_H
#include "element.h"
#include "graphics.h"
#include "imovable.h"
#include "aliases.h"

using namespace graphics;
class imagebox: public element,
		public imovable
{
	sptr<image> inner_img;
	uptr<drawer> drwr;
public:
	imagebox(const unsigned int w, const unsigned int h);
	imagebox(const unsigned int w, const unsigned int h,
		 const sptr<bit_image> &img);
	virtual ~imagebox();
	void set_image(sptr<image> img);
	sptr<image> get_inner_img();
	virtual void update()override;
	virtual void move(int x, int y)override;
};

#endif // IMAGEBOX_H
