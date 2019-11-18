#pragma once

#include "Database.h"
using namespace System;

using namespace	System::Net;

using namespace System::Net::Sockets;

#include <string>
#include <stdio.h>
#include <stdlib.h>


namespace KlientForCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Username;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Password;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  LoginBut;
	private: System::Windows::Forms::Button^  CloseBtn;

	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->LoginBut = (gcnew System::Windows::Forms::Button());
			this->CloseBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// Username
			// 
			this->Username->BackColor = System::Drawing::SystemColors::WindowText;
			this->Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Username->ForeColor = System::Drawing::Color::DeepPink;
			this->Username->Location = System::Drawing::Point(280, 284);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(464, 37);
			this->Username->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::WindowText;
			this->label1->Font = (gcnew System::Drawing::Font(L"AR DESTINE", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Magenta;
			this->label1->Location = System::Drawing::Point(264, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(466, 41);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Login to your application";
			// 
			// Password
			// 
			this->Password->BackColor = System::Drawing::SystemColors::WindowText;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Password->ForeColor = System::Drawing::Color::DeepPink;
			this->Password->Location = System::Drawing::Point(280, 364);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(464, 37);
			this->Password->TabIndex = 2;
			this->Password->UseSystemPasswordChar = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(227, 364);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(47, 37);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(227, 284);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(47, 37);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// LoginBut
			// 
			this->LoginBut->BackColor = System::Drawing::SystemColors::WindowText;
			this->LoginBut->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->LoginBut->FlatAppearance->BorderSize = 0;
			this->LoginBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginBut->Font = (gcnew System::Drawing::Font(L"AR DARLING", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginBut->ForeColor = System::Drawing::Color::DeepPink;
			this->LoginBut->Location = System::Drawing::Point(427, 489);
			this->LoginBut->Name = L"LoginBut";
			this->LoginBut->Size = System::Drawing::Size(176, 58);
			this->LoginBut->TabIndex = 5;
			this->LoginBut->Text = L"LOGIN";
			this->LoginBut->UseVisualStyleBackColor = false;
			this->LoginBut->Click += gcnew System::EventHandler(this, &Login::LoginBut_Click);
			// 
			// CloseBtn
			// 
			this->CloseBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CloseBtn.BackgroundImage")));
			this->CloseBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CloseBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CloseBtn->FlatAppearance->BorderSize = 0;
			this->CloseBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseBtn->Location = System::Drawing::Point(971, 12);
			this->CloseBtn->Name = L"CloseBtn";
			this->CloseBtn->Size = System::Drawing::Size(50, 49);
			this->CloseBtn->TabIndex = 6;
			this->CloseBtn->UseVisualStyleBackColor = true;
			this->CloseBtn->Click += gcnew System::EventHandler(this, &Login::CloseBtn_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1033, 691);
			this->Controls->Add(this->CloseBtn);
			this->Controls->Add(this->LoginBut);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Username);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void CloseBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void LoginBut_Click(System::Object^  sender, System::EventArgs^  e) {
		
		TcpClient^ myTcpClient;
		myTcpClient = gcnew TcpClient("localhost", 12150);
		int bufferSize = 1024;

		array<Byte>^ sendBuffer = gcnew array<Byte>(bufferSize);

		array<Byte>^ receiveBuffer = gcnew array<Byte>(bufferSize);

		array<Byte>^ byteCount;
		int bytesToRead = 0, nextReadCount, rc;

		// Get a client stream for reading and writing.
	   //  Stream stream = client.GetStream();
		String^ str = "fasKo\0";

		//sendBuffer = str;
		NetworkStream^ stream = myTcpClient->GetStream();
		

		sendBuffer = System::Text::Encoding::ASCII->GetBytes(str);

		// Send the message to the connected TcpServer. 
		//stream->Write(sendBuffer, 0, sendBuffer);
		stream->Write(sendBuffer, 0, System::Text::Encoding::ASCII->GetByteCount(str));
		

		this->Hide();
		Database^ d = gcnew Database;
		d->ShowDialog();
		this->Close();
}
private: System::Void Login_Load(System::Object^  sender, System::EventArgs^  e) {
}
};


}
