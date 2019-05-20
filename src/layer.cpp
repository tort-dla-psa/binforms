#include "layer.h"
#include "element.h"
#include "graphics.h"

using namespace binforms;

layer::layer(const uint w, const uint h)
	:element (w,h)
{}

/*
bool layer::get_changed()const{
	for(const auto &el:elements){
		if(el->get_changed()){
			return true;
		}
	}
	return false;
}*/

void layer::update(){
	graphics::drawer dr;
	for(auto &el:elements){
		//if(el->get_changed()){
		el->update();
		const auto el_x = el->get_x(),
			el_y = el->get_y();
		const sptr<bit_image> el_img = el->get_image();
		dr.draw_image(el_x, el_y, el_img, this->img);
		//el->set_changed(false);
		//}
	}
}

vec_s<element> layer::get_elements()const{
	return this->elements;
}

sptr<element> layer::get_element(const uint place)const{
	return elements[place];
}

sptr<element> layer::get_element(const int x, const int y)const{
	for(const sptr<element> &el:elements){
		const int el_x = el->get_x();
		const int el_y = el->get_y();
		const int el_h = el->get_h();
		const int el_w = el->get_w();
		if(x >= el_x &&
			y >= el_y &&
			x <= el_x+el_w &&
			y <= el_y+el_h)
		{
			return el;
		}
	}
	return nullptr;
}

void layer::add_element(const sptr<element> &el){
	this->elements.emplace_back(el);
	//set_changed(true);
}
