/*
Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
Date : 22.12.07
Time : 00:23
Comment : 
	LeetCode를 거의 안 써봐서; 아직 익숙하지가 않넹...

*/

#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int bufK;

    KthLargest(int k, vector<int>& nums) {
        bufK = k;
        for (int x : nums)
            add(x);
    }

    int add(int val) {
        if (minheap.size() < bufK)
            minheap.push(val);
        else {
            if (val > minheap.top()) {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};