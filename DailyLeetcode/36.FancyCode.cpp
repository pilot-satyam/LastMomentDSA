#include<bitstd++.h>
using namespace std;

/*
====================================================================
Fancy Sequence - Optimized Approach (Lazy Affine Transformation)
====================================================================

We want to support these operations efficiently:

append(val)
addAll(inc)
multAll(m)
getIndex(idx)

--------------------------------------------------
Why naive solution fails
--------------------------------------------------

If we update every element for addAll and multAll:

addAll  -> O(n)
multAll -> O(n)

But operations ≤ 1e5

Worst case:
100000 operations * 100000 array size = 10^10 operations ❌

So we must avoid updating every element.

--------------------------------------------------
Key Idea
--------------------------------------------------

Observe that every operation can be represented as a formula:

    value = stored_value * mul + add

Where:
mul → global multiplication factor
add → global addition factor

Instead of modifying elements in the array,
we modify only these two variables.

--------------------------------------------------
Example To Derive Formulas
--------------------------------------------------

Start with operations:

append(2)
append(3)
addAll(5)
multAll(2)

Naive result:

[2,3]
addAll(5) → [7,8]
multAll(2) → [14,16]

Let's derive mathematically.

Take value x.

Step 1:
append(x)

Step 2:
addAll(5)

    x + 5

Step 3:
multAll(2)

    (x + 5) * 2
    = 2x + 10

This fits the form:

    value = x * mul + add

Where:

    mul = 2
    add = 10

--------------------------------------------------
Deriving addAll Formula
--------------------------------------------------

Suppose current transformation is:

    value = x * mul + add

Now we call:

    addAll(inc)

New value:

    value = (x * mul + add) + inc
          = x * mul + (add + inc)

So:

    add = add + inc

--------------------------------------------------
Deriving multAll Formula
--------------------------------------------------

Current transformation:

    value = x * mul + add

Now apply:

    multAll(m)

New value:

    value = (x * mul + add) * m
          = x * (mul * m) + add * m

So:

    mul = mul * m
    add = add * m

--------------------------------------------------
Deriving append Formula
--------------------------------------------------

Current transformation:

    value = stored * mul + add

Suppose we append:

    append(10)

But if we store 10 directly:

Real value becomes:

    10 * mul + add

Which is wrong.

We want final value to be exactly 10.

So we reverse the transformation.

Solve:

    10 = stored * mul + add

Subtract add:

    10 - add = stored * mul

Divide by mul:

    stored = (10 - add) / mul

Since we use modulo arithmetic:

    stored = (val - add) * modInverse(mul)

--------------------------------------------------
Example Walkthrough
--------------------------------------------------

Start:

mul = 1
add = 0

append(2)

stored = (2 - 0) / 1 = 2

arr = [2]

Actual value:

2*1 + 0 = 2

--------------------------------------------------

addAll(3)

mul = 1
add = 3

arr = [2]

Actual value:

2*1 + 3 = 5

--------------------------------------------------

multAll(2)

mul = 2
add = 6

arr = [2]

Actual value:

2*2 + 6 = 10

--------------------------------------------------

So we never changed the array.

But the visible value changed from:

2 → 5 → 10

--------------------------------------------------
getIndex(idx)

We reconstruct value using:

    value = stored * mul + add

--------------------------------------------------

Time Complexity

append   → O(log MOD) (mod inverse)
addAll   → O(1)
multAll  → O(1)
getIndex → O(1)

Space Complexity: O(n)

====================================================================
*/

class Fancy {
public:

    const long long MOD = 1e9 + 7;

    vector<long long> arr;

    long long mul = 1;
    long long add = 0;

    Fancy() {}

    // Fast power to compute modular inverse
    long long modInverse(long long x) {
        long long power = MOD - 2;
        long long result = 1;

        while(power > 0) {
            if(power & 1)
                result = (result * x) % MOD;

            x = (x * x) % MOD;
            power >>= 1;
        }

        return result;
    }

    void append(int val) {
        long long stored = (val - add + MOD) % MOD;
        stored = (stored * modInverse(mul)) % MOD;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {

        if(idx >= arr.size())
            return -1;

        return (arr[idx] * mul + add) % MOD;
    }
};

//My version ===> only 2 T.C were failing due to TLE 
// class Fancy {    
// public:
//     vector<long long> ans;
//     long long MOD = 1e9 + 7;
//     Fancy() {
//     }
    
//     void append(int val) {
//         ans.push_back(val%MOD);
//     }
    
//     void addAll(int inc) {
//         for(long long i=0;i<ans.size();i++){
//             ans[i] = (ans[i] + inc)%MOD;
//         }
//     }
    
//     void multAll(int m) {
//             for(long long i=0;i<ans.size();i++){
//             ans[i] = (ans[i] * m)%MOD;
//         }
//     }
    
//     int getIndex(int idx) {
//         if(idx >= ans.size()) return -1;
//         return ans[idx] % MOD;
//     }
// };

// /**
//  * Your Fancy object will be instantiated and called as such:
//  * Fancy* obj = new Fancy();
//  * obj->append(val);
//  * obj->addAll(inc);
//  * obj->multAll(m);
//  * int param_4 = obj->getIndex(idx);
//  */


/*

int main(){
    Fancy fancy;
    fancy.append(2); // arr = [2]
    fancy.addAll(3); // arr = [5]
    fancy.multAll(2); // arr = [10]
    cout << fancy.getIndex(0) << endl; // Output: 10
}