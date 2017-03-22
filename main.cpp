#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

void processCalc();
bool isInt(const string s);
bool isBinary(const string s);
string decToBinary(const unsigned long long int decimal);
unsigned long long int binaryToDecimal(string binary);
void errorMessage(string program);

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        string foo = argv[1];
        if(foo == "inv" && isBinary(argv[2]))
        {
            string value = argv[2];

            if(value.length() > 18)
            {
                cout << "binary value too large to convert, must be 63 characters or less";
                exit(1);
            }
            else
            {
                cout << "Answer: " << binaryToDecimal(value) << endl;
            }
        }
        else
        {
            errorMessage(argv[0]);
        }
    }
    else if(argc == 2 && isInt(argv[1]))
    {
        string valueString = argv[1];
        const char* valueCString = valueString.c_str();
        char* end;
        if(valueString.length() > 18)
        {
            cout << "decimal value too large to convert, must be 18 characters or less";
            exit(1);
        }
        else
        {
            cout << "Answer: " << decToBinary(strtoull(valueCString, &end, 0)) << endl;
        }
    }
    else
	{
        errorMessage(argv[0]);
	}

    return 0;
}
//prints an error message to console
void errorMessage(string program)
{
    std::cout << "Usage: " << program << " <positive decimal number>" << " or " << program << " inv <positive binary number>"<<'\n';

    exit(1);
}

//Checks a string to make sure it is a positive integer
bool isInt(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}
//Checks a string to make sure it is only binary numbers
bool isBinary(const string s){
  return s.find_first_not_of( "01" ) == string::npos;
}

//converts a decimal number into a string representation of a binary number
string decToBinary(const unsigned long long int decimal)
{
    vector<char> binary = {};
    if(decimal > 0)
    {
        for(unsigned long long int i = decimal; i > 1; i=i/2)
        {
            if(i%2 == 0)
                binary.insert(binary.begin(),'0');
            else
                binary.insert(binary.begin(),'1');
        }
        binary.insert(binary.begin(),'1');
        string answer(binary.begin(),binary.end());
        return answer;
    }
    return "0";
}
//converts a string representation of a binary number into a decimal number
unsigned long long int binaryToDecimal(string binary)
{
    unsigned long long int decimal = 0;

    if(binary != "0")
    {
        vector<char> binaryCString(binary.c_str(), binary.c_str() + binary.length() + 1);
        for(unsigned long long int i = 0; i < binaryCString.size(); i++)
        {
            if(binaryCString[i] == '1')
                decimal += pow(2, binaryCString.size()-i-2);
        }
        return decimal;
    }
    return decimal;
}

