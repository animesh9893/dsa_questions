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

vector<ll> factorialList(int n){
	vector<ll> fact(n+1,1);
	ll temp = 1;
	int m = 1000000000+7;
	for(int i=1;i<=n;i++){
		temp = ((temp%m)*(i%m))%m;
		fact[i]=temp;
		// cout<<i<<"--> "<<temp<<endl; 
	}
	return fact;
}

vector<int> sei(1000005,-1);
void seive(){
    int n = sei.size();
    sei[0]=sei[1]=-2;
    for(int i = 2; i*i<n;i++){
        if(sei[i]==-1){
            sei[i]=i;
            for(int j=i*i;j<n;j+=i){
                if(sei[j]!=-1) continue;
                sei[j]=i;
            }
        }
    }
}

vector<int> pcount(){
	vector<int> count(sei.size(),0);
	int cnt = 0;
	for(int i=2;i<sei.size();i++){
		if(sei[i]==i) cnt++;
		count[i]=cnt;
	}
	return count;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	seive();
	int m = 1000000000+7;
	auto pcnt = pcount();
	auto fact = factorialList(100);
	int T;
	cin>>T;
	while(T--){
		int n;cin>>n;
		ll ans = ((fact[int(pcnt[n])]%m)*(fact[n-int(pcnt[n])]%m))%m;
		cout<<ans<<endl;
	}
	return 0;
}