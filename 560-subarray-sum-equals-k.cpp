class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int count = 0;
        hash[0] = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(hash.count(sum-k))
                count += hash[sum-k];
            hash[sum]++;
        }
        return count;
    }
};
