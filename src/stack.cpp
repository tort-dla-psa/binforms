#include <stack.h>

stack::stack():element(0,0){
	drwr = uptr<drawer>(new drawer());
}

stack::~stack(){}

uint stack::get_size()const{
	return elements.size();
}

uint stack::get_place(const sptr<element> &el)const{
	const uint end = elements.size();
	for(uint i=0; i<end; i++){
		if(elements[i] == el){
			return i;
		}
	}
	return -1;
}

sptr<element> stack::get_next_of(const sptr<element> &el)const{
	const uint place = get_place(el);
	return get_element(place+1);
}

sptr<element> stack::get_prev_of(const sptr<element> &el)const{
	const uint place = get_place(el);
	return get_element(place-1);
}

vec_s<element> stack::get_elements()const{
	return elements;
}

sptr<element> stack::get_element(const uint place)const{
	return elements[place];
}

void stack::move(int x, int y){
	this->x = x;
	this->y = y;
//	set_changed(true);
}


v_stack::v_stack():stack(){}

void v_stack::align_items(){
	uint prev_h = 0;
	for(auto &el: elements){
		sptr<imovable> cast = std::dynamic_pointer_cast<imovable>(el);
		if(cast)
			cast->move(0, prev_h);
		prev_h += el->get_h();
	}
//	set_changed(true);
}

void v_stack::set_elements(const vec_s<element> &elements){
	this->elements = elements;
	align_items();
	update_size();
}

void v_stack::set_element(const uint place, const sptr<element> &el) {
	this->elements[place] = el;
	align_items();
	update_size();
}

void v_stack::add_element(const sptr<element> &el){
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
//	set_changed(true);
}

void v_stack::update(){
	uint prev_h = 0;
	for(auto &el:elements){
		//if(el->get_changed()){
		drwr->draw_image(0, prev_h, el->get_image(), this->img);
		//el->set_changed(false);
		//}
		prev_h += el->get_h();
	}
	//set_changed(true);
}


h_stack::h_stack():stack(){}

void h_stack::align_items(){
	uint prev_w = 0;
	for(auto &el: elements){
		sptr<imovable> cast = std::dynamic_pointer_cast<imovable>(el);
		if(cast)
			cast->move(prev_w, 0);
		prev_w += el->get_w();
	}
	//set_changed(true);
}

void h_stack::set_elements(const vec_s<element> &elements){
	this->elements = elements;
	align_items();
	update_size();
}

void h_stack::set_element(const uint place, const sptr<element> &el) {
	this->elements[place] = el;
	align_items();
	update_size();
}

void h_stack::add_element(const sptr<element> &el){
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
	//set_changed(true);
}

void h_stack::update(){
	uint prev_w = 0;
	for(auto &el:elements){
		//if(el->get_changed()){
		drwr->draw_image(prev_w, 0, el->get_image(), this->img);
		//el->set_changed(false);
		//}
		prev_w += el->get_w();
	}
	//set_changed(true);
}
