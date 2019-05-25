#include "button.h"
#include "binfont.h"
#include "graphics.h"

#define button_def_text "btn"

using namespace binforms;

button::button()
	:button(std::string(button_def_text))
{}

button::button(unsigned int w, unsigned int h)
	:button(w,h, std::string(button_def_text))
{}

button::button(unsigned int w, unsigned int h, std::shared_ptr<label> lbl)
	:button(w,h,lbl->get_text())
{}

button::button(std::shared_ptr<label> lbl)
	:button(lbl->get_text())
{}

button::button(unsigned int w, unsigned int h, const std::string &text)
	:element (w,h),imovable (),iresizable ()
{
	drwr = std::unique_ptr<drawer>(new drawer());
	set_label(text);
	update();
}

button::button(const std::string &text)
	:button(binfont::get_pixel_width(text)+4,
		binfont::get_pixel_height(text)+4,
		text)
{}

button::~button(){};

void button::set_label(const std::string &text){
	lbl = std::make_shared<label>(text);
	resize(img->get_w(),img->get_h());
	//set_changed(true);
}

void button::set_label(std::shared_ptr<label> lbl){
	set_label(lbl->get_text());
}

void button::move(int x, int y) {
	this->x = x;
	this->y = y;
	//set_changed(true);
}

std::shared_ptr<label> button::get_label()const{
	return lbl;
}

void button::resize(unsigned int w, unsigned int h) {
	img = std::make_shared<bit_image>(w,h);
	const std::string txt = lbl->get_text();
	unsigned int text_w = binfont::get_pixel_width(txt),
		text_h = binfont::get_pixel_height(txt);

	const int x = (text_w < w)? (w - text_w)/2 : 0,
			y = (text_h < h)? (h - text_h)/2 :0;
	lbl->move(x,y);
	//set_changed(true);
}

void button::update(){
	unsigned int w = get_w();
	unsigned int h = get_h();
	const auto img = lbl->get_image();
	drwr->draw_image(lbl->get_x(), lbl->get_y(), img, this->img);
	drwr->draw_rect(0, 0, w-1, h-1, color::white, this->img);
}

void button::bind(std::function<void()> f){
	this->f = f;
}

void button::on_press_e(std::shared_ptr<event> e){
	f();
}
