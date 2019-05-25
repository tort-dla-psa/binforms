#include "binform.h"
#include "graphics.h"

using namespace binforms;

binform::binform(unsigned int w, unsigned int h)
	:container(w,h)
{}

binform::~binform(){}

void binform::update(){
	drawer dr;
	for(auto &l:layers){
		l->update();
		const auto elements = l->get_elements();
		//TODO: blend settings
		for(const auto &el:elements){
			dr.draw_image(el->get_x(), 
				el->get_y(), el->get_image(), this->img);
		}
	}
}

void binform::add_layer(std::shared_ptr<container> l){
	layers.emplace_back(l);
	const auto els = l->get_elements();
	for(const auto &el:els){
		elements.emplace_back(el);
	}
}

size_t binform::get_layers_count()const{
	return layers.size();
}

std::vector<std::shared_ptr<container>> binform::get_layers()const{
	return layers;
}

std::shared_ptr<element> binform::get_layer(unsigned int place)const{
	return layers.at(place);
}

std::vector<std::shared_ptr<element>> binform::get_elements()const{
	return elements;
}

std::vector<std::shared_ptr<element>> binform::get_elements(int x, int y)const{
	std::vector<std::shared_ptr<element>> temp;
	for(const auto &l:layers){
		const auto el = l->get_element(x,y);
		if(el){
			temp.emplace_back(el);
		}
	}
	return temp;
}

std::shared_ptr<element> binform::get_element(const int x, const int y)const{
	//reverse iteration, from upper to lowest
	for(auto i = layers.rbegin(); i!= layers.rend(); i++){
		const auto el = (*i)->get_element(x,y);
		if(el){
			return el;
		}
	}
	return nullptr;
}

void binform::add_element(std::shared_ptr<element> el, unsigned int layer){
	layers.at(layer)->add_element(el);
	elements.emplace_back(el);
}
