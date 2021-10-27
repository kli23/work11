#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int s = sizeof(unsigned int);
unsigned int gen_rand() {
    int a = open("/dev/urandom", O_RDONLY);
    unsigned int p[1];
    if ( read(a, p, s) < s) return 0;
    return p[0];
}

int main() {
    unsigned int rand[10];
    int i;
    for (i = 0; i < 10; i++) {
      rand[i] =  gen_rand();
    }
    printf("Generating random numbers:");
    for (i = 0; i < 10; i++) {
        printf("\n\trandom %d: %u", i, rand[i]);
    }

    printf("\n\nWriting numbers to file...");
    int file = open("writetarget.txt", O_RDWR | O_CREAT, 0644);
    int check = write(file, rand, s * 10);
    if (check != s * 10) printf("\nerror!!\n");

    printf("\n\nReading numbers from file...");
    unsigned int rand2[10];
    int file2 = open("writetarget.txt", O_RDONLY, 0);
    check = read(file2, rand2, s * 10);
    if (check != s * 10) printf("\nerror!!\n");


    printf("\n\nVerification that written values were the same:");
    for (i = 0; i < 10; i++)
        printf("\n\trandom %d: %u", i, rand2[i]);
    printf("\n");
    }