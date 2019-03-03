#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <string>  		// std::to_string

#include <cstdint>
#include <vector>  		// std::to_string

#include <printTab.hpp>



int main(void)
{
	double tab[5][5];
	for(int r=0; r < 5; r++)
	{
		for(int c=0; c < 5; c++)
		{
			tab[r][c] = (1+(-2)*(r & 1))*10*r*c + c;
		}
	}
	MyPrintFunc::printTab2Dim(tab, 5, 5,true,false,2);
	
	std::vector<std::vector<double> > tab2(5, std::vector<double>(5));
	for(int r=0; r < 5; r++)
	{
		for(int c=0; c < 5; c++)
		{
			tab2[r][c] = (1+(-2)*(r & 1))*10*r*c + c;
		}
	}
	MyPrintFunc::printTab2Dim(tab2, 5, 5, false,true);
}
