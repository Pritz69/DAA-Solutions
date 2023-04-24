Problem Link :- https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

int f(int ind, int w, int* wt, int* vl, int** dp, int n)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
        {
            return vl[0];
        }
        return 0;
    }
    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int nottake = 0 + f(ind - 1, w, wt, vl, dp, n);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = vl[ind] + f(ind - 1, w - wt[ind], wt, vl, dp, n);
    }
    return dp[ind][w] = (take > nottake) ? take : nottake;
}

int knapsack(int* weight, int* value, int n, int maxWeight) 
{
    // Write your code here
    int** dp = (int**) malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int*) malloc(sizeof(int) * (maxWeight + 1));
        for (int j = 0; j < maxWeight + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    int result = f(n - 1, maxWeight, weight, value, dp, n);
    for (int i = 0; i < n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main()
{
    int weight[] = {10, 20, 30};
    int value[] = {60, 100, 120};
    int n = sizeof(value) / sizeof(value[0]);
    int maxWeight = 50;
    printf("Maximum value that can be obtained: %d", knapsack(weight, value, n, maxWeight));
    return 0;
}
