// // https://codeforces.com/problemset/problem/855/B
// #include <bits/stdc++.h>

// using namespace std;

// int main(){
// 	long long n,p,q,r;
// 	cin>>n>>p>>q>>r;
// 	vector<long long> arr(n,0);
// 	for(auto &val:arr){
// 		cin>>val;
// 	}
// 	long long max_so_far = long long_MIN;
// 	vector<long long> prefix;
// 	for(auto &val:arr){
// 		max_so_far = max(val*p,max_so_far);
// 		prefix.push_back(max_so_far);
// 	}
// 	max_so_far = long long_MIN;
// 	vector<long long> sufix(n,0);
// 	for(long long i=n-1;i>=0;i--){
// 		max_so_far = max(arr[i]*r,max_so_far);
// 		sufix[i]=max_so_far;
// 	}

// 	max_so_far = long long_MIN;
// 	for(long long i=0;i<n;i++){
// 		max_so_far = max(max_so_far,arr[i]*q+prefix[i]+sufix[i]);
// 	}
// 	cout<<max_so_far<<endl;
// }

#include<bits/stdc++.h>

using namespace std;

void maxExpression(long long arr[], long long n, long long p, long long q, long long r){
	long long pMax[n];
	long long sMax[n];

	pMax[0]=p*arr[0];
	sMax[n-1]=r*arr[n-1];
	long long ans=LLONG_MIN;

	for(int i=1; i<=n-1; i++){
		pMax[i]=max(p*arr[i], pMax[i-1]);
	}
	for(int i=n-2; i>=0; i--){
		sMax[i]=max(r*arr[i], sMax[i+1]);
	}
	for(int i=0; i<=n-1; i++){
		ans= max(ans, pMax[i]+q*arr[i]+sMax[i]);
	}
	cout<<ans<<endl;
}

int main(){
	long long n,p,q,r;
	cin>>n>>p>>q>>r;
	long long arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	maxExpression(arr, n, p, q, r);
}