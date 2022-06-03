// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

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

void func(vector<vector<char> > &letter,vector<char> &op,int i,vector<string>&ans){
	int n = letter.size();
	if(i>=n){
		string temp(op.begin(),op.end());
		ans.push_back(temp);
	}else{
		for(auto x:letter[i]){
			op[i] = x;
			func(letter,op,i+1,ans);
		}
	}
}


vector<string> letterCombinations(string digits) {
	vector<char> op(digits.length());
	vector<string> ans;
	if(digits==""){ans.push_back("");return ans;}
	vector<vector<char> > st = {
		{'a','b','c'}, // 2
		{'d','e','f'}, //3
		{'g','h','i'},//4
		{'j','k','l'},//5
		{'m','n','o'},//6
		{'p','q','r','s'},//7
		{'t','u','v'},//8
		{'w','x','y','z'}//9
	};
	vector<vector<char> > letters;
	for(int i=0;i<digits.length();i++){
		int temp = digits[i]-'0';
		temp-=2; // index
		letters.push_back(st[temp]);
	}
	func(letters,op,0,ans);

	return ans;
}

int main(){
	letterCombinations("23");
	return 0;
}