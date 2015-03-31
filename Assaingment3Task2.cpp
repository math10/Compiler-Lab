/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

stack<string >s;
vector<string >rpn;
bool flag = 1;
int GetOperatorWeight(char op) {
    switch(op) {
    case '+':
        return 1;
    case '-':
        return 0;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        flag = 0;
        return -1;
    }
}

bool HasHigherPrecedence(char op1, char op2) {
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    return op1Weight > op2Weight;
}

bool check(string st){
    int i = 0;
    if(st[i] == '-') i++;
    return isalpha(st[i]);

}

void eval(string st) {
    int len = st.size();
    rep(i,len) {
        if(flag == 0) return;
        if(st[i] == ' ') continue;
        if(isalnum(st[i]) ) {
            string ch = "";
            while(i<len && isalnum(st[i])) {
                ch += st[i++];
            }
            if(!check(ch)) flag = 0;
            i--;
            rpn.pb(ch);
        }
        else if(st[i] == '(') {
            string ch = "";
            ch += st[i];
            s.push(ch);
        } else if(st[i] == ')') {
            while(!s.empty() && s.top() !=  "(") {
                rpn.pb(s.top());
                s.pop();
            }
            if(s.empty()) flag = 0;
            s.pop();
        } else {
            if(st[i] =='-' && i+1<len && isalnum(st[i+1])) {
                i++;
                string ch = "-";
                while(i<len && isalnum(st[i])) {
                    ch += st[i++];
                }
                i--;
                if(ch.size() == 0) flag = 0;
                if(!check(ch)) flag = 0;
                rpn.pb(ch);
            }
            else{
                while(!s.empty() && s.top() != "(" && HasHigherPrecedence(s.top()[0],st[i])) {
                    rpn.pb(s.top());
                    s.pop();
                }
                string ch = "";
                ch += st[i];
                s.push(ch);
            }
        }
    }
    while(!s.empty()) {
        rpn.pb(s.top());
        s.pop();
    }
}
char pa[mx];

void rpnCheck(){
    int len = rpn.size();
    int cnt = 0;
    forstl(it,rpn){
        string st = *it;
        if(isalpha(st[0])) cnt++;
        else if(st.size() == 1) cnt--;
        else cnt++;
        if(cnt <= 0) {
            flag = 0;
            return;
        }
    }
}

int main() {
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    gets(pa);
    eval(pa);
    if(!flag) cout << "Not Accepted" << endl;
    else{
        rpnCheck();
        if(flag) cout << "Accepted" << endl;
        else cout << "Not Accepted" << endl;
    }
}

/*
(abc - b2)*(-c * d3) - g : Accepted
(abc - b2)*(-c * d3 - g : Not Accepted
(abc - b2)*(-c * d3) - -g : Accepted
(abc - b2)*(c ** d3) - g : Not Accpeted
*/
