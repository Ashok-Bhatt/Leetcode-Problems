class Solution(object):
    def moveZeroes(self, nums):
        
        i = 0
        j = 0

        while i<len(nums) and j<len(nums):

            while (j<len(nums) and nums[j]==0):
                j += 1
            
            if (j<len(nums)):
                nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j += 1
        
