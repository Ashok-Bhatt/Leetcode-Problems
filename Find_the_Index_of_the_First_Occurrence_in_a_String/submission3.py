class Solution(object):
    def strStr(self, haystack, needle):
        
        space = len(haystack) - len(needle) + 1
        for i in range(space):
            if (haystack[i:i+len(needle)] == needle):
                return i
        
        return -1
        