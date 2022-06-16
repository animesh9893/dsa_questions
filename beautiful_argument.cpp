// https://leetcode.com/problems/beautiful-arrangement/
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

bool isCondition(int index,int value){
	if(value%(index+1)==0 or (index+1)%value==0)
		return true;
	return false;
}

void func(vector<int> &arr,int index,int &count){
	if(index==arr.size()){
		for(auto x:arr){
			cout<<x<<" ";
		}cout<<endl;
		count++;
		return ;
	}
	for(int i=index;i<arr.size();i++){
		if(isCondition(index,arr[i]) ){
			swap(arr[index],arr[i]);
			func(arr,index+1,count);
			swap(arr[index],arr[i]);
		}
	}
	return ;
}

int countArrangement(int n) {
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i] = i+1;
	}       
	int count = 0;
	func(arr,0,count);
	return count;
}

int main(){
	cout<<endl<<countArrangement(6)<<endl;
	cout<<endl;
	return 0;
}