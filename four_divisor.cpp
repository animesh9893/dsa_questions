// https://leetcode.com/problems/four-divisors/
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


vector<int> leastPrimeFactor(int n){
	vector<int> least_prime(n+1, 0);
	least_prime[1] = 1;

	for (int i = 2; i <= n; i++){
		if (least_prime[i] == 0){
			least_prime[i] = i;
			for (int j = i*i; j <= n; j += i)
				if (least_prime[j] == 0)
				least_prime[j] = i;
		}
	}
	return least_prime;
}

int sumFourDivisors(vector<int>& nums) {
	auto prime = leastPrimeFactor(10000);
	int sum = 0;
	for(auto x:nums){
		vector<int> div = {1,0,0,x};
		div[1] = prime[x];
		div[2] = x/div[1];
		if(div[0]!=div[1] and div[0]!=div[2] and div[0]!=div[3] and div[1]!=div[2] and div[1]!=div[3] and div[2]!=div[3]){
			sum+=div[0]+div[1]+div[2]+div[3];
		}
	}
	return sum;       
}


int main(){
	int n;cin>>n;
	auto arr = inputArray(n);
	cout<<sumFourDivisors(arr)<<endl;
	cout<<endl;
	return 0;
}