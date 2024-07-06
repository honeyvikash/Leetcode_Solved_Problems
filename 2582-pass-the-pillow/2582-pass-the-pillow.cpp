class Solution {
public:
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ll long long
#define all(a) (a).begin(), (a).end()
#define in insert
#define pb push_back
#define B break
#define C continue
#define F first
#define S second
    int passThePillow(int n, int t) {
        ll s=1; 
        ll p=1; 
        while(t--)
        { 
             if(s==n)p=-1; 
             if(s==1)p=1;
             s+=p; 
        } 
        return s; 
    }
};