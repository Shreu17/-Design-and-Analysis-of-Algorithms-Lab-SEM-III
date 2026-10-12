#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int n;
int cost[20][20];
int dp[1 << 20][20];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        if (cost[pos][0] != -1) {
            return cost[pos][0];
        }
        return INF;
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int min_cost = INF;

    for (int next_city = 0; next_city < n; next_city++) {
        if ((mask & (1 << next_city)) == 0 && cost[pos][next_city] != -1) {
            int new_cost = cost[pos][next_city] + tsp(mask | (1 << next_city), next_city);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }

    return dp[mask][pos] = min_cost;
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);

    if (result >= INF) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
