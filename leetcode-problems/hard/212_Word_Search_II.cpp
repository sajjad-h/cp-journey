class Solution {

struct node {
    int end;
    node* child[26];

    node() {
        end = -1;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };

public:

    set<string> resultSet;

    void Insert(node* root, string s, int ind) {
        node* curNode = root;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (curNode->child[x] == NULL) {
                curNode->child[x] = new node();
            }
            curNode = curNode->child[x];
        }
        curNode->end = ind;
    }

    int isEmpty(node* curNode) {
        for (int i = 0; i < 26; i++) {
            if (curNode->child[i] != NULL) return 0;
        }
        return 1;
    }

    int Remove(node* curNode, string s) {
        if (s.size() == 0) {
            return isEmpty(curNode);
        }
        int x = s[0] - 'a';
        if (Remove(curNode->child[x], s.substr(1, s.size() - 1))) {
            curNode->child[x] = NULL;
            return isEmpty(curNode);
        }
        return 0;
    }

    void solve(node* root, node* curNode, int x, int y, string word, vector<vector<char>>& board, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == ' ') return ;
        int next = board[x][y] - 'a';
        if (curNode->child[next] != NULL) {
            curNode = curNode->child[next];
            word = word + board[x][y];
            if (curNode->end != -1) {
                Remove(root, word);
                resultSet.insert(word);
            }
            char ch = board[x][y];
            board[x][y] = ' ';
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                solve(root, curNode, tx, ty, word, board, n, m);
            }
            board[x][y] = ch;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root = new node();
        for (int i = 0; i < words.size(); i++) {
            Insert(root, words[i], i);
        }
        int n = board.size();
        int m = board[0].size();
        resultSet.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(root, root, i, j, "", board, n, m);
            }
        }
        vector<string> ans;
        for (auto word : resultSet) {
            ans.push_back(word);
        }
        return ans;
    }
};