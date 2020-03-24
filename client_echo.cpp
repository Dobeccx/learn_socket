#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
    size_t client_fd = socket(AF_INET,SOCK_STREAM,0);
    if(client_fd==-1)
    {
        std::cout<<"create client socket error."<<std::endl;
        return -1;
    }

    struct sockaddr_in server_socket_addr;
    server_socket_addr.sin_family = AF_INET;
    server_socket_addr.sin_addr.s_addr =inet_addr("127.0.0.1");
    server_socket_addr.sin_port = htons(3000);
    if(connect(client_fd,(struct sockaddr*)&server_socket_addr,sizeof(server_socket_addr))==-1)
    {
        std::cout << "connect socket error." << std::endl;
        return -1;
    }
    char recv_buf[64]={0};
    int ret = recv(client_fd,recv_buf,sizeof(recv_buf),0);
    if(ret>0)
    {
        std::cout << "recv data successfully, data: " << recv_buf << std::endl;
    } 
    else 
    {
	std::cout << "recv data error, data: " << recv_buf << std::endl;
    }
    char send_data[64] = {0};
    while(true)
    {
        memset(send_data,0,sizeof(send_data));
        std::cin>>send_data;
        ret = send(client_fd,send_data,strlen(send_data),0);
        if (ret != strlen(send_data))
	{
            std::cout << "send data error." << std::endl;
            return -1;
	}
        ret = recv(client_fd,recv_buf,sizeof(recv_buf),0);
        if(ret>0)
        {
            std::cout << "recv data successfully, data: " << recv_buf << std::endl;
            if(strcmp(recv_buf,"-1")==0)
                break;
        } 
        else 
        {
            std::cout << "recv data error, data: " << recv_buf << std::endl;
        }
    }
    close(client_fd);
    return 0;
}
