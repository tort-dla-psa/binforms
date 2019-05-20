#include "imagebox.h"
#include "graphics.h"

using namespace binforms;
using namespace graphics;

imagebox::imagebox(const uint w, const uint h)
	:element (w,h), imovable ()
{
	drwr = std::unique_ptr<drawer>(new drawer());
	set_image(this->img);
}

imagebox::imagebox(const uint w, const uint h,
		const sptr<bit_image> &img)
	:imagebox(w,h)
{
	this->inner_img = img;
}

imagebox::~imagebox(){}

void imagebox::set_image(sptr<image> img){
	this->inner_img = img;
	//set_changed(true);
}

sptr<image> imagebox::get_inner_img(){
	return inner_img;
}

void imagebox::update(){
	sptr<bit_image> casted = std::static_pointer_cast<bit_image>(inner_img);
	if(casted)
		drwr->draw_image(0, 0, casted, this->img);
	//set_changed(true);
}

void imagebox::move(int x, int y){
	this->x = x;
	this->y = y;
	//set_changed(true);
}
