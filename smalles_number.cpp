#include <bits/stdc++.h>

using namespace std;

// vector<long long int> inputArray(long long int n){vector<long long int> arr(n);long long int i=0; FOR(i,n) cin>>arr[i];return arr;}

void fun(vector<long long int> arr,vector<bool> &sign,long long int index,long long int &ans){
	// for(auto x:arr){
		// cout<<x<<" ";
	// }cout<<endl;
	if (arr.size()==1 or index==sign.size()){
		// cout<<endl;
		// if(arr[0]!=0)
		ans = min(arr[0],ans);	
	}
	for(long long int i=0;i<arr.size()-1;i++){
		for(long long int j=i+1;j<arr.size();j++){
			long long int sum = arr[i]*arr[j];
			if(sign[index]) sum=arr[i]+arr[j];
			vector<long long int> temp;
			for(long long int x=0;x<arr.size();x++){
				if(x!=i and x!=j) temp.push_back(arr[x]);
			}
			temp.push_back(sum);
			fun(temp,sign,index+1,ans);
		}
	}

	// return 0;
}

int main(){

	vector<long long int> arr(4);
	for(auto i=0;i<4;i++)
		cin>>arr[i];
	vector<bool> sign(3,false);
	long long int ans =  LONG_MAX;

	for(auto i=0;i<3;i++){
		char temp;cin>>temp;
		if(temp=='+') sign[i] = true;
	}
	fun(arr,sign,0,ans);
	cout<<ans<<endl;
	return 0;
}