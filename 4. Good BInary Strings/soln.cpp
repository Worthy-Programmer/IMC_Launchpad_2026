#include <bits/stdc++.h>
using namespace std;

#define DEFAULT_STRING "11011000"

string largestBinString(string binString) {
	int n = binString.size();

	vector<string> substrings;

	int count = 0;
	int j = 0;


	for (int i =0; i < n; ++i) {
		if (binString[i] == '1') count++; else count --;
		
		
		if (count == 0) {
			substrings.push_back('1' + largestBinString(binString.substr(j + 1, i - j -1)) + '0' );
			count = 0;
			j = i + 1; 
		}
	} // Even final index gets added to the vector

	sort(substrings.begin(), substrings.end(), [](const string &a, const string &b) { return a+b > b+a; }); // Sort descending order way

	string largest;
	for (auto &s: substrings) largest += s;
	return largest;
}

int main() {	
	string binString;
	cout << "Enter BinString (Write d for " << DEFAULT_STRING << "): ";
	cin >> binString;
	if ( binString == "d" ) binString = DEFAULT_STRING;
	string largest = largestBinString(binString);
	cout << "Largest BinString formed from " << binString << " is : " << largest;
	return 0;
}
