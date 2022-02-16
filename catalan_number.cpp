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


vector<ll> catalanNumbers(const int &N){
	const ll m = 1000000007;
	vector<ll> ans(N+1,0);
	ans[0]=ans[1]=1;
	for(int i=2;i<=N;i++){
		for(int j=0;j<i;j++){
			ans[i]+=((ans[j]%m)*(ans[i-j-1]%m))%m;
			ans[i]%=m;
		}
	}
	return ans;
}

int main(){
	auto cat_num = catalanNumbers(500);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;cin>>t;
	while(t--){
		int n;
		if(n%2==1) cout<<-1<<endl;
		else cout<<cat_num[n/2]<<endl;
	}
	return 0;
}