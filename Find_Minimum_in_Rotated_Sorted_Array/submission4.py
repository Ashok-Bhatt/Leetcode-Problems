class Solution(object):
    def findMin(self, nums):
        
        low = 0
        high = len(nums) - 1
        n = len(nums)
        ans = nums[0]

        while low<=high:
            mid = low + (high-low)//2
            if nums[mid] < nums[(mid+n-1)%n] and nums[mid] < nums[(mid+n+1)%n]:
                ans = nums[mid]
                break
            elif nums[mid] >= nums[0]:
                low = mid + 1
            else:
                high = mid - 1
        
        return ans