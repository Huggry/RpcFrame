#include <bits/stdc++.h>
using namespace std;

//KMP算法  next数组  i之前有多大相等的前缀和后缀长度-1

void GetNext(vector<int>& next, const string& needle){
    int j = -1;
    next[0] = j;
    for(int i = 1; i < needle.size(); i++){
        while(j >= 0 && needle[i] != needle[j + 1]){   //我们用的是j+1        精髓：前面已经匹配好的部分的下一个
            j = next[j];               //嵌套运用KMP算法
        }

        if(needle[i] == needle[j + 1]){
            j++;
        }

        next[i] = j;
    }
}

int str(const string& haystack, const string& needle, vector<int>& next){
    int j = -1;

    for(int i = 0; i < haystack.size(); i++){
        while(j >= 0 && haystack[i] != needle[j + 1]){   //之前已经匹配上的位置的下一个
            j = next[j];    //j寻找之前已经匹配上的位置  
        }

        if(haystack[i] == needle[j + 1]){
            j++;
        }

        if(j == needle.size() - 1){
            return i - needle.size() + 1;
        }
    }

    return -1;
}


int main(){
    string haystack, needle;
    cin >> haystack >> needle;

    if(needle.size() == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> next(needle.size(), 0);

    GetNext(next, needle);

    int result = str(haystack, needle, next);
    cout << result << endl;

    return 0;
}