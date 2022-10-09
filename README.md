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

There are 4 possible proccesed inputs in the program: 1,2,3,4:

The asan commands are the following:

	gcc ejemplo2.c -std=c17 -Wall -o ejemplo2_asan -fsanitize=address -static-libasan -g

	./ejemplo2_asan 1 2> asan_parameter1.txt -> No memory leaks
	
	./ejemplo2_asan 2 2> asan_parameter2.txt -> memory leak:
	
		=================================================================
		==20336==ERROR: LeakSanitizer: detected memory leaks

		Direct leak of 100 byte(s) in 1 object(s) allocated from:
		    #0 0x561a1827f0f7 in malloc (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x980f7)
		    #1 0x561a182c4cf2 in optionTwo /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:15
		    #2 0x561a182c50cc in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:64
		    #3 0x7f2efee98d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

		SUMMARY: AddressSanitizer: 100 byte(s) leaked in 1 allocation(s).
		=================================================================

	
	./ejemplo2_asan 3 2> asan_parameter3.txt -> heap use after call free function
	
=================================================================
==20343==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x564c22160b73 bp 0x7ffe458854b0 sp 0x7ffe45884c58
WRITE of size 19 at 0x60b0000000f0 thread T0
    #0 0x564c22160b72 in __interceptor_memcpy (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x1db72)
    #1 0x564c22220d70 in optionThree /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:23
    #2 0x564c222210d8 in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:67
    #3 0x7f707e759d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7f707e759e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x564c2214b3c4 in _start (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x83c4)

0x60b0000000f0 is located 0 bytes inside of 100-byte region [0x60b0000000f0,0x60b000000154)
freed by thread T0 here:
    #0 0x564c221dada7 in free (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x97da7)
    #1 0x564c22220d55 in optionThree /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:22
    #2 0x564c222210d8 in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:67
    #3 0x7f707e759d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

previously allocated by thread T0 here:
    #0 0x564c221db0f7 in malloc (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x980f7)
    #1 0x564c22220d45 in optionThree /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:21
    #2 0x564c222210d8 in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:67
    #3 0x7f707e759d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-use-after-free (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x1db72) in __interceptor_memcpy
Shadow bytes around the buggy address:
  0x0c167fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff8000: fa fa fa fa fa fa fa fa fd fd fd fd fd fd fd fd
=>0x0c167fff8010: fd fd fd fd fd fa fa fa fa fa fa fa fa fa[fd]fd
  0x0c167fff8020: fd fd fd fd fd fd fd fd fd fd fd fa fa fa fa fa
  0x0c167fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==20343==ABORTING
=================================================================
	
	./ejemplo2_asan 4 2> asan_parameter4.txt -> heap overflow
=================================================================
==20381==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000052 at pc 0x55bab3a1cb73 bp 0x7ffff4f31b10 sp 0x7ffff4f312b8
WRITE of size 19 at 0x603000000052 thread T0
    #0 0x55bab3a1cb72 in __interceptor_memcpy (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x1db72)
    #1 0x55bab3adcdc3 in optionFour /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:29
    #2 0x55bab3add0e4 in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:70
    #3 0x7f4222371d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7f4222371e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x55bab3a073c4 in _start (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x83c4)

0x603000000052 is located 0 bytes to the right of 18-byte region [0x603000000040,0x603000000052)
allocated by thread T0 here:
    #0 0x55bab3a970f7 in malloc (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x980f7)
    #1 0x55bab3adcda4 in optionFour /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:28
    #2 0x55bab3add0e4 in main /home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2.c:70
    #3 0x7f4222371d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow (/home/lab/Escritorio/DPS/lab1-strings-mluenv00/pruebas_ejemplo2/ejemplo2_asan+0x1db72) in __interceptor_memcpy
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00[02]fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==20381==ABORTING
=================================================================







