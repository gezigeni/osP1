#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>

//indentation is set to a static global variable. It is 4 as default. 
static int indentation = 4;
static int numberlink;

//this function prints last accessed time modification of a file
void printaccess(char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) == -1)
      		perror("Failed to get file status");
	else
		printf("%s last accessed at %s", path, ctime(&statbuf.st_atime));
}
//depth first function 
void depthFirst(char * path){
        struct dirent *sd;
	DIR *dir;
        char rpath[PATH_MAX];
	dir = opendir(path);
        int i;        
	struct stat sb;
		//if the directory can not be opened it returns null and terminates the program with exit(1) code
                if(dir == NULL){
                        printf("Error, unable to open\n");
                        exit(1);
                }
		//it loops until it reads the last directory in the current directory, returns null when it reaches to end
                while( (sd = readdir(dir)) != NULL){
			//ignoring .  ,  .. 
			if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0){
			//prints a space in the amount of static variable indentation
			for(i = 0; i < indentation; i++){
                                       printf(" ");
                        }
			
			printf("%s\n",sd->d_name);
			realpath(sd->d_name,rpath);
		
			
	
			if(isdirectory(rpath)){
				depthFirst(sd->d_name);
			
				
			}		
			                       
		}
		        
                }

        
	closedir(dir);
}
int groupId(char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) == -1){
        perror("stat");
   }
        else
        return statbuf.st_gid; 
}
int userId(char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) == -1){
        perror("stat");
   }
        else
        return statbuf.st_uid;
}
int numberLinks(char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) == -1){
	perror("stat");
      return 0;
   }
        else
        return S_ISLNK(statbuf.st_nlink); }
int isdirectory(char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) == -1){
	perror("stat");
      return 0;
   }
	else
	return S_ISDIR(statbuf.st_mode); }
int main(int argc, char *argv[]){
	char * path;
	char * currentDirectory = ".";
	int i;
	int userid,groupid;

	if(argc<2){
		printf("No arguments");
		//currentDirectory = ".";
		depthFirst(currentDirectory);
	}
	else{                
		path = argv[1];
	

		int c;
		while( (c = getopt(argc, argv, "hI:Ldgipstul")) != -1){
		
			switch(c){
				case 'h':
					printf("This is the help message, please read README file for further information");
					exit(1);
					printf("In the help page\n");
					break;
				case 'I':
                                        printf("Setting indentation\n");
					indentation = atoi(optarg);
					printf("Indentation is: %d\n", indentation);
                                        break;
				 case 'L':
                                        printf("Following symbolic links\n");
                                        break;
				 case 'd':
                                        //printf("Time of last modification\n");
                                        if(argc<2)
						printaccess(currentDirectory);
                                       	else
						printaccess(path);
					break;
				 case 'g':
                                        //printf("Print group id\n");
					groupid = groupId(path);
                                        printf("Group Id is: %d\n",groupid);
					break;
				 case 'i':
                                        printf("Print number of links in inode table\n");
					int numberlink = numberLinks(path);
                        		printf("number of links: %d\n",numberlink);
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
                                        //printf("Print user id\n");
					userid = userId(path);
                                        printf("User Id is: %d\n",userid);
                                        break;
				 case 'l':
                                        printf("Optional one\n");
                                        break;	
				default:
					perror("Not a valid command-line argument");
					break;



		}
			
		



		}
		
		if (optind < argc) {
			path = argv[optind];
			//printf(path);
			depthFirst(path);
		}else 
			depthFirst(currentDirectory);
	}				
		//depthFirst(path);
		return 0;
	}







