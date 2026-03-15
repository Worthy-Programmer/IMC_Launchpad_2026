#include <bits/stdc++.h>
using namespace std;


// Place your functions (frequencySort, finalOccupied, etc.) here

int finalOccupied(vector<int> transfer) {
	int n = transfer.size();
	vector<int> indegree (n+1, 0); // n+1, So I can use 1-based indexing
	for (auto &t: transfer) indegree[t]++;
	
	queue<int> zeroQ;
	for (int i = 1; i <=n; ++i) {
		if (indegree[i] == 0) zeroQ.push(i);
	}

	int filledLocations = n;

	while (!zeroQ.empty()) {
		filledLocations--;
		
		int l = zeroQ.front();
		zeroQ.pop();
		
		int adjLocation = transfer[l-1]; // Transfer vector is still 0-based indexing, so don't forget to -1
		indegree[l]--;
		indegree[adjLocation]--;

		if (indegree[adjLocation] == 0) zeroQ.push(adjLocation);

		// This loops stops when only cyclic graphs exists
	}

	return filledLocations;
}

int main() {
    // Fast I/O - Good habit for Quant tests
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Test Case for Robot Transfers
    vector<int> robots = {3, 4, 1, 3}; // Example from your test; This means first robot goes to 3rd, 2nd goes to 4th. 3rd goes to first, 4th goes to 3rd
    int result = finalOccupied(robots);
    cout << "Occupied: " << result << endl;

    return 0;
}