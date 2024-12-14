class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        long long ans = 0; 
        int ws = 0, we = 0; 
        map<int, int> mp;

        while (we < nums.size())
        {
            mp[nums[we]] += 1;
            
            while (!mp.empty() && (mp.rbegin()->first - mp.begin()->first > 2))
            {
                mp[nums[ws]] -= 1; 
                if (mp[nums[ws]] == 0)      mp.erase(nums[ws]);
                
                ws += 1; 
            }

      
            ans += (we - ws + 1);
            we += 1; 
        }

        return ans;
    }
};
