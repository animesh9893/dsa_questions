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

// we know their is no duplicates in union 
// array  input do have so we have to use new trick

// merge the array and filter it with set property
// this may be easiest way but it is like cheating
vector<int> mergeSortedArrays(vector<int> &arr1,vector<int> &arr2){
	int n = arr1.size();
	int m = arr2.size();

	vector<int> res(m+n);

	int i=0,j=0,c=0;

	while(i<n and j<m)
		if(arr1[i]<arr2[j])
			res[c++] = arr1[i++];
		else
			res[c++] = arr2[j++];
	
	for(;i<n;i++)
		res[c++] = arr1[i];
	for(;j<m;j++)
		res[c++] = arr2[j];
	return res;
}

// using set is cheating 
vector<int> union_arraySet(vector<int> &arr1,vector<int> &arr2){
	auto ans = mergeSortedArrays(arr1,arr2);
	set<int> s;
	for(auto x:ans){
		s.insert(x);
	}
	vector<int> res;
	for(auto x:s){
		res.push_back(x);
	}
	return res;
}

// optimal option
vector<int> union_array(vector<int> &arr1,vector<int> &arr2){
	int n = arr1.size();
	int m = arr2.size();

	int i=0,j=0;
	int last = INT_MIN;
	vector<int> ans;
	while(i<n and j<n){
		if(arr1[i]<arr2[j] and arr1[i]!=last){
			last = arr1[i];
			ans.push_back(arr1[i++]);
		}else if(arr1[i]>=arr2[j] and arr2[j]!=last){
			last = arr2[j];
		}
	}
}





int main(){
	int n,m;cin>>n;
	auto arr1 = inputArray(n);
	cin>>m;
	auto arr2 = inputArray(m);
	cout<<endl;

	auto ans = union_array(arr1,arr2);
	for(auto x:ans)
		cout<<x<<" ";
	cout<<endl;

	return 0;
}








