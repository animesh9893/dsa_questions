// https://www.spoj.com/problems/PRIME1/
// PRIME1 - Prime Generator

#include <bits/stdc++.h>
using namespace std;

vector<int> seive(){
	int n=100000;
	bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
    	if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    std::vector<int> v;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.push_back(p);
    return v;
}

vector<int> fun(int l,int r,vector<int> s){
	vector<int> result;
	if(r<100000){
		for(int i=0;i<s.size();i++){
			if(s[i]>r){
				return result;
			}
			if(s[i]>=l and s[i]<=r)
				result.push_back(s[i]);
		}
	}

	int len = r-l+1;
	int primes[len];
	for(int i=0;i<len;i++)
		primes[i]=1;
	int root = ceil(sqrt(r));
	for(int i=0;i<=root;i++){
		int p = s[i];
		int first_m = ceil(1.0*l/p);
		int last_m = floor(1.0*r/p);

		for(int i=first_m;i<last_m;i++){
			primes[p*i-l]=0;
		}
	}
	for(int i=0;i<len;i++){
		if(primes[i]==1)
			result.push_back(i+l);
	}
	return result;
}

int main(){
	std::vector<int> v=seive();
	int t;cin>>t;
	while(t--){
		int l,r;cin>>l>>r;
		std::vector<int> res = fun(l,r,v);
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<endl;
		cout<<endl;
	}
	
}