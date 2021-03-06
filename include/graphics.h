#pragma once
#include <memory>
#include "image.h"

namespace binforms{
struct dot{
	int x,y;
};

enum class blend_mode{
	mode_and=0,
	mode_or,
	mode_xor
};

enum class color{
	black=0,
	white
};

class drawer{
	void check_ptr(std::shared_ptr<bit_image> img);
public:
	drawer();

	void draw_line(int x1, int y1, int x2, int y2, enum color,
			std::shared_ptr<bit_image> img);
	void draw_line(dot dt1, dot dt2, enum color, std::shared_ptr<bit_image> img);

	void draw_rect(int x1, int y1, int x2, int y2, enum color,
			std::shared_ptr<bit_image> img);
	void draw_rect(dot dt1, dot dt2, enum color, std::shared_ptr<bit_image> img);

	void draw_rect_filled(int x1, int y1, int x2, int y2, enum color,
			std::shared_ptr<bit_image> img);
	void draw_rect_filled(dot dt1, dot dt2, enum color, std::shared_ptr<bit_image> img);

	void draw_ellipse(int x1, int y1, int x2, int y2, enum color,
			std::shared_ptr<bit_image> img);
	void draw_ellipse(dot dt1, dot dt2, enum color, std::shared_ptr<bit_image> img);

	void draw_image(int x1, int y1, std::shared_ptr<bit_image> src,
			std::shared_ptr<bit_image> dst);
	void draw_image(dot dt1, std::shared_ptr<bit_image> src,
			std::shared_ptr<bit_image> dst);

	void draw_text(int x1, int y1, const std::string &txt,
			std::shared_ptr<bit_image> img);

	void fill_image(enum color, std::shared_ptr<bit_image> img);
};
}
