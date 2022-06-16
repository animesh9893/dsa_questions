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

// bool isPanlindrome(string s,int l,int r){
// 	while(l<r){
// 		if(s[l--]!=s[r--]) return false;
// 	}
// 	return true;
// }

// void func(string s,int index,vector<string> &arr,vector<vector<string>> &res){
// 	if(index==s.size()){
// 		res.push_back(arr);
// 		return ;
// 	}

// 	for(int i = index;i<s.size();i++){
// 		if(isPanlindrome(s,index,i)){
// 			arr.push_back(s.substr(index,index+i-1));
// 			func(s,index+1,arr,res);
// 			arr.pop_back();
// 		}
// 	}
// }
bool isPalindrome(const string& s, int start, int end) {
	while(start <= end) {
		if(s[start++] != s[end--])
		return false;
	}
	return true;
}


void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
	if(index == s.size()) {
		ret.push_back(path);
		return;
	}
	for(int i = index; i < s.size(); ++i) {
		if(isPalindrome(s, index, i)) {
			path.push_back(s.substr(index, i - index + 1));
			dfs(i+1, s, path, ret);
			path.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string> > ret;
	if(s.empty()) return ret;

	vector<string> path;
	dfs(0, s, path, ret);

	return ret;
}   

int main(){
	auto ans = partition("aab");
	for(auto item:ans){
		for(auto x:item){
			cout<<x<<" ";
		}cout<<endl;
	}
	cout<<endl;
	return 0;
}