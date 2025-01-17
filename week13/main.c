#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *clean_spaces(char *str)
{
    while (isspace(*str))
    {
        str++;
    }
    return str;
}


char **saferealloc(char * * arr,size_t size){
        char ** a = realloc(arr,size);
        if(!a){
        puts("error allocating");
        exit(1);}
        return a;}
        

char ** split_strings(char *str)
{
    char **addrs = saferealloc(NULL,1*sizeof(char *));

    str = clean_spaces(str);

    int k = 0;
    for (; *str != '\0'; k++)
    {

        char * start = str;
        while (*str != '\0' && !isspace(*str))
            str++;
        char * end = str;

        addrs = saferealloc(addrs,(k+2)*(sizeof(char*)));
        addrs[k] = strndup(start,end-start);

        str = clean_spaces(str);
    }
    addrs[k] = NULL;
    return addrs;
}


int peek(){
    int c = getchar();
    ungetc(c,stdin);
    return c;
}

char ** get_lines(){

    char ** lines= saferealloc(NULL,1*sizeof(char *));
    int k = 0;
     
    char buff[256];
    while (fgets(buff,255,stdin))
    {
      
        char* p = strdup(buff);
        
        int len = strlen(p);
        // "abc\0"
        // "\3abc"
        for(int i=len;i>0;i--){
            p[i] = p[i-1];
        }
        p[0] = len;

        lines = saferealloc(lines,(k+2)*(sizeof(lines)));
        lines[k++] =p;
    }
    lines[k] = NULL;
    return lines;
}

void print_lines(char ** lines){
    while(*lines){
        int n = (int)(*lines)[0];
        for(int i=1;i<=n;i++)
            putchar((*lines)[i]);
        putchar('\n');
        lines++;
}}

int get_len(char ** lines){
    int k =0;
    while(lines[k++]){};
    return k-1;
}

int cmp(const void* a, const void* b){
    char ** p = (char **) a ;  
    char ** q = (char **) b ;  
    int np =(int) **p;
    int nq =(int) **q;
    if(np!=nq)return np-nq;
    for(int i=1;i<=np;i++){
        if((*p)[i]!=(*q)[i])
            return (*p)[i]-(*q)[i];
    }
    return 0;
}

void free_matrix(char** m){
    for(int i=0;m[i];i++){
    free(m[i]);
   }
   free(m);
}
void print_matrix(char** m){
    for(int i=0;m[i];i++){
   printf("%s\n",m[i]);
   }
}

int main()
{
    //1
    char* str = "these are words";
    char** addrs = split_strings(str);

    print_matrix(addrs);
    free_matrix(addrs);
    printf("%s\n",str);

    //2
    addrs = get_lines();
    qsort(addrs,get_len(addrs), sizeof(char *),&cmp);

    print_lines(addrs);
    free_matrix(addrs);

    return 0;
}