#ifndef TRAVERSE_FUNC_H
#define TRAVERSE_FUNC_H

template <typename T>
struct Show {
	Show() {};
	virtual void operator()(T & t) { cout << t << endl; }
};


#endif //TRAVERSE_FUNC_H