#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
        int nbytes,fd[2];
        char readBuff[100];
        pid_t childpid;
        char str[]="Hello world!!";
        
        pipe(fd);
        
        printf("fd[0]=%d and fd[1]=%d\n",fd[0],fd[1]);
        
        if((childpid=fork())==-1)
        {
                printf("Error!!");
                exit(1);
        }
        
               
        if(childpid==0)
        {
                /*child process closes up input side of pipe*/
                close(fd[0]);
                
                write(fd[1],str,strlen(str)+1);
                exit(0);
        }
        else
        {
                close(fd[1]);
                nbytes=read(fd[0],readBuff,sizeof(readBuff));
                printf("String read by process=%s\n",readBuff);
                exit(0);
        }
        
        return 0;
}
                
        
        
