#include <algorithm>
#include "graphics.h"
#include "container.h"

container::container(unsigned int w, unsigned int h):element(w,h){}

container::~container(){}


void container::update(){
	drawer dr;
	for(auto &el:elements){
		el->update();
		const auto el_x = el->get_x(),
			el_y = el->get_y();
		const auto el_img = el->get_image();
		dr.draw_image(el_x, el_y, el_img, this->img);
	}
}

bool container::contains(std::shared_ptr<element> el)const{
	auto it = std::find(elements.begin(), elements.end(), el);
	return (it != elements.end());
}

void container::add_element(std::shared_ptr<element> el){
	elements.emplace_back(el);
}

void container::set_elements(const std::vector<std::shared_ptr<element>> &elements){
	this->elements = elements;
}

size_t container::get_size()const{
	return elements.size();
}

std::shared_ptr<element> container::get_element(const int place)const{
	return elements.at(place);
}

std::shared_ptr<element> container::get_element(int x, int y)const{
	for(const auto &el:elements){
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

std::vector<std::shared_ptr<element>> container::get_elements()const{
	return elements;
}

std::vector<std::shared_ptr<element>> container::get_elements(int x, int y)const{
	std::vector<std::shared_ptr<element>> els;
	for(const auto &el:elements){
		const int el_x = el->get_x();
		const int el_y = el->get_y();
		const int el_h = el->get_h();
		const int el_w = el->get_w();
		if(x >= el_x &&
			y >= el_y &&
			x <= el_x+el_w &&
			y <= el_y+el_h)
		{
			els.emplace_back(el);
		}
	}
	return els;
}

void container::on_press_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_press_e(e);
	}
}
void container::on_tap_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_tap_e(e);
	}
};
void container::on_release_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_release_e(e);
	}
};
void container::on_focus_enter_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_focus_enter_e(e);
	}
};
void container::on_focus_leave_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_focus_leave_e(e);
	}
};
void container::on_swipe_left_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_swipe_left_e(e);
	}
};
void container::on_swipe_right_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_swipe_right_e(e);
	}
};
void container::on_swipe_up_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_swipe_up_e(e);
	}
};
void container::on_swipe_down_e(std::shared_ptr<event> e){
	auto el = get_element(e->get_x(), e->get_y());
	if(el){
		el->on_swipe_down_e(e);
	}
};
