// João Paulo Bodanese <joao.bodanese@gmail.com>
// Fabio Rafael Segundo <fabio.segundo@gmail.com>

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <process.h>
#using <System.DLL>
#using <System.Drawing.DLL>
#using <System.Windows.Forms.DLL>

#define PROGNAME L"Tests Stand for 8086"
const long SWITCH_PORT		 = 0x20;
const long LED_PORT			 = 0x22;
const unsigned char INT_OFF  = 0x0;
const unsigned char INT_ON   = 0xFF;

const int nrTentativas = 351;
char nrChamadas = 0;
char sINI_FILE[60]   = ".\\emu8086.ini";
char sIO_FILE[60]    = ".\\emu8086.io";
char sINT_FILE[60]   = ".\\emu8086.hw";

namespace Bancada8086 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Resources;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			unsigned int i;

			ReadIniFile();
			CreateFiles();

			InitializeComponent();
			
			WRITE_IO_BYTE(LED_PORT, 0);
			UpdateLeds(0);

			running = true;

			switchVal = 0;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);

			for(i=0;i<=255;i++)
				WRITE_INTERRUPT(i,INT_OFF);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			running = false;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblText1;
	protected: 

	protected: 

	protected: 

	private: System::Windows::Forms::Button^  btnSair;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Variáveis
		Thread^ demoThread;
		bool running;
		unsigned char switchVal;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	//private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::PictureBox^  switch1Off;
	private: System::Windows::Forms::PictureBox^  switch1On;

	private: System::Windows::Forms::PictureBox^  led1On;
	private: System::Windows::Forms::PictureBox^  led1Off;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  switch2On;
	private: System::Windows::Forms::PictureBox^  switch3On;
	private: System::Windows::Forms::PictureBox^  switch4On;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  switch2Off;
	private: System::Windows::Forms::PictureBox^  switch3Off;
	private: System::Windows::Forms::PictureBox^  switch4Off;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::PictureBox^  led2Off;
	private: System::Windows::Forms::PictureBox^  led3Off;
	private: System::Windows::Forms::PictureBox^  led4Off;
	private: System::Windows::Forms::PictureBox^  led2On;
	private: System::Windows::Forms::PictureBox^  led3On;
	private: System::Windows::Forms::PictureBox^  led4On;
	private: System::Windows::Forms::PictureBox^  switch5Off;
	private: System::Windows::Forms::PictureBox^  switch6Off;
	private: System::Windows::Forms::PictureBox^  switch7Off;
	private: System::Windows::Forms::PictureBox^  switch8Off;




	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::PictureBox^  switch5On;
	private: System::Windows::Forms::PictureBox^  switch6On;
	private: System::Windows::Forms::PictureBox^  switch7On;
	private: System::Windows::Forms::PictureBox^  switch8On;
private: System::Windows::Forms::PictureBox^  led5On;
private: System::Windows::Forms::PictureBox^  led6On;
private: System::Windows::Forms::PictureBox^  led7On;
private: System::Windows::Forms::PictureBox^  led8On;
private: System::Windows::Forms::PictureBox^  led5Off;
private: System::Windows::Forms::PictureBox^  led6Off;
private: System::Windows::Forms::PictureBox^  led7Off;
private: System::Windows::Forms::PictureBox^  led8Off;
private: System::Windows::Forms::Button^  Int0x90;
private: System::Windows::Forms::Button^  Int0x92;

private: System::Windows::Forms::Button^  Int0x91;




private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TextBox^  textBoxC0Hex;

private: System::Windows::Forms::TextBox^  textBoxChavesHex;
private: System::Windows::Forms::TextBox^  textBoxLedHex;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Button^  btnSobre;
		 
	private: System::Windows::Forms::TextBox^  textBox1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lblText1 = (gcnew System::Windows::Forms::Label());
			this->btnSair = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->switch1Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch1On = (gcnew System::Windows::Forms::PictureBox());
			this->led1On = (gcnew System::Windows::Forms::PictureBox());
			this->led1Off = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->switch2On = (gcnew System::Windows::Forms::PictureBox());
			this->switch3On = (gcnew System::Windows::Forms::PictureBox());
			this->switch4On = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->switch2Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch3Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch4Off = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->led2Off = (gcnew System::Windows::Forms::PictureBox());
			this->led3Off = (gcnew System::Windows::Forms::PictureBox());
			this->led4Off = (gcnew System::Windows::Forms::PictureBox());
			this->led2On = (gcnew System::Windows::Forms::PictureBox());
			this->led3On = (gcnew System::Windows::Forms::PictureBox());
			this->led4On = (gcnew System::Windows::Forms::PictureBox());
			this->switch5Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch6Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch7Off = (gcnew System::Windows::Forms::PictureBox());
			this->switch8Off = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->switch5On = (gcnew System::Windows::Forms::PictureBox());
			this->switch6On = (gcnew System::Windows::Forms::PictureBox());
			this->switch7On = (gcnew System::Windows::Forms::PictureBox());
			this->switch8On = (gcnew System::Windows::Forms::PictureBox());
			this->led5On = (gcnew System::Windows::Forms::PictureBox());
			this->led6On = (gcnew System::Windows::Forms::PictureBox());
			this->led7On = (gcnew System::Windows::Forms::PictureBox());
			this->led8On = (gcnew System::Windows::Forms::PictureBox());
			this->led5Off = (gcnew System::Windows::Forms::PictureBox());
			this->led6Off = (gcnew System::Windows::Forms::PictureBox());
			this->led7Off = (gcnew System::Windows::Forms::PictureBox());
			this->led8Off = (gcnew System::Windows::Forms::PictureBox());
			this->Int0x90 = (gcnew System::Windows::Forms::Button());
			this->Int0x92 = (gcnew System::Windows::Forms::Button());
			this->Int0x91 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBoxC0Hex = (gcnew System::Windows::Forms::TextBox());
			this->textBoxChavesHex = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLedHex = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->btnSobre = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch1Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch1On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led1On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led1Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch2On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch3On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch4On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch2Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch3Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch4Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led2Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led3Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led4Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led2On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led3On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led4On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch5Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch6Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch7Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch8Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch5On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch6On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch7On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch8On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led5On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led6On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led7On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led8On))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led5Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led6Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led7Off))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led8Off))->BeginInit();
			this->SuspendLayout();
			// 
			// lblText1
			// 
			this->lblText1->AutoSize = true;
			this->lblText1->Location = System::Drawing::Point(306, 92);
			this->lblText1->Name = L"lblText1";
			this->lblText1->Size = System::Drawing::Size(70, 13);
			this->lblText1->TabIndex = 0;
			this->lblText1->Text = L"Port 22h high";
			this->lblText1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// btnSair
			// 
			this->btnSair->Location = System::Drawing::Point(365, 396);
			this->btnSair->Name = L"btnSair";
			this->btnSair->Size = System::Drawing::Size(75, 23);
			this->btnSair->TabIndex = 11;
			this->btnSair->Text = L"&Close";
			this->btnSair->UseVisualStyleBackColor = true;
			this->btnSair->Click += gcnew System::EventHandler(this, &Form1::btnSair_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(291, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(306, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Port 20h low (Switches)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(306, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Port 22h low (LEDs)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(290, 168);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(290, 61);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(63, 20);
			this->textBox3->TabIndex = 1;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// switch1Off
			// 
			this->switch1Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch1Off.Image")));
			this->switch1Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch1Off.InitialImage")));
			this->switch1Off->Location = System::Drawing::Point(166, 52);
			this->switch1Off->Name = L"switch1Off";
			this->switch1Off->Size = System::Drawing::Size(86, 36);
			this->switch1Off->TabIndex = 9;
			this->switch1Off->TabStop = false;
			this->switch1Off->Click += gcnew System::EventHandler(this, &Form1::switch1Off_Click);
			// 
			// switch1On
			// 
			this->switch1On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch1On.Image")));
			this->switch1On->Location = System::Drawing::Point(166, 52);
			this->switch1On->Name = L"switch1On";
			this->switch1On->Size = System::Drawing::Size(86, 36);
			this->switch1On->TabIndex = 10;
			this->switch1On->TabStop = false;
			this->switch1On->Click += gcnew System::EventHandler(this, &Form1::switch1On_Click);
			// 
			// led1On
			// 
			this->led1On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led1On.Image")));
			this->led1On->Location = System::Drawing::Point(52, 52);
			this->led1On->Name = L"led1On";
			this->led1On->Size = System::Drawing::Size(44, 41);
			this->led1On->TabIndex = 12;
			this->led1On->TabStop = false;
			// 
			// led1Off
			// 
			this->led1Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led1Off.Image")));
			this->led1Off->Location = System::Drawing::Point(52, 52);
			this->led1Off->Name = L"led1Off";
			this->led1Off->Size = System::Drawing::Size(44, 41);
			this->led1Off->TabIndex = 13;
			this->led1Off->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(112, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Switch 1";
			// 
			// switch2On
			// 
			this->switch2On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch2On.Image")));
			this->switch2On->Location = System::Drawing::Point(166, 101);
			this->switch2On->Name = L"switch2On";
			this->switch2On->Size = System::Drawing::Size(86, 36);
			this->switch2On->TabIndex = 15;
			this->switch2On->TabStop = false;
			this->switch2On->Click += gcnew System::EventHandler(this, &Form1::switch2On_Click);
			// 
			// switch3On
			// 
			this->switch3On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch3On.Image")));
			this->switch3On->Location = System::Drawing::Point(166, 150);
			this->switch3On->Name = L"switch3On";
			this->switch3On->Size = System::Drawing::Size(86, 36);
			this->switch3On->TabIndex = 16;
			this->switch3On->TabStop = false;
			this->switch3On->Click += gcnew System::EventHandler(this, &Form1::switch3On_Click);
			// 
			// switch4On
			// 
			this->switch4On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch4On.Image")));
			this->switch4On->Location = System::Drawing::Point(166, 200);
			this->switch4On->Name = L"switch4On";
			this->switch4On->Size = System::Drawing::Size(86, 36);
			this->switch4On->TabIndex = 17;
			this->switch4On->TabStop = false;
			this->switch4On->Click += gcnew System::EventHandler(this, &Form1::switch4On_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(112, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Switch 2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(112, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Switch 3";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(112, 212);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Switch 4";
			// 
			// switch2Off
			// 
			this->switch2Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch2Off.Image")));
			this->switch2Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch2Off.InitialImage")));
			this->switch2Off->Location = System::Drawing::Point(166, 101);
			this->switch2Off->Name = L"switch2Off";
			this->switch2Off->Size = System::Drawing::Size(86, 36);
			this->switch2Off->TabIndex = 21;
			this->switch2Off->TabStop = false;
			this->switch2Off->Click += gcnew System::EventHandler(this, &Form1::switch2Off_Click);
			// 
			// switch3Off
			// 
			this->switch3Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch3Off.Image")));
			this->switch3Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch3Off.InitialImage")));
			this->switch3Off->Location = System::Drawing::Point(166, 149);
			this->switch3Off->Name = L"switch3Off";
			this->switch3Off->Size = System::Drawing::Size(86, 36);
			this->switch3Off->TabIndex = 22;
			this->switch3Off->TabStop = false;
			this->switch3Off->Click += gcnew System::EventHandler(this, &Form1::switch3Off_Click);
			// 
			// switch4Off
			// 
			this->switch4Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch4Off.Image")));
			this->switch4Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch4Off.InitialImage")));
			this->switch4Off->Location = System::Drawing::Point(166, 200);
			this->switch4Off->Name = L"switch4Off";
			this->switch4Off->Size = System::Drawing::Size(86, 36);
			this->switch4Off->TabIndex = 23;
			this->switch4Off->TabStop = false;
			this->switch4Off->Click += gcnew System::EventHandler(this, &Form1::switch4Off_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 12);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"LEDs - Port 22h low";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 25;
			this->label8->Text = L"LED 1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 113);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 13);
			this->label9->TabIndex = 26;
			this->label9->Text = L"LED 2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 161);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 13);
			this->label10->TabIndex = 27;
			this->label10->Text = L"LED 3";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 212);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 28;
			this->label11->Text = L"LED 4";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(149, 12);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(118, 13);
			this->label12->TabIndex = 29;
			this->label12->Text = L"Switches - Port 20h low";
			// 
			// led2Off
			// 
			this->led2Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led2Off.Image")));
			this->led2Off->Location = System::Drawing::Point(52, 101);
			this->led2Off->Name = L"led2Off";
			this->led2Off->Size = System::Drawing::Size(44, 41);
			this->led2Off->TabIndex = 30;
			this->led2Off->TabStop = false;
			// 
			// led3Off
			// 
			this->led3Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led3Off.Image")));
			this->led3Off->Location = System::Drawing::Point(52, 148);
			this->led3Off->Name = L"led3Off";
			this->led3Off->Size = System::Drawing::Size(44, 41);
			this->led3Off->TabIndex = 31;
			this->led3Off->TabStop = false;
			// 
			// led4Off
			// 
			this->led4Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led4Off.Image")));
			this->led4Off->Location = System::Drawing::Point(52, 195);
			this->led4Off->Name = L"led4Off";
			this->led4Off->Size = System::Drawing::Size(44, 41);
			this->led4Off->TabIndex = 32;
			this->led4Off->TabStop = false;
			// 
			// led2On
			// 
			this->led2On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led2On.Image")));
			this->led2On->Location = System::Drawing::Point(52, 101);
			this->led2On->Name = L"led2On";
			this->led2On->Size = System::Drawing::Size(44, 41);
			this->led2On->TabIndex = 33;
			this->led2On->TabStop = false;
			// 
			// led3On
			// 
			this->led3On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led3On.Image")));
			this->led3On->Location = System::Drawing::Point(52, 148);
			this->led3On->Name = L"led3On";
			this->led3On->Size = System::Drawing::Size(44, 41);
			this->led3On->TabIndex = 34;
			this->led3On->TabStop = false;
			// 
			// led4On
			// 
			this->led4On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led4On.Image")));
			this->led4On->Location = System::Drawing::Point(52, 195);
			this->led4On->Name = L"led4On";
			this->led4On->Size = System::Drawing::Size(44, 41);
			this->led4On->TabIndex = 35;
			this->led4On->TabStop = false;
			// 
			// switch5Off
			// 
			this->switch5Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch5Off.Image")));
			this->switch5Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch5Off.InitialImage")));
			this->switch5Off->Location = System::Drawing::Point(166, 247);
			this->switch5Off->Name = L"switch5Off";
			this->switch5Off->Size = System::Drawing::Size(86, 36);
			this->switch5Off->TabIndex = 36;
			this->switch5Off->TabStop = false;
			this->switch5Off->Click += gcnew System::EventHandler(this, &Form1::switch5Off_Click);
			// 
			// switch6Off
			// 
			this->switch6Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch6Off.Image")));
			this->switch6Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch6Off.InitialImage")));
			this->switch6Off->Location = System::Drawing::Point(166, 294);
			this->switch6Off->Name = L"switch6Off";
			this->switch6Off->Size = System::Drawing::Size(86, 36);
			this->switch6Off->TabIndex = 37;
			this->switch6Off->TabStop = false;
			this->switch6Off->Click += gcnew System::EventHandler(this, &Form1::switch6Off_Click);
			// 
			// switch7Off
			// 
			this->switch7Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch7Off.Image")));
			this->switch7Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch7Off.InitialImage")));
			this->switch7Off->Location = System::Drawing::Point(166, 341);
			this->switch7Off->Name = L"switch7Off";
			this->switch7Off->Size = System::Drawing::Size(86, 36);
			this->switch7Off->TabIndex = 38;
			this->switch7Off->TabStop = false;
			this->switch7Off->Click += gcnew System::EventHandler(this, &Form1::switch7Off_Click);
			// 
			// switch8Off
			// 
			this->switch8Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch8Off.Image")));
			this->switch8Off->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch8Off.InitialImage")));
			this->switch8Off->Location = System::Drawing::Point(166, 388);
			this->switch8Off->Name = L"switch8Off";
			this->switch8Off->Size = System::Drawing::Size(86, 36);
			this->switch8Off->TabIndex = 39;
			this->switch8Off->TabStop = false;
			this->switch8Off->Click += gcnew System::EventHandler(this, &Form1::switch8Off_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(112, 257);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(48, 13);
			this->label13->TabIndex = 40;
			this->label13->Text = L"Switch 5";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(112, 305);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(48, 13);
			this->label14->TabIndex = 41;
			this->label14->Text = L"Switch 6";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(112, 353);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(48, 13);
			this->label15->TabIndex = 42;
			this->label15->Text = L"Switch 7";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(112, 399);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(48, 13);
			this->label16->TabIndex = 43;
			this->label16->Text = L"Switch 8";
			// 
			// switch5On
			// 
			this->switch5On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch5On.Image")));
			this->switch5On->Location = System::Drawing::Point(166, 247);
			this->switch5On->Name = L"switch5On";
			this->switch5On->Size = System::Drawing::Size(86, 36);
			this->switch5On->TabIndex = 44;
			this->switch5On->TabStop = false;
			this->switch5On->Click += gcnew System::EventHandler(this, &Form1::switch5On_Click);
			// 
			// switch6On
			// 
			this->switch6On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch6On.Image")));
			this->switch6On->Location = System::Drawing::Point(166, 294);
			this->switch6On->Name = L"switch6On";
			this->switch6On->Size = System::Drawing::Size(86, 36);
			this->switch6On->TabIndex = 45;
			this->switch6On->TabStop = false;
			this->switch6On->Click += gcnew System::EventHandler(this, &Form1::switch6On_Click);
			// 
			// switch7On
			// 
			this->switch7On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch7On.Image")));
			this->switch7On->Location = System::Drawing::Point(166, 341);
			this->switch7On->Name = L"switch7On";
			this->switch7On->Size = System::Drawing::Size(86, 36);
			this->switch7On->TabIndex = 46;
			this->switch7On->TabStop = false;
			this->switch7On->Click += gcnew System::EventHandler(this, &Form1::switch7On_Click);
			// 
			// switch8On
			// 
			this->switch8On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"switch8On.Image")));
			this->switch8On->Location = System::Drawing::Point(166, 388);
			this->switch8On->Name = L"switch8On";
			this->switch8On->Size = System::Drawing::Size(86, 36);
			this->switch8On->TabIndex = 47;
			this->switch8On->TabStop = false;
			this->switch8On->Click += gcnew System::EventHandler(this, &Form1::switch8On_Click);
			// 
			// led5On
			// 
			this->led5On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led5On.Image")));
			this->led5On->Location = System::Drawing::Point(52, 242);
			this->led5On->Name = L"led5On";
			this->led5On->Size = System::Drawing::Size(44, 41);
			this->led5On->TabIndex = 48;
			this->led5On->TabStop = false;
			// 
			// led6On
			// 
			this->led6On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led6On.Image")));
			this->led6On->Location = System::Drawing::Point(52, 289);
			this->led6On->Name = L"led6On";
			this->led6On->Size = System::Drawing::Size(44, 41);
			this->led6On->TabIndex = 49;
			this->led6On->TabStop = false;
			// 
			// led7On
			// 
			this->led7On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led7On.Image")));
			this->led7On->Location = System::Drawing::Point(52, 336);
			this->led7On->Name = L"led7On";
			this->led7On->Size = System::Drawing::Size(44, 41);
			this->led7On->TabIndex = 50;
			this->led7On->TabStop = false;
			// 
			// led8On
			// 
			this->led8On->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led8On.Image")));
			this->led8On->Location = System::Drawing::Point(52, 383);
			this->led8On->Name = L"led8On";
			this->led8On->Size = System::Drawing::Size(44, 41);
			this->led8On->TabIndex = 51;
			this->led8On->TabStop = false;
			// 
			// led5Off
			// 
			this->led5Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led5Off.Image")));
			this->led5Off->Location = System::Drawing::Point(52, 242);
			this->led5Off->Name = L"led5Off";
			this->led5Off->Size = System::Drawing::Size(44, 41);
			this->led5Off->TabIndex = 52;
			this->led5Off->TabStop = false;
			// 
			// led6Off
			// 
			this->led6Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led6Off.Image")));
			this->led6Off->Location = System::Drawing::Point(52, 289);
			this->led6Off->Name = L"led6Off";
			this->led6Off->Size = System::Drawing::Size(44, 41);
			this->led6Off->TabIndex = 53;
			this->led6Off->TabStop = false;
			// 
			// led7Off
			// 
			this->led7Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led7Off.Image")));
			this->led7Off->Location = System::Drawing::Point(52, 336);
			this->led7Off->Name = L"led7Off";
			this->led7Off->Size = System::Drawing::Size(44, 41);
			this->led7Off->TabIndex = 54;
			this->led7Off->TabStop = false;
			// 
			// led8Off
			// 
			this->led8Off->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"led8Off.Image")));
			this->led8Off->Location = System::Drawing::Point(52, 383);
			this->led8Off->Name = L"led8Off";
			this->led8Off->Size = System::Drawing::Size(44, 41);
			this->led8Off->TabIndex = 55;
			this->led8Off->TabStop = false;
			// 
			// Int0x90
			// 
			this->Int0x90->Location = System::Drawing::Point(328, 242);
			this->Int0x90->Name = L"Int0x90";
			this->Int0x90->Size = System::Drawing::Size(75, 23);
			this->Int0x90->TabIndex = 7;
			this->Int0x90->Text = L"Int 9&0h";
			this->Int0x90->UseVisualStyleBackColor = true;
			this->Int0x90->Click += gcnew System::EventHandler(this, &Form1::Int0x90_Click);
			// 
			// Int0x92
			// 
			this->Int0x92->Location = System::Drawing::Point(328, 300);
			this->Int0x92->Name = L"Int0x92";
			this->Int0x92->Size = System::Drawing::Size(75, 23);
			this->Int0x92->TabIndex = 9;
			this->Int0x92->Text = L"Int 9&2h";
			this->Int0x92->UseVisualStyleBackColor = true;
			this->Int0x92->Click += gcnew System::EventHandler(this, &Form1::Int0x92_Click);
			// 
			// Int0x91
			// 
			this->Int0x91->Location = System::Drawing::Point(328, 271);
			this->Int0x91->Name = L"Int0x91";
			this->Int0x91->Size = System::Drawing::Size(75, 23);
			this->Int0x91->TabIndex = 8;
			this->Int0x91->Text = L"Int 9&1h";
			this->Int0x91->UseVisualStyleBackColor = true;
			this->Int0x91->Click += gcnew System::EventHandler(this, &Form1::Int0x91_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(9, 257);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(37, 13);
			this->label17->TabIndex = 59;
			this->label17->Text = L"LED 5";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(9, 353);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(37, 13);
			this->label18->TabIndex = 60;
			this->label18->Text = L"LED 7";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(9, 305);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(37, 13);
			this->label19->TabIndex = 61;
			this->label19->Text = L"LED 6";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(9, 399);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(37, 13);
			this->label20->TabIndex = 62;
			this->label20->Text = L"LED 8";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(336, 214);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(51, 13);
			this->label21->TabIndex = 63;
			this->label21->Text = L"Interrups:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(341, 12);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(34, 13);
			this->label22->TabIndex = 64;
			this->label22->Text = L"Ports:";
			// 
			// textBoxC0Hex
			// 
			this->textBoxC0Hex->Location = System::Drawing::Point(395, 113);
			this->textBoxC0Hex->Name = L"textBoxC0Hex";
			this->textBoxC0Hex->Size = System::Drawing::Size(44, 20);
			this->textBoxC0Hex->TabIndex = 4;
			// 
			// textBoxChavesHex
			// 
			this->textBoxChavesHex->Location = System::Drawing::Point(395, 165);
			this->textBoxChavesHex->Name = L"textBoxChavesHex";
			this->textBoxChavesHex->Size = System::Drawing::Size(45, 20);
			this->textBoxChavesHex->TabIndex = 6;
			// 
			// textBoxLedHex
			// 
			this->textBoxLedHex->Location = System::Drawing::Point(395, 61);
			this->textBoxLedHex->Name = L"textBoxLedHex";
			this->textBoxLedHex->Size = System::Drawing::Size(44, 20);
			this->textBoxLedHex->TabIndex = 2;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(361, 116);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(29, 13);
			this->label23->TabIndex = 68;
			this->label23->Text = L"Hex:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(361, 168);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(29, 13);
			this->label24->TabIndex = 69;
			this->label24->Text = L"Hex:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(360, 64);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(29, 13);
			this->label25->TabIndex = 70;
			this->label25->Text = L"Hex:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(265, 116);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(25, 13);
			this->label26->TabIndex = 71;
			this->label26->Text = L"Bin:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(264, 172);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(25, 13);
			this->label27->TabIndex = 72;
			this->label27->Text = L"Bin:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(265, 64);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(25, 13);
			this->label28->TabIndex = 73;
			this->label28->Text = L"Bin:";
			// 
			// btnSobre
			// 
			this->btnSobre->Location = System::Drawing::Point(365, 366);
			this->btnSobre->Name = L"btnSobre";
			this->btnSobre->Size = System::Drawing::Size(75, 23);
			this->btnSobre->TabIndex = 10;
			this->btnSobre->Text = L"&About";
			this->btnSobre->UseVisualStyleBackColor = true;
			this->btnSobre->Click += gcnew System::EventHandler(this, &Form1::btnSobre_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 434);
			this->Controls->Add(this->btnSobre);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->textBoxLedHex);
			this->Controls->Add(this->textBoxChavesHex);
			this->Controls->Add(this->textBoxC0Hex);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->Int0x91);
			this->Controls->Add(this->Int0x92);
			this->Controls->Add(this->Int0x90);
			this->Controls->Add(this->led8Off);
			this->Controls->Add(this->led7Off);
			this->Controls->Add(this->led6Off);
			this->Controls->Add(this->led5Off);
			this->Controls->Add(this->led8On);
			this->Controls->Add(this->led7On);
			this->Controls->Add(this->led6On);
			this->Controls->Add(this->led5On);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->switch8Off);
			this->Controls->Add(this->switch7Off);
			this->Controls->Add(this->switch6Off);
			this->Controls->Add(this->switch5Off);
			this->Controls->Add(this->led4Off);
			this->Controls->Add(this->led3Off);
			this->Controls->Add(this->led2Off);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->led1Off);
			this->Controls->Add(this->led1On);
			this->Controls->Add(this->switch1Off);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnSair);
			this->Controls->Add(this->lblText1);
			this->Controls->Add(this->switch1On);
			this->Controls->Add(this->switch2Off);
			this->Controls->Add(this->switch2On);
			this->Controls->Add(this->switch3Off);
			this->Controls->Add(this->switch3On);
			this->Controls->Add(this->switch4Off);
			this->Controls->Add(this->switch4On);
			this->Controls->Add(this->switch5On);
			this->Controls->Add(this->switch6On);
			this->Controls->Add(this->switch7On);
			this->Controls->Add(this->switch8On);
			this->Controls->Add(this->led2On);
			this->Controls->Add(this->led3On);
			this->Controls->Add(this->led4On);
			this->Name = L"Form1";
			this->Text = PROGNAME;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch1Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch1On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led1On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led1Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch2On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch3On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch4On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch2Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch3Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch4Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led2Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led3Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led4Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led2On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led3On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led4On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch5Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch6Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch7Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch8Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch5On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch6On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch7On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->switch8On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led5On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led6On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led7On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led8On))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led5Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led6Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led7Off))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->led8Off))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
				
			 }
	private: System::Void btnSair_Click(System::Object^  sender, System::EventArgs^  e) {
				 //this->demoThread->ResetAbort();
				 running = false;
				 ExitApplication();
			 }

	private: System::Void btnSobre_Click(System::Object^  sender, System::EventArgs^  e) {
   char buf[1500];
   /*strcpy_s(buf, "Bancada de Testes versão 1.1mvc\n\n");
   strcat_s(buf, "Programa que simula uma bancada com chaves, leds e interrupções\n");
   strcat_s(buf, "para interação com o emulador de processador 8086 (EMU8086).\n\n");
   strcat_s(buf, "Criado para a disciplina Microprocessadores: DAS5332 e BLU3302\n");
   strcat_s(buf, "da Universidade Federal de Santa Catarina.\n");
   strcat_s(buf, "Inspirado no simulador Abacus do Prof. Roberto Ziller no EEL/UFSC.\n\n");
   strcat_s(buf, "Projetistas/desenvolvedores:\n");
   strcat_s(buf, "  Fabio Rafael Segundo <fabio.segundo@ufsc.br> UFSC Blumenau\n");
   strcat_s(buf, "  João Paulo Bodanese <joao.bodanese@gmail.com> PPGEAS/UFSC\n");
   strcat_s(buf, "  Werner Krauss Junior <werner.kraus@ufsc.br> DAS/UFSC\n\n");
   strcat_s(buf, "Programa sob licença GNU GPL v3.\n");*/
   strcpy_s(buf, "Tests Stand for 8086 version 1.2-mvc\n\n");
   strcat_s(buf, "Program wich simulates a test bench with leds, keys, buttons and\n");
   strcat_s(buf, "displays for interaction to the 8086 microprocessor emulator (EMU8086).\n\n");
   strcat_s(buf, "Created for the Microprocessors courses: DAS5332 and BLU3302\n");
   strcat_s(buf, "at Universidade Federal de Santa Catarina (UFSC).\n");
   strcat_s(buf, "Inspired in the Abacus simulator created by Prof. Roberto Ziller at EEL/UFSC.\n\n");
   strcat_s(buf, "Designers/developers:\n");
   strcat_s(buf, "  Fabio Rafael Segundo <fabio.segundo@ufsc.br> UFSC Blumenau;\n");
   strcat_s(buf, "  João Paulo Bodanese <joao.bodanese@gmail.com> PPGEAS/UFSC;\n");
   strcat_s(buf, "  Werner Krauss Junior <werner.kraus@ufsc.br> DAS/UFSC.\n\n");
   strcat_s(buf, "Program under GNU GPL v3 license.\n");
      MessageBox::Show(String(buf).ToString(),PROGNAME, MessageBoxButtons::OK,MessageBoxIcon::Information);
			 }

	void charToBin(char bin[9], unsigned char val) {
		int i;
		for(i=7;i>=0;i--)
		  (val & (1 << i)) ? bin[7-i]='1' : bin[7-i]='0';
		bin[8]='\0';
	}

    void SetTextBox1(unsigned char val)
    {
		char hex[5], bin[9]="";
		
		charToBin(bin,val);
		sprintf_s(hex,"%02Xh",val);

		textBox1->Text = gcnew String(bin);
		textBoxC0Hex->Text = gcnew String(hex);
    }
	 
    void SetTextBox2(unsigned char val)
    {
		char hex[5],bin[9]="";
		
		charToBin(bin,val);
		sprintf_s(hex,"%02Xh",val);

		textBox2->Text = gcnew String(bin);
		textBoxChavesHex->Text = gcnew String(hex);
    }
	 
	void SetTextBox3(unsigned char val)
    {
		char hex[5],bin[9]="";

		UpdateLeds(val);

		charToBin(bin,val);
		sprintf_s(hex,"%02Xh",val);

		textBox3->Text = gcnew String(bin);
		textBoxLedHex->Text = gcnew String(hex);
    }

	void ReadBus()
    {
		unsigned char val;
		unsigned int  ival;

		ival = READ_IO_WORD(LED_PORT);
		val = ival & 0x00FF;
		SetTextBox3(val);
		val = (ival & 0xFF00) >> 8;
		SetTextBox1(val);

		//val = READ_IO_BYTE(0xC0);
		//SetTextBox1(val);
		val = READ_IO_BYTE(SWITCH_PORT);
		SetTextBox2(val);
		//val = READ_IO_BYTE(LED_PORT);
		//SetTextBox3(val);

	}
		
	void UpdateLeds(unsigned char val)
    {
		// LED 1
		if(val & 0x1){
			led1On->Visible = true;
			led1Off->Visible = false;
		}else{
			led1On->Visible = false;
			led1Off->Visible = true;
		}

		// LED 2
		if(val & 0x2){
			led2On->Visible = true;
			led2Off->Visible = false;
		}else{
			led2On->Visible = false;
			led2Off->Visible = true;
		}

		// LED 3
		if(val & 0x4){
			led3On->Visible = true;
			led3Off->Visible = false;
		}else{
			led3On->Visible = false;
			led3Off->Visible = true;
		}

		// LED 4
		if(val & 0x8){
			led4On->Visible = true;
			led4Off->Visible = false;
		}else{
			led4On->Visible = false;
			led4Off->Visible = true;
		}

		// LED 5
		if(val & 0x10){
			led5On->Visible = true;
			led5Off->Visible = false;
		}else{
			led5On->Visible = false;
			led5Off->Visible = true;
		}

		// LED 6
		if(val & 0x20){
			led6On->Visible = true;
			led6Off->Visible = false;
		}else{
			led6On->Visible = false;
			led6Off->Visible = true;
		}

		// LED 7
		if(val & 0x40){
			led7On->Visible = true;
			led7Off->Visible = false;
		}else{
			led7On->Visible = false;
			led7Off->Visible = true;
		}

		// LED 8
		if(val & 0x80){
			led8On->Visible = true;
			led8Off->Visible = false;
		}else{
			led8On->Visible = false;
			led8Off->Visible = true;
		}

    }

	unsigned char READ_IO_BYTE(long lPORT_NUM)
	{
		unsigned char tb;

		FILE *fp;
		errno_t err;
		while ((err = fopen_s(&fp, sIO_FILE, "rb"))!=0)
		  if (errno!=EACCES) FileNotFound(sIO_FILE);
     
		fseek(fp, lPORT_NUM, SEEK_SET);
		tb = fgetc(fp);

		fclose(fp);

		return tb;
	}

	unsigned int READ_IO_WORD(long lPORT_NUM)
	{
		unsigned int ti;
		unsigned char tb1;
		unsigned char tb2;

		tb1 = READ_IO_BYTE(lPORT_NUM);
		tb2 = READ_IO_BYTE(lPORT_NUM+1);

		ti = tb2;
		ti = ti << 8;
		ti = ti + tb1;

		return ti;
	}
	 
	void WRITE_IO_BYTE(long lPORT_NUM, unsigned char uValue)
	{
		FILE *fp;
		errno_t err;

		while ((err = fopen_s(&fp, sIO_FILE, "rb+"))!=0)
		  if (errno!=EACCES) FileNotFound(sIO_FILE);

		fseek(fp, lPORT_NUM, SEEK_SET);
		fputc(uValue, fp);

		fclose(fp);
	}

	void WRITE_INTERRUPT(long interrupt, unsigned char uValue)
	{
		FILE *fp;
		errno_t err;

		while ((err = fopen_s(&fp, sINT_FILE, "rb+"))!=0)
		  if (errno!=EACCES) FileNotFound(sINT_FILE);

		fseek(fp, interrupt, SEEK_SET);
		fputc(uValue, fp);

		fclose(fp);
	}

	void WRITE_IO_WORD(long lPORT_NUM, unsigned int iValue)
	{
		WRITE_IO_BYTE (lPORT_NUM, iValue & 0x00FF);
		WRITE_IO_BYTE (lPORT_NUM+1, (iValue & 0xFF00) >> 8);
	}

	void CreateFiles()
	{
		char buf[500];
		FILE *fIo,*fInt;
		errno_t err;

        // IO
		int ct=0;
		while ((err = fopen_s(&fIo, sIO_FILE, "wb+")) != 0 && ct<nrTentativas) ct++;
		if (ct==nrTentativas) {
			strcpy_s(buf, "Not possible to create the file ");
			strcat_s(buf, sIO_FILE);
			strcat_s(buf, ". Verify the file path and write grant!");
			MessageBox::Show(String(buf).ToString(),L"Error", MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
			fclose(fIo);
			Environment::Exit(0);
		}
		fclose(fIo);

        // Interrupt
		ct=0;
		while ((err = fopen_s(&fInt, sINT_FILE, "wb+")) != 0 && ct<nrTentativas) ct++;
		if (ct==nrTentativas) {
			strcpy_s(buf, "Not possible to create the file ");
			strcat_s(buf, sINT_FILE);
			strcat_s(buf, ". Verify the file path and write grant!");
			MessageBox::Show(String(buf).ToString(),L"Error", MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
			fclose(fIo);
			Environment::Exit(0);
		}
		fclose(fInt);

	}

	void ExitApplication()
    {
      if (MessageBox::Show("Close application?",PROGNAME, MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes )
      {
         Application::Exit();
      }
    }

	void FileNotFound(char sFile[])
    {
	  char buf[500];
	  char str[255];

	  strcpy_s(buf, "Arquivo ");
	  strcat_s(buf, sFile);
	  strcat_s(buf, ". Erro: (");
	  _itoa_s((int)errno, str, 10);
	  strcat_s(buf, str);
	  strcat_s(buf, ") ");
	  strerror_s(str,255,errno);
	  strcat_s(buf, str);
	  strcat_s(buf, ". Sair da Aplicação?");
      if(MessageBox::Show(String(buf).ToString(),PROGNAME, MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes )
      {
         //Application::Exit();
		Environment::Exit(0);
      }
    }

	void FileIniNotFound()
    {
	  char buf[500];
      strcpy_s(buf, "Arquivo ");
	  strcat_s(buf, sINI_FILE);
	  strcat_s(buf, ". não encontrado ou sem configuração para EMUPORT e/ou HW_INTERRUPT_FILE. Verifique se a instalação está correta.");
      MessageBox::Show(String(buf).ToString(),L"Error", MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
	  Environment::Exit(0);
    }

	void ReadIniFile() {

   	  // Recupera valor do emu8086.ini		
	  FILE *f;
      errno_t err;

      if (err = fopen_s(&f, sINI_FILE, "r") != 0) {
		FileIniNotFound();
	  } else {

		// Busca EMUPORT e HW_INTERRUPT_FILE no emu8086.ini  
		int lineNumber = 0;
		char* Setting=(char*)malloc(40);
        char* Value=(char*)malloc(60);
		int ctvalores=0;

        for(;;) {
		  // le linha do arquivo ini
          char line[255]; 
          fgets(line, 255, f);
          if (feof(f) || ctvalores==2) { 
			break;
		  } else {
            lineNumber++;
          }

		  // verifica configuracao = valor na linha
		  int ct=0, ctv=0, cts=0;
		  Value[0]='\0';
		  Setting[0]='\0';
		  int posigual=0, ctbarra=0;
		  while (line[ct]!=0 && line[ct]!=';' && line[ct]!=13) {
			if (line[ct]==10) { ct++; continue; }
			if (line[ct]==' ' && !posigual) { ct++; continue; }
			if (line[ct]=='=') { posigual=1; ct++; continue; }
			if (posigual) {
			  if (ctv<60) { Value[ctv]=line[ct]; ctv++; }
			} else {
			  if (ctv<40) {	Setting[cts]=line[ct]; cts++; }
			}
			if (line[ct]=='\\')
			  if (ctbarra==0) { ctbarra++; continue; }
			  else ctbarra=0;
			ct++;
		  }
		  Value[ctv]=0;
		  Setting[cts]=0;

          // se a configuracao for EMUPORT ou HW_INTERRUPT_FILE atribui valores
		  // se os dois valores já foram obtidos termina a leitura do arquivo ini
		  // ok int a=sscanf_s(line, "%s=%s", &Setting, &Value);
          //if (sscanf_s(line, "%[^=]=%s", &Setting, &Value)==2) {
		  if(strcmp(Setting,"EMUPORT")==0) {
			strcpy_s(sIO_FILE,strlen(Value)+1,Value);
		    ctvalores++;
		  } else {
			if (strcmp(Setting,"HW_INTERRUPT_FILE")==0) {
			  strcpy_s(sINT_FILE,strlen(Value)+1,Value);
		      ctvalores++;
			}
		  }
        }
        fclose(f);	
      }

      return;
	}



//private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e) {
	void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			this->demoThread = gcnew Thread(gcnew ThreadStart(this,&Form1::readThread));
		    this->demoThread->Start();

	}

	private: void readThread()
	{
		while(running){
			this->Invoke(gcnew MethodInvoker(this, &Form1::ReadBus));
			Thread::Sleep(100);
		}
	}

	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

// SWITCH 1
private: System::Void switch1On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch1On->Visible = false;
			switch1Off->Visible = true;
			switchVal &= 0xFE;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch1Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch1On->Visible = true;
			switch1Off->Visible = false;
			switchVal |= 0x01; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		}

// SWITCH 2
private: System::Void switch2On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch2On->Visible = false;
			switch2Off->Visible = true;
			switchVal &= 0xFD; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
}
private: System::Void switch2Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch2On->Visible = true;
			switch2Off->Visible = false;
			switchVal |= 0x02;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }

// SWITCH 3
private: System::Void switch3On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch3On->Visible = false;
			switch3Off->Visible = true;
			switchVal &= 0xFB; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch3Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch3On->Visible = true;
			switch3Off->Visible = false;
			switchVal |= 0x04;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }

// SWITCH 4
private: System::Void switch4On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch4On->Visible = false;
			switch4Off->Visible = true;
			switchVal &= 0xF7; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch4Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch4On->Visible = true;
			switch4Off->Visible = false;
			switchVal |= 0x08;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch5On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch5On->Visible = false;
			switch5Off->Visible = true;
			switchVal &= 0xEF; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch5Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch5On->Visible = true;
			switch5Off->Visible = false;
			switchVal |= 0x10;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch6On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch6On->Visible = false;
			switch6Off->Visible = true;
			switchVal &= 0xDF; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch6Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch6On->Visible = true;
			switch6Off->Visible = false;
			switchVal |= 0x20;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch7On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch7On->Visible = false;
			switch7Off->Visible = true;
			switchVal &= 0xBF; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch7Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch7On->Visible = true;
			switch7Off->Visible = false;
			switchVal |= 0x40;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch8On_Click(System::Object^  sender, System::EventArgs^  e) {
			switch8On->Visible = false;
			switch8Off->Visible = true;
			switchVal &= 0x7F; 
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void switch8Off_Click(System::Object^  sender, System::EventArgs^  e) {
			switch8On->Visible = true;
			switch8Off->Visible = false;
			switchVal |= 0x80;
			WRITE_IO_BYTE(SWITCH_PORT,switchVal);
		 }
private: System::Void Int0x90_Click(System::Object^  sender, System::EventArgs^  e) {
			 WRITE_INTERRUPT(0x90,INT_ON);
		 }
private: System::Void Int0x91_Click(System::Object^  sender, System::EventArgs^  e) {
			 WRITE_INTERRUPT(0x91,INT_ON);
		 }
private: System::Void Int0x92_Click(System::Object^  sender, System::EventArgs^  e) {
			 WRITE_INTERRUPT(0x92,INT_ON);
		 }
};
}


//========================================================================================================
// Exemplo para interrupção 0x90
#if 0

; interrupt vector (memory from 00000h to 00400h)
; keeps addresses of all interrupts (from 00h to 0ffh).
; you can add new interrupt or modify existing interrupts.
; address of interrupt M is stored in vector at offset M * 4,
; for example: interrupt 10h is stored at offset 10h * 4.
; first goes the offset, then segment (total of 2 bytes).

; for more information refer to "global memory table" in c:\emu8086\documentation.
 
; note: this is simplified example, it is not recommended to make changes to it
; and run it on the real computer, especially it is not recommended to replace disk
; processing interrupts because this may cause data loss and other instability problems.

 
name "custint"

#start=Interrupt.exe#

org 100h

start:
 
; set video mode to 3 - 16 color 80x25
mov ah, 0
mov al, 3
int 10h
 
 
; set es to "0000":
mov ax, 0       
mov es, ax
; calculate vector address for interrupt 90h:
mov al, 90h    
; multiply 90h by 4, store result in ax:
mov bl, 4h       
mul bl          
mov bx, ax
; copy offset into interrupt vector:
mov si, offset [test1]
mov es:[bx], si
add bx, 2   
; copy segment into interrupt vector:    
mov ax, cs     
mov es:[bx], ax
         

; int 90h    ; test newly created interrupt.
wait_for_hw_int:
    in al,111     ;read the port at 111
    jmp wait_for_hw_int
 
; wait for any key press:
mov ah, 0
int 16h
 
 
int 20h     ; halt execution.


; interrupt 90h starts here:
test1: pusha  ; store all registers.

; make sure data segment is code segment:
       push cs
       pop ds

; set segment register to video memory:
       mov     ax, 0b800h
       mov     es, ax

; print message, each character is written as
; a word, high byte is color and low byte is
; ascii code:
      lea si, msg      ; load offset of msg to si.
      mov di, 0        ; point to start of the screen.
print:
      cmp [si], 0      ; if "0" then stop.
      je stop
      mov bl,  [si]    ; read ascii code from msg.
      mov bh, 0f1h     ; set colors: white background, blue text.
      mov es:[di], bx  ; write to vidio memory.
      add di, 2        ; go to next position on screen.
      inc si           ; next char.
      jmp print
stop:
      popa  ; re-store all registers.
      iret  ; return from interrupt.
 
msg db "test of custom interrupt!", 0

#endif

//========================================================================================================



//========================================================================================================
// Exemplo de In/Out
#if 0

; c:\emu8086\devices\Bancada8086.exe

#start=Bancada8086.exe#


#make_bin#

name "Bancada8086"
           
  mov ah, 0
x1:
  in al, 20h
  out 22h, ax
  inc ah
jmp x1

hlt

#endif
