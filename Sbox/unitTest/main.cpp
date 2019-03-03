#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

#include "printTab.hpp"
#include "myTools.hpp"

int main(int argv, char** argc)
{
	uint8_t sizeStabel = 16;
	int8_t sizeStabelPow2 = MyTools::getPow2(sizeStabel);
	std::cout << (int)sizeStabelPow2 << std::endl;
	//uint8_t soutput[sizeStabel] = {14,8,13,1,2,15,11,8,3,10,6,12,5,9,0,7};
	uint8_t soutput[sizeStabel] = {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7};
	MyPrintFunc::printTab1Dim(soutput, sizeStabel,true,true);
	//int8_t resLinear[sizeStabel][sizeStabel];
	std::vector<std::vector<int8_t>> resLinear(sizeStabel,std::vector<int8_t>(sizeStabel));
	
	for (uint16_t inSum=0;inSum<sizeStabel;inSum++)
	{
		for (uint16_t outSum=0;outSum<sizeStabel;outSum++)
		{	
			int8_t sumEq = 0;
			for (uint16_t inVal=0;inVal<sizeStabel;inVal++)
			{
				uint8_t inValMask = inVal & inSum;
				uint8_t inValXor = 0;
				for (uint16_t numPow2=0;numPow2<sizeStabelPow2;numPow2++)
				{
					inValXor  ^= ((inValMask & (0x1 << numPow2) ) >> numPow2);
				}
				uint8_t outValMask = soutput[inVal] & outSum;
				uint8_t outValXor = 0;
				for (uint16_t numPow2=0;numPow2<sizeStabelPow2;numPow2++)
				{
					outValXor  ^= ((outValMask & (0x1 << numPow2) ) >> numPow2);
				}
				if (inValXor == outValXor)
				{
					sumEq++;
				}
			}
			resLinear[inSum][outSum] = sumEq - sizeStabel/2;
		}
	}
	MyPrintFunc::printTab2Dim(resLinear,(uint32_t)sizeStabel,(uint32_t)sizeStabel,true,true);
}


