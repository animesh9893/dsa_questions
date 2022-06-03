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

//pascal triangle for finding combination value upto 10005
vector<vector<ll> > pascal_mat(10005,vector<ll>(10005));
void pascal_triangle(){
	int n = pascal_mat.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			pascal_mat[i][j] = 0;
	for(int i=0;i<n;i++){
		pascal_mat[i][0]=pascal_mat[i][i]=1;
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=i;j++){
			pascal_mat[i][j]=pascal_mat[i-1][j-1]+pascal_mat[i-1][j];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	pascal_triangle();
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(j>i) continue;
			cout<<pascal_mat[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}