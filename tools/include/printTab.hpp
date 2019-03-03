#ifndef PRINT_TAB_HPP__
#define PRINT_TAB_HPP__

#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <string>  		// std::to_string
#include "myTools.hpp"


namespace MyPrintFunc
{

template<typename T>
void printTab2Dim(T tab, uint32_t row, uint32_t col, bool addIndex = true, bool castInt = false, uint16_t presition = 6)
{
	// get max len
	uint32_t maxLen = 0;
	for(uint32_t r=0; r < row; r++)
	{
		for(uint32_t c=0; c < col; c++)
		{
			uint32_t curentLen;
			if (castInt)
			{
				curentLen = std::string(std::to_string((int64_t)tab[r][c])).size();
			}
			else
			{
				curentLen = std::string(MyTools::to_string_with_precision(tab[r][c],presition)).size();
			}
			if(curentLen > maxLen)
			{
				maxLen = curentLen;
			}
		}
	}
	uint32_t maxLen2 = 0;
	if (addIndex)
	{
		int32_t curentLen = MyTools::getPow10(col);
		if (curentLen < 0)
		{
			curentLen = 0;
		}
		curentLen++;
		if((uint32_t)curentLen > maxLen)
		{
			maxLen = curentLen;
		}
	
		curentLen = MyTools::getPow10(row);
		if (curentLen < 0)
		{
			curentLen = 0;
		}
		curentLen++;
		maxLen2 = (uint32_t)curentLen;
		std::cout << std::string(( maxLen2 + 2 ),' ');
		for(uint32_t c=0; c < col; c++)
		{
			int32_t curentLen = MyTools::getPow10(c);
			if (curentLen < 0)
			{
				curentLen = 0;
			}
			curentLen++;
			std::cout << ':' << std::string(( (maxLen - curentLen)/2 + 1 ),' ') << c << std::string(( (maxLen - curentLen + 1 )/2 + 1 ),' ');
		}
		std::cout << ':' << std::endl;
	}
	
	for(uint32_t r=0; r < row; r++)
	{
		if (addIndex)
		{
			std::cout << std::string(( (maxLen2) ),' ') << "--";
		}
		std::cout << std::string(( (maxLen+3)*col + 1 ),'-') << std::endl;
		if (addIndex)
		{
			int32_t curentLen = MyTools::getPow10(r);
			if (curentLen < 0)
			{
				curentLen = 0;
			}
			curentLen++;
			std::cout << r << std::string(( (maxLen2-curentLen + 2) ),' ');
		}
		for(uint32_t c=0; c < col; c++)
		{
			
			std::string curValString;
			if (castInt)
			{
				curValString = std::to_string((int64_t)tab[r][c]); // to do change cast
			}
			else
			{
				curValString = MyTools::to_string_with_precision(tab[r][c],presition);
			}
			
			uint32_t curentLen = std::string(curValString).size();
			std::cout << '|' << std::string(( (maxLen - curentLen)/2 + 1 ),' ') << curValString << std::string(( (maxLen - curentLen + 1 )/2 + 1 ),' ');
		}
		std::cout << '|' << std::endl;
	}
	if (addIndex)
	{
		std::cout << std::string(( (maxLen2) ),' ') << "--";
	}
	std::cout << std::string(( (maxLen+3)*col + 1 ),'-') << std::endl << std::endl;
}

template<typename T>
void printTab1Dim(T tab, uint32_t col, bool addIndex = true, bool castInt = false, uint16_t presition = 6)
{
	// get max len
	uint32_t maxLen = 0;
	for(uint32_t c=0; c < col; c++)
	{
		uint32_t curentLen;
		if (castInt)
		{
			curentLen = std::string(std::to_string((int64_t)tab[c])).size();
		}
		else
		{
			curentLen = std::string(MyTools::to_string_with_precision(tab[c],presition)).size();
		}
		if(curentLen > maxLen)
		{
			maxLen = curentLen;
		}
	}
	if (addIndex)
	{
		int32_t curentLen = MyTools::getPow10(col);
		if (curentLen < 0)
		{
			curentLen = 0;
		}
		curentLen++;
		if((uint32_t)curentLen > maxLen)
		{
			maxLen = curentLen;
		}
		
		for(uint32_t c=0; c < col; c++)
		{
			int32_t curentLen = MyTools::getPow10(c);
			if (curentLen < 0)
			{
				curentLen = 0;
			}
			curentLen++;
			std::cout << ':' << std::string(( (maxLen - curentLen)/2 + 1 ),' ') << c << std::string(( (maxLen - curentLen + 1 )/2 + 1 ),' ');
		}
		std::cout << ':' << std::endl;
	}
	std::cout << std::string(( (maxLen+3)*col + 1 ),'-') << std::endl;
	for(uint32_t c=0; c < col; c++)
	{
		
		std::string curValString;
		
		if (castInt)
		{
			curValString = std::to_string((int64_t)tab[c]);
		}
		else
		{
			curValString = MyTools::to_string_with_precision(tab[c],presition);
		}
		
		uint32_t curentLen = std::string(curValString).size();
		std::cout << '|' << std::string(( (maxLen - curentLen)/2 + 1 ),' ') << curValString << std::string(( (maxLen - curentLen + 1 )/2 + 1 ),' ');
	}
	std::cout << '|' << std::endl;
	std::cout << std::string(( (maxLen+3)*col + 1 ),'-') << std::endl << std::endl;
}

}

#endif // PRINT_TAB_HPP__
