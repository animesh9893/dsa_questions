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


int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int n,m,t,k;
	// cout<<"enter n m k t\n";
	cin>>n>>m>>k>>t;
	vector<vector<int> > mat(n,vector<int>(m));
	while(k--){
		int i,j;cin>>i>>j;
		mat[i-1][j-1]=-1;
	}
	int cnt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==-1){continue;}
			mat[i][j]=cnt;
			cnt++;
			if(cnt>3) cnt=1;
		}
	}
	while(t--){
		int i,j;cin>>i>>j;
		if(mat[i-1][j-1]==-1) cout<<"Waste\n";
		else if(mat[i-1][j-1]==1) cout<<"Carrots\n";
		else if(mat[i-1][j-1]==2) cout<<"Kiwis\n";
		else if(mat[i-1][j-1]==3) cout<<"Grapes\n";
	}
	return 0;
}