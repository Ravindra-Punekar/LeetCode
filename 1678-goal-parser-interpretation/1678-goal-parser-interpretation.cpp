class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for (int i = 0; i < command.length(); i++) {

            if (command[i] == '(')
                if (command[i + 1] == 'a') {
                    ans += "al";
                    i += 3;
                } else {
                    ans += 'o';
                    i += 1;
                }
            else
                ans += command[i];
        }
        return ans;
    }
};