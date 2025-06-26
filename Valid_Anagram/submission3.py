class Solution(object):
    def isAnagram(self, s, t):
        
        occurance = defaultdict(int)
        
        for i in s:
            occurance[i] += 1
        
        for i in t:
            occurance[i] -= 1
            
        for item in occurance.values():
            if (item!=0):
                return False
        
        return True