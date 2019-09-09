#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
void depthFirst(DIR *dir){
        struct dirent *sd;
        char path[PATH_MAX];         
                

                if(dir == NULL){
                        printf("Error, unable to open\n");
                        exit(1);
                }

                while( (sd = readdir(dir)) != NULL){
			if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0){
                        printf("%s\n", sd->d_name);
                	realpath(sd->d_name,path);
			if(isdirectory(path)){
				printf("\t");
				depthFirst(opendir(sd->d_name));
			}		
		}
		        
                }
                

}
int isdirectory(char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) == -1)
      return 0;
	else
	return S_ISDIR(statbuf.st_mode); }
int main(int argc, char *argv[]){

	

	if(argc<2){
		printf("No arguments");
		DIR *dir;
		dir = opendir(".");
		depthFirst(dir);	
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

