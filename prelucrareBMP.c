#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void permisiuni(struct stat file)
{
    if(file.st_mode & S_IRUSR)
        printf("R");
    else
        printf("-");
    if(file.st_mode & S_IWUSR)
            printf("W");
    else
        printf("-");
    if(file.st_mode & S_IXUSR)
        printf("X");
    else
       printf("-");
    printf("\n");

    if(file.st_mode & S_IRGRP)
        printf("R");
    else
        printf("-");
    if(file.st_mode & S_IWGRP)
        printf("W");
    else
        printf("-");
    if(file.st_mode & S_IXGRP)
        printf("X");
    else
        printf("-");
    printf("\n");

    if(file.st_mode & S_IROTH)
        printf("R");
    else
        printf("-");
    if(file.st_mode & S_IWOTH)
        printf("W");
    else
        printf("-");
    if(file.st_mode & S_IXOTH)
        printf("X");
    else
        printf("-");
    printf("\n");
}


int main(int argc, char **argv) {
    if (argc != 2)
        printf("Usage ./program <fisier_intrare>");

    struct stat file;
    if (stat( argv[1], &file) == 0) {
        if (S_ISREG(file.st_mode)) {
            printf("fisierul s-a deschis cu succes si este un REG\n");
        }
        else {
            printf("fisierul s-a deschis cu succes dar nu este un REG\n");
            exit(EXIT_FAILURE);
            return 0;
        }
    }
    else {
        printf("fisierul nu s-a putut deschide\n");
        exit(EXIT_FAILURE);
        return 0;
    }

    if(S_ISREG(file.st_mode))
    {
        permisiuni(file);
    }

}