class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
        Arrays.sort(arr,(a,b)->(b.profit-a.profit));
        int maxdead=0;
        for (int i=0;i<n;i++)
        {
            maxdead=Math.max(maxdead,arr[i].deadline);
        }
        int dead[]=new int[maxdead];
        Arrays.fill(dead,-1);
        int count=0;
        int profit=0;
        for (int i=0;i<n;i++)
        {
            for (int j=arr[i].deadline-1;j>=0;j--)
            {
                if (dead[j]==-1)
                {
                    dead[j]=1;
                    count +=1;
                    profit +=arr[i].profit;
                    break;
                }
            }
        }
        int result[]=new int[2];
        result[0]=count;
        result[1]=profit;
        return result;
    }
}

/*
class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}
