class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, x = 0, ans = 0;
        unordered_map<int, int> occurrence;

        while (i<n){

            if (j<n){
                occurrence[nums[j]]++;
                j++;
                x = max(j, x);
            } else if (occurrence.size() < k){
                break;
            }

            if (occurrence.size() == k){
                while (x<n && occurrence.find(nums[x])!=occurrence.end()){
                    x++;
                }

                ans = ans + x - j + 1;

                while (occurrence.size() == k){
                    occurrence[nums[i]]--;
                    if (occurrence[nums[i]] == 0){
                        occurrence.erase(nums[i]);
                    }
                    if (occurrence.size() == k){
                        ans = ans + x - j + 1;
                    }
                    i++;
                }
            }
        }

        return ans;

    }
};