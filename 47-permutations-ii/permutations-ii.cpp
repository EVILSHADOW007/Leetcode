class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int index) {
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=index;i<nums.size();i++) {
            if(used.count(nums[i])) continue;


            used.insert(nums[i]);
            swap(nums[index],nums[i]);
            solve(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};