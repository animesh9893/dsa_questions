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

void rightShift(string &s,int i,int j){
	char temp = s[j];
	for(int a=j-1;a>=i and a>=0;a--){
		s[a+1] = s[a];
	}
	s[i] = temp;
}

void leftShift(string &s,int i,int j){
	char temp = s[i];
	for(int a=i+1;a<=j+1 and a<s.size();a++){
		s[a-1] = s[a];
	}
	s[j] = temp;
}

void permutation(string &s,int index){
	if(index==s.size()-1){
		cout<<s<<endl;
		return ;
	}

	int n = s.size();
	for(int i=index;i<n;i++){
		rightShift(s,index,i);
		permutation(s,index+1);
		leftShift(s,index,i);
	}
	return ;
}

int main(){
	string s;
	cin>>s;
	cout<<endl;
	permutation(s,0);
	cout<<endl;
	return 0;
}