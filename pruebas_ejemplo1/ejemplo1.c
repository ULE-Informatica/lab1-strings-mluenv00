/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };

//(Not supported for C17 standard) 
//const char* s1 = R"foo(Hello 
//World)foo";

const char* s1 = "Hello\nWorld";

const char* s2 = "\nHello\nWorld\n";

int gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  
  buf[strlen(buf) - 1] = '\0';
  
 return 0;
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(char *response) {  
	//char response[2]; unused local variable

	
	//gets(response); // deprecated vulnerable function that should be replaced by fgets
	
	do{
		printf("Continue? [y] n: ");  
		fgets(response,sizeof(response),stdin); // an alternative to use gets function
		fflush(stdout);
	}while(tolower(response[0]) != 'n' && tolower(response[0]) != 'y');
	
	
	
	if (tolower(response[0]) == 'n'){
		response[0]='n';
		response[1]='\0';
		exit(0); 
	} 
	else if (tolower(response[0]) == 'y')
	{
		response[0]='n';	
		response[1]='\0';
		return;
	}
		 

	
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[2];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal"; // literal variable read only
    
    //int size_array1 = strlen("аналитик"); // Unused variable, I should delete it.
    //int size_array2 = 100; // Unused variable, I should delete it.
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
   // char analitic3[100]="аналитик"; // Unused variable, I should delete it.

    puts(get_dirname(__FILE__));
    
   
    //line argument comprobation, it necessary also to sanitize the inputs. ----------
    if (argc == 3){
    	strcpy(key, argv[1]);  	
    	strcat(key, " = ");  
    	strcat(key, argv[2]);
    }

    //fgets(response,sizeof(response),stdin); not necesary line
    
    //Obtain the same result passing response as a argument
    get_y_or_n(response);

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");

    
    //strncpy(array3, array5, sizeof(array3));  // Fit the string to copy from array5 to strlen(array3):
    strncpy(array3, array5, sizeof(array3)); 
    
    //strncpy(array4, array3, strlen(array3)); // Fit to the dst array
    strncpy(array4, array3,  strlen(array3)); 
    
    array5[0] = 'M'; 
    //printf("%c", array5[0]);
    
    //*ptr_char[0] = 'N'; //invalid type assignation, ptr_char is a pointer that points to the first index of memory location array, the memory of a literal is a only read memory.
    // you can read the string:
    
    printf ("%s",ptr_char);
    printf ("\n");
    
    // or only a character:
    
    printf ("%c",ptr_char[0]);
    printf ("\n");
    
    
    array3[sizeof(array3)-1]='\0';
    
    return 0;
}
