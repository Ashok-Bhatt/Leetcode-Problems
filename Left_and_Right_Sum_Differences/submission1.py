class Solution(object):
    def leftRightDifference(self, nums):
        
        left = 0
        right = 0
        n = len(nums)

        # Setting the value for right part
        for i in range(1,n):
            right += nums[i]
        
        # Placing the answers at repestive indices in array
        for i in range(n):
            element = nums[i]
            nums[i] = abs(left-right)
            left += element
            if (i != n-1):
                right -= nums[i+1]
        
        return nums