#include "server_functions.hpp"
 
int main(int argc, char *argv[])
{
    if (argc == 3) 
    {
        string answer;
        char buffer[buf_len];
        int server = socket_func(PF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        socklen_t addr_lenght; 

        addr.sin_family = AF_INET;
        addr.sin_port = htons(stoi(argv[2])); //stoi(argv[2]) 2405
        addr.sin_addr.s_addr = inet_addr(argv[1]); // argv[1] 127.0.0.1
        memset(&(addr.sin_zero), '\0', sizeof addr.sin_zero);
        addr_lenght = sizeof addr; 

        bind_func(server, (struct sockaddr *) &addr, sizeof addr);
        listen_func(server, 10);

        while (true)
        {
            int file_descriptor = accept_func(server, (struct sockaddr *) &addr, &addr_lenght);
            recv_func(file_descriptor, &buffer, buf_len, 0);
            answer = count_of_words(buffer); 
            send_func(file_descriptor, answer.c_str(), sizeof answer, 0);

            close(file_descriptor);
            sleep(1);
        }
        
        close(server);
    }
    else
    {
        cout << "enter 3 argumets! " << argc << endl;
    }
    return 0;
}

// ./server 127.0.0.1 2405