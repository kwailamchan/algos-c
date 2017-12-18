/*
 * binary to decimal:
 *
 *   14 % 2 = 0, 14 / 2 = 7, binary = 0, i = 10
 *    7 % 2 = 1,  7 / 2 = 3, binary = 0 + 1 * 10 = 10, i = 10 * 10 = 100
 *    3 % 2 = 1,  3 / 2 = 1, binary = 10 + 1 * 100 = 110, i = 100 * 10 = 1000
 *    1 % 2 = 1,  1 / 2 = 0, binary = 110 + 1 * 1000 = 1110, i = 1000 * 10 = 10000
 *
 * decimal to binary:
 * 
 *   1110 % 10 = 0, 1110 / 10 = 111, decimal = 0 + 0 = 0,            i = 1
 *    111 % 10 = 1,  111 / 10 = 11,  decimal = 0 + (1 * 2 ^ 1) = 2,  i = 2
 *     11 % 10 = 1,   11 / 10 = 1,   decimal = 2 + (1 * 2 ^ 2) = 6,  i = 3
 *      1 % 10 = 1,    1 / 10 = 0,   decimal = 6 + (1 * 2 ^ 3) = 14, i = 4
 */

#include <stdio.h>

long decimal_to_binary(long n)
{
	int remainder;
	long binary = 0;
	long i = 1;

	while (n != 0)
	{
		remainder = n % 2;
		n = n / 2;
		binary = binary + (remainder * i);
		i = i * 10;
	}

	return binary;
}


long binary_to_decimal(long n)
{
	int remainder;
	long decimal = 0;
	long i = 0;

	while (n != 0)
	{
		remainder = n % 10;
		n = n / 10;
		decimal = decimal + (remainder * pow(2, i));
		++i;
	}

	return decimal;
}


int main(void)
{
	long binary = decimal_to_binary(14);
	printf("%ld\n", binary);

	long decimal = binary_to_decimal(11110);
	printf("%ld\n", decimal);
}
