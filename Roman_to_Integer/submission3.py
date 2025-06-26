class Solution(object):
    def romanToInt(self, s):
        
        i = 0
        ans = 0

        integer_values = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

        while (i < len(s)):
            if ((i!=len(s)-1)  and  ((s[i]=="I" and (s[i+1]=="V" or s[i+1]=="X"))  or  (s[i]=="X" and (s[i+1]=="L" or s[i+1]=="C"))  or  (s[i]=="C" and (s[i+1]=="D" or s[i+1]=="M")))):
                ans += integer_values[s[i+1]] - integer_values[s[i]]
                i += 2
            else:
                ans += integer_values[s[i]]
                i += 1
        
        return ans