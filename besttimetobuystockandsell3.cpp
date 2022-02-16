// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v){
	for(auto &val:v){
		cout<<val<<" ";
	}cout<<endl;
}

int maxProfit(vector<int>& prices){
	if( prices.size() == 0 or prices.size() == 1)
		return 0;
	int n = prices.size();
	
	// first part of transections
	vector< int > pmin( n+1 , 0 );
	pmin[0] = prices[0];
	for(int i=1 ; i<n ; i++) pmin[i] = min(pmin[i-1],prices[i]);
	pmin[0] = 0;
	for(int i=1 ; i<n ; i++){
		pmin[i] = max(pmin[i-1],prices[i]-pmin[i]);
	} 

	// second part of transection
	vector< int > spro( n+1 , 0);
	int max_so_far = prices[n-1];
	spro[n-1] = 0;

	for(int i = n-2; i>=0;i--){
		int new_profit = max_so_far - prices[i];
		spro[i] = max(spro[i+1],new_profit);
		max_so_far = max(max_so_far,prices[i]);
	}
	int profit = spro[0];

	for(int i=0;i<n;i++){
		int new_profit = pmin[i]+spro[i+1];
		profit = max(new_profit,profit);
	}
	// display(prices);
	// display(pmin);
	// display(spro);
	return profit;
}


int main(){
	// vector<int> v={3,3,5,0,0,3,1,4};
	vector<int> v={2,1,4,5,2,9,7};
	cout<<maxProfit(v)<<endl;
}