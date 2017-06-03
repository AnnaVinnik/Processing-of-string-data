#include <stdio.h>
#include <string.h>
#include "lib.h"
#define MAX_PATH 260

void input(char *arr)
{
int i;
    printf("Введите путь \n");
    for (i = 0;arr[i - 1] != 10 ; i++){
        arr[i] = getchar();
    }
}

int check(char *arr)
{
int i, j;
char forbiddenSymbol[8] = {'/', ':', '*', '?', 34, '<', '>', '|'};

    /*for (i = 260; i < 270; i++){
        if (arr[i] != 0){
            return 1;
        }
    }*/
    for (i = 0; i < 260; i++){
        for (j = 0; j < 8; j++){
            if (arr[i] == forbiddenSymbol[j]){
                return 1;
            }
        }
    }

return 0;
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
 

}

int checkData(char *ptr[])
{
char org[] = "org", ru[] = "ru", com[] = "com";
int i, j = 0, point = 0, swch = 0;
   for (i = 0; ptr[2][i] != '\0'; i++){
        if (ptr[2][i] == '.'){
            point++;
            j = i;
        }
    }
    if (point > 3)
        return 1;

    if ((i - j - 1 == 3) && (ptr[2][i + j + 1] == 'c')){
        for (i = 0; ptr[2][i + j + 1] != '\0'; i++)
            if (ptr[2][i + j + 1] != com[i])
            return 1;
    }
    if ((i - j - 1 == 3) && (ptr[2][i + j + 1] == 'o')){
        for (i = 0; ptr[2][i + j + 1] != '\0'; i++)
            if (ptr[2][i + j + 1] != com[i])
                return 1;
    }
    if (i - j - 1 ==2){
        for(i = 0; ptr[2][i + j + 1] != '\0'; i++){
            if (ptr[2][i + j + 1] != ru[i])
                return 1;
            }
    }

}

void suntok(char newDelim, char *ptr[], int j)
{
int i;
    for(i = 1; i < j; i++){
        *(ptr[i] - 1) = newDelim;
    }
}
