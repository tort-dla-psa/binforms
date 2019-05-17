#include <algorithm>
#include "image.h"

image::image(const uint w, const uint h)
	:w(w),h(h)
{}

image::~image(){}

uint image::get_w()const{
	return w;
}

uint image::get_h()const{
	return h;
}


bit_image::bit_image(const uint w, const uint h)
	:image(w,h)
{
	img.resize(w*h,false);
}

bit_image::bit_image(const uint w, const uint h,
	const std::vector<bool> &img)
	:bit_image(w,h)
{
	set_pixels(img);
}

bit_image::~bit_image(){}

bool bit_image::get_pixel(const uint x, const uint y)const{
	return img[x+y*w];
}

std::vector<bool> bit_image::get_pixels() const{
	return img;
}

void bit_image::set_pixel(const uint x, const uint y, const bool pixel) {
	this->img[x+y*w] = pixel;
}

void bit_image::set_pixels(const std::vector<bool> &img){
	if(img.size() != w*h){
		throw std::out_of_range("wrong image size");
	}
	this->img = std::move(img);
}

byte_image::byte_image(const uint w, const uint h)
	:image(w,h)
{
	const uint size = w*h/sizeof(char);
	img.reserve(size);
	std::fill_n(img.begin(),size,0x00);
}

byte_image::byte_image(const uint w, const uint h,
	const std::vector<uint8_t> &img)
	:image(w,h)
{
	set_pixels(img);
}

byte_image::~byte_image(){}

bool byte_image::get_pixel(const uint x, const uint y)const{
	const int selector = 1<<y%8;
	return img[x+y/8*w]&selector;
}

std::vector<uint8_t> byte_image::get_pixels()const{
	return img;
}

void byte_image::set_pixel(const uint x, const uint y, const bool pixel){
	//some magic
	const int selector = 1 << (y % sizeof(uint8_t));
	const uint coord = x + y/sizeof(uint8_t) * w;
	if(pixel){
		img[coord] |= selector;
	}else{
		img[coord] &= ~selector;
	}
}

void byte_image::set_pixels(const std::vector<uint8_t> &img){
	if(img.size()/sizeof(uint8_t) != w*h){
		throw std::out_of_range("wrong image size");
	}
	this->img = std::move(img);
}
