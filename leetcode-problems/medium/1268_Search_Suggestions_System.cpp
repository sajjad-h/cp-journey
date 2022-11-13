class Solution {

public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> answer;
        int okay = 1;
        for (int i = 0; i < searchWord.size(); i++) {
            vector<string> tmp_ans;
            if (!okay) {
                answer.push_back(tmp_ans);
                continue;
            }
            int lo = 0;
            int hi = products.size() - 1;
            int ans_lo = hi + 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (products[mid][i] == searchWord[i]) {
                    ans_lo = min(ans_lo, mid);
                    hi = mid - 1;
                }
                else if (products[mid][i] < searchWord[i]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            if (ans_lo == products.size()) {
                answer.push_back(tmp_ans);
                okay = 0;
                continue;
            }
            lo = ans_lo;
            hi = products.size() - 1;
            int ans_ho = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (products[mid][i] == searchWord[i]) {
                    ans_ho = max(ans_ho, mid);
                    lo = mid + 1;
                }
                else if (products[mid][i] < searchWord[i]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            for (int j = 0; j < 3 && ans_lo + j <= ans_ho; j++) {
                tmp_ans.push_back(products[ans_lo + j]);
            }
            answer.push_back(tmp_ans);
            vector<string> tmps;
            for (int j = ans_lo; j <= ans_ho; j++) {
                if (products[j].size() <= i) continue;
                tmps.push_back(products[j]);
            }
            products = tmps;
        }
        return answer;
    }
};