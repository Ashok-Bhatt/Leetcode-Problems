class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), temp = 0, firstParityBit = 1, first = 0, second = 0;

        for (int i=0; i<n; i++){
            temp = temp ^ nums[i];
        }

        while (!(temp & firstParityBit)){
            firstParityBit = firstParityBit<<1;
        }

        for (int i=0; i<n; i++){
            if (firstParityBit & nums[i]){
                first = first ^ nums[i];
            } else {
                second = second ^ nums[i];
            }
        }

        vector<int> ans = {first, second};
        return ans;
    }
};