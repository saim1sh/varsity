#include<stdio.h>
#include<string.h>
int main()
{ 
    int sd,sh,sm,ss,ed,eh,em,es,stotal,etotal,dtotal,dd,dh,dm,ds;
    char ch1,ch2,ch3,ch4,ch5,ch6;
    scanf("%s %d %d %s %d %s %d %s %d %d %s %d %s %d",&ch1,&sd,&sh,&ch2,&sm,&ch3,&ss,&ch4,&ed,&eh,&ch5,&em,&ch6,&es);
    stotal=(sd*86400)+(sh*3600)+(sm*60)+ss;
    etotal=(ed*86400)+(eh*3600)+(em*60)+es;
    dtotal=etotal-stotal;
    dd=dtotal/(86400);
    dh=(dtotal- dd*86400)/3600;
    dm=(dtotal- dd*86400- dh*3600)/60;
    ds = dtotal- dd*86400- dh*3600 - dm*60;
    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)",dd,dh,dm,ds);

    return 0;
}