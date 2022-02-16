// we know the gcd of two number is lenthy process so we
// use euclid method to get gcd

#include <iostream>
using namespace std;

// complexity is log(max(a,b))
int gcd(int a,int b){
	if(a==0 or b==0){
		return max(a,b);
	}
	int r=a%b;
	int gcd = min(a,b);
	int temp = max(a,b);
	while(r!=0){
		r = temp%gcd;
		if(r==0){
			break;
		}else{
			temp=gcd;
			gcd=r;
		}
	}
	return gcd;
}

int main(){
	int a,b;cin>>a>>b;
	cout<<gcd(a,b)<<endl;
}