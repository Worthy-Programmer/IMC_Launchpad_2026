#include <bits/stdc++.h>
using namespace std;

string largestBinString(string binString) {
	string goodBin;
	int n = binString.size();

	vector<string> substrings;

	int c0 = 0;
	int c1 = 0; 
		

	for (int i =0; i < n; ++i) {
		goodBin += binString[i];
		if (binString[i] == '0') c0 +=1; else c1+=1;
		
		if (c0 == c1 && (i == n-1 || binString[i+1] == '1')) {
			substrings.push_back(goodBin);
			goodBin.clear();
			c0 = 0;
			c1 = 0;
		}
	} // Even final index gets added to the vector

	sort(substrings.begin(), substrings.end(), [](const string &a, const string &b) { 
		return a+b > b+a;

		// My inital plan for comparing: 
		//int na = a.size();
		//int nb = b.size();
		//auto p = minmax(a,b);
		//auto deln = p.second - p.first;
		//string suffix(deln, '1');
		//if (na >= nb) return na  > (nb + suffix);
		//return ((na + suffix) > nb);
	}); // Sort descending order way

	string largest;
	for (auto &s: substrings) largest += s;
	return largest;
}

int main() {	
	string binString;
	cout << "Enter BinString (Write d for 10100110): ";
	cin >> binString;
	if ( binString == "d" ) binString = "10100110";
	string largest = largestBinString(binString);
	cout << "Largest BinString formed from " << binString << " is : " << largest;
	return 0;
}
