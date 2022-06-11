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

int x = 100;

void fun1(){
	cout<<x<<endl;
}

// int getValue(int x=0,int y=0,int z){
	// return x+y+z;
// }

void fun2(){
	cout<<x<<endl;
}
int main(){
	// fun2();
	// fun1();
	// cout<<getValue(10);
	// int a=10;
	// while(a>5){
	// 	int a=1;
	// 	cout<<a<<endl;
	// 	a--;
	// }
	int a=5;
	int const *q=&a;a++;
	cout<<q<<endl;
	// q++;
	cout<<q<<endl;

	(*q)++;
	cout<<a<<endl;
	return 0;
}










// https://docs.google.com/document/d/1xWOadbW5zWdD8D3qNP9fc2dmBJfhEIWbCw0ngFCqJtU/edit?usp=sharing