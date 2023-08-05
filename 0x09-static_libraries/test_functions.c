#include "main.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// Function to test _putchar
void test_putchar(void) {
    assert(_putchar('H') == 72);
    assert(_putchar('\n') == 10);
    // Add more test cases for _putchar if needed
}

// Function to test _isupper
void test_isupper(void) {
    assert(_isupper('A') == 1);
    assert(_isupper('a') == 0);
    // Add more test cases for _isupper if needed
}

// Function to test _memset
void test_memset(void) {
    char arr[5];
    _memset(arr, 'X', 5);
    assert(arr[0] == 'X');
    assert(arr[4] == 'X');
    // Add more test cases for _memset if needed
}

// Function to test _strcat
void test_strcat(void) {
    char dest[20] = "Hello, ";
    char src[] = "world!";
    _strcat(dest, src);
    assert(strcmp(dest, "Hello, world!") == 0);
    // Add more test cases for _strcat if needed
}

// Function to test _isdigit
void test_isdigit(void) {
    assert(_isdigit('5') == 1);
    assert(_isdigit('A') == 0);
    // Add more test cases for _isdigit if needed
}

// Function to test _memcpy
void test_memcpy(void) {
    char src[] = "Hello, World!";
    char dest[20];
    _memcpy(dest, src, 5);
    assert(strcmp(dest, "Hello") == 0);
    // Add more test cases for _memcpy if needed
}

// Function to test _strncat
void test_strncat(void) {
    char dest[20] = "Hello, ";
    char src[] = "world!";
    _strncat(dest, src, 3);
    assert(strcmp(dest, "Hello, wor") == 0);
    // Add more test cases for _strncat if needed
}

// Function to test _strchr
void test_strchr(void) {
    char str[] = "Hello, World!";
    assert(_strchr(str, 'l') == &str[2]);
    assert(_strchr(str, 'W') == &str[7]);
    assert(_strchr(str, 'z') == NULL);
    // Add more test cases for _strchr if needed
}

// Function to test _strlen
void test_strlen(void) {
    char str[] = "Hello, World!";
    assert(_strlen(str) == 13);
    assert(_strlen("") == 0);
    // Add more test cases for _strlen if needed
}

// Function to test _strncpy
void test_strncpy(void) {
    char dest[20];
    char src[] = "Hello, World!";
    _strncpy(dest, src, 5);
    assert(strcmp(dest, "Hello") == 0);
    // Add more test cases for _strncpy if needed
}

// Function to test _islower
void test_islower(void) {
    assert(_islower('a') == 1);
    assert(_islower('A') == 0);
    // Add more test cases for _islower if needed
}

// Function to test _puts
void test_puts(void) {
    _puts("Hello, World!");
    // No assertion here as we are testing the output manually
}

// Function to test _strcmp
void test_strcmp(void) {
    assert(_strcmp("Hello", "Hello") == 0);
    assert(_strcmp("Hello", "Hello, World!") < 0);
    assert(_strcmp("Hello, World!", "Hello") > 0);
    // Add more test cases for _strcmp if needed
}

// Function to test _strspn
void test_strspn(void) {
    char str[] = "Hello, World!";
    char accept[] = "Heo, Wrld";
    assert(_strspn(str, accept) == 12);
    // Add more test cases for _strspn if needed
}

// Function to test _isalpha
void test_isalpha(void) {
    assert(_isalpha('A') == 1);
    assert(_isalpha('a') == 1);
    assert(_isalpha('Z') == 1);
    assert(_isalpha('z') == 1);
    assert(_isalpha('0') == 0);
    assert(_isalpha('*') == 0);
    // Add more test cases for _isalpha if needed
}

// Function to test _strpbrk
void test_strpbrk(void) {
    char str[] = "Hello, World!";
    char accept[] = "rdWl";
    assert(_strpbrk(str, accept) == &str[2]);
    // Add more test cases for _strpbrk if needed
}

// Function to test _strstr
void test_strstr(void) {
    char haystack[] = "Hello, World!";
    char needle[] = "World";
    assert(_strstr(haystack, needle) == &haystack[7]);
    // Add more test cases for _strstr if needed
}

// Function to test _abs
void test_abs(void) {
    assert(_abs(5) == 5);
    assert(_abs(-5) == 5);
    // Add more test cases for _abs if needed
}

// Function to test _strcpy
void test_strcpy(void) {
    char dest[20];
    char src[] = "Hello, World!";
    _strcpy(dest, src);
    assert(strcmp(dest, "Hello, World!") == 0);
    // Add more test cases for _strcpy if needed
}

// Function to test _atoi
void test_atoi(void) {
    assert(_atoi("123") == 123);
    assert(_atoi("-123") == -123);
    // Add more test cases for _atoi if needed
}

int main(void) {
    // Call test functions for each function to test
    test_putchar();
    test_isupper();
    test_memset();
    test_strcat();
    test_isdigit();
    test_memcpy();
    test_strncat();
    test_strchr();
    test_strlen();
    test_strncpy();
    test_islower();
    test_puts();
    test_strcmp();
    test_strspn();
    test_isalpha();
    test_strpbrk();
    test_strstr();
    test_abs();
    test_strcpy();
    test_atoi();

    printf("All tests passed successfully!\n");
    return 0;
}

