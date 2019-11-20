#pragma once
#include <typeinfo>
#include <stdio.h>

using namespace System;

using namespace	System::Net;

using namespace System::Net::Sockets;

namespace KlientForCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for Database
	/// </summary>
	public ref class Database : public System::Windows::Forms::Form
	{
	public:
		Database(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}



		 TcpClient^ myTcpClient;

		 int bufferSize = 1024;

		 array<Byte>^ sendBuffer = gcnew array<Byte>(bufferSize);

		 array<Byte>^ receiveBuffer = gcnew array<Byte>(bufferSize);

		 NetworkStream^ stream;


		void tryToConnect() {
			myTcpClient = gcnew TcpClient("localhost", 12150);
			stream = myTcpClient->GetStream();


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Database()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	protected:
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  AddBut;

	private: System::Windows::Forms::Button^  ViewT;

	private: System::Windows::Forms::Button^  CTBut;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  TypeTB;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  NameTB;
	private: System::Windows::Forms::Button^  AddCol;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Database::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->AddBut = (gcnew System::Windows::Forms::Button());
			this->ViewT = (gcnew System::Windows::Forms::Button());
			this->CTBut = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TypeTB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NameTB = (gcnew System::Windows::Forms::TextBox());
			this->AddCol = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->AddBut);
			this->panel1->Controls->Add(this->ViewT);
			this->panel1->Controls->Add(this->CTBut);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(213, 814);
			this->panel1->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(0, 537);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(213, 79);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Dashboard";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// AddBut
			// 
			this->AddBut->FlatAppearance->BorderSize = 0;
			this->AddBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddBut->ForeColor = System::Drawing::Color::White;
			this->AddBut->Location = System::Drawing::Point(0, 425);
			this->AddBut->Name = L"AddBut";
			this->AddBut->Size = System::Drawing::Size(213, 79);
			this->AddBut->TabIndex = 2;
			this->AddBut->Text = L"Add";
			this->AddBut->UseVisualStyleBackColor = true;
			// 
			// ViewT
			// 
			this->ViewT->FlatAppearance->BorderSize = 0;
			this->ViewT->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ViewT->ForeColor = System::Drawing::Color::White;
			this->ViewT->Location = System::Drawing::Point(0, 312);
			this->ViewT->Name = L"ViewT";
			this->ViewT->Size = System::Drawing::Size(213, 79);
			this->ViewT->TabIndex = 1;
			this->ViewT->Text = L"View Table";
			this->ViewT->UseVisualStyleBackColor = true;
			this->ViewT->Click += gcnew System::EventHandler(this, &Database::ViewT_Click);
			// 
			// CTBut
			// 
			this->CTBut->FlatAppearance->BorderSize = 0;
			this->CTBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CTBut->ForeColor = System::Drawing::Color::White;
			this->CTBut->Location = System::Drawing::Point(0, 212);
			this->CTBut->Name = L"CTBut";
			this->CTBut->Size = System::Drawing::Size(213, 79);
			this->CTBut->TabIndex = 0;
			this->CTBut->Text = L"Create Table";
			this->CTBut->UseVisualStyleBackColor = true;
			this->CTBut->Click += gcnew System::EventHandler(this, &Database::CTBut_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(213, 91);
			this->panel3->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(131, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(82, 91);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(275, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(944, 678);
			this->panel2->TabIndex = 1;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Database::panel2_Paint);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(39, 72);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(948, 708);
			this->dataGridView1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Controls->Add(this->TypeTB);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->NameTB);
			this->panel4->Controls->Add(this->AddCol);
			this->panel4->Location = System::Drawing::Point(398, 192);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1044, 777);
			this->panel4->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(554, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(386, 33);
			this->label3->TabIndex = 5;
			this->label3->Text = L"(Int, Double, String, Boolean)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(19, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 33);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Data Type";
			// 
			// TypeTB
			// 
			this->TypeTB->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->TypeTB->Location = System::Drawing::Point(223, 170);
			this->TypeTB->Name = L"TypeTB";
			this->TypeTB->Size = System::Drawing::Size(309, 40);
			this->TypeTB->TabIndex = 3;
			this->TypeTB->TextChanged += gcnew System::EventHandler(this, &Database::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(18, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Name";
			// 
			// NameTB
			// 
			this->NameTB->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NameTB->Location = System::Drawing::Point(223, 78);
			this->NameTB->Name = L"NameTB";
			this->NameTB->Size = System::Drawing::Size(309, 40);
			this->NameTB->TabIndex = 1;
			// 
			// AddCol
			// 
			this->AddCol->Location = System::Drawing::Point(25, 270);
			this->AddCol->Name = L"AddCol";
			this->AddCol->Size = System::Drawing::Size(158, 64);
			this->AddCol->TabIndex = 0;
			this->AddCol->Text = L"Add Col";
			this->AddCol->UseVisualStyleBackColor = true;
			this->AddCol->Click += gcnew System::EventHandler(this, &Database::AddCol_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 47);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Load Data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Database::button1_Click);
			// 
			// Database
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->ClientSize = System::Drawing::Size(1276, 814);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"Database";
			this->Text = L"Database";
			this->Load += gcnew System::EventHandler(this, &Database::Database_Load);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
		DataTable^ table = gcnew DataTable;
#pragma endregion
	private: System::Void Database_Load(System::Object^  sender, System::EventArgs^  e) {
		


		panel2->Visible = true;
		panel4->Visible = false;


	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
}
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void CTBut_Click(System::Object^  sender, System::EventArgs^  e) {
	panel2->Visible = false;
	panel4->Visible = true;
}
private: System::Void ViewT_Click(System::Object^  sender, System::EventArgs^  e) {
	panel4->Visible = false;
	panel2->Visible = true;

	
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}


		 int strToEnum(String^ str) {
			 str = str->ToLower();
			 
		
			 if (str->Contains("int")) {
				 return 1;
			 }

			 if (str->Contains("double")) {
				 return 2;
			 }

			 if (str->Contains("string")) {
				 return 3;
			 }

			 if (str->Contains("boolean")) {
				 return 4;
			 }
		 
			 return 0;
		 }

private: System::Void AddCol_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ name = NameTB->Text;
	String^ type = TypeTB->Text;

	switch (strToEnum(type))
	{
	case 1:
		table->Columns->Add(name, int::typeid);
		break;
	case 2:
		table->Columns->Add(name, double::typeid);
		break;
	case 3:
		table->Columns->Add(name, String::typeid);
		break;
	case 4:
		table->Columns->Add(name, Boolean::typeid);
		break;

	default:
		break;
	}

	
	
}
		 void addColToTable(String^ str1, String^ str2) {

			 switch (strToEnum(str2))
			 {
			 case 1:
				 table->Columns->Add(str1, int::typeid);
				 break;
			 
			 case 2:
				 table->Columns->Add(str1, double::typeid);
				 break;

			 case 3:
				 table->Columns->Add(str1, String::typeid);
				 break;

			 case 4:
				 table->Columns->Add(str1, Boolean::typeid);
				 break;

			 default:
				 break;
			 }

		 }

		 void loadTableByStr(array<Byte>^ recvBufr) {
			 delete table;
			 table = gcnew DataTable;
			 int i = 0;
			
			 String^ str = "";
			 array<System::String ^>^ splitedStr = gcnew array<System::String ^>(10);
			 

			 do {

				 if (recvBufr[i] == ' ' || recvBufr[i] == '*') {
					 splitedStr = str->Split(':');
					 addColToTable(splitedStr[0], splitedStr[1]);
					 str = "";
				 }
				 else { str += Convert::ToChar(recvBufr[i]); }

				 i++;

			 } while (recvBufr[i] != '*');

			 i += 2;

			 do {

				 if (recvBufr[i] == ':') {
					 splitedStr = str->Split(',');
					 for (int i = 0; i < table->Columns->Count; i++) {
						 DataRow^ row = table->NewRow();
						//TODO
						 table->Rows->InsertAt(row, i);
						 table->Rows->Add(splitedStr[i]);
					 }
					 
					 str = "";
				 }
				 else { str += Convert::ToChar(recvBufr[i]); }

				 i++;

			 } while (recvBufr[i] != '*');

			 dataGridView1->DataSource = table;
			 

		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {



	table->Columns->Add("ID", int::typeid);
	table->Rows->Add(1);

	String^ str = "LOAD:111\0";

	sendBuffer = System::Text::Encoding::ASCII->GetBytes(str);
	stream->Write(sendBuffer, 0, System::Text::Encoding::ASCII->GetByteCount(str));

	do {

		if (stream->DataAvailable) {
			stream->Read(receiveBuffer, 0, 150);

			break;
		}
	} while (true);

	str = System::Text::Encoding::ASCII->GetString(receiveBuffer);

	loadTableByStr(receiveBuffer);

}
};
}
