class SummaryRanges {
public:
    map<int,int>mpp ;
    SummaryRanges() {
        mpp.clear() ;
    }
    
    void addNum(int value) {
        int left = value ;
        int right = value ;

        auto justBada = mpp.upper_bound(value) ;
        if(justBada!=mpp.begin())
        {
            auto justPeeche = justBada ;
            justPeeche-- ;

            if(justPeeche->second >=value) return ;

            if(justPeeche->second == value-1)
            {
                left = justPeeche->first ;
            }
        }

        if(justBada->first ==value+1)
        {
            right = justBada->second;
            mpp.erase(justBada->first);
        }

        mpp[left]=right ;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res ;
        for(auto it : mpp)
        {
            res.push_back({it.first,it.second}) ;
        }
        return res ;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */