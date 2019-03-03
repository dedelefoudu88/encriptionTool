#ifndef MY_TOOLS_HPP__
#define MY_TOOLS_HPP__

#include <sstream>



namespace MyTools
{
	template <typename T>
	std::string to_string_with_precision(const T a_value, const int n)
	{
		std::ostringstream out;
		out.precision(n);
		out << std::fixed << a_value;
		return out.str();
	}
	
	int8_t getPow2(uint64_t in)
	{
		uint8_t res = -1;
		while(in)
		{
				in >>= 1;
				res++;
		}
		return res;
	}
	
	int8_t getPow10(uint64_t in)
	{
		uint8_t res = -1;
		while(in)
		{
				in /= 10;
				res++;
		}
		return res;
	}
}

#endif // MY_TOOLS_HPP__
