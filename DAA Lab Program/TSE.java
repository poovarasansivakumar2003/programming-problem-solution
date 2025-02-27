import java.util.Scanner;

public class TSE {
    static int n = 4;
    static int MAX = 1000000;
    static int[][] dist = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 15, 20},
        {0, 10, 0, 25, 25},
        {0, 15, 25, 0, 30},
        {0, 20, 25, 30, 0}
    };
    static int[][] memo = new int[n + 1][1 << (n + 1)];

    static int fun(int i, int mask) {
        if (mask == ((1 << i) | 3)) // 3 means the first two cities are visited
            return dist[1][i]; // Return the distance from city 1 to city i

        if (memo[i][mask] != 0)
            return memo[i][mask];

        int res = MAX; // Initialize result for this sub-problem
        for (int j = 1; j <= n; j++) {
            if ((mask & (1 << j)) != 0 && j != i && j != 1) { // Check if j is visited and not the starting city
                res = Math.min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);
            }
        }
        return memo[i][mask] = res;
    }

    public static void main(String[] args) {
        int ans = MAX;
        for (int i = 1; i <= n; i++) {
            ans = Math.min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);
        }
        System.out.println("The cost of the most efficient tour = " + ans);
    }
}
