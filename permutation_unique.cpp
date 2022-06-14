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

unordered_map<vector<int>,int> hash;

bool isPresent(vector<int> &nums){
	if(hash.find(nums)==hash.end())
		return false;
	return true;
}

void func(vector<int> &nums,int index,vector<vector<int>> &ans){
	if(index==nums.size()){
		ans.push_back(nums);
		return;
	}
	if(!isPresent(nums)){
		hash[nums] = 1;
		for(int i=index;i<nums.size();i++){
			sort(nums.begin()+index,nums.end());
			func(nums,index+1)
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
        
}

int main(){
	vector<int> arr = {1,2,3};
	auto ans = permuteUnique(arr);

	cout<<endl;
	return 0;
}