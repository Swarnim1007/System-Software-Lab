#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char *fifo_path = "myfifo";

    // Create the FIFO if it does not exist
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("Error creating FIFO");
        exit(EXIT_FAILURE);
    }

    // Open the FIFO for writing
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Write data to the FIFO
    char message[] = "Hello from Writer";
    write(fd, message, strlen(message));

    // Close the FIFO
    close(fd);

    return 0;
}

