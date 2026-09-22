// Q : https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18 

/**
 * The angle between the hour and minute hands of a clock can be calculated using the following steps:
 * 1. Calculate the angle of the minute hand from 12 o'clock:
 *   - The minute hand moves 360 degrees in 60 minutes, so it moves
 *   6 degrees per minute. Therefore, the angle of the minute hand can be calculated as:
 *    minuteAngle = minutes * 6
 * 2. Calculate the angle of the hour hand from 12 o'clock:
 *  - The hour hand moves 360 degrees in 12 hours, so it moves
 * 30 degrees per hour. Additionally, the hour hand also moves as the minutes pass, so it moves 0.5 (30 / 60) degrees per minute. Therefore, the angle of the hour hand can be calculated as:
 *  hourAngle = (hour % 12) * 30 + (minutes * 0.5)
 * 3. Calculate the absolute difference between the two angles:
 * diff = abs(hourAngle - minuteAngle)
 * 4. Return the minimum of the difference and the complement of the difference (to get the smaller angle):
 * return min(diff, 360 - diff)
 */

#include<bitstd/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourHand = (hour % 12) * 30.0 + (0.5 * minutes); 
        double diff = abs(hourHand - minuteAngle);
        return min(diff, 360.0 - diff);
    }
};

int main(){
    Solution sol;
    int hour1 = 3, minutes1 = 30;
    cout << "Angle between " << hour1 << " and " << minutes1 << " is: " << sol.angleClock(hour1, minutes1) << endl; // Expected output: 75.0

    int hour2 = 12, minutes2 = 0;
    cout << "Angle between " << hour2 << " and " << minutes2 << " is: " << sol.angleClock(hour2, minutes2) << endl; // Expected output: 0.0

    int hour3 = 9, minutes3 = 0;
    cout << "Angle between " << hour3 << " and " << minutes3 << " is: " << sol.angleClock(hour3, minutes3) << endl; // Expected output: 90.0

     return 0;
}