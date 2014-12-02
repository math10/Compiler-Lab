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
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'|c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"    ";
        return *this;
    }
} dbg;
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
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
vector<string >keyWords;
FILE *in;
int line;
void init_keyWords() {
    FILE *k;
    k = fopen("keywords.txt","r");
    char ch;
    while((ch=getc(k))!=EOF) {
        string st = "";
        st += ch;
        while((ch=getc(k))!=EOF && ch != '\n') st += ch;
        keyWords.pb(st);
    }
    fclose(k);
}

bool isKeyword(string st) {
    forstl(it,keyWords) {
        if(*it == st) return true;
    }
    return false;
}

bool isIdentifier(string st) {
    if(isalpha(st[0]) || st[0] == '_') {
        forstl(it,st) {
            if(isalnum(*it) || (*it) == '_') continue;
            return false;
        }
        return true;
    }
    return false;
}


bool isOperator(char ch) {
    string st = "";
    st += ch;
    if(ch == '!') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '%') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '^') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '&') {
        ch = getc(in);
        if(ch == '&') {
            st += ch;
        } else if(ch == '=') st += ch;
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '*') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '-') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch =='-')st += ch;
        else if(ch == '>') st += ch;
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '+') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch == '+') st += ch;
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '=') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '`' || ch == '.' || ch == '?') {
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '|') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch == '|')st += ch;
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '<') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch == '<') {
            st += ch;
            ch = getc(in);
            if(ch == '=') {
                st += ch;
            }
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '>') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch == '>') {
            st += ch;
            ch = getc(in);
            if(ch == '=') {
                st += ch;
            }
        }
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    } else if(ch == '/') {
        ch = getc(in);
        if(ch == '=') {
            st += ch;
        } else if(ch == '/')st += ch;
        printf("Operator found at line %d is %s\n",line,st.c_str());
        return true;
    }
}

bool isSeparator(char ch) {
    if(ch == '(' ||ch == ')' ||ch == '{' ||ch == '}' ||ch == '[' ||ch == ']' ||ch == ',' ||ch == ';' ||ch == ':') return true;
    return false;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    init_keyWords();
    in = fopen("source.c","r");
    char ch,pre = '\n';
    line = 1;
    while((ch = getc(in))!=EOF) {
        if(ch == '/') {
            char tmp = getc(in);
            if(tmp == '/') {
                int cnt = 0;
                int tmpLine = line;
                while((ch=getc(in))!=EOF) {
                    if(ch=='\n') {
                        line++;
                        break;
                    }
                }
            } else if(tmp == '*') {
                int cnt = 0;
                int tmpLine = line;
                tmp = getc(in);
                while((ch=getc(in))!=EOF) {
                    if(ch == '/' && tmp == '*') break;
                    tmp = ch;
                }

            } else {
                if(tmp == '\n') line++;
            }
        } else {
            if(ch == '#' && pre == '\n') {
                string st = "";
                st += ch;
                while((ch=getc(in))!=EOF && isalpha(ch)) {
                    st += ch;
                }
                printf("Preprocessor found at line %d is %s\n",line,st.c_str());
            } else if(isalpha(ch)) {
                string st = "";
                st += ch;
                while((ch=getc(in))!=EOF) {
                    if(ch == ',' ||ch == ' ' ||ch == ';' ||ch == '=' ||ch == '\n') break;
                    st += ch;
                }
                if(isKeyword(st)) {
                    printf("Keyword found at line %d is %s\n",line,st.c_str());
                } else if(isIdentifier(st)) {
                    printf("Identifier found at line %d is %s\n",line,st.c_str());
                }
            }
            if(ch == '\n') line++;
        }

        pre = ch;
    }
    fclose(in);

    in = fopen("source.c","r");
    pre = '\n';
    line = 1;
    while((ch = getc(in))!=EOF) {
        if(ch == '/') {
            char tmp = getc(in);
            if(tmp == '/') {
                int cnt = 0;
                int tmpLine = line;
                while((ch=getc(in))!=EOF) {
                    if(ch=='\n') {
                        line++;
                        break;
                    }
                }
            } else if(tmp == '*') {
                int cnt = 0;
                int tmpLine = line;
                tmp = getc(in);
                while((ch=getc(in))!=EOF) {
                    if(ch == '/' && tmp == '*') break;
                    tmp = ch;
                }

            } else {
                if(tmp == '\n') line++;
            }
        } else {
            if(ch == '#' && pre == '\n') {

            } else if(!isalnum(ch)) {
                if(isOperator(ch));
                if(isSeparator(ch))printf("Separator found at line %d is %c\n",line,ch);
            }
            if(ch == '\n') line++;
        }

        pre = ch;
    }
    fclose(in);
}
