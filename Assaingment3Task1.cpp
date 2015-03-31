/*
S:- S1 | S2
S1 :- 0S11 | Ɛ
S2 :- 1S20 | Ɛ
*/
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 7;
char ch[mx];

bool check(){
    int len = strlen(ch);
    if(!len) return 1;

    bool flag = (ch[0] == '1');
    int tmp = len/2;
    for(int i = 0;i < tmp;i++){
        bool f = (ch[i] == '1');
        if(flag != f) return 0;
    }

    flag = !flag;
    for(int i = tmp;i < len;i++){
        bool f = (ch[i] == '1');
        if(flag != f) return 0;
    }

    return  !(len%2);
}

int main(){
    gets(ch);

    if(check()) cout << "Accepted" << endl;
    else cout << "Not Accepted" << endl;

    return 0;
}

----------------------------------------------------------------------
/*
S:- aTb | bTa
 T :- XTX | X | Ɛ
 X :- a | b
*/
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 7;
char ch[mx];

bool check(){
    int len = strlen(ch);
    if(ch[0] == 'a' && ch[len-1] == 'b'){
        for(int i = 0;i<len;i++){
            if(ch[i] == 'a' || ch[i] == 'b') continue;
            return false;
        }
    }else if(ch[0] == 'b' && ch[len-1] == 'a'){
        for(int i = 0;i<len;i++){
            if(ch[i] == 'a' || ch[i] == 'b') continue;
            return false;
        }
    }else return false;

    return true;
}

int main(){
    gets(ch);

    if(check()) cout << "Accepted" << endl;
    else cout << "Not Accepted" << endl;

    return 0;
}
