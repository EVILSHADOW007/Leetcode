#define ll long long
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int  n= intervals.size();
        for(int i=0;i<n;i++){
             intervals[i].push_back(i);   
        }
        sort(intervals.begin(), intervals.end());

        struct x{
            ll val;
            vector<int> v;
            bool operator<(const x& other) const {
                if(val != other.val){
                    return val < other.val;
                }
                else {
                    return v < other.v;
                }
            }
        };

        int K = 4;
        x def = {0, vector<int>()};
        vector<vector<x>> dp(n, vector<x>(6, def));

        for(int i = n-1; i>=0; i--){        
           // dont choose
           for(int j=1; j<=K; j++){
                if(i!=n-1)
                    dp[i][j] = min(dp[i][j], dp[i+1][j]);
           }

           //choose
           int l = i;
           int r = n;
           while(r-l>1){
                int mid = (l+r)/2;
                if(intervals[mid][0] > intervals[i][1]){
                    r = mid;
                }
                else l = mid;
           }     

           for(int j=1;j<=K; j++){
              x canuse;
                if(r<n) canuse = dp[r][j-1];
                else canuse = {0, vector<int>()};
              vector<int> indices = canuse.v;
              indices.push_back(intervals[i][3]);
              sort(indices.begin(), indices.end());

              x pos = {-intervals[i][2] + canuse.val, indices};
              dp[i][j] = min(dp[i][j], pos);  
           }
        }


        return dp[0][4].v;
    }
};