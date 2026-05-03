#include<bits/stdc++.h>
using namespace std;

//Q: https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=SUBMISSION

//Refer: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/

// Recursive function to solve Ninja Training problem with memoization
// day: current day
// last: last activity performed (0, 1, 2 for activities, 3 for none)
// points: matrix of points for each activity per day
// dp: memoization table
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  // If the result for this day and last activity is already calculated, return it
  if (dp[day][last] != -1) return dp[day][last];

  // Base case: When we reach the first day (day == 0)
  // We need to select the activity with the maximum points, but not the one performed last
  if (day == 0) {
    int maxi = 0;
    // Try all activities except the last one
    for (int i = 0; i < 3; i++) {
      if (i != last) maxi = max(maxi, points[0][i]);
    }
    // Store and return the result for this state
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  // Try all activities for the current day except the one performed last
  for (int i = 0; i < 3; i++) {
    if (i != last) {
      // Recursively calculate the points for the current activity
      // and add it to the maximum points obtained so far
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }
  // Store and return the result for this state
  return dp[day][last] = maxi;
}

// Tabulation (bottom-up DP) approach
// n: number of days
// points: matrix of points for each activity per day
int ninjaTraining(int n, vector<vector<int>> &points) {
  // dp[day][last]: max points up to 'day' if last activity was 'last'
  // 'last' ranges from 0 to 3:
  // 0, 1, 2 represent the three activities
  // 3 represents 'no activity restriction' (used for initialization and final answer)
  // Why do we use 4 columns for 'last'?
  // Example:
  // Suppose points = {{1,2,3},{3,2,1},{2,1,3}}
  // On the first day, there is no previous activity, so 'last' = 3 (no restriction).
  // For each day, we want to know the best score if the previous day's activity was 0, 1, 2, or none (3).
  // This makes initialization and final answer uniform:
  // - Initialization: dp[0][3] means no restriction, so we take the max of all activities.
  // - Final answer: dp[n-1][3] gives the best possible score for the last day, regardless of what activity was done last.
  // This is why we need 4 columns, even though there are only 3 activities.
  vector<vector<int>> dp(n, vector<int>(4, -1));

  // Base case: Fill dp for day 0
  // For each possible 'last' activity, choose the best among the other two
  dp[0][0] = max(points[0][1], points[0][2]); // If last was 0, pick max of 1 or 2
  dp[0][1] = max(points[0][0], points[0][2]); // If last was 1, pick max of 0 or 2
  dp[0][2] = max(points[0][0], points[0][1]); // If last was 2, pick max of 0 or 1
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // If no last, pick max of all

  // Fill dp table for all days
  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      // Try all activities for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate points for this activity and add previous day's best
          int activity = points[day][task] + dp[day - 1][task];
x(points[0][1], points[0][2]);
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
  // Example: 3 days, 3 activities per day
  // points[i][j] = points for day i, activity j
  vector<vector<int>> points = {
    {1, 2, 3},   // Day 0: Activity 0 = 1, Activity 1 = 2, Activity 2 = 3
    {3, 2, 1},   // Day 1: Activity 0 = 3, Activity 1 = 2, Activity 2 = 1
    {2, 1, 3}    // Day 2: Activity 0 = 2, Activity 1 = 1, Activity 2 = 3
  };
  int n = points.size();
  cout << "Maximum points (Tabulation): " << ninjaTraining(n, points) << endl;
  // Output: Maximum points (Tabulation): 7
  // Explanation:
  // Day 0: Choose Activity 2 (3 points)
  // Day 1: Choose Activity 0 (3 points) [can't repeat Activity 2]
  // Day 2: Choose Activity 2 (3 points) [can't repeat Activity 0]
  // Total = 3 + 3 + 3 = 9, but since we can't repeat activities, the best path is 3 + 3 + 1 = 7
}