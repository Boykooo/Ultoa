

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;

#pragma warning(disable : 4996)

char* ultoaRealization(unsigned long value, char* buffer, int radix);
char digit_to_char(unsigned digit);
int main()
{
	char buffer[40];
	cout << "C++ " << _ultoa(400, buffer, 55);

	cout << "\n";
	char buff[40] = {};
	cout << "My " << ultoaRealization(400, buff, 55);

	printf("\n");
	system("pause");
	return 0;
}

char* ultoaRealization(unsigned long value, char* buffer, int radix) {

	unsigned long temp;
	char buf[34] = {}, *p = &buf[0], *startP = &buffer[0];

	do
	{
		temp = value % radix;
		*p++ = digit_to_char(temp);
		value /= radix;
	} while (value != 0);

	// записываем
	do
	{
		*buffer++ = *--p;
	} while (p != &buf[0]);

	// возвращаем указатель
	buffer = startP;

	return buffer;
}

char digit_to_char(unsigned digit)
{
	return (digit <= 9) ? '0' + digit : 'a' + (digit - 10);
}

