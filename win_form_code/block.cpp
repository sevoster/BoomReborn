#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <conio.h>
#include <winsock2.h>
#define Max 625
using namespace std;
using namespace System;
        using namespace System::ComponentModel;
        using namespace System::Collections;
        using namespace System::Windows::Forms;
        using namespace System::Data;
        using namespace System::Drawing;
        using namespace System::Threading;

class Block
{
protected:
        int x,y,t;
        bool z;
        bool d;// 0-const  1-destr
        bool bomba;
public:
        Block(){};
        Block (int a,int b) {x=a;y=b;};
        virtual int GetX (){return x;}
        virtual int GetY (){return y;}
        virtual bool GetZ (){return z;}
        virtual bool GetD(){return d;}
        virtual bool GetB(){return bomba;}
        virtual int GetT(){return t;}
        virtual void SetX(int q)
                {
                        x=q;
                }
        virtual void SetY(int q)
                {
                        y=q;
                }
        virtual void Draw(Graphics^ g) {};
        virtual Block*** bombom(Block*** field){return field;}
};
 
class StatWall: public Block
{
public:
        StatWall(){};
        StatWall (int a,int b) {x=a;y=b;z=1; d=0;bomba=0;t=0;};
        void Draw(Graphics^ g)
        {
                g->FillRectangle(Brushes::Gray, x*30, y*30, 30, 30);
        };
};
 
class NoWall: public Block
{
public:
        NoWall(){};
        NoWall (int a,int b) {x=a;y=b; z=0; d=0;bomba=0;t=0;};
        void Draw(Graphics^ g)
        {
                g->FillRectangle(Brushes::White, x*30, y*30, 30, 30);
        }
 
};
 
class Disap: public Block
{
public:
        Disap(){};
        Disap (int a,int b) {x=a;y=b;};
};
 
class Wall: public Disap
{
public:
        Wall(){};
        Wall (int a,int b) {x=a;y=b;z=1; d=1;bomba=0;t=0;};
        void Draw(Graphics^ g)
        {
                g->FillRectangle(Brushes::Brown, x*30, y*30, 30, 30);
        }
};
 
class Bomb: public Disap
{
protected:
public:
        Bomb(){};
        Bomb (int a,int b,int timey) {x=a;y=b;z=1;d=0;bomba=1;t=timey;};
        void Draw(Graphics^ g)
        {
                g->FillRectangle(Brushes::Black,x*30,y*30,30,30);
        };
        Block*** bombom(Block*** field)
        {
                if ((field[x][y+1]->GetD())==1) field[x][y+1]=new NoWall(x,y+1);
                if ((field[x+1][y]->GetD())==1) field[x+1][y]=new NoWall(x+1,y);
                if ((field[x][y-1]->GetD())==1) field[x][y-1]=new NoWall(x,y-1);
                if ((field[x-1][y]->GetD())==1) field[x-1][y]=new NoWall(x-1,y);
                field[x][y]=new NoWall(x,y);
                return field;
        };
 
       
};
 
class Player:public Block
        {
        public:
                Player(){};
                Player(int q,int w)
                {
                        x=q; y=w; z=1;d=1;bomba=0;t=0;
                };
 
                void Draw(Graphics^ g)
                {
                        g->FillEllipse(Brushes::DarkGoldenrod, x*30, y*30, 30, 30);
                }
        };
 
class Game
{
protected:
        int m,n;
        Block*** field;
        Block *p;
        bool f;
public:
        Game(const int q, const int w):m(q),n(w),f(0) { p=new Player(1,1);};
        void generation()
        {
                field=new Block**[m];
                for(int i=0;i<m;i++)
                        field[i]=new Block*[n];
                for(int i=0;i<m;i++)
                {
                        field[i][0]=new StatWall(i,0);;
                        field[i][n-1]=new StatWall(i,n-1);;
                };
                for(int j=0;j<n;j++)
                {
                        field[0][j]=new StatWall(0,j);;
                        field[m-1][j]=new StatWall(m-1,j);;
                };
                int a;
                for (int i=1;i<m-1;i++)
                        for (int j=1;j<n-1;j++)
                        {
                                if (((i%2)==0)&&((j%2)==0))
                                {
                                        field[i][j]=new StatWall(i,j);;
                                }
                                else
                                {
                                a=rand()%2+1;
                                switch (a)
                                {
                                case 1:
                                        {
                                        field[i][j]=new Wall(i,j);
                                        break;
                                        }
                                case 2:
                                        {
                                                field[i][j]=new NoWall(i,j);;
                                                break;
                                        }
                                };
                                };
                                field[1][1]=new NoWall(1,1);
                                field[2][1]=new NoWall(2,1);
                                field[1][2]=new NoWall(1,2);
                                field[m-2][n-2]=new NoWall(m-2,n-2);
                                field[m-2][n-3]=new NoWall(m-2,n-3);
                                field[m-3][n-2]=new NoWall(m-3,n-2);
                        };
 
        };
        void PlayerGo()
        {
                field[1][1]=p;
        };
        void Controls(KeyPressEventArgs^ e,int timey)
        {
                switch (e->KeyChar)
                        {
                case 'f':
                        f=1;
                        break;
                case 'w':
                                if ((field[p->GetX()][p->GetY()-1]->GetZ())==0)
                                {
                                        if (f==1)
                                        {
                                                field[p->GetX()][p->GetY()]=new Bomb(p->GetX(),p->GetY(),timey);
                                                f=0;
                                        }
                                        else
                                        field[p->GetX()][p->GetY()]=new NoWall(p->GetX(),p->GetY());
                                        p->SetY((p->GetY())-1);
                                        field[p->GetX()][p->GetY()]=p;
                                }
                                break;
                case 'a':
                                if ((field[(p->GetX())-1][p->GetY()]->GetZ())==0)  
                                {
                                        if (f==1)
                                        {
                                                f=0;
                                                field[p->GetX()][p->GetY()]=new Bomb(p->GetX(),p->GetY(),timey);
                                        }
                                        else
                                        field[p->GetX()][p->GetY()]=new NoWall(p->GetX(),p->GetY());
                                        p->SetX((p->GetX())-1);
                                        field[p->GetX()][p->GetY()]=p;
                                }
                                break;
                case 'd':
                                if ((field[(p->GetX())+1][p->GetY()]->GetZ())==0)
                                {
                                        if (f==1)
                                        {
                                                f=0;
                                                field[p->GetX()][p->GetY()]=new Bomb(p->GetX(),p->GetY(),timey);
                                        }
                                        else
                                        field[p->GetX()][p->GetY()]=new NoWall(p->GetX(),p->GetY());
                                        p->SetX((p->GetX())+1);
                                        field[p->GetX()][p->GetY()]=p;
                                }
                                break;
                case 's':
                                if ((field[p->GetX()][(p->GetY())+1]->GetZ())==0)  
                                {
                                        if (f==1)
                                        {
                                                field[p->GetX()][p->GetY()]=new Bomb(p->GetX(),p->GetY(),timey);
                                                f=0;
                                        }
                                        else
                                        field[p->GetX()][p->GetY()]=new NoWall(p->GetX(),p->GetY());
                                        p->SetY((p->GetY())+1);
                                        field[p->GetX()][p->GetY()]=p;
                                }
                                break;
                        };
        };
        void Draw(Graphics^ g)
        {
                for(int i=0;i<m;i++)
                {
                        for (int j=0;j<n;j++)
                                field[i][j]->Draw(g);
                        cout<<"\n";
                };
        };
        void BOOOM(int tim)
        {
                for(int i=0;i<m;i++)
                        for (int j=0;j<n;j++)
                                if (((field[i][j]->GetB())==1)&&((field[i][j]->GetT())<=tim-2))
                                        field=field[i][j]->bombom(field);
        };
        ~Game()
        {
			if (field!=NULL)
			{
                for (int i=0;i<m;i++)
                        for (int j=0;j<n;j++)
                                delete [] field[i][j];
                for (int i=0;i<m;i++)
                        delete [] field[i];
				delete [] field;}
        }
};

//class Client
//{
//private:
//	WSADATA ws;
//    int error;
//    SOCKET s;
//    sockaddr_in s_addre;
//	char* buff;
//	int actual_len;
//public:
//	Client(const char* addr,int port)
//	{
//	buff=new char[100];
//	actual_len=0;
//	WSAStartup (MAKEWORD( 1, 1 ), &ws) ;
//	s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
//   ZeroMemory (&s_addre, sizeof (s_addre));
//   // тип адреса (TCP/IP)
//   s_addre.sin_family = AF_INET;
//   //адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода 
//   // адреса используем функцию inet_addr.
//   s_addre.sin_addr.S_un.S_addr = inet_addr (addr); 
//   // Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
//   s_addre.sin_port = htons (port);
//	}
//
//  void Connect()
//  {
//   connect (s, (sockaddr *) &s_addre, sizeof (s_addre) ) ;
//  }
//  void Ret()
//  {
//	  actual_len = recv (s, buff,100, 0 );
//  }
//  void close()
//  {
//	  closesocket (s);
//  }
//  char* What()
//  {
//	  return buff;
//  };
//  ~Client()
//  {
//	  delete[] buff;
//  }
//};
//
//class Server
//{
//	private:
//	WSADATA ws;
//    int error;
//    SOCKET s;
//    sockaddr_in s_addre;
//	char* buff;
//	int actual_len;
//public:
//	Server(const char* addr,int port)
//	{
//		buff=new char[100];
//		actual_len=0;
//	WSAStartup (MAKEWORD( 1, 1 ), &ws) ;
//	s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
//   ZeroMemory (&s_addre, sizeof (s_addre));
//   // тип адреса (TCP/IP)
//   s_addre.sin_family = AF_INET;
//   //адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода 
//   // адреса используем функцию inet_addr.
//   s_addre.sin_addr.S_un.S_addr = inet_addr (addr); 
//   // Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
//   s_addre.sin_port = htons (port);
//	}
//
//  void Connect()
//  {
//   connect (s, (sockaddr *) &s_addre, sizeof (s_addre) ) ;
//  }
//  void Ret()
//  {
//	  actual_len = recv (s, buff,100, 0 );
//  }
//  void close()
//  {
//	  closesocket (s);
//  }
//  char* What()
//  {
//	  return buff;
//  }
//  ~Server()
//  {
//	  delete[] field;
//  }
//};
//class Serverok
//{
//	private:
//	WSADATA ws;
//    int error;
//    SOCKET s;
//    sockaddr_in s_addre;
//	sockaddr client_addr;
//	char* buff;
//	int actual_len;
//	int client_addr_size;
//public:
//	Serverok()
//	{
//		buff=new char[100];
//		actual_len=0;
//	WSAStartup (MAKEWORD( 1, 1 ), &ws) ;
//	s = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
//   ZeroMemory (&s_addre, sizeof (s_addre));
//   // тип адреса (TCP/IP)
//   s_addre.sin_family = AF_INET;
//   //адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода 
//   // адреса используем функцию inet_addr.
//   s_addre.sin_addr.S_un.S_addr = inet_addr ("192.168.0.213"); 
//   // Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
//   s_addre.sin_port = htons (8888);
//	}
//	void con()
//	{
//		connect (s, (sockaddr *) & client_addr, sizeof (client_addr) );
//	}
//  void Ret()
//  {
//	  actual_len= recv(s, buff, Max * sizeof(char), 0);
//  }
//  void close()
//  {
//	  closesocket (s);
//  }
//  char* What()
//  {
//	  return buff;
//  }
//  ~Serverok()
//  {
//	  delete[] buff;
//  }
//};

class Serv
{
	WORD sockVer;
    WSADATA wsaData;
    int retVal;
	SOCKET servSock;
	SOCKADDR_IN sin;
	SOCKET clientSock;
		char szReq[8]; 
public:
	Serv()
	{
		
	}
	void Start()
	{
		sockVer = MAKEWORD(2,2); 
    WSAStartup(sockVer, &wsaData);
	servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(servSock == INVALID_SOCKET)
    {
       MessageBox::Show("sock_serv");
        WSACleanup();
    }
	sin.sin_family = PF_INET;
    sin.sin_port = htons(1111);
    sin.sin_addr.s_addr = INADDR_ANY;
	retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));
    if(retVal == SOCKET_ERROR)
    {
        MessageBox::Show("bind_serv");
        WSACleanup();
    }
	}
	void Listening()
	{
		retVal = listen(servSock, 10);
    if(retVal == SOCKET_ERROR)
    {
        MessageBox::Show("listen_serv");
        WSACleanup();
    }
	}
	void waiting()
	{
		clientSock = accept(servSock, NULL, NULL);
 
    if(clientSock == INVALID_SOCKET)
    {
       MessageBox::Show("clientsock_serv");
        WSACleanup();
    }
	}
	void recieve()
	{
	
    retVal = recv(clientSock, szReq, 8, 0);
 
    if(retVal == SOCKET_ERROR)
    {
        MessageBox::Show("recv_serv");
    }
	}
	void sending()
	{
		char *szResp = "Response";
		retVal = send(clientSock, szResp, strlen(szResp), 0);
 
    if(retVal == SOCKET_ERROR)
    {
       MessageBox::Show("send_serv");
    }
	}
	void closing()
	{
		closesocket(clientSock);
    closesocket(servSock);
 
    WSACleanup();
	}
};

class Client
{
	WORD ver;
    WSADATA wsaData;
    int retVal;
	LPHOSTENT hostEnt;
	 SOCKET clientSock ;
	 SOCKADDR_IN serverInfo;
	 char szResponse[9];
public:
	Client()
	{
		
	}
	void start()
	{
		ver = MAKEWORD(2,2);
		retVal=0;
		WSAStartup(ver,(LPWSADATA)&wsaData);
		hostEnt = gethostbyname("localhost");
		if(!hostEnt)
    {
        MessageBox::Show("host_cl");
        WSACleanup();
    }
		clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		 if(clientSock == SOCKET_ERROR)
    {
        MessageBox::Show("clsock_cl");
        WSACleanup();
    }
		  serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
    serverInfo.sin_port = htons(1111);
	}
	void connecting()
	{
		retVal=connect(clientSock,(LPSOCKADDR)&serverInfo, sizeof(serverInfo));
    if(retVal==SOCKET_ERROR)
    {
		MessageBox::Show("connect fail");
    }
	else
		MessageBox::Show("YUPII");
	}
	void sending(char* a)
	{
		char *pBuf = "Request";
    retVal = send(clientSock, pBuf, strlen(pBuf), 0);
 
    if(retVal == SOCKET_ERROR)
    {
       MessageBox::Show("send_cl");
    }
	}
	void recieve()
	{
		
    retVal = recv(clientSock, szResponse, 9, 0);
 
    if(retVal == SOCKET_ERROR)
    {
        MessageBox::Show("recv_cl");
    }
	else
	{
		String^ fd=gcnew String(szResponse);
		MessageBox::Show(fd);
	}
	}
	void closing()
	{
		closesocket(clientSock);
    WSACleanup();
	}
};