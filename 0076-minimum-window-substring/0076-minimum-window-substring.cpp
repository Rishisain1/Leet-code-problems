class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> required;
        for (auto ch : t) {
            required[ch]++;
        }
        unordered_map<char, int> curr;
        int i = 0, j = 0;
        int n = s.length();
        int count = 0;
        for (; j < n; j++) {
            if (required.count(s[j])) {
                curr[s[j]]++;
                if (curr[s[j]] == required[s[j]]) {
                    count++;
                }
            }
            if (required.size() == curr.size() && count == curr.size()) {
                j++;
                break;
            }
        }
        if (count < required.size()) {
            return "";
        } // you missed it broo
        while (!required.count(s[i]) || curr[s[i]] > required[s[i]]) {
            if(required.count(s[i])){
                curr[s[i]]--;
                    }
                        i++;
        }
        vector<int> ans = {i, j};
        int len = j - i;

        while (j < n) {
            while (i < j) {
                if (required.count(s[i])) {
                    if (curr[s[i]] == required[s[i]]) {
                        count--;
                        curr[s[i]]--;
                        i++;
                        break;
                    }
                    curr[s[i]]--;
                }
                i++;
            }
            while (j < n) {
                if (required.count(s[j])) {
                    curr[s[j]]++;
                    if (curr[s[j]] == required[s[j]]) {
                        count++;
                    }
                }
                if (required.size() == curr.size() && count == curr.size()) {
                    j++;
                    while (!required.count(s[i]) ||
                           curr[s[i]] > required[s[i]]) { // here also
                    if(required.count(s[i])){
                            curr[s[i]]--;
                    }
                        i++;
                    }
                    if (j - i < len) {
                        len = j - i;
                        ans = {i, j};
                    }
                    break;
                }
                j++;
            }
        }
        string temp = "";
        for (int a = ans[0]; a < ans[1]; a++) {
            temp += s[a];
        }
        return temp;
    }
};