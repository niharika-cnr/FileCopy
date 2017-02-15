# FileCopy

Copies the contents of one file to another using pipes.

The names of the source and target files should be passed from the command line.
For example, after the following compilation of the code,

							>> gcc filecopy.c -o copyfiles
if the file names are passed as

							>> ./copyfiles srcfile.txt trgtfile.txt
then the contents of an existing 'srcfile.txt' will be copied into a new file 'trgtfile.txt'.	
