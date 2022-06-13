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

void query_1(long long l,long long r,vector<long long> &x){
	for(;l<r and l<x.size();l++){
		if(x[l]==0) x[l]=1;
		else x[l]=0;
	}
}

void query_2(vector<long long> &x,vector<long long> &y,long long p){
	for(int i=0;i<y.size();i++){
		y[i]+=x[i]*p;
	}
}

int query_3(vector<long long> &y,long long index){
	if(index>=y.size()) return -1;
	return y[index];
}

vector<long long> solve(int A, vector<vector<int> > &B) {
	vector<long long> x(A,0),y(A,0);
	vector<long long> ans;
	for(auto queries : B){
		if(queries[0]==1){
			query_1(queries[1],queries[2],x);
		}else if(queries[0]==2){
			query_2(x,y,queries[1]);
		}else if(queries[0]==3){
			long long temp = query_3(y,queries[1]);
			ans.push_back(temp);
		}
	}
	return ans;
}


int main(){
	
	return 0;
}