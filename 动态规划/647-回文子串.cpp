/***
题目描述：
    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
题解：
    中心扩展法
***/
class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        int n = s.length();
        if(n == 0)  return 0;
        for(int i=0; i<n; i++){
            extendAroudCenter(s, i, i);
            extendAroudCenter(s, i, i+1);
        }
        return count;
    }

    void extendAroudCenter(string s, int left, int right) {
        int n = s.length();
        while(left >=0 && right < n){
            if(s[left] == s[right]){
                left--;
                right++;
                count++;
            }
            else    break;
        }
    }
};