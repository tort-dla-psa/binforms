#ifndef event_h
#define event_h

enum event_type{
	cursor_press,
	cursor_release,
	cursor_move,
	key_press,
	key_release
};

class event{
	event_type type;
public:
	event(event_type type);
};

class cursor_event:public event{
	const int x,y;
public:
	cursor_event(event_type type, int x, int y);
	int get_x()const;
	int get_y()const;
};

class key_event:public event{
	const int key;
public:
	key_event(event_type type, int key);
	int get_key()const;
};
#endif
