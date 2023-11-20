#include <string>
#include <vector>
#include <algorithm>

int stringConstruction(const std::string& target, int cloneCost, int appendCost) {
    int n = target.size();
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + appendCost;  // Cost of appending character

        for (int j = i - 1; j >= 0; --j) {
            std::string sub = target.substr(j, i - j);
            int cost = cloneCost;

            if (j > 0) {
                cost += dp[j - 1];  // Cost of cloning substring and appending
            }

            if (sub.size() >= 2 && std::count(sub.begin(), sub.end(), sub[0]) == sub.size()) {
                // If the substring is repeated characters, reduce the cost
                cost = std::min(cost, appendCost);
            }

            dp[i] = std::min(dp[i], cost);
        }
    }

    return dp[n];
}
