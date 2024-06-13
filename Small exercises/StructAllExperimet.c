#include <stdio.h>

typedef struct
{
    char a;
    void* ptr;
    char b;
} Foo_24_bytes;

typedef struct
{
    void* ptr;
    char a;
    char b;
} Foo_16_bytes;

typedef struct
{
    char a;
    char b;
    void* ptr;
} Foo_16_bytes2;

int main()
{
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(void*) = %zu\n", sizeof(void*));

    printf("sizeof(Foo_24_bytes) = %zu\n", sizeof(Foo_24_bytes));
    printf("sizeof(Foo_16_bytes) = %zu\n", sizeof(Foo_16_bytes));
    printf("sizeof(Foo_16_bytes) = %zu\n", sizeof(Foo_16_bytes2));

    return 0;
}