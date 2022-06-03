// https://leetcode.com/problems/container-with-most-water/
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

// prefix max
vector<int> pmax(vector<int> &v){
	int n = v.size();
	vector<int> ans(v);
	if(n<=0) return ans;
	for(int i = 1;i<n;i++){
		ans[i]=max(ans[i],ans[i-1]);
	}
	return ans;
}

// sufix max
vector<int> smax(vector<int> &v){
	int n = v.size();
	vector<int> ans(v);
	if(n<=0) return ans;
	for(int i = n-2;i>=0;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	return ans;
}


int maxArea(vector<int> &height){
	auto p = pmax(height);
	auto s = smax(height);
	int max_so_far = 0;
	int n=height.size();
	int i=0,j=n-1;
	while(i!=j){
		int temp = min(p[i],s[j])*(j-i);
		max_so_far = max(max_so_far,temp);
		if(p[i]>s[j]) j--;
		else i++;
	}
	return max_so_far;
}

int main(){
	// vector<int> arr = { 1,8,6,2,5,4,8,3,7 };
	vector<int> arr = { 1,1 };
	cout<<maxArea(arr)<<endl;
	return 0;
}