// https://leetcode.com/problems/generate-parentheses/

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

void fun(int n,int o,int c,int i,vector<char> &res,vector<string> &ans){
	if(o==c){
		if(o==n){
			// for(auto x:res){
				// cout<<x;
			// }cout<<endl;
			string s(res.begin(),res.end());
			ans.push_back(s);
		}
	}
	if(o<n){
		res[i]='(';
		fun(n,o+1,c,i+1,res,ans);
	}
	if(c<o){
		res[i]=')';
		fun(n,o,c+1,i+1,res,ans);
	}
	return;
}

vector<string> generateParenthesis(int n) {
	vector<char> res(2*n);
	vector<string> ans;
	fun(n,0,0,0,res,ans);
	return ans;
}

int main(){
	int n;
	cin>>n;
	auto ans = generateParenthesis(n);
	for(auto x:ans){
		cout<<x<<" ";
	}cout<<endl;
	return 0;
}