class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache
        def rec(i):
            if i==0:
                return nums[i]
            if i<0:
                return 0
            pick = nums[i] + rec(i-2)
            not_pick = 0 + rec(i-1)
            return max(pick,not_pick)
        
        return rec(len(nums)-1)

    #sumitted by Vibhor chutiya