// 2. Anagram Phrase Counter

// The Problem:
// Given a list of words, find how many phrases can be formed by replacing words with their // anagrams.
//    Example: If "cat" and "act" are in the list, the phrase "cat" can be replaced by "act".
//    Key Concept: Two words are anagrams if they have the same characters in the same frequency.

#include <bits/stdc++.h>
using namespace std;
vector<string> splitByWhiteSpace(string p) {
	vector<string> v;
	string word = "";

	for(const auto &c: p) {
		if(c != ' ') word += c;
		else {
			v.push_back(word);
			word = "";
		}			
	}
	v.push_back(word);
	return v;	
}

vector<int> countAnagramPhrase(vector<string> words, vector<string> phrases) {
	unordered_map<string, int> anagram_freq;

	for(auto w: words) {
		string sortedW = w;
		sort(sortedW.begin(), sortedW.end());
		anagram_freq[sortedW]++;
	}

	vector<int> counts;

	for (auto p: phrases) { 
		int count = 1;
		auto v = splitByWhiteSpace(p); // This function is given
		for (auto word: v) {
			sort(word.begin(), word.end());
			auto it = anagram_freq.find(word);
			if (it != anagram_freq.end()) {
				count *= it->second;
			}
		}

		counts.push_back(count);
	}

	return counts;
}


int main() {
	
	int n1;
	cout << "How many words ?: ";

	cin >> n1;

	cout << "Write down the words:  " << endl;

	vector<string> words(n1);

	for(int i =0; i< n1; ++i) cin >> words[i];
	
	cout << "How many phrases ?: ";
	cin >> n1;
	vector<string> phrases(n1);

	cout << "Write the phrases: " << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for(int i =0; i< n1; ++i) {
		cout << "Phrase "<< i << ". " ;
		getline(cin, phrases[i]);
	}
	
	
	auto v = countAnagramPhrase(words, phrases);
	cout << "Answers: " << endl;
	for (auto &n: v) cout << n << endl;
}