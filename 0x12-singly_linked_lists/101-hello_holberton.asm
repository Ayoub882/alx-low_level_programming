section .data
    hello_msg db "Hello, Holberton", 10, 0  ; 10 is the ASCII code for newline

section .text
    global main
    extern printf

main:
    sub rsp, 8          ; Align the stack to 16 bytes (8 bytes for function calls)
    mov rdi, hello_msg ; Load the address of the string into rdi
    call printf        ; Call the printf function
    add rsp, 8          ; Restore the stack pointer
    xor eax, eax       ; Set the return value to 0
    ret                ; Return from main

