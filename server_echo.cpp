#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <vector>

int main(int argc,char* argvp[])
{
    size_t listen_fd = socket(AF_INET,SOCK_STREAM,0);
    if(listen_fd == -1)
    {
        std::cout<<"create listen socket error."<<std::endl;
        return -1;
    }

    //设置服务器端口及ip
    struct sockaddr_in bind_addr;
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind_addr.sin_port = htons(3000);

    //绑定服务器地址信息
    if(bind(listen_fd,(struct sockaddr*)&bind_addr,sizeof(bind_addr)) == -1)
    {
        std::cout<<"bind listen socket error."<<std::endl;
        return -1;
    }

    //启动侦听
    if(listen(listen_fd,SOMAXCONN) == -1)
    {
        std::cout<<"listen error."<<std::endl;
        return -1;
    }
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    size_t client_fd = accept(listen_fd,(struct sockaddr *)&client_addr,&client_addr_len);
    if(client_fd == -1)
    {
        std::cout<<"create client socket error."<<std::endl;
        return -1;
    }
    char recv_buf[32] = "hello message from server ";
    int ret = send(client_fd, recv_buf, strlen(recv_buf), 0);
    if (ret != strlen(recv_buf))
    {
		std::cout << "send data error." << std::endl;		
	    std::cout << "send data to client successfully, data: " << recv_buf << std::endl;
	} 

    while(true)
    {
        memset(recv_buf,0,sizeof(recv_buf));
        ret = recv(client_fd,recv_buf,32,0);
        if(ret>0)
        {
            std::cout<<"recv data from client, data:"<<recv_buf<<std::endl;
        }
        else 
	    {
	        std::cout << "recv data error." << std::endl;
        }
        ret = send(client_fd, recv_buf, strlen(recv_buf), 0);
        if (ret != strlen(recv_buf))
        {
	    	std::cout << "send data error." << std::endl;		
	        std::cout << "send data to client successfully, data: " << recv_buf << std::endl;
	    } 
        if(strcmp(recv_buf,"-1")==0)
            break;
    }
    close(listen_fd);
    return 0;
}
