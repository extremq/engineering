#include <stdio.h>
#include "date.h"

void binary_rep(unsigned num) {
	int i = 0, bit;
	
	printf("%u:", num);

	for(; i < 32; ++i) {
		bit = (num & (1 << i));

		if (bit)
			printf("1");
		else
			printf("0");

		if (i % 8 == 0) 
			printf(" ");
	}

	printf("\n");
}

int main(void) {
	union DATE date;
	unsigned day, month, year;
	scanf("%u%u%u", &day, &month, &year);
	
	pack(&date, day, month, year);
	
	printf("%u %u %u\n", date.data.day, date.data.month, date.data.year);
	binary_rep(date.bits);	

	return 0;
}

