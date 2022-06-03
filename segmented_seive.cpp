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


vector<int> sei(1000005,-1);
void seive(){
    int n = sei.size();
    sei[0]=sei[1]=-2;
    for(int i = 2; i*i<n;i++){
        if(sei[i]==-1){
            sei[i]=i;
            for(int j=i*i;j<n;j+=i){
                if(sei[j]!=-1) continue;
                sei[j]=i;
            }
        }
    }
}


vector<int> segmentedSeive(int l,int r){
	
	if(sei[2]!=2) seive();
	int n = sei.size();
    vector<int> primes;
    for(int i = 2;i<n;i++){
    	if(sei[i]==i){
    		primes.push_back(i);
    	}
    }

    vector<bool> isPrime(r-l+1,1);

    for(int i = 0;i<primes.size();i++){
    	int k = ceil(l*1.0/primes[i]);
    	if(k<2) k++;
    	for(int j = k;primes[i]*j<=r;j++){
    		isPrime[primes[i]*j-l]=false;
    	}
    }

    vector<int> ans;
    for(int i = 0;i<isPrime.size();i++){
    	if(isPrime[i]) ans.push_back(i+l);
    }

    return ans;
}


void displayVector(vector<int> &v){
	for(auto x:v){
		cout<<x<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int n){
	n = min(n,v.size());
	for(int i = 0;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n){
	n = min(n,v.size());
	i = max(0,i);
	for(;i<n;i++){
		cout<<v[i]<<" ";  
	}cout<<endl;
}

void displayVector(vector<int> &v,int i,int n, bool rev){
	n = min(n,v.size());
	i = max(0,i);
	if(!rev){
		for(;i<n;i++){
			cout<<v[i]<<" ";  
		}cout<<endl;
	}else{
		n--;
		for(;n>=i;n--){
			cout<<v[n]<<" ";  
		}cout<<endl;
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int l,r;cin>>l>>r;
		auto ans = segmentedSeive(l,r);
		displayVector(ans);
	}
	return 0;
}