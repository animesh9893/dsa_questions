// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(),matrix.end());
    int n = matrix[0].size();
    vector< vector<int> > v(n , vector<int>(n,0));

    int count = 0;

    for(int i=0; i < n ; i++){
    	for(int j=0; j<n ; j++){
    		v[j][i] = matrix[i][j];
    	}
    }

    matrix = v;
}

void display(vector<vector<int> > &v){
	for(auto &val:v){
		for(auto &val2:val){
			cout<<val2<<" ";
		}cout<<endl;
	}
}


int main(){
	vector<vector<int> > v = { {1,2,3}, {4,5,6}, {7,8,9} };
	display(v);cout<<endl;
	rotate(v);
	display(v);
}	