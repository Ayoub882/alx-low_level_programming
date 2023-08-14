The C Preprocessor is not a part of the compiler, but is a separate step in the compilation process. In simple terms, a C Preprocessor is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation. We'll refer to the C Preprocessor as CPP.

All preprocessor commands begin with a hash symbol (#). It must be the first nonblank character, and for readability, a preprocessor directive should begin in the first column.

Sr.No.	Directive & Description
1
#define

Substitutes a preprocessor macro.

2
#include

Inserts a particular header from another file.

3
#undef

Undefines a preprocessor macro.

4
#ifdef

Returns true if this macro is defined.

5
#ifndef

Returns true if this macro is not defined.

6
#if

Tests if a compile time condition is true.

7
#else

The alternative for #if.

8
#elif

#else and #if in one statement.

9
#endif

Ends preprocessor conditional.

10
#error

Prints error message on stderr.

11
#pragma

Issues special commands to the compiler, using a standardized method.
