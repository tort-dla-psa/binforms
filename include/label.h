#ifndef LABEL_H
#define LABEL_H
#include <string>
#include "element.h"
#include "imovable.h"

class label: public element, public imovable {
	std::string text;
public:
	label();
	label(const std::string &text);
	void set_text(const std::string &text);
	std::string get_text()const;
	void move(int x, int y)override;
	void update()override;
};

#endif // LABEL_H
