#include <string.h>
#include <stdexcept>
#include "graphics.h"


using namespace graphics;

drawer::drawer(){}

void drawer::check_ptr(bit_image* img){
	if(!img){
		throw std::runtime_error("drawer: image pointer isn't set");
	}
}

void drawer::check_ptr(sptr<bit_image> img){
	if(!img){
		throw std::runtime_error("drawer: image pointer isn't set");
	}
}

void drawer::draw_line(int x1, int y1, int x2, int y2, bit_image* img){
	check_ptr(img);
	draw_line(x1, y1, x2, y2, true, img);
}

void drawer::draw_line(int x1, int y1, int x2, int y2, sptr<bit_image> img){
	check_ptr(img);
	draw_line(x1, y1, x2, y2, true, img.get());
}

void drawer::draw_line(int x1, int y1, int x2, int y2, bool color, bit_image* img){
	check_ptr(img);

	{
		int w = img->get_w();
		int h = img->get_h();
		if (x1 >= w || x2 >= w ||
			y1 >= h || y2 >= h)
		{
			return;
		}
	}

	const int dx = std::max(x1, x2) - std::min(x1, x2),
			dy = std::max(y1, y2) - std::min(y1, y2),
			sx = (x2 > x1)? 1: -1,
			sy = (y2 > y1)? 1: -1;

	int err = (dx > dy ? dx : -dy) / 2, e2;
	for (;;) {
		img->set_pixel(x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy) { err += dx; y1 += sy; }
	}
}

void drawer::draw_line(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img) {
	check_ptr(img);
	draw_line(x1, y1, x2, y2, color, img.get());
}

void drawer::draw_line(dot dt1, dot dt2, bit_image* img){
	draw_line(dt1.x, dt1.y, dt2.x, dt2.y, true, img);
}

void drawer::draw_line(dot dt1, dot dt2, sptr<bit_image> img){
	check_ptr(img);
	draw_line(dt1.x, dt1.y, dt2.x, dt2.y, true, img.get());
}

void drawer::draw_line(dot dt1, dot dt2, bool color, bit_image* img){
	draw_line(dt1.x, dt1.y, dt2.x, dt2.y, color, img);
}

void drawer::draw_line(dot dt1, dot dt2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_line(dt1.x, dt1.y, dt2.x, dt2.y, color, img);
}


void drawer::draw_rect(int x1, int y1, int x2, int y2, bit_image* img){
	draw_rect(x1,y1,x2,y2, true, img);
}

void drawer::draw_rect(int x1, int y1, int x2, int y2, sptr<bit_image> img){
	check_ptr(img);
	draw_rect(x1,y1,x2,y2, true, img.get());
}

void drawer::draw_rect(int x1, int y1, int x2, int y2, bool color, bit_image* img) {
	check_ptr(img);
	int w = img->get_w();
	if(x2 < x1){
		std::swap(x1, x2);
	}
	if(y2 < y1){
		std::swap(y1, y2);
	}
	int rect_w = x2-x1+1;
	std::vector<bool> raw_img = img->get_pixels();
	std::fill_n(raw_img.begin()+x1+y1*w,rect_w, color);
	std::fill_n(raw_img.begin()+x1+y2*w,rect_w, color);
	int start = y1+1,
			end = y2;
	for(int y=start; y<end; y++){
		raw_img[x1+y*(rect_w)] = color;
		raw_img[x2+y*(rect_w)] = color;
	}
	img->set_pixels(raw_img);
}

void drawer::draw_rect(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_rect(x1,y1,x2,y2, color, img.get());
}

void drawer::draw_rect(dot dt1, dot dt2, bit_image* img){
	draw_rect(dt1.x, dt1.y, dt2.x, dt2.y, true, img);
}

void drawer::draw_rect(dot dt1, dot dt2, sptr<bit_image> img){
	check_ptr(img);
	draw_rect(dt1.x, dt1.y, dt2.x, dt2.y, true, img.get());
}

void drawer::draw_rect(dot dt1, dot dt2, bool color, bit_image* img){
	draw_rect(dt1.x, dt1.y, dt2.x, dt2.y, color, img);
}

void drawer::draw_rect(dot dt1, dot dt2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_rect(dt1.x, dt1.y, dt2.x, dt2.y, color, img.get());
}


void drawer::draw_rect_filled(int x1, int y1, int x2, int y2, bit_image* img){
	draw_rect_filled(x1,y1,x2,y2, true, img);
}

void drawer::draw_rect_filled(int x1, int y1, int x2, int y2, sptr<bit_image> img){
	check_ptr(img);
	draw_rect_filled(x1,y1,x2,y2, true, img.get());
}

void drawer::draw_rect_filled(int x1, int y1, int x2, int y2, bool color, bit_image* img){
	check_ptr(img);
	int w = img->get_w();
	if(x2 < x1){
		std::swap(x1, x2);
	}
	if(y2 < y1){
		std::swap(y1, y2);
	}
	int rect_w = x2-x1;
	std::vector<bool> raw_img = img->get_pixels();
	for(int y=y1; y<y2; y++){
		std::fill_n(raw_img.begin()+x1+y*w,rect_w, color);
	}
	img->set_pixels(raw_img);
}

void drawer::draw_rect_filled(int x1, int y1, int x2, int y2,
		bool color, sptr<bit_image> img)
{
	check_ptr(img);
	draw_rect_filled(x1,y1,x2,y2, color, img.get());
}

void drawer::draw_rect_filled(dot dt1, dot dt2, bit_image* img){
	draw_rect_filled(dt1.x, dt1.y, dt2.x, dt2.y, true, img);
}

void drawer::draw_rect_filled(dot dt1, dot dt2, sptr<bit_image> img){
	check_ptr(img);
	draw_rect_filled(dt1.x, dt1.y, dt2.x, dt2.y, true, img.get());
}

void drawer::draw_rect_filled(dot dt1, dot dt2, bool color, bit_image* img){
	draw_rect_filled(dt1.x, dt1.y, dt2.x, dt2.y, color, img);
}

void drawer::draw_rect_filled(dot dt1, dot dt2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_rect_filled(dt1.x, dt1.y, dt2.x, dt2.y, color, img.get());
}

void drawer::draw_ellipse(int x1, int y1, int x2, int y2, bit_image* img){
	draw_ellipse(x1,y1,x2,y2, true, img);
}

void drawer::draw_ellipse(int x1, int y1, int x2, int y2, sptr<bit_image> img){
	check_ptr(img);
	draw_ellipse(x1,y1,x2,y2, true, img.get());
}

void drawer::draw_ellipse(int x1, int y1, int x2, int y2, bool color, bit_image* img){
}

void drawer::draw_ellipse(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_ellipse(x1,y1,x2,y2, color, img.get());
}

void drawer::draw_ellipse(dot dt1, dot dt2, bit_image* img){
	draw_ellipse(dt1.x, dt1.y, dt2.x, dt2.y, true, img);
}

void drawer::draw_ellipse(dot dt1, dot dt2, sptr<bit_image> img){
	check_ptr(img);
	draw_ellipse(dt1.x, dt1.y, dt2.x, dt2.y, true, img.get());
}

void drawer::draw_ellipse(dot dt1, dot dt2, bool color, bit_image* img){
	draw_ellipse(dt1.x, dt1.y, dt2.x, dt2.y, color, img);
}

void drawer::draw_ellipse(dot dt1, dot dt2, bool color, sptr<bit_image> img){
	check_ptr(img);
	draw_ellipse(dt1.x, dt1.y, dt2.x, dt2.y, color, img.get());
}

void drawer::draw_image(int x1, int y1, bit_image* src, bit_image* dst){
	check_ptr(src);
	check_ptr(dst);

	int srcw = src->get_w(),
		srch = src->get_h();
	if(x1 + srcw < 0||
		y1 + srch <0)
	{
		return;
	}
	if(x1 < 0){
		srcw += x1;
		x1 = 0;
	}
	if(y1 < 0){
		srch += y1;
		y1 = 0;
	}
	std::vector<bool> src_bits = src->get_pixels();
	std::vector<bool> dst_bits = dst->get_pixels();
	int dstw = dst->get_w();
	int dsth = dst->get_h();
	if(x1 + srcw >= dstw||
		y1 + srch >= dsth)
	{
		srcw = dstw-1-x1;
		srch = dsth-1-y1;
	}
	int dst_start = x1 + y1*dstw;

	for(int i=0; i<srch; i++){
		std::copy(src_bits.begin() + i*srcw,
				  src_bits.begin() + (i + 1)*srcw,
				  dst_bits.begin() + dst_start + i*dstw);
	}
	dst->set_pixels(dst_bits);
}

void drawer::draw_image(dot dt1, bit_image* src, bit_image* dst){
	draw_image(dt1.x, dt1.y, src, dst);
}

void drawer::draw_image(int x1, int y1, sptr<bit_image> src, sptr<bit_image> dst){
	check_ptr(src);
	check_ptr(dst);
	draw_image(x1, y1, src.get(), dst.get());
}

void drawer::draw_image(dot dt1, sptr<bit_image> src, sptr<bit_image> dst){
	check_ptr(src);
	check_ptr(dst);
	draw_image(dt1.x, dt1.y, src.get(), dst.get());
}

void drawer::fill_image(bool color, bit_image* img){
	check_ptr(img);
	std::vector<bool> src = img->get_pixels();
	std::fill_n(src.begin(), src.size(), color);
	img->set_pixels(src);
}

void drawer::fill_image(bool color, sptr<bit_image> img){
	check_ptr(img);
	fill_image(color, img.get());
}
