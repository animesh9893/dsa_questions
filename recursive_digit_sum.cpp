// https://www.hackerrank.com/challenges/recursive-digit-sum/problem
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


string digitSum(string s){
	int sum = 0;
	for(int i=0;i<s.length();i++){
		int num = s[i]-'0';
		sum+=num;
	}
	string ans = to_string(sum);
	return ans;
}

string digitSum(string s,int k){
	int sum = 0;
	for(int i=0;i<s.length();i++){
		int num = s[i]-'0';
		sum+=num;
	}
	sum*=k;
	string ans = to_string(sum);
	return ans;
}

int func(string n){
	// cout<<n<<endl;
	if(n.length()==0) return 0;
	else if(n.length()==1) return n[0]-'0';

	n = digitSum(n);
	return func(n);
}


int main(){
	string s;int k;cin>>s>>k;
	s = digitSum(s,k);
	cout<<func(s)<<endl;
	
	return 0;
}