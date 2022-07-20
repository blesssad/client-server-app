#include "error.hpp"

int main(int argc, char *argv[])
{
    if (argc == 3) 
    {
        string str;
        char buf[buf_len];
        int cnt = 0;

        getline(cin, str);
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')
            {
                cnt++;   
            }
        }
        if (cnt != 1)
        {
            cout << "enter 2 words!" << endl;
            return 1;
        }
        int client = socket_func(PF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;

        addr.sin_family =  AF_INET;
        addr.sin_port = htons(stoi(argv[2])); //stoi(argv[2])
        addr.sin_addr.s_addr = inet_addr(argv[1]); // argv[1]
        memset(&(addr.sin_zero), '\0', sizeof addr.sin_zero);

        connect_func(client, (struct sockaddr *) &addr, sizeof addr);
        send_func(client, str.c_str(), sizeof str, 0);
        recv_func(client, &buf, buf_len, 0);

        cout << "Response from the server: " << buf << endl;

        close(client);
    }
    else
    {
        cout << "enter 3 argumets! " << argc << endl;
    }
    return 0;
}