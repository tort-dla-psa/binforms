#ifndef BUTTON_H
#define BUTTON_H
#include "iresizable.h"
#include "aliases.h"
#include "label.h"
#include "element.h"
#include "graphics.h"

using namespace graphics;
using uint = unsigned int;

class button: public element, public iresizable, public imovable {
protected:
	uptr<drawer> drwr;
	sptr<label> lbl;
public:
	button();
	button(const uint w, const uint h);
	button(const label &lbl);
	button(const uint w, const uint h, const label &lbl);
	button(const sptr<label> &lbl);
	button(const uint w, const uint h, const sptr<label> &lbl);
	button(const std::string &text);
	button(const uint w, const uint h, const std::string &text);
	virtual ~button();

	virtual void set_label(const std::string &text);
	virtual void set_label(const sptr<label> &lbl);
	sptr<label> get_label()const;

	virtual void move(int x, int y)override;
	virtual void resize(const uint w, const uint h)override;

	virtual void update()override;
};

#endif // BUTTON_H
