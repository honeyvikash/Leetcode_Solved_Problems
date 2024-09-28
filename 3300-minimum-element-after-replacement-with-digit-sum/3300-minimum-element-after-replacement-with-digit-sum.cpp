class Solution {
public:
    int minElement(vector<int>& nums) {
      int answer = INT_MAX;
      for(int i=0;i<nums.size(); i++){
        int sum = 0;
        int cp = nums[i];
        while(cp>0){
            sum+=cp%10;
            cp/=10;
        }
        answer = min(answer, sum);
      }   
      return answer; 
    }
};