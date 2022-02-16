// https://leetcode.com/problems/combination-sum/
#include<bits/stdc++.h>

using namespace std;

void push_emp(vector<int> &v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int sum(vector<int> &v){
	int x;
	for(int i=0;i<v.size();i++)
		x+=v[i];
	return x;
}

void fun(std::vector<int> &emp,int i,vector<int> &nums,int target){
	if(target==0)
		push_emp(emp);	

	if(i>nums.size()-1 or target<0 or target<nums[i])
		return;
	
	emp.push_back(nums[i]);
	fun(emp,i,nums,target-nums[i]);
	emp.pop_back();


	for(int j=1;j+i<nums.size();j++)
		fun(emp,i+j,nums,target);
}

int main(){
	vector<int> emp;
	vector<int> nums={2,3,6,7};
	int target = 7;
	fun(emp,0,nums,target);
}