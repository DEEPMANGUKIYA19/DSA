 class Solution {
public:
    int findmaximum(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long function(vector<int>& piles, int mid)
    {
        long long totalho = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            totalho += ceil((double)piles[i] / (double)mid);
        }

        return totalho;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int hig = findmaximum(piles);

        while (low <= hig)
        {
            int mid = low + (hig - low) / 2;

            long long x = function(piles, mid);

            if (x > h)
            {
                low = mid + 1;
            }
            else
            {
                hig = mid - 1;
            }
        }

        return low;
    }
};