# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Follow the instructions explained in the beginning of file ejemplo1.c for compiling with gcc and g++ (you can try also clang). 

1-Compiler's Versions used in this practice:

gcc -> gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
g++ -> g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
clang -> version 14.0.0-1ubuntu1

2- Compiling tests of each compiler.

  2.1- Tests using the gcc compiler:
  
  	2.1.0 - I try the following standards and flags:
  		- No flags
  		- Wall Flag (Would be used with the following -std flags)
  		- std=c17
  		- std=c89
  		- std=c90
  		- std=c90 with -pedantic
  		- std=gnu11
  		
  	2.1.1 - Compile the program with no flags enabled:
  		The compiler generates the binary file.
  		gcc ejemplo1.c -o gcc_no_parameters 2> gcc_no_parameters.txt
  		Output: /pruebas_ejemplo1/gcc_no_parameters.txt
  		
  	2.1.2 - Compile the program with the flag that activates all Warnings:
  		The compiler generates the binary file.
  		gcc ejemplo1.c -Wall -o gcc_wall_parameter 2> gcc_wall_parameter.txt
  		Output: /pruebas_ejemplo1/gcc_wall_parameter.txt
  		
	2.1.3 - Try to obtain the default parameter -std used in the compilation:
		gcc -dM -E -x c  /dev/null | grep -F __STDC_VERSION_
		Output: __STDC_VERSION__ 201710L -> C17 (C standard revision)
		
	2.1.4 - Verify that the flag -std=c17 generates other errors:
		The compiler does not generates the binary file because the source code not 			 	
		verifies the sintaxis requisites of the standard.
		gcc ejemplo1.c -std=c17 -o gcc_stdc17_parameter 2> gcc_stdC17_parameter.txt
		Output: /pruebas_ejemplo1/gcc_stdC17_parameter.txt
		
	2.1.5 - Verify that the flag -std=c89 generates other errors but the same as c17:
		The compiler does not generates the binary file because the source code not 			 	
		verifies the sintaxis requisites of the standard.
		gcc ejemplo1.c -std=c89 -o gcc_stdc89_parameter 2> gcc_stdC89_parameter.txt
		Output: /pruebas_ejemplo1/gcc_stdC89_parameter.txt
		
	2.1.6 - Compare the differences between the flag -std=c90 and the combination of the flag 
		-std=c90 with the flag -pedantic
		
		The compiler does not generates the binary file because the source code not 			 	
		verifies the sintaxis requisites of the standard.
		
		-std=c90 makes gcc accept a superset of C90 (for example the more flexible C99 variable 	
		declarations anywhere in the program). In order to make gcc enforce the C90 standard, the 
		-pedantic flag needs to also be specified. 
		
		gcc ejemplo1.c -std=c90 -o gcc_stdc90_parameter 2> gcc_stdC90_parameter.txt
		Output: /pruebas_ejemplo1/gcc_stdC90_parameter.txt
		
		gcc ejemplo1.c -std=c90 -pedantic -o gcc_stdc90_pedantic_parameter 2> 
		gcc_stdC90_pedantic_parameter.txt
		Output: /pruebas_ejemplo1/gcc_stdC90_pedantic_parameter.txt
		
		
	2.1.7 - The last flag I try is -std=gnu11 that generates less errors than others:
		The compiler generates the binary file because the source code
		verifies the sintaxis requisites of the standard.
		gcc ejemplo1.c -std=gnu11 -o gcc_stdgnu11_parameter 2> gcc_stdgnu11_parameter.txt

	
	
  2.2- Tests using the g++ compiler:
  
  	2.2.0 - I try the following standards and flags:
  		- No flags
  		- Wall Flag (Would be used with the following -std flags)
  		- std=c++98
		- std=c++11
		- std=c++14
		- std=c++17
		- std=c++2a 
  		- std=gnu++11
  		
  	2.2.1 - Compile the program with no flags enabled:
  		The compiler does not generates the binary file because the source code not verifies the standard requisites.
  		g++ ejemplo1.c -o g++_no_parameters 2> g++_no_parameters.txt
  		Output: /pruebas_ejemplo1/g++_no_parameters.txt
  	
  	2.2.X - I used the following commands to compile with standards:
  		
  		g++ ejemplo1.c -Wall -o g++_wall_no_parameters 2> g++_wall_no_parameters.txt
  		g++ ejemplo1.c -std=c++98 -o gcc_stdc++98_parameter 2> gcc_stdc++98_parameter.txt
		g++ ejemplo1.c -std=c++11 -o gcc_stdc++11_parameter 2> gcc_stdc++11_parameter.txt
		g++ ejemplo1.c -std=c++14 -o gcc_stdc++14_parameter 2> gcc_stdc++14_parameter.txt
		g++ ejemplo1.c -std=c++17 -o gcc_stdc++17_parameter 2> gcc_stdc++17_parameter.txt	
		g++ ejemplo1.c -std=c++2a -o gcc_stdc++2a_parameter 2> gcc_stdc++2a_parameter.txt
		
		In conclusion,  the standards does not allow the sintaxis and the programming elements used in the source code and does not
		generates the binary executables. Depending on the standard we use, the compiler throws diferent warnings and errors of deprecated 		 
		functions and programming missuses are reflected in the file's traces located in the folder.

  2.3- Tests using the clang compiler:
  
  2.4- Fixing all warnings to compile the code with gcc compiler (For example with std=gnu11 and -Wall Flags):
  
 	- I obtain the following errors:
 	
 		1 - Non expected return value in a void function:
 	
			ejemplo1.c:34:16: warning: ‘return’ with a value, in function returning void [-Wreturn-type]
			   34 |         return 1;
			   
			- I fix it changing the expected return type of the function (void --> int)
		
	
			ejemplo1.c:30:6: note: declared here
		   	30 | void gets_example_func(void) {
		      	|      ^~~~~~~~~~~~~~~~~
			ejemplo1.c: In function ‘get_y_or_n’:
		
		2 - Deprecated function to read string from line input:
		
			ejemplo1.c:53:9: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
			   53 |         gets(response);
			      |         ^~~~
			      |         fgets
			      
			- I fix it changing the deprecated function with the new implementation that have a new parameter to select the max buffer to read 	
			(gets() --> fgets())
			
			
		3 - Comment the unused variables:
			
			ejemplo1.c:75:10: warning: unused variable ‘analitic3’ [-Wunused-variable]
			   75 |     char analitic3[100]="аналитик";
			      |          ^~~~~~~~~
			ejemplo1.c:71:9: warning: unused variable ‘size_array2’ [-Wunused-variable]
			   71 |     int size_array2 = 100;
			      |         ^~~~~~~~~~~
			ejemplo1.c:70:9: warning: unused variable ‘size_array1’ [-Wunused-variable]
			   70 |     int size_array1 = strlen("аналитик");
			      |         ^~~~~~~~~~~

  
  	

## ejemplo2.c. Program Instrumentation

Find the memory errors presented in file ejemplo2 using gcc instrumentation option **AddressSanitizer (ASan)**.
Explain in this file each error.






