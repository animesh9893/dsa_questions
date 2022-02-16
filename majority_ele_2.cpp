// https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v){
	for(auto x:v){
		cout<<x<<" ";
	}cout<<endl;
}

// there is only 2 max possible element
vector<int> majorityElement(vector<int>& a) {
	vector <int> result;
    int candOne = (int)1e9 + 1 , candTwo = (int)1e9 + 1 , cntOne = 0 , cntTwo = 0;
    for(int &i : a)
    {
        if(candOne == i)
            cntOne++;
        else if(candTwo == i)
            cntTwo++;
        else if(cntOne == 0)
        {
            candOne = i;
            cntOne++;
        }
        else if(cntTwo == 0)
        {
            candTwo = i;
            cntTwo++;
        }
        else
        {
            cntOne--;
            cntTwo--;
        }
    }
    cntOne = 0;
    cntTwo = 0;
    for(int &i : a)
    {
        if(i == candOne)
            cntOne++;
        if(i == candTwo)
            cntTwo++;
    }
    if(cntOne > ((int)a.size()) / 3)
        result.push_back(candOne);
    if(cntTwo > ((int)a.size()) / 3)
        result.push_back(candTwo);
    return result;
}



int main(){
	vector<int> nums = {
		3,3,2,2,1,1,4,4
		// 1,1,1,1,1,2,2,2,2,2
	};
	vector<int> ans = majorityElement(nums);
	display(ans);
}