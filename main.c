#include <stdio.h>
#include <string.h>
#define MAX_PATH 260

void input(char *arr)
{
int i;
    printf("Введите путь \n");
    for (i = 0;arr[i - 1] != 10 ; i++){
        arr[i] = getchar();
    }
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
    for (int i = 0; arr[i] != 10; i++){
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

void ShiftTo(char *arr, int to, int since)
{
int i, j;
     for (j = 0; j < to; j++){
         for (i = since; i < 260 - since; i++){
             arr[260 - i] = arr[260 - i - 1];
         }
     }

}

int slen(char *str)
{
int i, len;
    for (i = 0; str[i] != '\0'; i++);
    len = i;
    return len;
}

int scmp(char str1[], char str2[])
{
    if (slen(str1) != slen(str2))
        return 0;
    else for (int i = 0; str1[i] != '\0'; i++){
        if (str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;


}

void add(char *arr, int since, char symbol)
{
   ShiftTo(arr, 1, since);
   arr[since] = symbol;
}

int schr(char str[], char delim)
{
int i;
    for (i = 0; str[i] != delim;)
        if (str[i] != '\0')
            i++;
        else return -1;
    return i;
}

int stok(char str[], char delim, char *ptr[])
{
char *suf = str;
ptr[0] = str; // первое поле – начало str
int i, j = 1; // j – счетчик полей

for(; (i = schr(suf, delim)) >= 0 ;){
            suf[i] = '\0';
            suf = suf + i + 1;
            ptr[j] = suf;
            j++;
        }
    
return j;
}

void process(char *ptr[], int number)
{
int i, j;
    for (i = 0; ptr[number - 1][i] != '\0' ; i++){
        if ((ptr[number - 1][i] == 'e')  && (ptr[number - 1][i + 1] == 'x') && (ptr[number - 1][i + 2] == 'e')){
            ptr[number - 1][i] = 'b';
            ptr[number - 1][i + 1] = 'i';
            ptr[number - 1][i + 2] = 'n';
        }
    }
 
printf("process: %s i = %d\n", ptr[number - 1], i);

}

void checkData(char *ptr[])
{
int i, j = 0, point = 0;
   for (i = 0; ptr[2][i] != '\0'; i++){
        if (ptr[2][i] == '.'){
            point++;
            j = i;
        }
    }
    //for (i = 0; ptr[i] != '
printf("point = %d j = %d \n", point, j);

}

int main()
{
char value[270] = {0};
char *ptr[20], delim = 92, cygdrive[] = "cygdrive";
int k = -5, checkRez[2] = {-5, -5}, len, i, scm;
   
    input(value);
    int j = stok(value, delim, ptr);
printf("ptr: %c \n", ptr[2][1]);
   // process(ptr, j);
    checkData(ptr);

    return 0;
}
