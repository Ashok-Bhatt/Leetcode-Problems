class Solution(object):
    def searchRange(self, nums, target):
        
        first = -1
        last = -1

        for index, num in enumerate(nums):
            if num == target:
                if first == -1:
                    first = index
                last = index
        
        return [first, last]