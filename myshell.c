#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>




void myshell() 
{
  char c[30];
     int pid;
     while(1)  
      { 
    	
         pid=fork(); 
         
         if(pid<0)
             { 
                printf("The fork has failed\n");
                
                exit(1);
             }
         else if(pid==0)          
             {  
                printf(" This is the child having p_id %d",(int)getpid());
                
                execl("/bin/sh", c , (char *)NULL);
               
                perror("chils failed to exec");  
             
             }
         
         else
             {
		
                wait(NULL);
                
                printf("\nThe child has excited\n");                
 
                printf("\nThis is the parent of %d with p_id %d\n",(int)pid,
                
                                                           (int)getpid()); 
               
                exit(1); 
             }  
   
      }  

}
