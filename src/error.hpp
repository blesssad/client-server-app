#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#define buf_len 128

using namespace std;

int socket_func(int domain, int type, int protocol)
{
    int result = socket(PF_INET, SOCK_STREAM, 0);
    if (result == -1)
    {
        cout << "socket failed!" << endl;
        exit(EXIT_FAILURE);
    }
    return result;
}

void bind_func(int sockfd, const struct sockaddr *addr, socklen_t addrlen) 
{
    int result = bind(sockfd, addr, addrlen);
    if (result == -1) 
    {
        cout << "bind failed!" << endl;
        exit(EXIT_FAILURE);
    }
}

void listen_func(int sockfd, int backlog)
{
    int result = listen(sockfd, backlog);
    if (result == -1)
    {
        cout << "listen failed!" << endl;
        exit(EXIT_FAILURE);
    }
}

void connect_func(int sockfd, const struct sockaddr *addr, socklen_t addrlen) 
{
    int result = connect(sockfd, addr, addrlen);
    if (result == -1) 
    {
        cout << "connect failed" << endl;
        exit(EXIT_FAILURE);
    }
}

int accept_func(int sockfd, struct sockaddr *addr, socklen_t *addrlen) 
{
    int result = accept(sockfd, addr, addrlen);
    if (result == -1) 
    {
        cout << "accept failed" << endl;
        exit(EXIT_FAILURE);
    }
    return result;
}

void send_func(int sockfd, const void* buf, size_t n, int flags)
{
    int result = send(sockfd, buf, n, flags);
    if (result == -1)
    {
        cout << "send failed!" << endl;
        exit(EXIT_FAILURE);
    }
}

void recv_func(int sockfd, void* buf, size_t n, int flags)
{
    int result = recv(sockfd, buf, n, flags);
    if (result == -1)
    {
        cout << "recv failed!" << endl;
        exit(EXIT_FAILURE);
    }
}