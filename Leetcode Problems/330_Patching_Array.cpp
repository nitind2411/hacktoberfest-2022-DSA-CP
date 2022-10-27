class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0, sz = nums.size();
        long count = 1;
        while (count <= n) {
            
            if (i < sz && nums[i] <= count) 
                count += nums[i++];
            
            else {
                count *= 2;
                patches++;
            }
        }
        
        return patches;
    }
};
