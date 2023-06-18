#pragma once
#include <string>
namespace rs
{
	template< typename T>
	void reverse(T& input, int size)
	{
		for (int i = 0, j = size - 1; i < j; ++i, j--)
		{
			char temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}

	void reverseString( std::string& input)
	{
		reverse(input, input.size());
	}

	void reverseString(char* input)
	{
		if (input == nullptr)
			return;

		reverse(input, strlen(input));
	}


}