class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> a;

        for (int i = 0; i < nums.size(); i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<vector<int>> groups;
        groups.push_back({a[0].first});

        for (int i = 1; i < a.size(); i++) {
            if (a[i].first - a[i - 1].first > limit)
                groups.push_back({});

            groups.back().push_back(a[i].first);
        }

        map<int, int> group;
        for (int g = 0; g < groups.size(); g++) {
            for (int x : groups[g])
                group[x] = g;
        }

        vector<int> pos(groups.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int g = group[nums[i]];
            nums[i] = groups[g][pos[g]++];
        }

        return nums;
    }
};