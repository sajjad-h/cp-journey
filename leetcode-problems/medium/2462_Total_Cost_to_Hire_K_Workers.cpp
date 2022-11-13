class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        set<pair<int, int>> leftPart, rightPart;
        vector<int> used(n, 0);
        for (int i = 0; i < candidates; i++) {
            leftPart.insert({costs[i], i});
        }
        for (int j = n - candidates; j < n; j++) {
            rightPart.insert({costs[j], j});
        }
        long long int ans = 0;
        int i = candidates;
        int j = n - candidates - 1;
        while (k--) {
            auto [leftVal, leftIndex] = *leftPart.begin();
            auto [rightVal, rightIndex] = *rightPart.begin();
            if (leftVal < rightVal || (leftVal == rightVal && leftIndex <= rightIndex)) {
                ans += leftVal;
                used[leftIndex] = 1;
                while (i < n && used[i] == 1) i++;
                if (i < n) {
                    leftPart.insert({costs[i], i});
                    i++;
                }
                leftPart.erase({leftVal, leftIndex});
                if (rightPart.find({leftVal, leftIndex}) != rightPart.end()) {
                    rightPart.erase({leftVal, leftIndex});
                    while (j >= 0 && used[j] == 1) j--;
                    if (j >= 0) {
                        rightPart.insert({costs[j], j});
                        j--;
                    }
                }
            }
            else if (leftVal > rightVal || (leftVal == rightVal && leftIndex >= rightIndex)) {
                ans += rightVal;
                used[rightIndex] = 1;
                while (j >= 0 && used[j] == 1) j--;
                if (j >= 0) {
                    rightPart.insert({costs[j], j});
                    j--;
                }
                rightPart.erase({rightVal, rightIndex});
                if (leftPart.find({rightVal, rightIndex}) != leftPart.end()) {
                    leftPart.erase({rightVal, rightIndex});
                    while (i < n && used[i] == 1) i++;
                    if (i < n) {
                        leftPart.insert({costs[i], i});
                        i++;
                    }
                }
            }
            else {
                assert(false);
            }
        }
        return ans;
    }
};