#include <conio.h>
#include <iostream>

#include <cmath>

int reverse(int num);
bool palindrome(int num);
int len(int num); 
int seek_the_number();

int main()
{
	std::cout << seek_the_number() << std::endl;
	//std::cout << palindrome(123321) << std::endl;
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
		int split_len = (num_len / 2);
		num_first_part /= pow(10, split_len);
		num_second_part %= int(pow(10, split_len));/////\-_-/\\\\\\/
	}
	else
	{
		int split_len = (num_len / 2) + 1;
		num_first_part /= pow(10, split_len);
		num_second_part %= int(pow(10, split_len-1));
	}
	if (num_first_part - reverse(num_second_part) != 0)//отнимаем от первой половины числа реверснутую вторую половину и сравниваем с 0. Если 0 - получили палиндром
	{
		return 0;
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

int reverse(int num)
{
	int length = len(num);
	int reversed_num = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		reversed_num += num % 10 * pow(10, i);
		num /= 10;
	}
	return reversed_num;
}


