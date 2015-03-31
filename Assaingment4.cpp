#include<bits/stdc++.h>
using namespace std;

struct node{
  string type,name,dataType,StaticDynamic,GlobalLocal,Procedure;
  node *next;
  node(){
    type = name = dataType = StaticDynamic = GlobalLocal = Procedure = "";
    next = NULL;
  }
};

node *head = new node();
string pro="";
void insert(string type,string name,string dataType,string StaticDynamic,string GlobalLocal){
    cout << name << endl;
    node *now;
    now = head;
    while(now->next != NULL){
        now = now->next;
        if(now->name == name){
            if(now->Procedure == pro) {
                printf("Duplicates found %s\n",name.c_str());
                return;
            }
        }
    }
    now->next = new node();
    now = now->next;
    now->type = type;
    now->name = name;
    now->dataType = dataType;
    now->StaticDynamic = StaticDynamic;
    now->GlobalLocal = GlobalLocal;
    now->Procedure = pro;

}

int main() {

    char inp[50][20],ide[50][20],t[25],con[25],t1[25],newprint[25];
    int i=0,in=0,j=0,k,l,f=0,m=0,f1=0;
    int mainchk=0,fnew=0;
    int jlen=0,finish=0;

    FILE *fp,*fp1;

    fp=fopen("in.txt","r");
    fp1=fopen("out.txt","w");

    while(!feof(fp)) {
        fscanf(fp,"%s",inp[i]);
        i++;
    }

    mainchk=1;
    l=0;
    in=i;
    f=0;

    fprintf(fp1,"\n \n Symtable for main \n");

    for(i=0; i<in; i++) { //1

        if(strcmp(inp[i],"main()")==0){
            mainchk=0;
            pro = "main()";
        }

        if(strcmp(inp[i],"goto")==0) {
            strcpy(t,inp[i+1]);
            t[strlen(t)-1]='\0';
            fprintf(fp1,"\n label \t\t %s \t - \t Static \t local \t",t);
            insert("lable",t,"-","Static","local");
            continue;
        }

        if(strcmp(inp[i],"#")==0) {
            strcpy(t,inp[i+2]);
            fprintf(fp1,"\n \n System table for procedure %s \n",t);
            pro = t;
        }

        if(strcmp(inp[i],"const")==0) {
            strcpy(t,inp[i+1]);
            i=i+1;
            f1=1;
            continue;
        }

        l=0;

        if(f1==1) {  //2
            k=0;
            m=0;

            for(j=0; j<strlen(inp[i]); j++) {

                if(inp[i][j]>='a' && inp[i][j]<='z') {
                    ide[l][k++]=inp[i][j];
                    continue;
                }

                else {
                    ide[l][k]='\0';
                    if(ide[l][0]!='\0')
                        strcpy(t1,ide[l]);
                }

                if(inp[i][j]>='0' && inp[i][j]<='9') {
                    con[m++]=inp[i][j];
                    continue;
                }

                else {
                    con[m]='\0';
                    m=0;
                }

                if(t1[0]!='\0' && con[0]=='\0') {
                    if(mainchk){
                        fprintf(fp1,"\n Constant \t %s \t %s \t Static \t global",t1,t);
                        insert("Constant",t1,t,"Static","global");
                    }
                    else{
                        fprintf(fp1,"\n Constant \t %s \t %s \t Static \t local",t1,t);
                        insert("Constant",t1,t,"Static","local");
                    }
                    l++;
                    m=0;
                }
            }
            f1=0;
        }  //2




        if((strcmp(inp[i],"int")==0)||(strcmp(inp[i],"char")==0)||(strcmp(inp[i],"float")==0)||(strcmp(inp[i],"double")==0)) {
            strcpy(t,inp[i]);
            f=1;
            if(strstr(inp[i+1],"new")) {
                fnew=1;
            }
            continue;
        }

        if(f==1 || fnew==1) {  //3
            k=0;
            jlen=strlen(inp[i]);

            for(j=0; j<jlen; j++) {

                if(inp[i][j]>='a' && inp[i][j]<='z') {
                    ide[l][k++]=inp[i][j];
                    continue;
                } else
                    ide[l][k]='\0';

                k=0;
                if(fnew==1) {
                    strcpy(newprint,"dynamic");
                } else
                    strcpy(newprint,"static");

                if(fnew==1 && inp[i][j]=='=') {
                    j=jlen;
                    finish=1;
                }
                if(finish==1) {
                    i++;
                    finish=0;
                    fnew=0;
                }
                if(ide[l][0]!='\0') {
                    if(mainchk){
                        fprintf(fp1,"\n identifier \t %s \t %s \t %s \t global \t",ide[l],t,newprint);
                        insert("identifier",ide[l],t,newprint,"global");
                    }
                    else{
                        fprintf(fp1,"\n identifier \t %s \t %s \t %s \t local \t",ide[l],t,newprint);
                        insert("identifier",ide[l],t,newprint,"local");
                    }
                    l++;
                }
            }
            f=0;
        }  //3


    } // 1

    printf("\n The symbol table was created successfully !!!");

    return 0;
}

