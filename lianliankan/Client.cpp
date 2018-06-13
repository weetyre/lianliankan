
#include "stdafx.h"
#include "Client.h"


int hasifOnserver(string id) {
	int has = 0;
	/*加载winsock文件*/
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 0);
	WSAStartup(sockVersion, &wsaData);

	/*创建服务器端的套接字*/
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("Failed socket()\n");
		WSACleanup();
		//system("pause");
	}

	/*socket中装入地址信息*/
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(8800); /*接收服务器13端口号*/
									 //servAddr.sin_addr.S_un.S_addr = inet_addr("218.249.50.112");
	//servAddr.sin_addr.S_un.S_addr = inet_addr("172.30.116.184");//my
	//servAddr.sin_addr.S_un.S_addr = inet_addr("172.30.101.133");//cw	
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//本地ip



	/*连接服务器*/
	if (connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf("Failed connect()\n");
		WSACleanup();
		//system("pause");
	}

	/*接收数据并打印到屏幕上*/
	char buff[1];
	send(s, id.data(), 256, 0);
	int nRecv = recv(s, buff, 1, 0);
	if (nRecv>0)
	{
		//printf("接收到数据：%c\n", buff[0]);
		if (buff[0] == '1')
		{
			has = 1;
		}
	}
	else
	{
		cout << "接受消息失败！" << endl;
	}
	return has;
}

int addIDOnserver(string id) {
	if (hasifOnserver(id) != 1) {
		//cout << "has not it and add one" << endl;
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] == '#')
			{
				id[i] = '$';
			}
		}
		hasifOnserver(id);//注册新的账号
		return 1;
	}
	else
	{
		//cout << "has it" << endl;
		return 0;
	}
}

int send(string str) {
	return hasifOnserver(str);
}

//int main()
//{
//	//int has = addIDOnserver("yinyei##1111");
//	int has = hasifOnserver("yinyeli##1111");
//	cout << has << endl;
//	system("pause");
//	return 0;
//}