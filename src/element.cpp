#include "element.h"
#include "image.h"

using namespace binforms;

element::element(const unsigned int w, const unsigned int h){
	img = std::make_shared<bit_image>(w,h);
}

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
std::shared_ptr<bit_image> element::get_image(){
	return img;
}
int element::get_x(){
	return x;
}
int element::get_y(){
	return y;
}

void element::on_press_e(std::shared_ptr<event> e){}
void element::on_tap_e(std::shared_ptr<event> e){}
void element::on_release_e(std::shared_ptr<event> e){}
void element::on_focus_enter_e(std::shared_ptr<event> e){}
void element::on_focus_leave_e(std::shared_ptr<event> e){}
void element::on_swipe_left_e(std::shared_ptr<event> e){}
void element::on_swipe_right_e(std::shared_ptr<event> e){}
void element::on_swipe_up_e(std::shared_ptr<event> e){}
void element::on_swipe_down_e(std::shared_ptr<event> e){}
