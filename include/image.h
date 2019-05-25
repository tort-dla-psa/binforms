#pragma once

#include <vector>
#include <string>

namespace binforms{
class image{
protected:
	uint w,h;
public:
	image(unsigned int w,unsigned int h);
	virtual ~image();

	virtual bool get_pixel(unsigned int x,unsigned int y)const=0;
	virtual void set_pixel(unsigned int x,unsigned int y, const bool pixel)=0;
	virtual std::string serialize()const=0;
	uint get_w()const;
	uint get_h()const;
};

class bit_image:public image{
protected:
	friend class drawer;
	std::vector<bool> img;
public:
	bit_image(unsigned int w,unsigned int h);
	bit_image(unsigned int w,unsigned int h,
		const std::vector<bool> &img);
	~bit_image();

	bool get_pixel(unsigned int x,unsigned int y)const override;
	std::vector<bool> get_pixels()const;
	void set_pixel(unsigned int x,unsigned int y, const bool pixel)override;
	void set_pixels(const std::vector<bool> &img);
	std::string serialize()const override;
};

class byte_image:public image{
	std::vector<uint8_t> img;
public:
	byte_image(unsigned int w,unsigned int h);
	byte_image(unsigned int w,unsigned int h,
		const std::vector<uint8_t> &img);
	~byte_image();

	bool get_pixel(unsigned int x,unsigned int y)const override;
	std::vector<uint8_t> get_pixels()const;
	void set_pixel(unsigned int x,unsigned int y, const bool pixel)override;
	void set_pixels(const std::vector<uint8_t> &img);
	std::string serialize()const override;
};
}
