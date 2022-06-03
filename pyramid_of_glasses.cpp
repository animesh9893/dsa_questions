// https://codeforces.com/contest/676/problem/B

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

void fun(int level,double ammount,vector<double> &arr,int &count,int node){
	// if((level-1)*(level-2)>arr.size()) return;
	if(arr[node]<100){
		if(arr[node]+ammount>100){
			ammount = ammount - (100-arr[node]);
			arr[node]=100;
		}else{
			arr[node] += ammount;
			ammount = 0;
		}
		if(arr[node]==100) count++;
	}
	if(ammount==0) return;
	fun(level+1,ammount/2,arr,count,node+level);
	fun(level+1,ammount/2,arr,count,node+level+1);
	return ;
}

int main(){
	int n,t;cin>>n>>t;
	int size_arr = n*(n-1);
	int count=0;
	vector<double> arr(size_arr+1,0);
	for(int i=1;i<=t;i++){
		fun(1,100,arr,count,1);
	}
	count=0;
	for(auto x:arr){
		if(x==100) count++;
	}
	cout<<count<<endl;
	return 0;
}


// https://pastebin.com/D50pzjar