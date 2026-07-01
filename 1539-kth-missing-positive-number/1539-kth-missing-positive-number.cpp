class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int hig=arr.size()-1;

        while(low<=hig)
        {
            int mid=low+(hig-low)/2;

            int missingnumber=arr[mid]-(mid+1);
            if(missingnumber<k)
            {
                low=mid+1;
            }
            else
            {
                hig=mid-1;
            }
        }
        return hig+k+1;
    }
};