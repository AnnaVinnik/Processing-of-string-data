#include <stdio.h>
#include <string.h>
#include "lib.h"
#define MAX_PATH 260

int main()
{
char value[270] = {0};
char *ptr[20], delim = 92, cygdrive[] = "cygdrive";
int k = -5, i, l, j;
   
    input(value);
    l = check(value);
    j = stok(value, delim, ptr);
    process(ptr, j);
    k = checkData(ptr);
    suntok(delim, ptr, j);
    if (l == 0)
        printf("\nIs UNC: yes\n");
    if (l == 1)
        printf("\nIs UNC: no \n");
    if (k == 1)
        printf("Domain name is correct: no\n");
    if (k == 0)
        printf("Domain name is correct: yes\n");
    printf("Updated path: %s", value);


    return 0;
}
