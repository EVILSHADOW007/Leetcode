class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (cnt[x]) {
                ans += target[i];
                cnt[x]--;
            } else {
                for (int j = x + 1; j < 26; j++) {
                    if (cnt[j]) {
                        ans += char('a' + j);
                        cnt[j]--;

                        for (int k = 0; k < 26; k++)
                            ans += string(cnt[k], 'a' + k);

                        return ans;
                    }
                }

                break;
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cnt[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (cnt[j]) {
                    string res = ans.substr(0, i);
                    res += char('a' + j);
                    cnt[j]--;

                    for (int k = 0; k < 26; k++)
                        res += string(cnt[k], 'a' + k);

                    return res;
                }
            }
        }

        return "";
    }
};