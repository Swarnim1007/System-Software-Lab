#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void print_opening_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("Error getting file flags");
        exit(1);
    }

    if (flags & O_RDONLY)
        printf("Read-only mode\n");
    else if (flags & O_WRONLY)
        printf("Write-only mode\n");
    else if (flags & O_RDWR)
        printf("Read-write mode\n");
    else
        printf("Unknown mode\n");

    if (flags & O_APPEND)
        printf("Append mode\n");
    if (flags & O_TRUNC)
        printf("Truncate mode\n");
    if (flags & O_CREAT)
        printf("Create mode\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    print_opening_mode(fd);

    close(fd);

    return 0;
}

