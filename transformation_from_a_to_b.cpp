// https://codeforces.com/contest/727/problem/A
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

template <typename T>
void displayVector(vector<T> &v){
	for(auto x:v){
		cout<<x<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int n){
	n = min(n,v.size());
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int i,int n){
	n = min(n,v.size());
	i = max(0,i);
	for(;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int i,int n, bool rev){
	n = min(n,v.size());
	i = max(0,i);
	if(!rev){
		for(;i<n;i++){
			cout<<v[i]<<" ";  
		}cout<<endl;
	}else{
		n--;
		for(;n>=i;n--){
			cout<<v[n]<<" ";  
		}cout<<endl;
	}
}

void func(){
	int a,b;cin>>a>>b;
	vector<int> ans;
	
	while(b>a){
		ans.push_back(b);
		if(b%10==1){
			b/=10;
		}else if(b%2==0){
			b/=2;
		}else{
			break;
		}
	}
	ans.push_back(b);
	if(b==a){
		cout<<"YES\n";
		cout<<ans.size()<<endl;
		displayVector(ans,0,ans.size(),true);
	}else{
		cout<<"NO\n";
	}
}

int main(){
	func();
	return 0;
}