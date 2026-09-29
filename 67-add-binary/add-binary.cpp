class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1, j = b.size()-1;
        int ci = 0;
        while(i>=0 && j>=0){
            int ai = a[i]-'0';
            int bi = b[j]-'0';
            int si = ai^bi^ci;
            ans.push_back(char(si+'0'));
            ci = (ci&(ai^bi)) || (ai&bi);
            i--;j--;
        }
        while(i>=0){
            int ai = a[i]-'0';
            ans.push_back(char('0'+(ai^ci)));
            ci = ci&ai;
            i--;
        }
        while(j>=0){
            int bi = b[j]-'0';
            ans.push_back(char('0'+(bi^ci)));
            ci = ci&bi;
            j--;
        }
        if(ci) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};