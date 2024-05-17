#include <iostream>
#include <vector>

using namespace std;

int calcSum(const vector<int>& arr) {
	int sum = 0;	
	for (auto& num : arr) {
		sum += num;
    }
	return sum;
}


long getCardCount(int n, int k, const vector<int> &cards) {
	if (k == n) return calcSum(cards);
	
	int max_sum = 0;

	vector<int> subarr;
	
	for (int i = 0; i < k; ++i){
    	subarr.push_back(cards[i]);
    }		

	max_sum = calcSum(subarr);	
	int cur_sum = max_sum;
	for (int i = k - 1, j = n - 1; i >= 0;){
    	
		cur_sum = cur_sum - cards[i] + cards[j];
    	if (max_sum < cur_sum) {
    		max_sum = cur_sum;
    	}
    	
    	--i;
    	--j;
    }
    return max_sum;
}


int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    int k = readInt();
    vector<int> cards = readList(n);
    cout << getCardCount(n, k, cards);
}
