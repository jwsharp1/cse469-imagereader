#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string ToHex(const string& s, bool upper_case)
{
	ostringstream ret;

	for (string::size_type i = 0; i < s.length(); ++i)
	{
		int z = s[i] & 0xff;
		ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
	}

	return ret.str();
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

			size = myfile.tellg();
			memblock = new char[size];
			myfile.seekg(0, ios::beg);
			myfile.read(memblock, size);
			myfile.close();

			string tohexed = ToHex(string(memblock, size), true);

			cout << tohexed << endl;
		}
	}
	else {
		cout << "No file path provided. Terminating." << endl;
	}

    return 0;
}