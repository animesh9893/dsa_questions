// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

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

void func(vector<char> &arr,int index,char element,vector<vector<char>> &res){
	if(index>=arr.size()){
		// for(auto x:arr){
			// cout<<x;
		// }cout<<endl;

		res.push_back(arr);
		return ;
	}
	if(index!=0 and arr[index-1]==element){
		return;
	}
	arr[index]=element;
	if(element!='a')
		func(arr,index+1,'a',res);
	if(element!='b')
		func(arr,index+1,'b',res);
	if(element!='c')
		func(arr,index+1,'c',res);
	return ;
}

string getHappyString(int size, int k) {
    vector<char> arr(size);
    vector<vector<char>> res;
    func(arr,0,'a',res);
    func(arr,0,'b',res);
    func(arr,0,'c',res);
    // int count = 1;
    // for(auto item:res){
    	// cout<<count<<" : ";
    	// for(auto x:item){
    		// cout<<x;
    	// }cout<<endl;
    	// count++;
    // }
    vector<char> temp = res[(k-1)*2];
    string s(temp.begin(),temp.end());
    return s;
}

int main(){
	int size,k;cin>>size>>k;
	cout<<getHappyString(size,k);
	cout<<endl;
	return 0;
}