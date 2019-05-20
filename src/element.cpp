#include "element.h"
#include "image.h"

using namespace binforms;

element::element(const unsigned int w, const unsigned int h)
	:img(new bit_image(w,h))
{}

element::~element(){}

/*
void element::set_changed(const bool status){
	this->changed = status;
}
bool element::get_changed() const{
	return changed;
}*/
unsigned int element::get_w()const{
	return img->get_w();
}
unsigned int element::get_h()const{
	return img->get_h();
}
sptr<bit_image> element::get_image(){
	return img;
}
int element::get_x(){
	return x;
}
int element::get_y(){
	return y;
}

