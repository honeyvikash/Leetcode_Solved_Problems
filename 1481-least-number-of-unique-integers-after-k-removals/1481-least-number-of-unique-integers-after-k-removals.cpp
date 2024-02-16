class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
    unordered_map<int, int> mp;
    vector<pair<int, int>> v;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }

    // for (auto x : mp)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
    for (auto x : mp)
    {
        v.push_back({x.second, x.first});
    }
    sort(v.begin(), v.end());
    int sum = 0, cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i].first;
        if (sum > k)
        {
            break;
        }
        cnt++;
    }

    return v.size()-cnt;
        
    }
};