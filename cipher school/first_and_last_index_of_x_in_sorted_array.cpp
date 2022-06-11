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

int search(vector<int> &nums,int low,int hig,const int target){
	if(low>hig) return -1;
	int mid = low + (hig-low)/2;
	if(nums[mid]==target) return mid;
	if(nums[mid]>target) return search(nums,low,mid-1,target);
	if(nums[mid]<target) return search(nums,mid+1,hig,target);
	return -1;
}

vector<int> searchRange(vector<int>&nums,const int target){
	vector<int> ans(2,-1);
	int n = nums.size();
	if(n==0) return ans;

	// finding first occurance of target
	int low = search(nums,0,n-1,target);
	int hig = low;
	while(low!=0 and nums[low-1]==target){
		low = search(nums,0,low-1,target);
	}
	while(hig!=n-1 and nums[hig+1]==target){
		hig = search(nums,hig,n-1,target);
	}
	ans[0] = low;
	ans[1] = hig;
	return ans;
}

// we can also use upper and lower bound 
vector<int> searchRange_with_bounds(vector<int> &nums,const int &target){
	int low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
	// checking if element is presnet or not
	if (low == nums.size() or nums[low]!=target) return {-1,-1};
	int hig = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;
	return {low,hig};
}

int main(){
	int n;cin>>n;
	auto arr = inputArray(n);

	int tar;
	while(cin>>tar){
		auto ans = searchRange(arr,tar);
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}

	cout<<endl;
	return 0;
}