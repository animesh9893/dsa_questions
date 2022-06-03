#include<bits/stdc++.h>

using namespace std;

string  FindMostFrequentWord(string str){
	unordered_map <string,int> counter;
	string word = "";
	for(auto x:str){
		if(x!=' '){
			word+=x;
		}else if(word!=" "){
			counter[word]++;
			word="";
		}
	}
	if(word!=" ") counter[word]++;
	int max_count = INT_MIN;string ans="";
	for(auto x:counter){
		if(max_count<x.second){
			max_count = x.second;
			ans = x.first;
		}
		//cout<<x.first<<"\t"<<x.second<<endl;
	}
	return ans;
}

char *  FindMostFrequentWord(char * str){
	unordered_map <char *,int> counter;
	string word = "";
	for(auto x:str){
		if(x!=' '){
			word+=x;
		}else if(word!=" "){
			counter[word]++;
			word="";
		}
	}
	if(word!=" ") counter[word]++;
	int max_count = INT_MIN;string ans="";
	for(auto x:counter){
		if(max_count<x.second){
			max_count = x.second;
			ans = x.first;
		}
		//cout<<x.first<<"\t"<<x.second<<endl;
	}
	return ans;
}


int main(){
	string str = "animesh s is animesh s";
	string ans = FindMostFrequentWord(str);
	cout<<ans<<endl;

}
