// ChromaFast v1.0 by Nitrocell

#ifndef __cplusplus
	#error "C++ is Required!"
#endif

#include <iostream>
#include <fstream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include "hex_to_dec.h"

typedef unsigned short word;
typedef unsigned char byte;

int main(int argc, char** argv)
{
	std::cout << "ChromaFast v1.0 - by Nitrocell" << std::endl;
	std::cout << "------------------------------" << std::endl;
	word color = 0x0000;
	int coli = 0x00000000;
	std::string scoli;

	if(argc > 1)
		scoli = argv[1];
	else
	{
		std::cout << "Enter color (#CCCCCC): ";
		std::cin >> scoli;
	}

	Baltazarus::HexDec to_dec(scoli);
	if(!to_dec.IsValid() || scoli.length() > 6 || scoli.length() < 6)
	{
		std::cout << "Invalid value specified!" << std::endl;
		return -1;
	}

	coli = (int)to_dec.ToDecimal();
	
	byte leftmost = (byte)(coli >> 16);
	byte middle = (byte)(coli >> 8);
	byte righmost = (byte)(coli >> 0);
	
	std::cout << "Color: #" << std::hex << coli << std::endl << std::endl;
	std::cout << "Leftmost: " << (word)leftmost << " | " << std::bitset<8>(leftmost) << std::endl; 
	std::cout << "Middle  : " << (word)middle << " | " << std::bitset<8>(middle) << std::endl;
	std::cout << "Rightmost: " << (word)righmost << " | " << std::bitset<8>(righmost) << std::endl;
	
	leftmost &= ((leftmost >> 3) << 3);
	middle &= ((middle >> 3) << 3);
	righmost &= ((righmost >> 3) << 3);
	
	color |= ((word)righmost << 7);
	color |= ((word)middle << 2);
	color |= ((word)leftmost >> 3);

	std::ostringstream chkstr;
	std::string to_uppercase;
	if(color < 0x0010)
		chkstr << "000";
	else if(color < 0x0100)
		chkstr << "00";
	else if(color < 0x1000)
		chkstr << '0';
	
	chkstr << std::hex << color;
	to_uppercase = chkstr.str();

	std::transform(to_uppercase.begin(), to_uppercase.end(), to_uppercase.begin(), ::toupper);
	std::cout << "\n===============================" << std::endl;
	std::cout << std::hex << "SNES COLOR: $" << to_uppercase << std::endl;
	std::cout << "===============================" << std::endl;	
	return 0;
}