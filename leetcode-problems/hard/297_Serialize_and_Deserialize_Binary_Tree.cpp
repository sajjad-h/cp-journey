/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "NULL";
        string leftPart = serialize(root->left);
        string rightPart = serialize(root->right);
        return to_string(root->val) + "[" + leftPart + "," + rightPart + "]";
    }

    int isDigit(char ch) {
        if (ch >= '0' && ch <= '9') return 1;
        return 0;
    }

    int findMiddleComma(string data) {
        int countBraces = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '[')      countBraces++;
            else if (data[i] == ']') countBraces--;
            else if (data[i] == ',') {
                if (countBraces == 0) return i;
            }
        }
        assert(false);
        return -1;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "NULL") return NULL;
        int val = 0;
        int i = 0;
        int sign = 1;
        if (data[0] == '-') {
            sign = -1;
            i = 1;
        }
        while (i < data.size() && isDigit(data[i])) {
            val = val * 10 + (data[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode();
        root->val = val * sign;
        int searchingComma = findMiddleComma(data.substr(i + 1, data.size() - 2 - i));
        root->left = deserialize(data.substr(i + 1, searchingComma));
        root->right = deserialize(data.substr(i + 1 + searchingComma + 1, data.size() - 2 - i - 1 - searchingComma));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));