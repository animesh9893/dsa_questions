// Minimum Window Substring
#include <bits/stdc++.h>

using namespace std;

void displaymap(map<char,int>m){
	for(auto it = m.cbegin(); it != m.cend(); ++it)
	{
	    std::cout << it->first<<"\t"<<it->second<<endl;
	}
}

bool check_key(map<char, int> m, int key)
{
    // Key is not present
    if (m.find(key) == m.end())
        return false;
 
    return true;
}
bool check_all_empty(map<char, int> m){
	for(auto it = m.cbegin(); it != m.cend(); ++it)
	{
	    if(it->second>0){
	    	return false;
	    }
	}
	return true;
}
bool compare(map<char, int> m,map<char, int> m2){
	for(auto it = m.cbegin(); it != m.cend(); ++it)
	{
	    if(it->second!=m2[it->first]){
	    	return false;
	    }
	}
	return true;
}

string fun(string s,string t){
	map<char,int> m;
	for(int i=0;i<s.size();i++){
		m[s[i]]++;
	}
	map<char,int> temp_m(m);
	int start,s_len=s.length(),t_len=t.length();
	int result_start = 0,result_end= 0;
	for(int i=0;i<s_len;i++){
		if(temp_m[s[i]]>0){
			start=i;
			break;
		}
	}
	int mid=start;
	while(s_len-(result_end-result_start)>=t_len){
		// finding mid
		for(int i=start+1;i<s_len;i++){
			if(check_key(temp_m,s[i])){
				temp_m[s[i]]--;
				mid=i;
			}
		}
		int last;
		// finding last
		for(int i=mid+1;i<s_len;i++){
			if(check_all_empty(temp_m)){
				last=i-1;
				i=s_len+1;
				temp_m = m;
			}else{
				temp_m[s[i]]--;
			}
		}
		if(compare(temp_m,m)){
			cout<<start<<"\t"<<mid<<"\t"<<last<<endl;
			start=mid;
		}else{
			break;
		}
	}
	return t;
}

int main(){
	cout<<fun("ADOBECODEBANC","ABC")<<endl;
}