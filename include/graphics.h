#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "image.h"

namespace graphics{
struct dot{
	int x,y;
};

class drawer{
	void check_ptr(bit_image* img);
	void check_ptr(sptr<bit_image> img);
public:
	drawer();

	void draw_line(int x1, int y1, int x2, int y2, bit_image* img);
	void draw_line(int x1, int y1, int x2, int y2, sptr<bit_image> img);
	void draw_line(int x1, int y1, int x2, int y2, bool color, bit_image* img);
	void draw_line(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img);
	void draw_line(dot dt1, dot dt2, bit_image* img);
	void draw_line(dot dt1, dot dt2, sptr<bit_image> img);
	void draw_line(dot dt1, dot dt2, bool color, bit_image* img);
	void draw_line(dot dt1, dot dt2, bool color, sptr<bit_image> img);

	void draw_rect(int x1, int y1, int x2, int y2, bit_image* img);
	void draw_rect(int x1, int y1, int x2, int y2, sptr<bit_image> img);
	void draw_rect(int x1, int y1, int x2, int y2, bool color, bit_image* img);
	void draw_rect(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img);
	void draw_rect(dot dt1, dot dt2, bit_image* img);
	void draw_rect(dot dt1, dot dt2, sptr<bit_image> img);
	void draw_rect(dot dt1, dot dt2, bool color, bit_image* img);
	void draw_rect(dot dt1, dot dt2, bool color, sptr<bit_image> img);

	void draw_rect_filled(int x1, int y1, int x2, int y2, bit_image* img);
	void draw_rect_filled(int x1, int y1, int x2, int y2, sptr<bit_image> img);
	void draw_rect_filled(int x1, int y1, int x2, int y2, bool color, bit_image* img);
	void draw_rect_filled(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img);
	void draw_rect_filled(dot dt1, dot dt2, bit_image* img);
	void draw_rect_filled(dot dt1, dot dt2, sptr<bit_image> img);
	void draw_rect_filled(dot dt1, dot dt2, bool color, bit_image* img);
	void draw_rect_filled(dot dt1, dot dt2, bool color, sptr<bit_image> img);

	void draw_ellipse(int x1, int y1, int x2, int y2, bit_image* img);
	void draw_ellipse(int x1, int y1, int x2, int y2, sptr<bit_image> img);
	void draw_ellipse(int x1, int y1, int x2, int y2, bool color, bit_image* img);
	void draw_ellipse(int x1, int y1, int x2, int y2, bool color, sptr<bit_image> img);
	void draw_ellipse(dot dt1, dot dt2, bit_image* img);
	void draw_ellipse(dot dt1, dot dt2, sptr<bit_image> img);
	void draw_ellipse(dot dt1, dot dt2, bool color, bit_image* img);
	void draw_ellipse(dot dt1, dot dt2, bool color, sptr<bit_image> img);

	void draw_image(int x1, int y1, bit_image* src, bit_image* dst);
	void draw_image(dot dt1, bit_image* src, bit_image* dst);
	void draw_image(int x1, int y1, sptr<bit_image> src, sptr<bit_image> dst);
	void draw_image(dot dt1, sptr<bit_image> src, sptr<bit_image> dst);

	void fill_image(bool color, bit_image* img);
	void fill_image(bool color, sptr<bit_image> img);
};
}
#endif // GRAPHICS_H
