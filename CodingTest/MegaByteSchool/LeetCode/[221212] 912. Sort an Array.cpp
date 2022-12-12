/*

*/

#include <iostream>
#include <vector>

using namespace std;

//bubbleSort(nums);
void bubbleSort(vector<int>& nums) {
	for (int i = nums.size() - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


}