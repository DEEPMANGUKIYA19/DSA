 class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorResult = 0;

        for (int number : nums) {
            xorResult ^= number;
        }

        long long distinguishingBit = xorResult & (-xorResult);

        int uniqueNumber1 = 0;
        int uniqueNumber2 = 0;

        for (int number : nums) {
            if (number & distinguishingBit)
                uniqueNumber1 ^= number;
            else
                uniqueNumber2 ^= number;
        }

        return {uniqueNumber1, uniqueNumber2};
    }
};