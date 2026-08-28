class Solution {
public:
    string lexPalindromicPermutation(string s,string target) {
        int n=s.size(),m=n/2;
        vector<int> cnt(26);

        for(char c:s) cnt[c-'a']++;

        char mid=0;
        for(int i=0;i<26;i++) {
            if(cnt[i]%2) {
                if(mid) return "";
                mid='a'+i;
            }
            cnt[i]/=2;
        }

        for(int pos=min(m,n);pos>=0;pos--) {
            vector<int> c=cnt;
            bool ok=true;

            for(int i=0;i<pos;i++) {
                int x=target[i]-'a';
                if(c[x]==0) {
                    ok=false;
                    break;
                }
                c[x]--;
            }

            if(!ok) continue;

            if(pos<m) {
                int x=target[pos]-'a';

                for(int j=x+1;j<26;j++) {
                    if(!c[j]) continue;

                    string left=target.substr(0,pos);
                    left+=char('a'+j);
                    c[j]--;

                    for(int k=0;k<26;k++)
                        left+=string(c[k],'a'+k);

                    string ans=makePalindrome(left,mid);

                    if(ans>target) return ans;
                }
            } else {
                string left=target.substr(0,m);
                string ans=makePalindrome(left,mid);

                if(ans>target) return ans;
            }
        }

        return "";
    }

private:
    string makePalindrome(string left,char mid) {
        string right=left;
        reverse(right.begin(),right.end());

        string ans=left;
        if(mid) ans+=mid;
        ans+=right;

        return ans;
    }
};