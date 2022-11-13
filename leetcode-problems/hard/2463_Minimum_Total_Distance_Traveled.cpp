class Solution {
public:
    long long int inf = 1e15;
    long long solve(int robot_at, int taken_from_factory, int factory_at, vector<int>& robot, vector<vector<int>>& factory, vector<vector<vector<long long>>>& dp) {
        if (robot_at == robot.size()) return 0;
        if (factory_at == factory.size()) return inf;
        if (dp[robot_at][taken_from_factory][factory_at] != -1) return dp[robot_at][taken_from_factory][factory_at];
        long long ans = solve(robot_at, 0, factory_at + 1, robot, factory, dp);
        if (taken_from_factory + 1 <= factory[factory_at][1]) {
            ans = min(ans, abs(factory[factory_at][0] - robot[robot_at]) + solve(robot_at + 1, taken_from_factory + 1, factory_at, robot, factory, dp));
            ans = min(ans, abs(factory[factory_at][0] - robot[robot_at]) + solve(robot_at + 1, 0, factory_at + 1, robot, factory, dp));
        }
        return dp[robot_at][taken_from_factory][factory_at] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<vector<vector<long long>>> dp = vector<vector<vector<long long>>>(robot.size(), vector<vector<long long>>(robot.size(), vector<long long>(factory.size(), -1)));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        return solve(0, 0, 0, robot, factory, dp);
    }
};