#pragma once

#include <vector>
#include "aliases.h"

using uint = unsigned int;

namespace binforms{
class image{
protected:
	uint w,h;
public:
	image(const uint w,const uint h);
	virtual ~image();
	virtual bool get_pixel(const uint x,const uint y)const=0;
	virtual void set_pixel(const uint x,const uint y, const bool pixel)=0;
	uint get_w()const;
	uint get_h()const;
};

namespace graphics{
	class drawer;
};

class bit_image:public image{
protected:
	friend class graphics::drawer;
	std::vector<bool> img;
public:
	bit_image(const uint w,const uint h);
	bit_image(const uint w,const uint h,
		const std::vector<bool> &img);
	~bit_image();
	bool get_pixel(const uint x,const uint y)const override;
	std::vector<bool> get_pixels()const;
	void set_pixel(const uint x,const uint y,
		const bool pixel)override;
	void set_pixels(const std::vector<bool> &img);
};

class byte_image:public image{
	std::vector<uint8_t> img;
public:
	byte_image(const uint w,const uint h);
	byte_image(const uint w,const uint h,
		const std::vector<uint8_t> &img);
	~byte_image();
	bool get_pixel(const uint x,const uint y)const override;
	std::vector<uint8_t> get_pixels()const;
	void set_pixel(const uint x,const uint y,
		const bool pixel)override;
	void set_pixels(const std::vector<uint8_t> &img);
};
}
