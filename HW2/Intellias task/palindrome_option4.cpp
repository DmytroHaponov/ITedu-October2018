// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <cmath>

bool palindrome(int num);
int len(int num);
int seek_the_number();

int main()
{
	int num_second_part = 104104;
	int num_len = 6;
	std::cout << seek_the_number() << std::endl;
	//std::cout << palindrome(123321) << std::endl;
	//num_second_part %= int(pow(10, num_len / 2));
	_getch();
	return 0;
}

int seek_the_number()
{
	int multip(0);
	int count(0);

	for (int i = 999, j = 999; i >= 100, j >= 100;)
	{
		count++;
		multip = i * j;
		if (palindrome(multip))
		{
			return multip;
		}
		if (count % 2 == 0)
		{
			j--;
		}
		else
		{
			i--;
		}
	}
	return 0;
}
bool palindrome(int num)
{
	int num_len = len(num);
	int num_first_part = num;
	int num_second_part = num;
	if (num_len % 2 == 0)
	{
		num_first_part /= pow(10, num_len / 2);
		num_second_part %= int(pow(10, num_len / 2));/////\-_-/\\\\\\/
	}
	else
	{
		num_first_part /= pow(10, (num_len / 2) + 1);
		num_second_part %= int(pow(10, (num_len / 2)));
	}
	int a = 0;
	int b = 0;
	for (int i = num_len / 2; i >= 1; i--)
	{
		a = num_first_part % 10;
		num_first_part /= 10;
		b = num_second_part / pow(10, i - 1);
		if (i < num_len / 2)
		{
			b %= 10;
		}
		if (a != b)
		{
			return 0;
		}
	}
	return 1;


}
int len(int num)
{
	int len(0);
	do
	{
		len++;
		num /= 10;
	} while (num > 0);
	return len;
}

