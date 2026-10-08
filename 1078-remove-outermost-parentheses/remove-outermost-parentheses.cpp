class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=1;
        stack<int> st;
        st.push(s[0]);
        string ans;

        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
                ans.push_back(s[i]);
            }else{
                st.pop();
                if(st.empty()){
                    i++;
                    st.push('(');
                }else{
                    ans.push_back(s[i]);
                }
            }
            i++;
        }
        return ans;
    }
};