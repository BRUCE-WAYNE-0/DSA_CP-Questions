class Solution {
public:
    bool checkValidString(string s) {
    int mini = 0, maxi = 0;

    for (char c : s) {
        if (c == '(') {
            mini++;
            maxi++;
        } else if (c == ')') {
            mini--;
            maxi--;
        } else { // '*' forks: ')', '', '('
            mini--;
            maxi++;
        }

        // no valid path remains
        if (maxi < 0) return false; 

        // clip negative-balance paths
        mini = max(mini, 0); 
    }

    // ∃ path ends with balance 0
    return mini == 0; 
}
};