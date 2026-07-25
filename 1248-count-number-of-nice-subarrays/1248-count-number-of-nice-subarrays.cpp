 class Solution {
public:
    int fun(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int l = 0, r = 0;
        int sum = 0;
        int cnt = 0;

        while (r < nums.size()) {
            sum += (nums[r] % 2);

            while (sum > goal) {
                sum -= (nums[l] % 2);
                l = l + 1;
            }

            cnt = cnt + (r - l + 1);
            r = r + 1;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};