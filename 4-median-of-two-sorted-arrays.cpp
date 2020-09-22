class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n;
        for(int el : nums1){
            n.push_back(el);
        }
        for(int el : nums2){
            n.push_back(el);
        }
        sort(n.begin(), n.end());
        double ans = 0;
        if(n.size() % 2){
            ans = n[ n.size()/2 ];
        }
        else{
            ans = (double)(n[n.size()/2] + n[n.size()/2 - 1]) / 2;
            // ans = ans/2;
        }
        return ans;
    }
};
