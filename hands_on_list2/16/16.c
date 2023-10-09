#include <stdio.h>
#include <stdlib.h>

int main() {
	int pipe_fd1[2];
	int pipe_fd2[2];
	char buffer[256];
	pid_t child_pid;

	if(pipe(pipe_fd1) == -1) {
		perror("pipe 1");
		exit(1);
	}

	if(pipe(pipe_fd2) == -1) {
		perror("pipe 2");
		exit(1);
	}

	child_pid = fork();

	if(child_pid == -1) {
		perror("fork");
		exit(1);
	}

	if(child_pid == 0) {
		close(pipe_fd1[1]);

		ssize_t bytes_read = read(pipe_fd1[0], buffer, 256);

		if(bytes_read == -1) {
			perror("read");
			exit(1);
		}

		printf("Child Process: Received data from the parent: %s, buffer");
		close(pipe_fd1[0]);
	}

	else {
		close(pipe_fd[0]);

		char message[256];

		ssize_t bytes_written = write(pipe_fd1[1], message, 256);

		if(bytes_written == -1) {
			perror("write");
			exit(1);
		}

		printf("Parent Process: Sent data to the child: %s", message);

		close(pipe_fd1[1]);
	}
}
