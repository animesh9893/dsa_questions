#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> &mat,int i,int j){
	int n = mat.size();
	for(int a=0;a<n;a++){
		if(mat[a][j]==1) return false;
	}
	int a = i,b=j;

	while(a>=0 and b>=0){
		if(mat[a--][b--]) return false;
	}
	a=i,b=j;
	while(a<n and b<n){
		if(mat[a++][b++]) return false;
	}

	a=i,b=j;
	while(a>=0 and b<n){
		if(mat[a--][b++]) return false;
	}	

	a=i,b=j;
	while(a<n and b>=0){
		if(mat[a++][b--]) return false;
	}

	return true;
}

void bkt(const int n,int queen,int i,vector<vector<int>> &mat,vector<vector<string>> &ans){
	// cout<<"Q : "<<queen<<endl;
	if(queen==0){
		// push answer
		vector<string> ans_temp;
		for(auto item:mat){
			string temp = "";
			for(auto x:item){
				if(x==1){
					temp+="Q";
				}else temp+=".";
			}
			// cout<<temp<<endl;
			ans_temp.push_back(temp);
		}
		ans.push_back(ans_temp);
	}
	if(i==n and queen<n) return ;

	for(int x=0;x<n;x++){
		if(isSafe(mat,i,x)){
			// cout<<i<<" "<<x<<endl;
			mat[i][x] = 1; // recursion forward
			bkt(n,queen-1,i+1,mat,ans);
			mat[i][x] = 0; // backtracking 
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	// 0 means all clear 1 means queen is at position
	vector<vector<int>> mat(n,vector<int>(n,0));
	vector<vector<string>> ans;
	bkt(n,n,0,mat,ans);
	return ans;
}

int main(){
	// int n;cin>>n;
	auto ans = solveNQueens(8);
	
	// vector<vector<pair<int,int>>> cred(ans.size(),vector<pair<int,int>>(8));
	for(auto x:ans){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(x[i][j]=='Q'){
					cout<<i<<" "<<j<<endl;
				}
			}
		}cout<<endl;
	}
	
	cout<<ans.size()<<endl;
	return 0;
}