// you are given and M*N matrix and we need to find total number of unique paths from (0,0) to (M-1,N-1)
// we can only move RIGHT & DOWN.

// By question get to know 
// countPath(0,0) = CountPath(0,1) + CountPath(1,0)
// because if any person is at (0,0) then he have 2 choices either to go with RIGHT or DOWN.
// and number of path for right is CountPath(0,1) = CountPath(0,2)+CountPath(1,1); 
// this will go on and on.

// Therefore recursive relation is : T(i,j) = T(i,j+1) + T(i+1,j)
// Termination condition : i==M-1 or j==N-1 return 1;   because when any person at bottom or extreme right so their is only one straight path to opt and by this bounries can not exeed.


#include<bits/stdc++.h>
using namespace std;

//code
int countPaths(int m,int n,int i,int j){
	if(i==m-1 or j==n-1) return 1;
	return countPaths(m,n,i+1,j)+countPaths(m,n,i,j+1);
}

// little memeory optimal becuase m,n is not changing so we can create their referance variable
int countPaths_1(int &m,int &n,int i,int j){
	if(i==m-1 or j==n-1) return 1;
	return countPaths(m,n,i+1,j)+countPaths(m,n,i,j+1);
}



int main(){
	int m=3,n=3;
	cout<<countPaths_1(m,n,0,0)<<endl;
}
