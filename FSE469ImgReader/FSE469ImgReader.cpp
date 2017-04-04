#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string ToHex(const string &s)
{
	ostringstream ret;

	for (string::size_type i = 0; i < s.length(); ++i)
	{
		int z = s[i] & 0xff;
		ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << z;
	}

	return ret.str();
}

void createMBRString(const string &s)
{
	ostringstream ret;

	for (string::size_type i = 0; i < s.length(); ++i)
	{
		int z = s[i] & 0xff;
		ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << z;
	}

	parseMBRString(ret.str());
}

void parseMBRString(string mbr)
{
	// at this point the MBR hex string is passed in, beginning with partition 1 and ending with 55AA boot signature
	for (int i = 0; i < mbr.length(); ++i)
	{

	}
}

int main(int argc, char* argv[])
{
	if (argc == 2) {
		string filePath = argv[1];
		cout << filePath << endl;

		ifstream::pos_type size;
		char * memblock;

		ifstream myfile(filePath, ios::in | ios::binary | ios::ate);
		if (!myfile.is_open()) {
			cout << "Could not open file." << endl;
		}
		else {
			cout << "File was opened successfully." << endl;

			//size = myfile.tellg();
			size = (16 * 5) + 15;
			memblock = new char[size];
			myfile.seekg(0, ios::beg);
			myfile.read(memblock, size);
			myfile.close();

			string tohexed = ToHex(string(memblock, size));

			cout << tohexed << endl;
		}
	}
	else {
		cout << "No file path provided. Terminating." << endl;
	}

    return 0;
}