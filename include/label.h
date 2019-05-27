#pragma once
#include <string>
#include "element.h"
#include "imovable.h"
#include "iresizable.h"

namespace binforms{

class label: public element, public imovable, public iresizable {
protected:
	std::string text;
	void resize(const unsigned int w, const unsigned int h)override;
public:
	label();
	label(const std::string &text);
	virtual ~label();
	void set_text(const std::string &text);
	std::string get_text()const;
	void move(int x, int y)override;
	void update()override;
};

}
