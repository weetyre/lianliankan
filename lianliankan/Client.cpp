
#include "stdafx.h"
#include <fstream>
#include "Client.h"

//待测，分数保存到排行榜

int sendms(string ms) {
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
	//servAddr.sin_addr.S_un.S_addr = inet_addr("172.30.65.254");//cw	
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//本地ip



	/*连接服务器*/
	if (connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf("Failed connect()\n");
		WSACleanup();
		//system("pause");
	}
	
	if (ms.at(0) == '-')
	{//获取文件
		ofstream  input_file;
		input_file.open("localphb.txt");
		if (!input_file.is_open()) {
			cout << "file open erro!" << endl;
		}
		char buff[1024];
		memset(buff, 0, sizeof(buff));//清空
		send(s, ms.data(), 256, 0);
		cout << "接到消息:" << endl;
		while (recv(s,buff,1024,0) > 0)
		{
			input_file << buff;
			cout << buff;
			memset(buff, 0, sizeof(buff));//清空
		}
		input_file.close();
	}
	else {
		/*接收数据并打印到屏幕上*/
		char buff[1];
		send(s, ms.data(), 256, 0);
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
	}
	
	return has;
}

int addIDOnserver(string id) {
	if (sendms(id) != 1) {
		//cout << "has not it and add one" << endl;
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] == '#')
			{
				id[i] = '$';
			}
		}
		sendms(id);//注册新的账号
		return 1;
	}
	else
	{
		//cout << "has it" << endl;
		return 0;
	}
}


//int main()
//{
//	//int has = addIDOnserver("yinyei##1111");
//	int has = hasifOnserver("yinyeli##1111");
//	cout << has << endl;
//	system("pause");
//	return 0;
//}