#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
void count(char *token2,char *token3)
{
int lc,wc,cc,fp;
char buffer[30];
lc=0;wc=0;cc=0;
fp=open(token3,O_RDONLY);
if(fp!=-1)
{
while(read(fp,buffer,1))
{
if(buffer[0]==' '||buffer[0]=='\t'||buffer[0]=='\n')
{
wc++;cc++;
}
else
cc++;
if(buffer[0]=='\n')
lc++;
}
}
else
printf("\nfile %s not found",token3);

if(strcmp(token2,"w")==0)
printf("\nwords count is:%d",wc);
if(strcmp(token2,"l")==0)
printf("\nline count is:%d",lc);
if(strcmp(token2,"c")==0)
printf("\nchar count is:%d",cc);
close(fp);

}
void main()
{
    char cmd[80],tok1[10],tok2[10],tok3[10],tok4[10];
    int n;

    while(1)
    {
        printf("\nMyShell$");
        fgets(cmd,80,stdin);

        n=sscanf(cmd,"%s%s%s%s",tok1,tok2,tok3,tok4);
         
        if(strcmp(tok1,"exit")==0)
        exit(0);


        switch(n)
        {
            case 1:if(fork()==0)
            execlp(tok1,tok1,NULL);
            wait(0);
            break;

            case 2:if(fork()==0)
            execlp(tok1,tok1,tok2,NULL);
            wait(0);
            break;

            case 3:if(strcmp(tok1,"count")==0){
            count(tok2,tok3);
            }
            else
            {
                execlp(tok1,tok1,tok2,tok3,NULL);
                wait(0);
                break;
            }

            case 4:if(fork()==0)
            execlp(tok1,tok1,tok2,tok3,tok4,NULL);
            wait(0);
            break;
        }
        }
}
