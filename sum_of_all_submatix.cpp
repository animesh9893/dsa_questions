// https://www.geeksforgeeks.org/sum-of-all-submatrices-of-a-given-matrix/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n;cin>>m>>n;
	int mat[m][n];

	long long sum = 0;
	for(int i=0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>mat[i][j];
			int temp = (i+1)*(j+1)*mat[i][j]*(m-i)*(n-j);
			sum+=temp;
		}
	}
	cout<<sum<<endl;
}