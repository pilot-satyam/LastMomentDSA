// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-03


// class Solution {
// private:
//     int solve(int zero,int one,int last,int cnt,int limit){
//         if(zero == 0 && one == 0) return 1;
//         if(dp[zero][one][last][cnt] != -1) return dp[zero][one][last][cnt];
//         long long ans = 0;
//         // place 0
//         if(zero > 0){
//             if(last == 0){
//                 if(cnt < limit){
//                     ans = (ans + solve(zero-1,one,0,cnt+1,limit)) % mod;
//                 }
//             }
//             else{
//                 ans = (ans + solve(zero-1,one,0,1,limit)) % mod;
//             }
//         }
//         // place 1
//         if(one > 0){
//             if(last == 1){
//                 if(cnt < limit){
//                     ans = (ans + solve(zero,one-1,1,cnt+1,limit)) % mod;
//                 }
//             }
//             else{
//                 ans = (ans + solve(zero,one-1,1,1,limit)) % mod;
//             }
//         }
//         return dp[zero][one][last][cnt] = ans % mod;
//     }

// public:
//     int dp[201][201][2][201];
//     const int mod = 1e9 + 7;
//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(dp,-1,sizeof(dp));
//         long long ans = 0;
//         if(zero > 0)
//             ans +=  solve(zero-1,one,0,1,limit) % mod;
//         if(one > 0)
//             ans +=  solve(zero,one-1,1,1,limit) % mod;
//         return ans % mod;
//     }
// };



class Solution {
public:

    const int MOD = 1e9+7;

    int numberOfStableArrays(int zero, int one, int limit) {
        static long long dp[201][201][2][201];
        memset(dp,0,sizeof(dp));
        if(zero > 0) dp[1][0][0][1] = 1;
        if(one > 0)  dp[0][1][1][1] = 1;

        for(int z=0; z<=zero; z++){
            for(int o=0; o<=one; o++){
                for(int last=0; last<2; last++){
                    for(int cnt=1; cnt<=limit; cnt++){

                        long long val = dp[z][o][last][cnt];
                        if(val == 0) continue;
                        if(last == 0){
                            // add another 0
                            if(z+1 <= zero && cnt+1 <= limit)
                                dp[z+1][o][0][cnt+1] =
                                (dp[z+1][o][0][cnt+1] + val) % MOD;

                            // switch to 1
                            if(o+1 <= one)
                                dp[z][o+1][1][1] =
                                (dp[z][o+1][1][1] + val) % MOD;
                        }
                        else{

                            // add another 1
                            if(o+1 <= one && cnt+1 <= limit)
                                dp[z][o+1][1][cnt+1] =
                                (dp[z][o+1][1][cnt+1] + val) % MOD;

                            // switch to 0
                            if(z+1 <= zero)
                                dp[z+1][o][0][1] =
                                (dp[z+1][o][0][1] + val) % MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=1;i<=limit;i++){
            ans = (ans + dp[zero][one][0][i]) % MOD;
            ans = (ans + dp[zero][one][1][i]) % MOD;
        }

        return ans;
    }
};