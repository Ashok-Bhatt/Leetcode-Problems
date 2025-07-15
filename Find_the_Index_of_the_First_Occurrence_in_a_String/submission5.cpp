class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int haySize = haystack.length();
        int needleSize = needle.length();

        int i=0;
        while (i<=(haySize-needleSize)){

            bool flag = true;
            int j=0;

            while (j<needleSize){
                if (haystack[i+j]!=needle[j]){
                    flag = false;
                    break;
                }
                j++;
            }

            if (flag==true){
                return i;
            }

            i++;
        }

        return -1;

    }
};