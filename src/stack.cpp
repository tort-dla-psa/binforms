#include "stack.h"
#include "graphics.h"

using namespace binforms;

stack::stack():container(0,0){
	drwr = std::make_unique<drawer>();
}

stack::~stack(){}


int stack::get_place(std::shared_ptr<element> el)const{
	for(int i=0; i<elements.size(); i++){
		if(elements[i] == el){
			return i;
		}
	}
	return -1;
}

std::shared_ptr<element> stack::get_next_of(std::shared_ptr<element> el)const{
	const int place = get_place(el);
	return get_element(place+1);
}

std::shared_ptr<element> stack::get_prev_of(std::shared_ptr<element> el)const{
	const int place = get_place(el);
	return get_element(place-1);
}

void stack::move(int x, int y){
	this->x = x;
	this->y = y;
//	set_changed(true);
}


v_stack::v_stack():stack(){}

void v_stack::align_items(){
	uint prev_h = y;
	for(auto &el: elements){
		auto cast = std::dynamic_pointer_cast<imovable>(el);
		if(cast)
			cast->move(x, prev_h);
		prev_h += el->get_h();
	}
//	set_changed(true);
}

void v_stack::set_elements(const std::vector<std::shared_ptr<element>> &elements){
	this->elements = elements;
	align_items();
	update_size();
}

void v_stack::add_element(std::shared_ptr<element> el){
	elements.emplace_back(el);
	align_items();
	update_size();
}

void v_stack::update_size(){
	uint new_w = 0, new_h = 0;
	for(auto &el: elements){
		new_h += el->get_h();
		new_w = std::max(new_w, el->get_w());
	}
	this->img = std::make_shared<bit_image>(new_w, new_h);
}

void v_stack::update(){
	for(auto &el:elements){
		drwr->draw_image(el->get_x()-x, el->get_y()-y, el->get_image(), this->img);
	}
}


h_stack::h_stack():stack(){}

void h_stack::align_items(){
	uint prev_w = x;
	for(auto &el: elements){
		auto cast = std::dynamic_pointer_cast<imovable>(el);
		if(cast)
			cast->move(prev_w, y);
		prev_w += el->get_w();
	}
}

void h_stack::set_elements(const std::vector<std::shared_ptr<element>> &elements){
	this->elements = elements;
	align_items();
	update_size();
}

void h_stack::add_element(std::shared_ptr<element> el){
	elements.emplace_back(el);
	align_items();
	update_size();
}

void h_stack::update_size(){
	uint new_w = 0, new_h = 0;
	for(auto &el: elements){
		new_h = std::max(new_h, el->get_h());
		new_w += el->get_w();
	}
	this->img = std::make_shared<bit_image>(new_w, new_h);
}

void h_stack::update(){
	for(auto &el:elements){
		drwr->draw_image(el->get_x()-x, el->get_y()-y, el->get_image(), this->img);
	}
}
