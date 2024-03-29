class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            int area = (right - left) * h;
            if (area > max)
                max = area;

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max;
    }
};