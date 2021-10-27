#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int gen_rand() {
    int a = open("/dev/urandom", O_RDONLY, 0);
    int p[1];
    read(a, p, 4);
    return p[0];
}

int main() {
    int rand[10];
    int i;
    for (i = 0; i < 10; i++) {
      rand[i] =  gen_rand();
    }
    printf("Generating random numbers:");
    for (i = 0; i < 10; i++) {
        printf("\n\trandom %d: %d", i, rand[i]);
    }

    printf("\n\nWriting numbers to file...");
    int file = open("writetarget.txt", O_RDWR, 0);
    write(file, rand, 4);
    write(file, rand + 1, 4);
    write(file, rand + 2, 4);
    write(file, rand + 3, 4);
    write(file, rand + 4, 4);
    write(file, rand + 5, 4);
    write(file, rand + 6, 4);
    write(file, rand + 7, 4);
    write(file, rand + 8, 4);
    write(file, rand + 9, 4);

    printf("\n\nReading numbers from file...");
    int rand2[10];
    read(file, rand2 + 9, 4);
    read(file, rand2 + 8, 4);
    read(file, rand2 + 7, 4);
    read(file, rand2 + 6, 4);
    read(file, rand2 + 5, 4);
    read(file, rand2 + 4, 4);
    read(file, rand2 + 3, 4);
    read(file, rand2 + 2, 4);
    read(file, rand2 + 1, 4);
    read(file, rand2, 4);

    printf("\n\nVerification that written values were the same:");
    for (i = 0; i < 10; i++)
        printf("\n\trandom %d: %d", i, rand2[i]);
}