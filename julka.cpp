#include <stdio.h>
#include<string.h>

void add(char v1[], char v2[])
{
     int i,d,c=0;
     int l1=strlen(v1);
     int l2=strlen(v2);
     for(i=l1;i<l2;i++) 
          v1[i]='0';
     for(i=l2;i<l1;i++) 
          v2[i]='0';
     for(i=0;i<l1||i<l2;i++)
     {
          d=(v1[i]-'0')+(v2[i]-'0')+c;
          c=d/10;
          d%=10;
          v1[i]='0'+d;
     }
     while(c)
     {
          v1[i]='0'+(c%10);
          c/=10;
          i++;
     }
     v1[i]='\0';
     v2[l2]='\0';
}

void subs(char v1[], char v2[])

{
     int i,d,c=0;
     int l1=strlen(v1);
     int l2=strlen(v2);
     for(i=l2;i<l1;i++)
          v2[i]='0';
     for(i=0;i<l1;i++)
     {
          d=(v1[i]-'0'-c)-(v2[i]-'0');
          if(d<0)
          {
               d+=10; 
               c=1;
          }
          else c=0;
          v1[i]='0'+d;
     }
     v2[l2]='\0';
     i=l1-1;
     while(i>0 && v1[i]=='0') 
          i--;
     v1[i+1]='\0';
}

int divi(char v[], int q)

{
     int i,l=strlen(v);
     int c=0,d;
     for(i=l-1;i>=0;i--)
     {
          d=c*10+(v[i]-'0');
          c=d%q; d/=q; v[i]='0'+d;
     }
     i=l-1;
     while(i>0 && v[i]=='0') 
          i--;
     v[i+1]='\0';
     return c;
}

void rev(char v[]) 
{
     int l=strlen(v);
     int i; char cc;
     for(i=0;i<l-1-i;i++)
     {
          cc=v[i];v[i]=v[l-1-i];v[l-i-1]=cc;
     }
}

int main() {
     char a[102],b[102];
     for(int i=0; i<10 ;++i)
     {
         
          gets(a);
          gets(b);
         
          rev(a);
          rev(b);
         
          
          add(a,b);
          
          divi(a,2);
         
          rev(a);
          puts(a);
         
          rev(a);
          subs(a,b);
         
          rev(a);
          puts(a);
          
          
     }
     return 0;
}
