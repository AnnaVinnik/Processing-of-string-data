#include <stdio.h>

void input(char *arr)
{
int i;
    printf("Введите путь (в конце пробел)\n");
    for (i = 0;arr[i - 1] != ' ' ; i++){
        arr[i] = getchar();
    }
}

int main()
{
char value[50] = {}, k;
input(value);
printf("str:%c %c \n", value[2], value[3] );
    return 0;
}
