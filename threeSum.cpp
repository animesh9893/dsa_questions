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


vector<vector<int> > threeSum(vector<int> &nums){
	int n=nums.size();
	vector<vector<int> > ans;
	if(n<3) return ans;
	sort(nums.begin(),nums.end());
	int hig=INT_MIN,low=INT_MAX;
	int pre = INT_MAX;int cnt=0;
	for(int i=0;i<n;i++){
		if(nums[i]==0) cnt++;
	}

	if(cnt>=3) ans.push_back({0,0,0});

	for(int i=0;i<n;i++){
		if(nums[i]==pre){continue;}
		pre=nums[i];
		hig = n-1;low=i+1;
		int a=nums[i]*-1;
		while(hig>low){
			int c=nums[low]+nums[hig];
			int x=nums[low],y=nums[hig];
			if(a==c){
				ans.push_back({a,nums[low],nums[hig]});
				while(nums[low]==x) low++;
				while(nums[hig]==y) hig--;
			}else if(a>c){
				while(nums[hig]==y) hig--;
			}else{
				while(nums[low]==x) low++;
			}
		}
	}
	return ans;
}

int main(){
	vector<int> nums = {-1,0,1,2,-1,-4};
	auto ans = threeSum(nums);
	for(auto i:ans){
		for(auto val:i){
			cout<<val<<" ";
		}cout<<endl;
	}
	return 0;
}