#include <stdio.h>
#define MAX_PATH 260

void input(char *arr)
{
int i;
    printf("Введите путь (в конце пробел)\n");
    for (i = 0;arr[i - 1] != ' ' ; i++){
        arr[i] = getchar();
    }
    arr[i - 1] = '0';
}

void check(char *arr, int *rez)
{
int i, j;
char forbiddenSymbol[9] = {'/', ':', '*', '?', 92, 34, '<', '>', '|'};

    for (i = 260; i < 270; i++){
        if (arr[i] != 0){
            rez[0] = 1;
        }
    }
    for (i = 0; i < 260; i++){
        for (j = 0; j < 10; j++){
            if (arr[i] == forbiddenSymbol[j]){
                rez[0] = 2;
                rez[1] = i;
            }
        }
    }


}

int main()
{
char value[270] = {0};
int k = -5, checkRez[2] = {-5, -5};

    input(value);

    check(value, checkRez);
    printf("check: %d  %d\n", checkRez[0], checkRez[1]);

    return 0;
}
