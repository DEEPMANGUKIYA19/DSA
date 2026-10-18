 class SummaryRanges
{
public:
    set<int> s;

    SummaryRanges() 
    {

    }

    void addNum(int value) 
    {
        s.insert(value);
    }

    vector<vector<int>> getIntervals()
     {
        vector<vector<int>> ans;

        for (int x : s) 
        {
            if (ans.empty() || ans.back()[1] + 1 < x)
            {
                ans.push_back({x, x});
            } else {
                ans.back()[1] = x;
            }
        }

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */