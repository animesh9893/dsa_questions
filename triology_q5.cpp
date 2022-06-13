#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    
    vector<int> ans;
    
    int n = A.size();
    int m = B.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // if(i>=n-1 and j>=m-1) continue;
            ans.push_back(A[i]|B[j]);
        }
    }
    // ans.push_back(B[m-1]);
    int temp = 0;
    for(auto x:ans){
        cout<<x<<" ";
        temp = temp^x;
    }
    cout<<endl;
    cout<<temp<<endl;
    return temp;
}

int main(){
	vector<int> A = {1,2};
	vector<int> B = {4,10};
	cout<<solve(A,B)<<endl;
}
