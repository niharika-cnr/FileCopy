/* Name:
	ID:
	Teammate name(s):
	Explain your steps as comments in the code itself.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1


int main(int argc, char **argv){
	char write_msg[BUFFER_SIZE] = "Greetings\n";
	char read_msg [BUFFER_SIZE];
	char ch;

	int fd[2];
	pid_t cpid;
	
	char *sourceFile = argv[1];
	char *targetFile = argv[2];
	
	FILE *trgt = fopen(targetFile,"w");
	FILE *src  = fopen(sourceFile,"r");
	
	printf("\n %s %s \n\n",sourceFile,targetFile);
	
	while (1) {
      ch = fgetc(fp1);
 
      if (ch == EOF)
         break;
      else
         putc(ch, fp2);
   }
	
	pipe(fd); /* create pipe */
	if((cpid = fork()) == -1){
		perror("Fork failed");
		exit(1);
	}
	
	if(cpid == 0){	// child process
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		read(
		printf("read: %s",read_msg);
		/* close the write end of the pipe */
		close(fd[READ_END]);

		/* Open the destination file and read from pipe */
		/* Create the destination file if it does not exist */
	}
	else{		//parent process execution
		/* parent only writes. Close the read end */
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		/* close the write end of the pipe */
		close(fd[WRITE_END]);

		/* Open the source file and write to pipe */
		/* Print error message if the source file does not exist */
	}
	/* Remember to close the files */

	return 0;
}
