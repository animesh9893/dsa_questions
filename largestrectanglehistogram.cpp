// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int max_so_far = INT_MIN;
	int n = heights.size();
	int p1 = 0,p2 = n-1;

	while(p1<=p2){
		int area = p2-p1+1;
		area*=
	}
} 

int main(){
	vector<int> v = {2,1,5,6,2,3};
	cout<<largestRectangleArea(v)<<endl;
}