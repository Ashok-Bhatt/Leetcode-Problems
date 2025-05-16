class Solution(object):
    def runningSum(self, nums):
        
        sum = 0
        ans = []

        for num in nums:
            sum += num
            ans.append(sum)

        return ans