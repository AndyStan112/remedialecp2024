#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


char *saferealloc(char * arr,size_t size){
        char * a = realloc(arr,size);
        if(!a){
        puts("error allocating");
        exit(1);}
        return a;}

void print_int_rec(int n){
    if(n==0)return;
    int c =n%10;
    print_int_rec(n/10);
    putchar('0'+c);
}


void print_int(int n){
    if(n==0){
        putchar('0');
        return;
    }
    print_int_rec(n);
}


void print_float(float n, int prec){
    if(n==0){
        putchar('0');
        return;
    }
    while(prec--){
        n *= 10;
        putchar('0'+(int)n%10);
        n-= floor(n);
    }
}


void myprintf( char *format,void ** args)
{
    
    while (*((int *)args) && *format != '\0')
    {
        
        while (*format != '%')
        {
            putchar(*format);
            format++;
        }
        format++;
        if(*format == '%'){
            putchar('%');
            format++;
            continue;
        }
            

        if (*format == 'd')
        {
            int n = **((int **) args);
            printf("%d",n);
            print_int(n);
            args++;
        }
        else if (*format == 'f')
        {
          float f =**((float **) args);
          int n = floor(f);
          print_int(n);
          putchar('.');
          float frac = f - n;
          print_float(frac,6);
          args++;
        }
      
        else if (*format == 's')
        {
            char * s = *((char **)args);
            
            while(*s++)putchar(*s);
            args++;
        }
        
        else
        {
           perror("Invalid format");
           return;
        }
        format++;
    }

    return ;
}



char* fib_string(int n){
    char * p = strdup("0");
    char * q = strdup("01");
    if(n==0){
    return p;
    free(q);
    }
    if(n==1)
    return q;

    char *s= saferealloc(NULL,strlen(p)+strlen(q)+1);
    for(int i=2;i<=n;i++){
        s = strdup(q);
        s= saferealloc(s,strlen(p)+strlen(q)+1);
        strcat(s,p);
        free(p);
        p=q;
        q=strdup(s);
    }

    free(p);
    free(q);
    return s;
}

int main()
{
    //1
char* str = fib_string(3);


int n =44;
float f = 2.123456;
void* args[4];
args[0] = str;
args[1] =&n;
args[2] =&f;
args[3] =NULL;

//2
myprintf("%s   %d   %f",args);
return 0;


}