#include <bits/stdc++.h>

using namespace std;

namespace linearDS {
	vector<int> inputArray(int &n){
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		return arr;
	}
	void display(vector<int> &num){
		for(auto x:num){
			cout<<x<<" ";
		}cout<<endl;
	}
	
};



int main(){
	int n;cin>>n;
	auto arr = (linearDS::inputArray(n));
	linearDS::display(arr);
}