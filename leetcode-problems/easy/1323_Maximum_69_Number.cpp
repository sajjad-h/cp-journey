class Solution {
public:

    string numberToString(int num) {
        string res = "";
        while (num != 0) {
            res.push_back(char((num % 10) + '0'));
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int stringToNumber(string data) {
        int num = 0;
        for (int i = 0; i < data.size(); i++) {
            int x = data[i] - '0';
            num = num * 10 + x;
        }
        return num;
    }

    int maximum69Number (int num) {
        string data = numberToString(num);
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '6') {
                data[i] = '9';
                break;
            }
        }
        int ans = stringToNumber(data);
        return ans;
    }
};