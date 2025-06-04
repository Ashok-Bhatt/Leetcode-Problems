class Solution(object):
    def search(self, arr, target):
        
        s = 0
        e = len(arr) - 1

        while s<=e:
            mid = s + (e-s)//2
            if arr[mid] == target:
                return mid
            elif arr[s] <= arr[mid]:
                if target>=arr[s] and target<=arr[mid]:
                    e = mid - 1
                else:
                    s = mid + 1
            else:
                if target>=arr[mid] and target<=arr[e]:
                    s = mid + 1
                else:
                    e = mid - 1
        
        return -1