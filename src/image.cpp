#include <algorithm>
#include <stdexcept>
#include "image.h"

using namespace binforms;

image::image(unsigned int w, unsigned int h)
	:w(w),h(h)
{}

image::~image(){}

uint image::get_w()const{
	return w;
}

uint image::get_h()const{
	return h;
}


bit_image::bit_image(unsigned int w, unsigned int h)
	:image(w,h)
{
	img.resize(w*h,false);
}

bit_image::bit_image(unsigned int w, unsigned int h,
	const std::vector<bool> &img)
	:bit_image(w,h)
{
	set_pixels(img);
}

bit_image::~bit_image(){}

bool bit_image::get_pixel(unsigned int x, unsigned int y)const{
	return img[x+y*w];
}

std::vector<bool> bit_image::get_pixels() const{
	return img;
}

void bit_image::set_pixel(unsigned int x, unsigned int y, const bool pixel) {
	this->img[x+y*w] = pixel;
}

void bit_image::set_pixels(const std::vector<bool> &img){
	if(img.size() != w*h){
		throw std::out_of_range("wrong image size");
	}
	this->img = std::move(img);
}

std::string bit_image::serialize()const{
	std::string data="";
	data.reserve(w*h);
	for(int i=0; i<h; i++){
		std::string line="";
		line.reserve(w);
		for(int j=0; j<w; j++){
			const char pixel = img[i*w+j]?'1':'0';
			line += std::move(pixel);
		}
		data += line;
	}
	return data;
}

byte_image::byte_image(unsigned int w, unsigned int h)
	:image(w,h)
{
	unsigned int size = w*h/sizeof(char);
	img.reserve(size);
	std::fill_n(img.begin(),size,0x00);
}

byte_image::byte_image(unsigned int w, unsigned int h,
	const std::vector<uint8_t> &img)
	:image(w,h)
{
	set_pixels(img);
}

byte_image::~byte_image(){}

bool byte_image::get_pixel(unsigned int x, unsigned int y)const{
	const int selector = 1<<y%8;
	return img[x+y/8*w]&selector;
}

std::vector<uint8_t> byte_image::get_pixels()const{
	return img;
}

void byte_image::set_pixel(unsigned int x, unsigned int y, const bool pixel){
	//some magic
	const int selector = 1 << (y % sizeof(uint8_t));
	unsigned int coord = x + y/sizeof(uint8_t) * w;
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

inline std::string serialize(uint8_t byte){
	const std::string arr = "0123456789ABCDEF";
	std::string data = "00";
	data[0] = arr[(byte>>4)&15];
	data[1] = arr[byte&15];
	return data;
}

std::string byte_image::serialize()const{
	std::string data="";
	data.reserve(w*h/8);
	for(int i=0; i<h/8; i++){
		std::string line="";
		line.reserve(w);
		for(int j=0; j<w; j++){
			line += ::serialize(img[j+i*w]);
		}
		data += line;
	}
	return data;
}
