#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 7;
char ch[mx];

bool check(){
    int len = strlen(ch);
    if(!len) return 1;

    bool flag = (ch[0] == '1');
    for(int i = 0;i < len;i++){
        bool f = (ch[i] == '1');
        if(flag != f) return 0;
        flag = !flag;
    }
    return  !(len%2);
}

int main(){
    gets(ch);

    if(check()) cout << "Accepted" << endl;
    else cout << "Not Accepted" << endl;

    return 0;
}
