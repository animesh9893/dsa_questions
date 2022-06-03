// https://codeforces.com/problemset/problem/835/C
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > sum_mat(105,vector<int>(105));

void initFunc(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    // sum_mat = vector(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            sum_mat[i][j]=matrix[i][j];
    
    for(int i=0;i<m;i++){
        int temp = 0;
        for(int j=0;j<n;j++){
            temp+=matrix[i][j];
            sum_mat[i][j] = temp;
        }
    }
    
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<m;j++){
            temp += sum_mat[j][i];
            sum_mat[j][i] = temp;
        }
    }
}
int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    if(row2>=0 and col2>=0)
        sum += sum_mat[row2][col2];
    if(row1-1>=0)
        sum -= sum_mat[row1-1][col2];
    if(col1-1>=0)
        sum -= sum_mat[row2][col1-1];
    if(row1-1>=0 and col1-1>=0)
        sum += sum_mat[row1-1][col1-1];
    return sum;
}

int main(){
	int n,q,c;cin>>n>>q>>c;
	vector<vector<int> > mat(105,vector<int>(105));
	for(int i = 0; i<n ; i++){
		int x,y,s;cin>>x>>y>>s;
		mat[x-1][y-1] = s;
	}
	initFunc(mat);
	for(int i=0;i<q;i++){
		int t,x1,y1,x2,y2;
		cin>>t>>x1>>y1>>x2>>y2;
		int temp = sumRegion(x1-1,y1-1,x2-1,y2-1)*(t+1);
		if(temp>c) temp = c;
		cout<<temp<<endl;
	}

}


