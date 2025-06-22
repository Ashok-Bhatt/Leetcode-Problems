class Solution(object):
    def removeDuplicates(self, nums):
        
        i = 0
        j = 0
        ans = 0

        while j < len(nums):
            element = nums[j]
            nums[i],nums[j] = nums[j],nums[i]
            ans += 1
            j += 1
            while (j<len(nums) and element==nums[j]):
                j += 1
            i += 1

        return ans