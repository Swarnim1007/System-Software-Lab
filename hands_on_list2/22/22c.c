#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

int main() {
    const char *fifo_path = "myfifo2";
    int fd;
    fd_set read_set;
    struct timeval timeout;

    // Create FIFO if it doesn't exist
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open FIFO for reading
    fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Set up the file descriptor set for select
    FD_ZERO(&read_set);
    FD_SET(fd, &read_set);

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data in FIFO...\n");

    // Wait for data to be written into FIFO within 10 seconds
    int select_result = select(fd + 1, &read_set, NULL, NULL, &timeout);

    if (select_result == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (select_result == 0) {
        printf("No data written into FIFO within 10 seconds.\n");
    } else {
        // Data is available to read from FIFO
        char buffer[256];
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[bytes_read] = '\0'; // Null-terminate the received data
        printf("Received data from FIFO: %s\n", buffer);
    }

    // Close the FIFO
    close(fd);

    // Remove the FIFO
    if (unlink(fifo_path) == -1) {
        perror("unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

