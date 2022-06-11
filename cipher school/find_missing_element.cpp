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

// question is their is an array of size n and their is element
// from 1 to n+1 one item is missing between them so to n+1
// we need to find that missing element

// time : O(n^2) space : O(1)
int missingElement_BruteForce(vector<int> &nums){
	int n = nums.size();
	// first brute force approach is check for every element
	// like check for 1 then 2 then 3 till n if some element is missing then 
	// that is  "Answer"
	
	for(int i=1;i<=n;i++){
		bool found = false;
		for(int j=0;j<n and !found;j++){
			if(nums[j]==i){
				found = true;
			}
		}
		if(found==false) return i;
	}
	return n+1;
} 

// time O(n) but if digits are big then it may cause the integer flow error
// so we use array of big integers then int value may overflow.
int missingElement_sum_method(vector<int> &nums){
	int n = nums.size();
	//another method is to find sum till n+1 from 1 and subract the sum of the array
	// we know sum of n number is n*(n+1)/2
	// so sum till n+1 is (n+1)*(n+2)/2
	int arr_sum = 0;
	for(auto x:nums){
		arr_sum+=x;
	}
	int number_sum = (n+1)*(n+2)/2;
	return (number_sum-arr_sum);
}

// xor is an operation where if we do a^a=0 then reult is 0.
// and if we do a^0 then result is a
// do it on paper (trace it)
int missingElement(vector<int> &nums){
	int n = nums.size();
	// so here we simply xor the all element of array and then xor the 
	// element from 1 to n+1 then if anything is missing then it left out
	// because property we mentioned above.
	int xor_ele = 0;
	for(auto x:nums)
		xor_ele = xor_ele^x;
	for(int i=1;i<=n+1;i++)
		xor_ele = xor_ele^i;
	return xor_ele;
}
int main(){
	int n;cin>>n;
	auto arr =inputArray(n);
	cout<<"Missing Element is : "<<missingElement(arr)<<endl;
	return 0;
}