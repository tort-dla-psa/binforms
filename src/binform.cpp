#include "binform.h"
#include "element.h"
#include "graphics.h"

using namespace binforms;

binform::binform(const unsigned int w, const unsigned int h)
	:element (w,h)
{}

/*
bool binform::get_changed()const{
	for(const auto &l:layers){
		if(l->get_changed()){
			return true;
		}
	}
	return false;
}*/

void binform::add_layer(const sptr<layer> &l){
	layers.emplace_back(l);
}

void binform::update(){
	drawer dr;
	for(auto &l:layers){
		//if(l->get_changed()){
		l->update();
		const auto elements = l->get_elements();
		for(const auto &el:elements){
			dr.draw_image(el->get_x(), 
				el->get_y(), el->get_image(), this->img);
		}
		//el->set_changed(false);
		//}
	}
}

vec_s<layer> binform::get_layers()const{
	return this->layers;
}

sptr<element> binform::get_layer(const uint place)const{
	return layers[place];
}

vec_s<element> binform::get_elements()const{
	vec_s<element> elements;
	for(const auto &l:layers){
		const auto elems = l->get_elements();
		elements.reserve(elements.size() + elems.size());
		for(const auto &el:elems){
			elements.emplace_back(el);
		}
	}
	return elements;
}

vec_s<element> binform::get_elements(const int x, const int y)const{
	vec_s<element> temp;
	for(const auto &l:layers){
		const auto el = l->get_element(x,y);
		if(el){
			temp.emplace_back(el);
		}
	}
	return temp;
}

sptr<element> binform::get_element(const int x, const int y)const{
	for(const auto &l:layers){
		const auto el = l->get_element(x,y);
		if(el){
			return el;
		}
	}
	return nullptr;
}

void binform::add_element(const sptr<element> &el, const uint layer){
	layers[layer]->add_element(el);
}
