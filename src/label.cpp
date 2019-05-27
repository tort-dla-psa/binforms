#include "label.h"
#include "binfont.h"
#include "graphics.h"

#define label_def_txt "label"

using namespace binforms;

label::label():label(label_def_txt)
{}

label::label(const std::string &text)
	:element (binfont::get_pixel_width(text),
		binfont::get_pixel_height(text)),
	text(text)
{
	drawer d;
	d.draw_text(0,0, text, img);
}

label::~label(){}


void label::set_text(const std::string &text){
	this->text = text;
	int w = binfont::get_pixel_width(text);
	int h = binfont::get_pixel_height(text);
	resize(w, h);
	//set_changed(true);
}

std::string label::get_text()const{
	return text;
}

void label::move(int x, int y){
	this->x = x;
	this->y = y;
	//set_changed(true);
}

void label::resize(const unsigned int w, const unsigned int h){
	img = std::make_shared<bit_image>(w,h);
}

void label::update(){
	drawer d;
	d.draw_text(0,0, text, img);
}
