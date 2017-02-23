

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
	cout << "C++ " << _ultoa(159231324, buffer, 16);

	cout << "\n";
	char buff[40] = {};
	cout << "My " << ultoaRealization(159231324, buff, 16);

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

	// ����������
	do
	{
		*buffer++ = *--p;
	} while (p != &buf[0]);

	// ���������� ���������
	buffer = startP;

	return buffer;
}

char digit_to_char(unsigned digit)
{
	if (digit <= 9)
		return '0' + digit;
	else if (digit <= 36)
		return 'a' + (digit - 10);

	abort();
}

