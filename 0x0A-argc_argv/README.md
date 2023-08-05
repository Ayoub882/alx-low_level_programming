--argc (ARGument Count) is an integer variable that stores the number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, the value of argc would be 2 (one for argument and one for program name)
The value of argc should be non-negative.
--argv (ARGument Vector) is an array of character pointers listing all the arguments.
If argc is greater than zero, the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments.
For better understanding run this code on your Linux machine.

Example:


// program named mainreturn.c
#include <stdio.h>
 
// defining main with arguments
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
Terminal Input:

$ gcc mainreturn.c -o main 
$ ./main geeks for geeks
Output:

You have entered 4 arguments:
./main
geeks
for
geeks
