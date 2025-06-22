class Solution(object):
    def moveZeroes(self, nums):
        
        zeroIndex = 0
        
        for index, element in enumerate(nums):
            nums[zeroIndex], nums[index] =  nums[index], nums[zeroIndex]
            
            if (nums[zeroIndex]):
                zeroIndex += 1
                