// https://leetcode.com/problems/combinations/

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

void func(int n,const int k,vector<int> &ans,vector<vector<int>> &res){
	if(ans.size()==k) {
		// for(auto x:ans){
			// cout<<x<<" ";
		// }cout<<endl;
		res.push_back(ans);
		return;
	}
	if(n==0) return;

	ans.push_back(n);
	func(n-1,k,ans,res);
	ans.pop_back();
	func(n-1,k,ans,res);
	return ;
}


vector<vector<int>> combine(int n, int k) {
	vector<vector<int> > res;
	vector<int> ans;
	func(n,k,ans,res);
	return res;
}


int main(){
	combine(4,2);
	cout<<endl;
	return 0;
}