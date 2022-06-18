#include<bits/stdc++.h>

using namespace std;
void printSudoku(vector<vector<char>>& arr){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr[i][j]<<" ";
			if(j==2 or j==5 or j==8) cout<<"| ";
		}cout<<endl;
		if(i==2 or i==5 or i==8) cout<<"-------------------------- ";
		cout<<endl;
	}
	cout<<endl;
}

bool isValid(vector<vector<char>> &board,int row,int col,char c){
	for(int i=0;i<9;i++){
		if(board[row][i]==c) return false;
		if(board[i][col]==c) return false;
		if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
	}
	return true;
}

bool solve(vector<vector<char>> &board){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(board[i][j]=='.'){
				for(int c=1;c<=9;c++){
					char temp = c+'0';
					if(isValid(board,i,j,temp)){
						board[i][j] = temp;
						if(solve(board)){
							return true;
						}
						else board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
 	solve(board);       
 	return ;
}

int main(){
	vector<vector<char>> arr {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	solveSudoku(arr);
	printSudoku(arr);
}