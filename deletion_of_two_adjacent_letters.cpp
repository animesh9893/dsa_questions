// https://codeforces.com/contest/1650/problem/A
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		char c; cin>>c;
		int n = s.length();
		bool flag = false;
		
		for(int i=0;i<n and !flag;i++){
			if(s[i]==c){
				int left = i;
				int right = n-i-1;
				if(left!=0 and right==0){
					if(left%2==0){
						flag=true;
					}
				}else if(left==0 and right==0){
					flag = true;
				}else if(left==0 and right!=0){
					if(right%2==0) flag = true;
				}else if(left!=0 and right!=0){
					if(right%2==0 and left%2==0) flag = true;
				}
			}
		}


		if(flag){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}