//Q. : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

/*
Intuition:
-----------
The multiplication table is sorted row-wise and column-wise, but too large
to flatten and sort.

We apply "binary search on the answer":
- The smallest possible value is 1
- The largest possible value is m * n

For any candidate value 'mid', we count how many numbers in the table
are <= mid. If at least k numbers are <= mid, then mid could be the answer,
otherwise mid is too small.

The key observation is that this count function is monotonic, which makes
binary search valid.
*/


/*
How counting works:
-------------------
Fix a row i (1-indexed).

Row i contains:
i*1, i*2, i*3, ..., i*n

We want to know how many values in this row are <= mid.

Condition:
i * col <= mid
=> col <= mid / i

So, the number of valid columns in this row is:
min(n, mid / i)

We sum this over all rows to get the total count of numbers <= mid.
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long count = 0;

            // Count how many numbers in the table are <= mid
            for (int i = 1; i <= m; i++) {
                // In row i, values are: i*1, i*2, ..., i*n
                // Count how many satisfy i*col <= mid
                count += min(n, mid / i);
            }

            // If we have at least k numbers <= mid,
            // mid is a valid candidate, try smaller values
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, mid is too small
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
