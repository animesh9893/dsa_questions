// https://codeforces.com/contest/776/problem/B

#include <bits/stdc++.h>

using namespace std;

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
    for(int i = 2;i<n;i++){
    	if(sei[i]==-1){
    		sei[i]=i;
    	}
    }
}

int main(){
	seive();
	int n ;cin>>n;
	int flag = 0;
	for(int i=n+1;i>=2;i--){
		if(sei[i]!=i){
			flag=1;
			cout<<2<<endl;break;
		}
	}
	if(!flag) cout<<1<<endl;
	for(int i = 2;i<n+2;i++){
		if(sei[i]==i){
			cout<<1<<" ";
		}else{
			cout<<2<<" ";
		}
	}
	cout<<endl;

}