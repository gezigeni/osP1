#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]){

	if(argc<2){
		printf("No arguments");
		DIR *dir;
		struct dirent *sd;

		dir = opendir(".");

		if(dir == NULL){
			printf("Error, unable to open\n");
			exit(1);
		}

		while( (sd = readdir(dir)) != NULL){
			printf("%s\n", sd->d_name);
		}

		closedir(dir);
	}
	else{
		int c;
		while( (c = getopt(argc, argv, "hILdgipstul")) != -1){
			switch(c){
				case 'h':
					printf("In the help page\n");
					break;
				case 'I':
                                        printf("Setting indentation\n");
                                        break;
				 case 'L':
                                        printf("Following symbolic links\n");
                                        break;
				 case 'd':
                                        printf("Time of last modification\n");
                                        break;
				 case 'g':
                                        printf("Print group id\n");
                                        break;
				 case 'i':
                                        printf("Print number of links in inode table\n");
                                        break;
				 case 'p':
                                        printf("Permissions\n");
                                        break;
				 case 's':
                                        printf("Sizes\n");
                                        break;
				 case 't':
                                        printf("Information of file\n");
                                        break;
				 case 'u':
                                        printf("Print user id\n");
                                        break;
				 case 'l':
                                        printf("Optional one\n");
                                        break;
				default:
					perror("Not a valid command-line argument");
					printf("Not valid");
					break;



		}
			
		



		}


	}





	return 0;
}
