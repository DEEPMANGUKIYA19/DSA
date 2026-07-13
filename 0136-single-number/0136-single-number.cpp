 class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int number = nums.size();
        int ans = 0;

        for(int i = 0; i < number; i++)
        {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};