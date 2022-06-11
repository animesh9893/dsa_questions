// https://leetcode.com/problems/combination-sum/
#include <bits/stdc++.h>

using namespace std;

#define max(a,b) (a<b? b:a)
#define min(a,b) (a<b? a:b)
#define mod 1e9+7
#define FOR(a,c) for(int (a)=0;(a)<(c);(a)++)
#define FORL(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define FORR(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
template <class T>
T modadd(T a,T b,ll m){return (a%b+b%m)%m;}
template <class T>
T modsub(T a,T b,ll m){T ans = (a%m)-(b%m);if(ans<0) ans+=m;return ans;}
template <class T>
T modmul(T a,T b,ll m){ return ((a%m)*(b%m))%m; }
vector<int> inputArray(int n){vector<int> arr(n);int i=0; FOR(i,n) cin>>arr[i];return arr;}

void func(const int target,vector<int>&arr,int index,int sum_so_far,vector<int> &ans,vector<vector<int>> &result){
	if(sum_so_far==target){
		for(auto x:ans){
			cout<<x<<" ";
		}cout<<endl;

		result.push_back(ans);
		return ;
	}
	if(index==arr.size()) return ;
	if(sum_so_far>target) return ;
	ans.push_back(arr[index]);
	func(target,arr,index,sum_so_far+arr[index],ans,result);
	ans.pop_back();
	func(target,arr,index+1,sum_so_far,ans,result);
	return ;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int> ans;
	vector<vector<int>> res;
	func(target,candidates,0,0,ans,res);
	return res;
}

int main(){
	int n;cin>>n;
	auto arr = inputArray(n);
	cout<<"Targer\t";
	int target;cin>>target;
	combinationSum(arr,target);
	cout<<endl;
	return 0;
}