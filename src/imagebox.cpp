#include "imagebox.h"
#include "graphics.h"

using namespace binforms;

imagebox::imagebox(unsigned int w, unsigned int h)
	:element (w,h), imovable ()
{
	drwr = std::make_unique<drawer>();
	set_image(this->img);
}

imagebox::imagebox(unsigned int w, unsigned int h,
	std::shared_ptr<bit_image> img)
	:imagebox(w,h)
{
	this->inner_img = img;
}

imagebox::~imagebox(){}

void imagebox::set_image(std::shared_ptr<image> img){
	this->inner_img = img;
	//set_changed(true);
}

std::shared_ptr<image> imagebox::get_inner_img(){
	return inner_img;
}

void imagebox::update(){
	auto casted = std::static_pointer_cast<bit_image>(inner_img);
	if(casted)
		drwr->draw_image(0, 0, casted, this->img);
	//set_changed(true);
}

void imagebox::move(int x, int y){
	this->x = x;
	this->y = y;
	//set_changed(true);
}
