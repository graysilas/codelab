#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <vector>
#include <cmath>

std::bitset<4> hex2bin(char hex);
int binToDec(long long n);

char mapTob64(std::string bin); 

int main(int argc, char *argv[]) {
	
	if(argc !=  2) {
		std::cout << "Invalid arguments" << std::endl;
		return -1;
	}


	std::string hexVal = argv[1];

	std::string binVal= "";

	for(int i = 0; i < hexVal.length(); i++) {
	
	binVal += hex2bin(hexVal[i]).to_string();	

	}	

	std::vector<std::string> bitPortions; // the bit value split into 6 bits
	bitPortions.push_back("");
	int index = 0;
	std::string tmp = "";
	
	while(index < binVal.length()) {
	
 	bitPortions.back()  += binVal[index];
	if(((index+1) % 6) == 0 && (index+1) != binVal.length()) {
		bitPortions.push_back("");
	}

	index++;
			
	}

	//Find if any padding is needed
	
	unsigned int numBits = ((bitPortions.size() -1) * 6) + bitPortions.back().length();
	
	while(numBits % 24 != 0) {
		
		if(numBits  % 6 != 0) {
			 bitPortions.back() += "0";
			 numBits++;
		}
		else {
			bitPortions.push_back("=");	
			numBits+=6;
		}	

	}
	
	std::cout << std::endl;
	for(int i =0; i < bitPortions.size(); i++) {
	std::cout << mapTob64(bitPortions[i]); 
	}
	std::cout << std::endl; 
	
	return 0;
}


std::bitset<4> hex2bin(char hex) {

	std::stringstream ss;
	ss << std::hex << hex;
	unsigned int n;
	ss >> n;

	std::bitset<4> b(n);

	return b;

}

// 6 bit binary value
	
char mapTob64(std::string bin) {
	// if it is padding, return padding
	if(bin == "=") return '=';
	
	int dec = binToDec(std::stoll(bin));
	if(dec < 26) {
		return static_cast<char> (dec + 65);
	}
	else if(dec < 52) {
		dec = dec - 26;
		return static_cast<char> (dec + 97);
	} else if(dec < 62) {
		dec = dec - 52;
		return static_cast<char> (dec + 48);
	}
	else if(dec == 62) return '+';
	else if(dec == 63) return '/';

}

int binToDec(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
