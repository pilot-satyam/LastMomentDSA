// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        for(int z=1; z<=min(zero,limit); z++) dp0[z][0] = 1;
        for(int o=1; o<=min(one,limit); o++) dp1[0][o] = 1;

        for(int z=1; z<=zero; z++){
            for(int o=1; o<=one; o++){

                dp0[z][o] = (dp0[z-1][o] + dp1[z-1][o]) % MOD;
                if(z-limit-1 >= 0)
                    dp0[z][o] = (dp0[z][o] - dp1[z-limit-1][o] + MOD) % MOD;

                dp1[z][o] = (dp0[z][o-1] + dp1[z][o-1]) % MOD;
                if(o-limit-1 >= 0)
                    dp1[z][o] = (dp1[z][o] - dp0[z][o-limit-1] + MOD) % MOD;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};