#include "date.h"

void pack(union DATE* date, unsigned day, unsigned month, unsigned year) {
	date->data.day = day;
	date->data.month = month;
	date->data.year = year;
}
