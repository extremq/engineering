#ifndef __DATE_H_
#define __DATE_H_

struct _DATE {
	unsigned day   :  5;
	unsigned month :  4;
	unsigned year  : 23;
};

union DATE {
	struct _DATE data;
	unsigned bits;
};	

void pack(union DATE*, unsigned, unsigned, unsigned);

#endif
