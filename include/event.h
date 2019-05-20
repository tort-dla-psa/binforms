#pragma once

namespace binforms{

class event{
	const int x,y;
public:
	event(int x, int y);
	int get_x()const;
	int get_y()const;
};
}
