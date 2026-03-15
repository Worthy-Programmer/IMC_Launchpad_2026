//1. Frequency-Based Sort
//The Problem:
//Given a vector of integers, sort them based on their frequency (how many times they appear).
//    Rule A: Higher frequency comes first.
//    Rule B: If two numbers have the same frequency, the smaller number comes first.

#include <bits/stdc++.h>
using namespace std;


void frequencySort(vector<int>& numbers) {
	// Generating frequency
	unordered_map<int, int> freq;
	for (auto n: numbers) freq[n] += 1;

	sort(numbers.begin(), numbers.end(), [&](int &a, int &b) {
		if (freq[a] != freq[b]) return freq[a] > freq[b]; // Higher freq comes first
		return a > b; /// Smaller number comes first
	});
}


// They give the below part

void printVector(const vector<int> & v) {
	cout << "Printing vector: ";
	for (const int &val: v) cout << val << " ,";
}

void parser() { 
	int n;
	cin >> n;
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; i++) cin >> numbers[i];
	frequencySort(numbers);
	printVector(numbers);
}

int main() {
	parser();
	return 0;
}