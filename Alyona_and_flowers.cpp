// https://codeforces.com/problemset/problem/740/B

#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v){
	for(auto &val:v){
		cout<<val<<" ";
	}cout<<endl;
}


int main(){
	int n; cin >> n;
	int q; cin >> q;

	vector < int > flower ( n+3 , 0);

	for( int i=1; i <= n; i++) cin>>flower[i];

	// pre computation of prefix and sufix;
	vector<int> psum(n+3,0);
	vector<int> ssum(n+3,0);

	for(int i=1 ; i <= n ; i++) psum[i]  = psum[i-1] + flower[i];

	ssum[n] = flower[n];
	for(int i = n-1; i>0; i--){
		ssum[i] = ssum[i+1] + flower[i];
	}

	int answer = 0;

	while( q-- ){
		int l , r ;
		cin >> l >> r;
		int sum = psum[n] - psum[l-1] - ssum[r+1];
		answer += max( 0, sum );
	}

	// display(flower);
	// display(psum);
	// display(ssum);

	cout << answer << endl;
}