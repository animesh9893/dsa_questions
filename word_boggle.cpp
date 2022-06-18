#include <bits/stdc++.h>

using namespace std;

// M*N matrix M rows and N cols
bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s) || dfs(board, i+1, j+1, s) || dfs(board, i+1, j-1, s) || dfs(board, i-1, j+1, s) || dfs(board, i-1, j-1, s);
    board[i][j] = c;
    return ret;
}

bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	vector<string> ans;
	for(auto x:dictionary){
		if(exist(board,x)){
			ans.push_back(x);
		}
	}
	return ans;
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<char>> words(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>words[i][j];
		}
	}
	cout<<endl;
	string s;cin>>s;
	cout<<exist(words,s);
	cout<<endl;
	return 0;
}