#include<iostream>
#include "binform.h"
#include "label.h"
#include "image.h"
#include "graphics.h"
#include "imagebox.h"
#include "button.h"
#include "event.h"
#include "image.h"

using namespace binforms;

inline void draw_img(image* img){
	const unsigned int w = img->get_w();
	const unsigned int h = img->get_h();

	for(unsigned int i=0; i<h; i++){
		for(unsigned int j=0; j<w; j++){
			std::cout<<(img->get_pixel(j,i)? '#':'_');
		}
		std::cout<<'\n';
	}
}

int main(){
	const auto w = 40, h = 20;
	auto form = std::make_unique<binform>(w, h);
	{
		auto lr = std::make_shared<container>(w, h);
		auto l = std::make_shared<label>("test123");
		lr->add_element(l);
		l->move(0,0);
		form->add_layer(lr);
	}
	form->update();
	draw_img(form->get_image().get());

	std::cout<<'\n';
	{
		auto lr = std::make_shared<container>(w, h);
		auto img = std::make_shared<bit_image>(10, 10);
		auto imgbox = std::make_shared<imagebox>(10,10,img);
		lr->add_element(imgbox);
		imgbox->move(lr->get_w()-img->get_w(),
			lr->get_h()-img->get_h());
		drawer d;
		d.draw_line(0, 0, imgbox->get_w()-1, imgbox->get_h()-1,
			color::white, img);
		form->add_layer(lr);
	}
	form->update();
	draw_img(form->get_image().get());
	{
		auto lr = std::make_shared<container>(w, h);
		auto b = std::make_shared<button>();
		b->move(lr->get_w(), lr->get_h()/2);
		lr->add_element(b);
		b->bind([](){std::cout<<"working\n";});
		form->add_layer(lr);
		b->on_press_e(std::make_shared<event>(0,0));
		auto f = [&form](){
			draw_img(form->get_image().get());
		};
		b->bind(f);
		b->on_press_e(std::make_shared<event>(0,0));
	}
}
