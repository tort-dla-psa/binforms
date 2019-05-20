#include <string.h>
#include <stdexcept>
#include "graphics.h"
#include "binfont.h"
#include "tools.h"

using namespace binforms;
using namespace graphics;

drawer::drawer(){}

void drawer::check_ptr(sptr<bit_image> img){
	if(!img){
		throw std::runtime_error("drawer: image pointer isn't set");
	}
}

void drawer::draw_line(int x1, int y1, int x2, int y2, enum color c, sptr<bit_image> img) {
	check_ptr(img);

	int w = img->get_w();
	int h = img->get_h();
	{
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
	bool real_color;
	if(c == color::black){
		real_color = false;
	}else{
		real_color = true;
	}
	for (;;) {
		img->img[x1 +  y1*w] = real_color;
		if (x1 == x2 && y1 == y2) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy) { err += dx; y1 += sy; }
	}
}

void drawer::draw_line(dot dt1, dot dt2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	draw_line(dt1.x, dt1.y, dt2.x, dt2.y, c, img);
}


void drawer::draw_rect(int x1, int y1, int x2, int y2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	int w = img->get_w();
	if(x2 < x1){
		std::swap(x1, x2);
	}
	if(y2 < y1){
		std::swap(y1, y2);
	}
	int rect_w = x2-x1+1;
	bool real_color;
	if(c == color::black){
		real_color = false;
	}else{
		real_color = true;
	}
	std::fill_n(img->img.begin() + x1 + y1*w, rect_w, real_color);
	std::fill_n(img->img.begin() + x1 + y2*w, rect_w, real_color);
	int start = y1+1, end = y2;
	for(int y=start; y<end; y++){
		img->img[x1 + y*rect_w] = real_color;
		img->img[x2 + y*rect_w] = real_color;
	}
}

void drawer::draw_rect(dot dt1, dot dt2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	draw_rect(dt1.x, dt1.y, dt2.x, dt2.y, c, img);
}


void drawer::draw_rect_filled(int x1, int y1, int x2, int y2, enum color c,
	sptr<bit_image> img)
{
	check_ptr(img);
	int w = img->get_w();
	if(x2 < x1){
		std::swap(x1, x2);
	}
	if(y2 < y1){
		std::swap(y1, y2);
	}
	int rect_w = x2-x1;
	bool real_color;
	if(c == color::black){
		real_color = false;
	}else{
		real_color = true;
	}
	for(int y=y1; y<y2; y++){
		std::fill_n(img->img.begin() + x1 + y*w, rect_w, real_color);
	}
}

void drawer::draw_rect_filled(dot dt1, dot dt2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	draw_rect_filled(dt1.x, dt1.y, dt2.x, dt2.y, c, img);
}

void drawer::draw_ellipse(int x1, int y1, int x2, int y2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	//TODO:make function
}

void drawer::draw_ellipse(dot dt1, dot dt2, enum color c, sptr<bit_image> img){
	check_ptr(img);
	draw_ellipse(dt1.x, dt1.y, dt2.x, dt2.y, c, img);
}

void drawer::draw_image(int x1, int y1, sptr<bit_image> src, sptr<bit_image> dst){
	check_ptr(src);
	check_ptr(dst);

	int srcw = src->get_w(),
		srch = src->get_h(),
		dstw = dst->get_w(),
		dsth = dst->get_h();
	const int orig_srcw = srcw;

	if(x1 + srcw < 0 || y1 + srch < 0 ||
		x1 > dstw || y1 > dsth)
	{
		return;
	}
	int src_start = 0;
	if(y1 < 0){
		src_start = -1 * y1 * srcw;
		srch += y1;
		y1 = 0;
	}
	if(x1 < 0){
		src_start = src_start - x1;
		srcw += x1;
		x1 = 0;
	}
	if(x1 + srcw > dstw){
		srcw = dstw-x1;
	}
	if(y1 + srch > dsth){
		srch = dsth-y1;
	}

	int dst_start = x1 + y1*dstw;
	for(int i=0; i<srch; i++){
		std::copy(src->img.begin() + src_start + i*orig_srcw,
			src->img.begin() + src_start + i * orig_srcw + srcw,
			dst->img.begin() + dst_start + i*dstw);
	}
}

void drawer::draw_image(dot dt1, sptr<bit_image> src, sptr<bit_image> dst){
	check_ptr(src);
	check_ptr(dst);
	draw_image(dt1.x, dt1.y, src, dst);
}

void drawer::draw_text(int x1, int y1, const std::string &txt, sptr<bit_image> img){
	int x=x1, y=y1;
	for(const char &c:txt){
		if(c == '\r'){
			x = x1;
		}else if(c == '\n'){
			y += 8;
			x = x1;
		}else if(c == '\t'){
			x += 6*4;
		}else{
			if(x+6 < 0 || unsigned(x) >= img->get_w() ||
				y+8 < 0 || unsigned(y) >= img->get_h())
			{
				continue;
			}
			const auto bits = binfont::to_bit_img(c);
			draw_image(x, y, bits, img);
			x += 6;
		}
	}
}

void drawer::fill_image(enum color c, sptr<bit_image> img){
	check_ptr(img);
	bool real_color;
	if(c == color::white){
		real_color = true;
	}else{
		real_color = false;
	}
	std::fill(img->img.begin(), img->img.end(), real_color);
}
