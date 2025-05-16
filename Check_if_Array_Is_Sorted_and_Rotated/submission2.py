class Solution(object):
    def check(self, nums):
        
        mark = 0
        n = len(nums)
        for i in range(n):
            if (nums[(i+1)%n] < nums[i]):
                mark += 1
        
        if (mark<=1):
            return True
        return False