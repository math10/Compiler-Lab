#include<bits/stdc++.h>
using namespace std;
string keyWords[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
int main() {
#ifdef Sanim
	//geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
#endif
    string st;
    cin >> st;
    bool flag = 0;
    for(int i = 0;i<32;i++){
        if(st == keyWords[i]) flag = 1;
    }
    if(flag) cout << "Key Word" << endl;
    else cout << "Not Key Word" << endl;
}

