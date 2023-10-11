/*
 * ============================================================================
 Name : 33.c
 Author : Swarnim Kukreti
 Description : Write a program to communicate between two machines using socket.
 Date: 12th OCT, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "172.16.145.2"
#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    strcpy(buffer, "Hello, Server!");
    send(client_socket, buffer, strlen(buffer), 0);
    printf("Sent: %s\n", buffer);

    // Receive a response from the server
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        perror("Error receiving data");
    } else {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}


