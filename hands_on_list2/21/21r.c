#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char *fifo_path = "myfifo";

    // Open the FIFO for reading
    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the FIFO
    char message[100];
    read(fd, message, sizeof(message));

    // Print the received message
    printf("Received message: %s\n", message);

    // Close the FIFO
    close(fd);

    // Remove the FIFO file
    unlink(fifo_path);

    return 0;
}

