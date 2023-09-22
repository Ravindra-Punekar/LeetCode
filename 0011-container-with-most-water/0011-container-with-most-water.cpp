class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;

        int l=0;
        int r=height.size()-1;

        while(l<r){
            maxArea = max(min(height[l],height[r])*(r-l), maxArea);
            (height[l]<height[r]) ? l++ : r--;
        }

        return maxArea;
    }
};