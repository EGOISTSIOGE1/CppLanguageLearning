/*************************************************************************
	> File Name: 7.leetcode-2258.cpp
	> Author: TaoJY
	> Mail: taojy@toramon.com
	> Created Time: Thu 09 Nov 2023 08:51:22 AM CST
 ************************************************************************/

/**
 * 2258. 逃离火灾

给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，它表示一个网格图。每个格子为下面 3 个值之一：

0 表示草地。
1 表示着火的格子。
2 表示一座墙，你跟火都不能通过这个格子。
一开始你在最左上角的格子 (0, 0) ，你想要到达最右下角的安全屋格子 (m - 1, n - 1) 。每一分钟，你可以移动到 相邻 的草地格子。每次你移动 之后 ，着火的格子会扩散到所有不是墙的 相邻 格子。

请你返回你在初始位置可以停留的 最多 分钟数，且停留完这段时间后你还能安全到达安全屋。如果无法实现，请你返回 -1 。如果不管你在初始位置停留多久，你 总是 能到达安全屋，请你返回 109 。

注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。

如果两个格子有共同边，那么它们为 相邻 格子。

输入：grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
输出：3
解释：上图展示了你在初始位置停留 3 分钟后的情形。
你仍然可以安全到达安全屋。
停留超过 3 分钟会让你无法安全到达安全屋。

输入：grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
输出：-1
解释：上图展示了你马上开始朝安全屋移动的情形。
火会蔓延到你可以移动的所有格子，所以无法安全到达安全屋。
所以返回 -1 。

输入：grid = [[0,0,0],[2,2,0],[1,2,0]]
输出：1000000000
解释：上图展示了初始网格图。
注意，由于火被墙围了起来，所以无论如何你都能安全到达安全屋。
所以返回 10^9 。
 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<utility>

using namespace std;

class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        // 返回三个数，分别表示到达安全屋/安全屋左边/安全屋上边的最短时间
        auto bfs = [&](vector<pair<int, int>> &q) -> tuple<int, int, int> {
            vector<vector<int>> time(m, vector<int>(n, -1)); // -1 表示未访问
            for (auto &[i, j]: q) {
                time[i][j] = 0;
            }
            for (int t = 1; !q.empty(); t++) { // 每次循环向外扩展一圈
                vector<pair<int, int>> nq;
                for (auto &[i, j]: q) {
                    for (auto &[dx, dy]: dirs) { // 枚举上下左右四个方向
                        int x = i + dx, y = j + dy;
                        if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == 0 && time[x][y] < 0) {
                            time[x][y] = t;
                            nq.emplace_back(x, y);
                        }
                    }
                }
                q = move(nq);
            }
            return {time[m - 1][n - 1], time[m - 1][n - 2], time[m - 2][n - 1]};
        };

        vector<pair<int, int>> q = {{0, 0}};
        auto [man_to_house_time, m1, m2] = bfs(q);
        if (man_to_house_time < 0) { // 人无法到安全屋
            return -1;
        }

        vector<pair<int, int>> fire_pos;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire_pos.emplace_back(i, j);
                }
            }
        }
        auto [fire_to_house_time, f1, f2] = bfs(fire_pos); // 多个着火点同时跑 BFS
        if (fire_to_house_time < 0) { // 火无法到安全屋
            return 1'000'000'000;
        }

        int d = fire_to_house_time - man_to_house_time;
        if (d < 0) { // 火比人先到安全屋
            return -1;
        }

        if (m1 != -1 && m1 + d < f1 || // 安全屋左边相邻格子，人比火先到
            m2 != -1 && m2 + d < f2) { // 安全屋上边相邻格子，人比火先到
            return d; // 图中第一种情况
        }
        return d - 1; // 图中第二种情况
    }
};


int main() {
    vector<vector<int>> grid_ex_1 = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    vector<vector<int>> grid_ex_2 = {{0,0,0,0},{0,1,2,0},{0,2,0,0}};
    vector<vector<int>> grid_ex_3 = {{0,0,0},{2,2,0},{1,2,0}};

    Solution solu;
    cout << "grid_ex_1_result: " << solu.maximumMinutes(grid_ex_1) << endl;
    cout << "grid_ex_2_result: " << solu.maximumMinutes(grid_ex_2) << endl;
    cout << "grid_ex_3_result: " << solu.maximumMinutes(grid_ex_3) << endl;

    return 0;
}