#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

struct Mountain{
	int left;
	int right;
	int value;
	Mountain(int l, int r, int v):left(l),right(r),value(v){}
};

Mountain split(string & tempstr){
	int l,r,v;
	size_t pos1 = tempstr.find_first_of(',');
	size_t pos2 = tempstr.find_last_of(',');
	l = atoi(tempstr.substr(0,pos1).c_str());
	r = atoi(tempstr.substr(pos1+1,pos2-pos1-1).c_str());
	v = atoi(tempstr.substr(pos2+1).c_str());
	return Mountain(l,r,v);
}


int calc(vector<Mountain>& data){
	int sz = data.size();
	if(sz == 0) return 0;
	int max_right = 0;
	for(int i=0; i<sz; i++)
		max_right = max(data[i].right, max_right);
	vector<int> height(max_right*2 + 2, 0);
	for(int i=0; i<sz; i++){
		int le = 2 * data[i].left;
		int ri = 2 * data[i].right;
		for(int j=le; j<=ri; j++)
			height[j] = max(height[j], data[i].value);
	}
	int sum = 0;
	sum += height[0];
	for(int i=1; i< max_right*2 + 2; i++){
		sum += abs(height[i]-height[i-1]);
	}
	sum += max_right;
	return sum;	
}

int resolve(const char* input)
{
	string s(input);
	vector<Mountain> mvec;
	stringstream stream(s);
	int T;
	stream>>T;
	string tempstr;
	while(T--){
		stream>>tempstr;
		mvec.push_back(split(tempstr));
	}
	return calc(mvec);	
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
    	//resolve(input[i]);
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
