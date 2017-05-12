#include <stdio.h>
#define MAX_PATH 260

void input(char *arr)
{
int i;
    printf("Введите путь (в конце пробел)\n");
    for (i = 0;arr[i - 1] != ' ' ; i++){
        arr[i] = getchar();
    }
    arr[i - 1] = ' ';
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

void delete(char *arr, int since, int quantity)
{
int i, j;
    for (j = 0; j < quantity; j++){
        for (i = since; i < 260 - 1; i++){
            arr[i] = arr[i + 1];
        }
    }
}

void clean(char *arr)
{
int i;
    for (i = 0; i < 260; i++){
        arr[i] = ' ';
    }
}

void print(char *arr)
{
    for (int i = 0; i < 10; i++){
        printf ("%c", arr[i]);
    }
    printf("\n");
}

void up(char *arr, int since)
{
    arr[since] -=32;
}

void substitution(char *arr, char before, char after)
{
int i;
    for (i = 0; i < 260; i++){
        if (arr[i] == before){
            arr[i] = after;
        }
    }
}

int main()
{
char value[270] = {0};
int k = -5, checkRez[2] = {-5, -5};

    input(value);
    substitution(value, 92, '/');//  92 = '\'

    print(value);

    return 0;
}
