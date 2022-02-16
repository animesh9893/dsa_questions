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


void displayVector(vector<int> &v){
	for(auto x:v){
		cout<<x<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int n){
	n = min(n,v.size());
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n){
	n = min(n,v.size());
	i = max(0,i);
	for(;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n, bool rev){
	n = min(n,v.size());
	i = max(0,i);
	if(!rev){
		for(;i<n;i++){
			cout<<v[i]<<" ";  
		}cout<<endl;
	}else{
		n--;
		for(;n>=i;n--){
			cout<<v[n]<<" ";  
		}cout<<endl;
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;cin>>n>>k;
	auto arr = inputArray(n); // take input of array
	vector<int> counter(k,0); // store the counting of common remainder
	int i=0;
	displayVector(arr);
	FOR(i,n){
		arr[i]=arr[i]%k; // convert into mod value
		counter[arr[i]]++;
	}
	displayVector(arr);
	int count = 0;
	int j = floor(k*1.0/2);i=1;
	if(counter[0]>=2){count+=(counter[0]*(counter[0]-1)/2);}
	if(k&2){count+=(counter[k/2]*(counter[k/2]-1)/2);j--;}
	FORL(i,i,j){
		int oth = k-i-1; // opposite index;
		count+=counter[i]*counter[oth];
	}
	displayVector(counter);
	cout<<count<<endl;
	return 0;
}