class Solution {
public:
    
    vector<int> slicing(vector<int> arr, int X, int Y)
    {
        auto start = arr.begin() + X;
        auto end = arr.begin() + Y + 1;
 
        vector<int> result(Y - X + 1);
 
        copy(start, end, result.begin());
        return result;
    }
    
    double medianOfTwo(int a, int b) {
        return (a + b) / 2.0;
    }
    
    double medianOfThree(int a, int b, int c) {
        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));
        return (a + b + c - mx - mn);
    }
    
    double medianOfFour(int a, int b, int c, int d) {
        int mx = max(a, max(b, max(c, d)));
        int mn = min(a, min(b, min(c, d)));
        return (a + b + c + d - mx - mn) / 2.0;
    }
    
    double medianSingle(vector<int> nums, int n) {
        if (n == 0) return -1;
        if (n % 2 == 0) {
            return (nums[n/2 - 1] + nums[n/2]) / 2.0;
        }
        return nums[n/2];
    }
    
    double getMedian(vector<int> nums1, int n, vector<int> nums2, int m) {
        if (n == 0) return medianSingle(nums2, m);
        else if (n == 1) {
            if (m == 1) return medianOfTwo(nums1[0], nums2[0]);
            else if (m % 2) {
                return medianOfFour(nums1[0], nums2[m/2 - 1], nums2[m/2], nums2[m/2 + 1]);
            }
            else {
                return medianOfThree(nums1[0], nums2[m/2 - 1], nums2[m/2]);
            }
        }
        else if (n == 2) {
            if (m == 2) {
                return medianOfFour(nums1[0], nums1[1], nums2[m/2 - 1], nums2[m/2]);
            }
            else if (m % 2) {
                return medianOfThree(nums2[m/2], max(nums1[0], nums2[m/2 - 1]), min(nums1[1], nums2[m/2 + 1]));
            }
            else {
                return medianOfFour(nums2[m/2], nums2[m/2 - 1], max(nums1[0], nums2[m/2 - 2]), min(nums1[1], nums2[m/2 + 1]));
            }
        }
        int i = (n - 1) / 2;
        int j = (m - 1) / 2;
        if (nums1[i] <= nums2[j]) {
            return getMedian(slicing(nums1, i, n - 1), n / 2 + 1, nums2, m - i);
        }
        return getMedian(nums1, n / 2 + 1, slicing(nums2, i, m - 1), m - i);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n < m) return getMedian(nums1, n, nums2, m);
        return getMedian(nums2, m, nums1, n);
    }
};