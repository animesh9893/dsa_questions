// https://leetcode.com/problems/combination-sum-iii/

#include<bits/stdc++.h>

using namespace std;

void func(const int size,const int sum,int element,int sum_so_far,vector<int> &ans,vector<vector<int>> &result){
	if(sum_so_far == sum and ans.size()==size){
		// for(auto x:ans){
			// cout<<x<<" ";
		// }cout<<endl;

		result.push_back(ans);
		return ;
	}
	if(element==0) return ;
	if(sum<sum_so_far) return;

	ans.push_back(element);
	func(size,sum,element-1,sum_so_far+element,ans,result);
	ans.pop_back();
	func(size,sum,element-1,sum_so_far,ans,result);
	return;
}


vector<vector<int>> combinationSum3(int size,int sum){
	vector<int> ans;
	vector<vector<int>> res;
	func(size,sum,9,0,ans,res);
	return res;
}

int main(){
	int n,k;cin>>k>>n;
	combinationSum3(k,n);
	cout<<endl;
// /	return ;
}