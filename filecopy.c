/*	
 *	Name:		Niharika CNR
 *	ID: 		1510110234
 *	Teammate name:	Sanjana Gautam
 *	Team Number: 	9
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 250
#define READ_END 0
#define WRITE_END 1


int main(int argc, char **argv)	{
	char write_data[MAX_SIZE];
	char read_data [MAX_SIZE];
	
	//character to read from the file
	char ch;
	//looping variable
	int i=0;
	
	//File pointers for source and target files
	FILE *src = NULL;
	FILE *trgt= NULL;

	int fd[2];
	pid_t cpid;

	/* char*'s to store the names of the files passed as command line arguments*/
	char *sourceFileName = argv[1];
	char *targetFileName = argv[2];
	

	pipe(fd); /* creates pipe */
	
	if((cpid = fork()) == -1){
		perror("Fork failed");
		exit(1);
	}

	// child process execution logic: child only READS
	if(cpid==0){
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		
		/* Create the destination file to write into if it does not exist */
		trgt = fopen(targetFileName,"w");
		
		/* Open the destination file and read from pipe */
		if(trgt!=NULL)	{
			/* read from the pipe */
			read(fd[READ_END], read_data, MAX_SIZE);
			fprintf(trgt,"%s",read_data);
			
			printf("\nContents of %s have been copied into %s\n\n",sourceFileName,targetFileName);
		}//end if
		
		/* Print error message if the target file does not exist */
		else	{
			printf("\nSorry! File could not be created!\n");
		}
		/* close the write end of the pipe */
		close(fd[READ_END]);

	}
	
	//parent process execution logic: parent only WRITES	
	else{
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		
		/* Open the extant source file to read from */
		src  = fopen(sourceFileName,"r");
		
		/* Open the source file and write to pipe */
		if(src!=NULL)	{
			while(1)	{
				ch = fgetc(src);
				
				/*end the writing process if we reach the END OF FILE or
				  if we reach the MAXIMUM LIMIT of data allowed */
				if ( (ch==EOF) || i==MAX_SIZE )
				   break;
				//writes data into pipe one character at a time
				else
				   write_data[i++]=ch;
			}//end while
			
			write(fd[WRITE_END], write_data, strlen(write_data)+1);
		}//end if
		
		/* Print error message if the source file does not exist */
		else	{
			printf("\nSource File not found!\n");
		}//end else
		
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	
	return 0;
}
