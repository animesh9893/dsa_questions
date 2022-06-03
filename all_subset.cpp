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


template <typename T>
void displayVector(vector<T> &v){
	for(auto x:v){
		cout<<x<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int n){
	n = min(n,v.size());
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int i,int n){
	n = min(n,v.size());
	i = max(0,i);
	for(;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

template <typename T>
void displayVector(vector<T> &v,int i,int n, bool rev){
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

template <typename T>
void subsets(vector<T> &v,vector<T> &op,int i,int k,void (*func)(vector<T>&,int)){
	int n = v.size();
	if(i>=n){
		func(op,k);
	}else{
		subsets(v,op,i+1,k,func);
		op[k] = v[i];
		subsets(v,op,i+1,k+1,func);
	}
}

int main(){
	vector<char> v = {'a','b','c'};
	vector<char> op(v.size());
	subsets(v,op,0,0,&displayVector);
	return 0;
}