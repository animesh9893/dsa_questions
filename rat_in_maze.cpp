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

void move(const int n,int i,int j,vector<vector<bool>> &visit,vector<char> &arr){
	if(i>=n or i<0 or j>=n or j<0) return;
	if(visit[i][j]==true) return;
	if(i==n-1 and j==n-1){
		string s(arr.begin(),arr.end());
		cout<<s<<endl;
		return ;
	}
	visit[i][j] = true;
	//left
	arr.push_back('L');
	move(n,i,j-1,visit,arr);
	arr.pop_back();
	//right
	arr.push_back('R');
	move(n,i,j+1,visit,arr);
	arr.pop_back();
	// down
	arr.push_back('D');
	move(n,i+1,j,visit,arr);
	arr.pop_back();
	//up
	arr.push_back('U');
	move(n,i-1,j,visit,arr);
	arr.pop_back();
	visit[i][j] = false;
	return ;
}

void func(){
	int n;cin>>n;//cout<<n<<endl;
	vector<vector<bool>> visit(n,vector<bool>(n,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;cin>>temp;
			if(temp==0){
				visit[i][j] = true;
			}
			// cout<<visit[i][j]<<" ";
		}//cout<<endl;
	}
	vector<char> arr;
	move(n,0,0,visit,arr);
}

int main(){
	int t;cin>>t;
	while(t--){
		func();
	}
	return 0;
}