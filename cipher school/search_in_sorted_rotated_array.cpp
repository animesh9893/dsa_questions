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


// this is recursive binary search solution
// cons are only stackoverflow
int searchInSortedRotateArrayRecursive(vector<int> &nums,int low,int hig,const int target){
	if(low>hig) return -1;
	// this is best way to find value of mid other option "may" cause an 
	// integer overflow exception
	int mid = low+(hig-low)/2;
	// if you got a target at an index just return that index
	if(nums[mid]==target) return mid;

	// if left part of an array is sorted just check if it is present on that side
	// or not
	if(nums[low]<=nums[mid]){
		// checking if target is present on the sorted part or not
		if(target>= nums[low] and target<=nums[mid])
			return searchInSortedRotateArrayRecursive(nums,low,mid-1,target);
		// if array is not present at that part just search on other
		return searchInSortedRotateArrayRecursive(nums,mid+1,hig,target);
	}
	// if right part is sorted then
	if(nums[mid]<=nums[hig]){
		// if target present at sorted part
		if(target>=nums[mid] and target<=nums[hig])
			return searchInSortedRotateArrayRecursive(nums,mid+1,hig,target);
	}
	// else target is at unsorted part or not presnt and all
	return searchInSortedRotateArrayRecursive(nums,low,mid-1,target);
}
// this is itrative solution the question
int searchInSortedRotateArrayItrative(vector<int> &nums,const int target){
	int n = nums.size();
	if(n==0) return -1;
	int hig = n-1,low = 0;

	while(low<=hig){
		int mid = low+(hig-low)/2;
		if(nums[mid]==target) return mid;
		// if left part is sorted
		if(nums[low]<=nums[mid]){
			// if target present at that part
			if(target>=nums[low] and target<=nums[mid]){
				hig=mid-1;
			}else{
				low = mid+1;
			}
		}else if(nums[mid]<=nums[hig]){
			// if right one is sorted
			//if target is in that part
			if(target>=nums[mid] and target<=nums[hig])
				low = mid+1;
			else
				hig = mid-1;
		}else{
			hig = mid-1;
		}
	}
	return -1;
}


int main(){
	int n;cin>>n;
	auto arr = inputArray(n);
	for(int i=0;i<n;i++){
		cout<<i<<" ";
	}cout<<endl;
	for(auto x:arr)
		cout<<x<<" ";cout<<endl;
	int tar;
	while(cin>>tar){
		cout<<searchInSortedRotateArray(arr,tar)<<endl;		
	}
	return 0;
}