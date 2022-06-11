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

// 2d row and column wise sorted matrix is given we need to find an element index

// this is an approach when matrix is both row and column sorted then we can use it

// if item is greater than current item then move down else move left
// like that we will hit any conditions
vector<int> search_in_2d_matrix(vector<vector<int> > &mat,const int target){
	int n = mat.size();
	if(n==0) return {-1,-1};
	int m = mat[0].size();

	int i=0,j=m-1;
	while(i<n and j>=0){
		if(target==mat[i][j]) return {i,j};
		if(target>mat[i][j]) i++;
		else j--;
	}
	return {-1,-1};
}

int main(){
	vector<vector<int> > arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	auto ans = search_in_2d_matrix(arr,20);

	cout<<ans[0]<<" "<<ans[1];

	cout<<endl;
	return 0;
}