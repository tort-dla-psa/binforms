#pragma once
#include <functional>
#include "iresizable.h"
#include "label.h"
#include "element.h"

namespace binforms{

class drawer;
class button: public element, public iresizable, public imovable {
protected:
	std::unique_ptr<drawer> drwr;
	std::shared_ptr<label> lbl;
	std::function<void()> f;
public:
	button();
	button(unsigned int w, unsigned int h);
	button(std::shared_ptr<label> lbl);
	button(unsigned int w, unsigned int h, std::shared_ptr<label> lbl);
	button(const std::string &text);
	button(unsigned int w, unsigned int h, const std::string &text);
	virtual ~button();

	virtual void set_label(const std::string &text);
	virtual void set_label(std::shared_ptr<label> lbl);
	std::shared_ptr<label> get_label()const;

	virtual void move(int x, int y)override;
	virtual void resize(unsigned int w, unsigned int h)override;

	virtual void update()override;
	void bind(std::function<void()> f);
	void on_press_e(std::shared_ptr<event> e) override;
};
}
