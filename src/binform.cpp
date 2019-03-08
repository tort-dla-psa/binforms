#include "binform.h"
#include "element.h"
#include "graphics.h"

binform::binform(const unsigned int w, const unsigned int h)
	:element (w,h)
{}

unsigned int binform::get_w()const{
	return img->get_w();
}
unsigned int binform::get_h()const{
	return img->get_h();
}

bool binform::get_changed()const{
	bool updated = false;
	for(const auto &el:elements){
		updated |= el->get_changed();
	}
	return updated;
}

void binform::update(){
	graphics::drawer dr(img);
	for(auto &el:elements){
		if(el->get_changed()){
			el->update();
			const int el_x = el->get_x(),
				el_y = el->get_y();
			const sptr<bit_image> el_img = el->get_image();

			dr.draw_image(el_x,el_y,el_img);
			el->set_changed(false);
		}
	}
}

vec_s<element> binform::get_elements()const{
	return this->elements;
}
vec_s<element> binform::get_elements(const int x, const int y)const{
	vec_s<element> temp;
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
			temp.emplace_back(el);
		}
	}
	return temp;
}

sptr<element> binform::get_element(const unsigned int place)const{
	return elements[place];
}
sptr<element> binform::get_element(const int x, const int y)const{
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

void binform::set_elements(const vec_s<element> &elements){
	this->elements = elements;
	set_changed(true);
}

void binform::set_element(const unsigned int place, const sptr<element> &el){
	this->elements[place] = el;
	set_changed(true);
}

void binform::add_element(const sptr<element> &el){
	this->elements.emplace_back(el);
	set_changed(true);
}
