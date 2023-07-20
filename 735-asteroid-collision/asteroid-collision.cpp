class Solution {
public:
// Last day of POD for july
// NM -> fk sbs -> th's -> it
   vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;

    for(auto &asteroid:asteroids){
        int checkPoint = 1;

        while(!st.empty() && (st.top()>0 && asteroid<0)){
            if(abs(st.top())<abs(asteroid)){
                st.pop();
                continue;
            }
            else if(abs(st.top()==abs(asteroid))){
                st.pop();
            }
            checkPoint = 0;
            break;
        }
        if(checkPoint)
            st.push(asteroid);
    }
    vector<int> ans(st.size());
    for (int i = ans.size() - 1; i >= 0;--i){
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
};