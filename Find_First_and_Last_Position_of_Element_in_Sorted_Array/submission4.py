class Solution(object):

    def lower_bound(self, nums, target):

        ans = -1
        s = 0
        e = len(nums)-1

        while s<=e:
            mid = s + (e-s)//2
            if (nums[mid] >= target):
                ans = mid
                e = mid - 1
            else:
                s = mid + 1
        
        return ans

    
    def upper_bound(self, nums, target):

        ans = len(nums)
        s = 0
        e = len(nums)-1

        while s<=e:
            mid = s + (e-s)//2
            if (nums[mid] > target):
                ans = mid
                e = mid - 1
            else:
                s = mid + 1
        
        return ans


    def searchRange(self, nums, target):
        
        lower = self.lower_bound(nums, target)
        higher = self.upper_bound(nums, target)

        if lower==-1 or nums[lower]!=target:
            return [-1,-1]
        return [lower, higher-1]