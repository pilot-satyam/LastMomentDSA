#include<bits/stdc++.h>
using namespace std;

//Q: https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=SUBMISSION

//Refer: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/

int f(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    // If the result for this day and last activity is already calculated, return it
    if(dp[day][last]!=-1) return dp[day][last];

    // Base case: When we reach the first day (day == 0)
    if(day == 0){
    int maxi = 0;
    // Calculate the maximum points for the first day by choosing an activity
    // different from the last one
        for(int i=0;i<3;i++){
            if(i != last) maxi = max(maxi,points[0][i]);
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    //iterating through the activites of current day
    for(int i=0;i<3;i++){
        if(i != last){
        // Calculate the points for the current activity and add it to the
        // maximum points obtained so far (recursively calculated)
        int activity = points[day][i] + f(day-1,i,points,dp);
        maxi = max(maxi,activity);
        }
    }
    return dp[day][last] = maxi;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    // return f(n-1,3,points,dp); ===> Recurscive approach
    
  // Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  //iterating through day1
  for(int day=1;day<n;day++){
    for(int last=0;last<4;last++){
        //iterating through task for day1
        for(int task=0;task<=2;task++){
            if(task!=last){
            // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (recursively calculated)
          int activity = points[day][task] + dp[day - 1][task];
          // Update the maximum points for the current day and last activity
          dp[day][last] = max(dp[day][last], activity);
            }
        }
    }
  }
  return dp[n-1][3];
}


//space optimized

int ninjaTraining(int n, vector<vector<int>>& points) {
  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    // Create a temporary vector to store the maximum points for the current day's activities
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (stored in prev)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    // Update prev with the maximum points for the current day
    prev = temp;
  }

  // The maximum points for the last day with any activity can be found in prev[3]
  return prev[3];
}

int main(){

}