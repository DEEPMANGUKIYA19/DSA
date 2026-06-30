class Solution {
public:
    int maxifunction(vector<int> &weights)
    {
        int maxi=0;
        for(int i=0;i<=weights.size()-1;i++)
        {
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }
    int sumofweight(vector<int> &weights)
    {
        int sum=0;
        for(int i=0;i<=weights.size()-1;i++)
        {
            sum=sum+weights[i];
        }
        return sum;
    }
    int function(vector<int> &weights,int mid)
    {
         int day=1;
        int load=0;
    for(int i=0;i<=weights.size()-1;i++)
     {
        
        if(load+weights[i]>mid)
        {
            day=day+1;
            load=weights[i];
        }
        else
        {
            load=load+weights[i];
        }
      
     }
         return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int  low=maxifunction(weights);
        int hig=sumofweight(weights);


        while(low<=hig)
        {
            int mid=low+(hig-low)/2;

            int value=function(weights,mid);

            if(value<=days)
            {
                hig=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};