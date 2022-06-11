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

bool isPanlindrome(string s){
    if(s.length()==1) return true;
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}
int removePalindromeSub(string s) {
    int moves = 0;
    int n = s.length();
    if(n==0) return moves;
    if(n==1) return 1;
    
    for(int i=0;i<n;i++){
        bool found = false;
        for(int j=n-1;j>i and !found;j--){
            if(isPanlindrome(s.substr(i,j-i+1))){
                found = true;
                i = j+1;
                moves++;
            }
        }
        if(!found){
            moves++;
        }
    }
    return moves;
}

int main(){
	cout<<isPanlindrome("aabb")<<endl;
	cout<<isPanlindrome("ababa")<<endl;
	
	cout<<removePalindromeSub("abb")<<endl;
	cout<<removePalindromeSub("ababa")<<endl;
	cout<<endl;
	return 0;
}



