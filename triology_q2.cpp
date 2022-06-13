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

void sum(vector<int> &A,vector<int> &B,vector<bool> &pos,long &sum_so_far){
	
}

void func(vector<int> &A,vector<int> &B,int c,long &sum_so_far,int current_index,vector<bool> &pos){
	if(current_index>=A.size() and c==0){
		sum(A,B,sum_so_far);
	}
	pos[current_index] = true;
	func(A,B,c-1,sum_so_far,current_index+1,pos);
	pos[current_index] = false;

	func(A,B,c,sum_so_far,current_index+1,pos);
}

long solve(vector<int> &A,vector<int> &B,int c){

}

int main(){

	cout<<endl;
	return 0;
}