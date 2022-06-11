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

int linearSearch1(vector<int> &arr,const int target,int index){
	if(index==arr.size()) return -1;
	if(arr[index]==target) return index;
	return linearSearch1(arr,target,index+1);
}

int linearSearch(int arr[],int n,const int target){
	if(n==0) return -1;
	if(arr[0]==target) return 0;
	int index = linearSearch(arr+1,n-1,target);
	if(index==-1) return index;
	return 1+index;
}

int main(){
	int n;cin>>n;
	// auto arr = inputArray(n);
	// cout<<linearSearch(arr,10)<<endl;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int tar;cin>>tar;
	cout<<"target : "<<tar<<" found at "<<linearSearch(arr,n,tar)<<endl;	
	return 0;
}










