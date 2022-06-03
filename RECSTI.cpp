// https://www.codechef.com/COOK140C/problems/RECSTI
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


void func(){
	int n;cin>>n;
	vector<int> arr(110,0);
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		arr[temp]++;arr[temp]%=4;
	}
	int cnt=0;
	int pairs = 0;
	
	for(int i=0;i<arr.size();i++){
		if(arr[i]==3){
			cnt++;arr[i]=0;
		}
	}

	for(int i=0;i<arr.size();i++){
		if(arr[i]==1){
			cnt++;arr[i]++;
		}
	}

	for(int i=0;i<arr.size();i++){
		if(arr[i]==2){
			pairs++;
		}
	}
	pairs%=2;
	cnt+=pairs*2;
	cout<<cnt<<endl;
}


int main(){
	int T;
	cin>>T;
	while(T--){
		func();
	}
	return 0;
}