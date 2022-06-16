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

bool findPath(vector<vector<int>>&m, vector<vector<int>>&res, int i, int j, int n){
       if(i<0||j<0||i>=n||j>=n) return false;
       if(i==n-1&&j==n-1){
           res[i][j]=1;
           return true;
       }
       res[i][j]=1;
       int d=m[i][j];
       for(int k=1; k<=d; k++){
           if(findPath(m, res, i,j+k, n)) return true;
           if(findPath(m, res, i+k,j, n)) return true;
       }
       res[i][j]=0;
       return false;
   }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
       int n=matrix.size();
       vector<vector<int>> res(n,vector<int>(n,0));
       vector<vector<int>> ans(1);
       ans[0].push_back(-1);
       if(matrix[0][0]==0&&n>1) return ans;
       if(findPath(matrix, res,0,0,n)) return res;
       
       return ans;
	}
vector<vector<bool>> ShortestDistance(vector<vector<int>>&matrix){
	int n = matrix.size();
	vector<vector<bool>> visit(n,vector<bool>(n,false));
	func(n,0,0,matrix,visit);
	return visit;
}

int main(){
	int n;cin>>n;
	vector<vector<int>> arr(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	auto ans = ShortestDistance(arr);
	cout<<endl;
	for(auto item:ans){
		for(auto x:item){
			cout<<x<<" ";
		}cout<<endl;
	}

	cout<<endl;
	return 0;
}