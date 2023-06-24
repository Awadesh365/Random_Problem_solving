class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        // NM...POD->fk...sbs->brs->mrg
        map<int,int>dp;
        dp[0]=0;

        for(auto &it:rods){
            map<int,int>temp = dp;

            for(auto &[k,v]:temp){
                dp[k+it] = max(dp[k+it],v);

                if(it<=k) dp[k-it] = max(dp[k-it],v+it);
                else dp[it-k] = max(dp[it-k],v+k);
            }
        }
        return dp[0];
    }
};