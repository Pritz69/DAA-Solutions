#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a job
struct Job
{
    int deadline;
    int profit;
};

// Function to compare two jobs by profit
int cmp(const void* a, const void* b)
{
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the maximum profit and the number of jobs done.
int* JobScheduling(struct Job arr[], int n)
{
    // Sort jobs by profit in decreasing order
    qsort(arr, n, sizeof(struct Job), cmp);
    
    // Find the maximum deadline
    int maxdead = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > maxdead)
        {
            maxdead = arr[i].deadline;
        }
    }
    
    // Create array to keep track of deadlines
    int* dead = (int*)malloc(maxdead * sizeof(int));
    memset(dead, -1, maxdead * sizeof(int));
    
    // Schedule the jobs
    int count = 0;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {
            if (dead[j] == -1)
            {
                dead[j] = 1;
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    
    // Create result array
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = count;
    result[1] = profit;
    
    // Return result array
    return result;
}

// Driver code
int main()
{
    // Example usage
    struct Job arr[] = {{4, 70}, {1, 80}, {1, 30}, {1, 100}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int* result = JobScheduling(arr, n);
    
    printf("Number of jobs done: %d\n", result[0]);
    printf("Maximum profit: %d\n", result[1]);
    
    free(result);
    
    return 0;
}
