https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <stdio.h> 
#include <limits.h>

int f(int i, int j, int arr[], int dp[][100]) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int mini = INT_MAX;
    for (int k = i; k < j; k++) {
        int steps = arr[i-1] * arr[j] * arr[k] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        if (steps < mini) {
            mini = steps;
        }
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int arr[], int N) {
    int dp[100][100];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = -1;
        }
    }
    return f(1, N-1, arr, dp);
}

int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int N = sizeof(arr)/sizeof(arr[0]);
    int result = matrixMultiplication(arr, N);
    printf("%d\n", result);
    return 0;
}
