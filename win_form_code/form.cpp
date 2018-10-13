#pragma once
#include "Blocks.h"
#include "Quest.h"
#include <winsock2.h>
#pragma comment ( lib, "ws2_32.lib" )
int timerum=0;
Game game(23,13);
static Serv s;
static Client cl;
static bool f=false;
char* abc="Ahuit'";
namespace Boom {
 
        using namespace System;
        using namespace System::ComponentModel;
        using namespace System::Collections;
        using namespace System::Windows::Forms;
        using namespace System::Data;
        using namespace System::Drawing;
		using namespace System::Threading;
        /// <summary>
        /// —водка дл€ Form1
        /// </summary>
        public ref class Form1 : public System::Windows::Forms::Form
        {
        public:
                        Form1(void)
                        {
                                InitializeComponent();
                                this->KeyPreview = true;
                        this->a="";
                                                this->b="";
                                                this->quest=gcnew Quest();
                                                this->Config->Hide();
                                                this->Start->Hide();
												this->Back->Hide();
                        }
 
        protected:
                /// <summary>
                /// ќсвободить все используемые ресурсы.
                /// </summary>
                ~Form1()
                {
					 if (f==1)
                                        {
                                        if (this->trd_cl->IsAlive)
        this->trd_cl->Abort();
                                        else
                                        if (this->trd_serv->IsAlive)
                                                this->trd_serv->Abort();
                                        }
                                        if (f==0)
                                        {if (this->trd_serv->IsAlive)
                                        this->trd_serv->Abort();}
                        if (components)
                        {
                                delete components;
                        }
                }
                private: String^a,^b;
                                  Quest^ quest; 
		/*private: Serverok* serv;*/
        private: System::Windows::Forms::Timer^  timer1;
                private: System::Windows::Forms::Button^  Client;
 
                private: System::Windows::Forms::Button^  Server;
 
                private: System::Windows::Forms::Button^  Config;
                private: System::Windows::Forms::Button^  Start;
		private: System::Windows::Forms::Button^  Back;
		private: System::Windows::Forms::TextBox^  textBox1;


 
 
 
 
        private: System::ComponentModel::IContainer^  components;
 
 
        protected:
 
        private:
                /// <summary>
                /// “ребуетс€ переменна€ конструктора.
                /// </summary>
 
 
#pragma region Windows Form Designer generated code
                /// <summary>
                /// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
                /// содержимое данного метода при помощи редактора кода.
                /// </summary>
                void InitializeComponent(void)
                {
					this->components = (gcnew System::ComponentModel::Container());
					this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
					this->Client = (gcnew System::Windows::Forms::Button());
					this->Server = (gcnew System::Windows::Forms::Button());
					this->Config = (gcnew System::Windows::Forms::Button());
					this->Start = (gcnew System::Windows::Forms::Button());
					this->Back = (gcnew System::Windows::Forms::Button());
					this->textBox1 = (gcnew System::Windows::Forms::TextBox());
					this->SuspendLayout();
					// 
					// timer1
					// 
					this->timer1->Tag = L"timer";
					this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
					// 
					// Client
					// 
					this->Client->Location = System::Drawing::Point(768, 304);
					this->Client->Name = L"Client";
					this->Client->Size = System::Drawing::Size(75, 23);
					this->Client->TabIndex = 1;
					this->Client->Text = L"Client";
					this->Client->UseVisualStyleBackColor = true;
					this->Client->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
					// 
					// Server
					// 
					this->Server->Location = System::Drawing::Point(768, 275);
					this->Server->Name = L"Server";
					this->Server->Size = System::Drawing::Size(75, 23);
					this->Server->TabIndex = 2;
					this->Server->Text = L"Server";
					this->Server->UseVisualStyleBackColor = true;
					this->Server->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
					// 
					// Config
					// 
					this->Config->Location = System::Drawing::Point(768, 304);
					this->Config->Name = L"Config";
					this->Config->Size = System::Drawing::Size(74, 23);
					this->Config->TabIndex = 3;
					this->Config->Text = L"Config";
					this->Config->UseVisualStyleBackColor = true;
					this->Config->Click += gcnew System::EventHandler(this, &Form1::Config_Click);
					// 
					// Start
					// 
					this->Start->Location = System::Drawing::Point(714, 275);
					this->Start->Name = L"Start";
					this->Start->Size = System::Drawing::Size(75, 23);
					this->Start->TabIndex = 4;
					this->Start->Text = L"Start";
					this->Start->UseVisualStyleBackColor = true;
					this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
					// 
					// Back
					// 
					this->Back->Location = System::Drawing::Point(768, 333);
					this->Back->Name = L"Back";
					this->Back->Size = System::Drawing::Size(75, 23);
					this->Back->TabIndex = 5;
					this->Back->Text = L"Back";
					this->Back->UseVisualStyleBackColor = true;
					this->Back->Click += gcnew System::EventHandler(this, &Form1::Back_Click);
					// 
					// textBox1
					// 
					this->textBox1->Location = System::Drawing::Point(637, 365);
					this->textBox1->Name = L"textBox1";
					this->textBox1->Size = System::Drawing::Size(100, 20);
					this->textBox1->TabIndex = 6;
					this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::text_chang);
					// 
					// Form1
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->ClientSize = System::Drawing::Size(882, 397);
					this->Controls->Add(this->textBox1);
					this->Controls->Add(this->Back);
					this->Controls->Add(this->Start);
					this->Controls->Add(this->Config);
					this->Controls->Add(this->Server);
					this->Controls->Add(this->Client);
					this->Name = L"Form1";
					this->Text = L"Start";
					this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
					this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
					this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
					this->ResumeLayout(false);
					this->PerformLayout();

				}
#pragma endregion
 
 
       private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
                                 Graphics^ g = Graphics::FromHwnd(this->Handle);
                                game.Controls(e,timerum);
                                 game.Draw(g);
                         }
        private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
                        timerum++;
                        game.BOOOM(timerum);
                        Graphics^ g = Graphics::FromHwnd(this->Handle);
                        game.Draw(g);
                         }
        private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
                                 timer1->Enabled=false;
                                 timer1->Interval=1000;					
                                                               
                                 
                         }
                private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
                                 {
									 
                                         Form1::Server->Hide();
                                         Form1::Client->Hide();
										 s.Start();
	s.Listening();
	s.waiting();
                                        game.generation();
                                 game.PlayerGo();
                                 Graphics^ g = Graphics::FromHwnd(this->Handle);
                                 game.Draw(g);
                                 timer1->Start();
								 ThreadStart ^myThreadDelegate = gcnew ThreadStart(this,&Boom::Form1::repeat_serv);
                                   this->trd_serv = gcnew Thread(myThreadDelegate);
                                   this->trd_serv->IsBackground = true;
                                   this->trd_serv->Start();
								   	
                                 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
                 {
                         this->Server->Hide();
                         this->Client->Hide();
						 cl.start();
	 cl.connecting();
                         /*this->Start->Show();
                         this->Config->Show();
						 this->Back->Show();*/
						 ThreadStart ^myThreadDelegate = gcnew ThreadStart(this,&Boom::Form1:: repeat_cl);
                                   this->trd_cl = gcnew Thread(myThreadDelegate);
                                   this->trd_cl->IsBackground = true;
                                   this->trd_cl->Start();
								
								   f=1;
                 }
 
private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
                         this->a=quest->Geta();
                         this->b=quest->Getb();
                         MessageBox::Show(a+" "+b);
 
                 }
private: System::Void Config_Click(System::Object^  sender, System::EventArgs^  e) {
                         quest->Show();
                 }
private: System::Void Back_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			             this->Server->Show();
                         this->Client->Show();
                         this->Start->Hide();
                         this->Config->Hide();
						 this->Back->Hide();
		 }

		 private: Thread ^trd_serv,^ trd_cl;
				  
private: void ThreadTask_serv()
{
	
	s.sending();
}
private: void repeat_serv()
{	
	while(true)
	{
	ThreadTask_serv();
	Thread::Sleep(100);
	}
}
		 private: void ThreadTask_cl()
{	
	cl.recieve();
}
private: void repeat_cl()
{	
	while(true)
	{
	ThreadTask_cl();
	Thread::Sleep(100);
	}
}
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 s.closing();
			 cl.closing();
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void text_chang(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}