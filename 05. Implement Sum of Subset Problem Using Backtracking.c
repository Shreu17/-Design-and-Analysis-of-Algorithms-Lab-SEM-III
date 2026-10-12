#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_SOLUTIONS 1048576 // 2^20 maximum possible subsets

// Structure to store all found subsets
int solutions[MAX_SOLUTIONS][MAX_N];
int solution_sizes[MAX_SOLUTIONS];
int total_solutions = 0;

// Global variables for problem state
int elements[MAX_N];
int n;
int target_sum;

// Temporal buffer to store the current subset path during recursion
int current_path[MAX_N];
int path_size = 0;

void backtrack(int index, int current_sum) {
    // Base Case: If running sum matches target sum, save this subset
    if (current_sum == target_sum) {
        solution_sizes[total_solutions] = path_size;
        for (int i = 0; i < path_size; i++) {
            solutions[total_solutions][i] = current_path[i];
        }
        total_solutions++;
        return; // Since elements >= 1, no need to process further elements
    }

    // Pruning: Out of bounds or exceeded target sum
    if (index == n || current_sum > target_sum) {
        return;
    }

    // 1. Include the current element
    current_path[path_size++] = elements[index];
    backtrack(index + 1, current_sum + elements[index]);
    path_size--; // Backtrack step

    // 2. Exclude the current element
    backtrack(index + 1, current_sum);
}

int main() {
    // Read input format
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &elements[i]) != 1) return 0;
    }
    
    if (scanf("%d", &target_sum) != 1) return 0;

    // Start backtracking from index 0 with a starting sum of 0
    backtrack(0, 0);

    // If no subsets were saved, print -1
    if (total_solutions == 0) {
        printf("-1\n");
    } else {
        // Print the subsets in reverse order of discovery
        for (int i = total_solutions - 1; i >= 0; i--) {
            for (int j = 0; j < solution_sizes[i]; j++) {
                // Print a space after every element to match "2·1·" format
                printf("%d ", solutions[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

