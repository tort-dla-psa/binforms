#pragma once
#include <functional>
#include "iresizable.h"
#include "aliases.h"
#include "label.h"
#include "element.h"

namespace binforms{
using uint = unsigned int;

class drawer;
class button: public element, public iresizable, public imovable {
protected:
	uptr<drawer> drwr;
	sptr<label> lbl;
	std::function<void(void)> f;
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
	void bind(std::function<void(void)> f);
	void on_press_e(sptr<event> e) override;
};
}
