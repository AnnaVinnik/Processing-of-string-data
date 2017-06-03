#ifndef LIB_H
#define LIB_H

void input(char *arr);
int check(char *arr);
void delete(char *arr, int since, int quantity);
void clean(char *arr);
int slen(char *str);
int scmp(char str1[], char str2[]);
int schr(char str[], char delim);
int stok(char str[], char delim, char *ptr[]);
void process(char *ptr[], int number);
int checkData(char *ptr[]);
void suntok(char newDelim, char *ptr[], int j);

#endif
