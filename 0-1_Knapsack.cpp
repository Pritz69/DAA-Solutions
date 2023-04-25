#include <bits/stdc++.h> 
int f(int ind,int w,vector<int> &wt,vector<int> &vl,vector<vector<int>>&dp)
{
	if (ind==0)
	{
		if (wt[0]<=w)
		{
			return vl[0];
		}
		return 0;
	}
	if (dp[ind][w]!=-1)
	{
		return dp[ind][w];
	}
	int nottake = 0 + f(ind-1,w,wt,vl,dp);
	int take=INT_MIN ;
	if (wt[ind]<=w)
	{
		take = vl[ind] + f(ind-1,w-wt[ind],wt,vl,dp);
	}
	return dp[ind][w] = max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}
