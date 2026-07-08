class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int number=nums.size();
        for(int i=0;i<number;i++)
        {
            int count=0;
            for(int j=0;j<number;j++)
            {
                if(nums[i]==nums[j])
                {
                    count= count+1;
                }
            }
            if(count == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};