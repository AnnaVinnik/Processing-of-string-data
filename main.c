#include <stdio.h>

void input(char *array)
{
array[2] = '2';


}

int main()
{
char value[5] = {}, k;

input(value);
printf("%c\n", value[2]);
    return 0;
}
