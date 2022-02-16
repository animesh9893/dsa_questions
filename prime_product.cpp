// Given two numbers 
// L
//  and 
// R
//  (inclusive) find the product of primes within this range. Print the product modulo 
// 10
// 9
// +
// 7
// . If there are no primes in that range you must print 
// 1
// .

// Input Format

// The first line contains a positive integer 
// T
// , denoting number of testcases
// The first line of each testcase contains two space - separated integers 
// L
//  and 
// R
// , denoting the range
// Constraints

// 1
 
// ≤
 
// T
 
// ≤
 
// 10
// 1
 
// ≤
 
// L
 
// ≤
 
// R
 
// ≤
 
// 10
// 9
// 0
 
// ≤
 
// R
// −
// L
 
// ≤
 
// 10
// 6
// Output Format

// Print the product of all primes in the range 
// [
// L
// ,
// R
// ]
//  modulo 
// 10
// 9
// +
// 7
// Sample Input

// 2
// 1 10
// 2 20

// Sample Output

// 210
// 9699690

// Sample Explanation

// Case 1: 
// 2
// ∗
// 3
// ∗
// 5
// ∗
// 7
// =
// 210
// Case 2: 
// 2
// ∗
// 3
// ∗
// 5
// ∗
// 7
// ∗
// 11
// ∗
// 13
// ∗
// 17
// ∗
// 19
// =
// 9699690
// Example
// Input
// 2  
// 1 10  
// 2 20
// Output
// 210
// 9699690



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


int main(){
    seive();
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi prime;
    int i=2;
    FOR(i,sei.size()){
        if(sei[i]==i) prime.PB(i);
    }    

    int T;
    cin>>T;
    while(T--){
        vi primes_range;
        int l,r;cin>>l>>r;
        if(r<sei.size()){   
            i=0;
            FOR(i,prime.size()){
                if(prime[i]<=r){
                    primes_range.PB(prime[i]);
                }
            }
        }else{
            primes_range = segmentedSeive(l,r);
        }
        if(primes_range.size()==0){cout<<1<<endl;}
        else{
            int mul = 1;
            for(int i=0;i<primes_range.size();i++){
                mul = modmul(mul,primes_range[i],mod);
            }
            cout<<mul<<endl;
        }
    }
    return 0;
}