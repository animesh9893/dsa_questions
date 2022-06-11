// https://codeforces.com/problemset/problem/768/B?f0a28=1
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

bool checker(vector<int> arr){
	for(auto x:arr){
		if(x==0 or x==1) continue;
		else return false;
	}
	return true;
}

vector<long long int> ans;

void fun(long long int n){
	if(n==1 or n==0){
		// cout<<n<<" ";
		ans.push_back(n);
		return ;
	}
	fun(n/2);
	fun(n%2);
	fun(n/2);
	return ;
}

int main(){
	// long long int n,l,r;cin>>n>>l>>r;
	// vector<int> arr;arr.push_back(n);
	// fun(n);
	// int count =0;
	// for(int i=l-1;i<r;i++)
		// if(ans[i]==1) count++;
	// cout<<count<<endl;


	for(int i=1;i<=25;i++){
		fun(i);
		for(int i=0;i<ceil(ans.size()*1.0/2);i++){
			cout<<ans[i]<<" ";
		}cout<<endl;
		ans.clear();
	}

	return 0;
}