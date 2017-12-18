/*
 * Reverse a string.
 */

#include <stdio.h>
#include <string.h>

void str_reverse(char * str)
{
	if (str == 0) return;   // skip null
	if (*str == 0) return;  // check empty

	char * start = str;
	char * end = str + strlen(str) - 1;
	char temp;
		
	while (end > start)
	{
		temp = * start;
		* start = * end;
		* end = temp;

		++start;
		--end;
	}
}

int main(void)
{
	char str[] = "alpesis";
	str_reverse(str);
	printf("%s\n", str);
	return 0;
}
