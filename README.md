# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Follow the instructions explained in the beginning of file ejemplo1.c for compiling with gcc and g++ (you can try also clang). 

1-Compiler's Versions used in this practice:

gcc -> gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
g++ -> g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
clang -> version 14.0.0-1ubuntu1

2- Compiling tests of each compiler.

  2.1- Tests using the gcc compiler:
  
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
		
	2.1.6 - The last flag I try is -std=gnu11 that generates less errors than others:
		The compiler generates the binary file because the source code
		verifies the sintaxis requisites of the standard.
		gcc ejemplo1.c -std=gnu11 -o gcc_stdgnu11_parameter 2> gcc_stdgnu11_parameter.txt

	
	
  2.1- 

## ejemplo2.c. Program Instrumentation

Find the memory errors presented in file ejemplo2 using gcc instrumentation option **AddressSanitizer (ASan)**.
Explain in this file each error.
