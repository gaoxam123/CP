// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
#include <bits/stdc++.h>
using namespace std;;
class Solution {
public:
    int dp[50005], n;
    pair <pair <int, int>, int> a[50005];
    static bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
        return x.first.second < y.first.second;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        for(int i = 1; i <= n; i ++) {
            a[i].first.first = startTime[i - 1];
            a[i].first.second = endTime[i - 1];
            a[i].second = profit[i - 1];
        }
        sort(a + 1, a + n + 1, cmp);
        dp[1] = a[1].second;
        for(int i = 2; i <= n; i ++) {
            dp[i] = dp[i - 1];
            for(int j = i - 1; j >= 0; j --) {
                if(a[j].first.second <= a[i].first.first) {
                    dp[i] = max(dp[i], dp[j] + a[i].second);
                    break;
                }
            }
        }
        return dp[n];
    }
};