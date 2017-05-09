#include <stdio.h>

int function(int *value)
{

return value[1];

}

int main()
{
int value[5] = {}, k;

    k = function(value);
printf("%d\n", k);
    return 0;
}
