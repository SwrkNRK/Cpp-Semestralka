#pragma once

namespace Klient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net::Sockets;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
	private: System::Windows::Forms::Button^  buttonAddColumn;
	private: System::Windows::Forms::TextBox^  textBoxAddColumn;
	private: System::Windows::Forms::Button^  buttonRemoveColumn;
	private: System::Windows::Forms::ComboBox^  comboBoxRemoveColumn;
	private: System::Windows::Forms::ComboBox^  comboBoxColumnType;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBoxColumns;
	private: System::Windows::Forms::GroupBox^  groupBoxServer;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TabControl^  tabControl1;


	private: System::Windows::Forms::TabPage^  tabPageDatabase;
	private: System::Windows::Forms::TabPage^  tabPageNew;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  buttonCreate;
	private: System::Windows::Forms::TextBox^  textBoxNewName;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TabPage^  tabPageCalendar;

	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;





	public:

		NetworkStream^ stream;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  ConnectBtn;
	private: System::Windows::Forms::Button^  LoadBtn;
	private: System::Windows::Forms::Button^  SaveBtn;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ConnectBtn = (gcnew System::Windows::Forms::Button());
			this->LoadBtn = (gcnew System::Windows::Forms::Button());
			this->SaveBtn = (gcnew System::Windows::Forms::Button());
			this->buttonAddColumn = (gcnew System::Windows::Forms::Button());
			this->textBoxAddColumn = (gcnew System::Windows::Forms::TextBox());
			this->buttonRemoveColumn = (gcnew System::Windows::Forms::Button());
			this->comboBoxRemoveColumn = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxColumnType = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxColumns = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBoxServer = (gcnew System::Windows::Forms::GroupBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageDatabase = (gcnew System::Windows::Forms::TabPage());
			this->tabPageNew = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxNewName = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreate = (gcnew System::Windows::Forms::Button());
			this->tabPageCalendar = (gcnew System::Windows::Forms::TabPage());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBoxColumns->SuspendLayout();
			this->groupBoxServer->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPageDatabase->SuspendLayout();
			this->tabPageNew->SuspendLayout();
			this->tabPageCalendar->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(7, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(811, 692);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MyForm::dataGridView1_DataError);
			// 
			// ConnectBtn
			// 
			this->ConnectBtn->Location = System::Drawing::Point(43, 55);
			this->ConnectBtn->Name = L"ConnectBtn";
			this->ConnectBtn->Size = System::Drawing::Size(133, 49);
			this->ConnectBtn->TabIndex = 1;
			this->ConnectBtn->Text = L"Connect";
			this->ConnectBtn->UseVisualStyleBackColor = true;
			this->ConnectBtn->Click += gcnew System::EventHandler(this, &MyForm::ConnectBtn_Click);
			// 
			// LoadBtn
			// 
			this->LoadBtn->Location = System::Drawing::Point(157, 21);
			this->LoadBtn->Name = L"LoadBtn";
			this->LoadBtn->Size = System::Drawing::Size(94, 49);
			this->LoadBtn->TabIndex = 2;
			this->LoadBtn->Text = L"Load Data";
			this->LoadBtn->UseVisualStyleBackColor = true;
			this->LoadBtn->Click += gcnew System::EventHandler(this, &MyForm::LoadBtn_Click);
			// 
			// SaveBtn
			// 
			this->SaveBtn->Location = System::Drawing::Point(31, 21);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(93, 49);
			this->SaveBtn->TabIndex = 3;
			this->SaveBtn->Text = L"Save Data";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &MyForm::SaveBtn_Click);
			// 
			// buttonAddColumn
			// 
			this->buttonAddColumn->Location = System::Drawing::Point(97, 95);
			this->buttonAddColumn->Name = L"buttonAddColumn";
			this->buttonAddColumn->Size = System::Drawing::Size(124, 32);
			this->buttonAddColumn->TabIndex = 4;
			this->buttonAddColumn->Text = L"Add Column";
			this->buttonAddColumn->UseVisualStyleBackColor = true;
			this->buttonAddColumn->Click += gcnew System::EventHandler(this, &MyForm::buttonAddColumn_Click);
			// 
			// textBoxAddColumn
			// 
			this->textBoxAddColumn->Location = System::Drawing::Point(97, 39);
			this->textBoxAddColumn->Name = L"textBoxAddColumn";
			this->textBoxAddColumn->Size = System::Drawing::Size(108, 22);
			this->textBoxAddColumn->TabIndex = 5;
			// 
			// buttonRemoveColumn
			// 
			this->buttonRemoveColumn->Location = System::Drawing::Point(97, 214);
			this->buttonRemoveColumn->Name = L"buttonRemoveColumn";
			this->buttonRemoveColumn->Size = System::Drawing::Size(124, 33);
			this->buttonRemoveColumn->TabIndex = 6;
			this->buttonRemoveColumn->Text = L"Remove Column";
			this->buttonRemoveColumn->UseVisualStyleBackColor = true;
			this->buttonRemoveColumn->Click += gcnew System::EventHandler(this, &MyForm::button_Remove_Column_Click);
			// 
			// comboBoxRemoveColumn
			// 
			this->comboBoxRemoveColumn->FormattingEnabled = true;
			this->comboBoxRemoveColumn->Location = System::Drawing::Point(97, 183);
			this->comboBoxRemoveColumn->Name = L"comboBoxRemoveColumn";
			this->comboBoxRemoveColumn->Size = System::Drawing::Size(140, 23);
			this->comboBoxRemoveColumn->TabIndex = 7;
			// 
			// comboBoxColumnType
			// 
			this->comboBoxColumnType->FormattingEnabled = true;
			this->comboBoxColumnType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Integer", L"Double", L"String", L"Boolean" });
			this->comboBoxColumnType->Location = System::Drawing::Point(97, 64);
			this->comboBoxColumnType->Name = L"comboBoxColumnType";
			this->comboBoxColumnType->Size = System::Drawing::Size(140, 23);
			this->comboBoxColumnType->TabIndex = 8;
			this->comboBoxColumnType->Text = L"String";
			this->comboBoxColumnType->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxColumnType_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 15);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Data Type:";
			// 
			// groupBoxColumns
			// 
			this->groupBoxColumns->Controls->Add(this->label3);
			this->groupBoxColumns->Controls->Add(this->buttonRemoveColumn);
			this->groupBoxColumns->Controls->Add(this->label2);
			this->groupBoxColumns->Controls->Add(this->comboBoxRemoveColumn);
			this->groupBoxColumns->Controls->Add(this->label1);
			this->groupBoxColumns->Controls->Add(this->textBoxAddColumn);
			this->groupBoxColumns->Controls->Add(this->comboBoxColumnType);
			this->groupBoxColumns->Controls->Add(this->buttonAddColumn);
			this->groupBoxColumns->Location = System::Drawing::Point(840, 175);
			this->groupBoxColumns->Name = L"groupBoxColumns";
			this->groupBoxColumns->Size = System::Drawing::Size(282, 273);
			this->groupBoxColumns->TabIndex = 11;
			this->groupBoxColumns->TabStop = false;
			this->groupBoxColumns->Text = L"Columns Management";
			this->groupBoxColumns->Enter += gcnew System::EventHandler(this, &MyForm::groupBoxColumns_Enter);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 15);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Col name:";
			// 
			// groupBoxServer
			// 
			this->groupBoxServer->Controls->Add(this->LoadBtn);
			this->groupBoxServer->Controls->Add(this->SaveBtn);
			this->groupBoxServer->Location = System::Drawing::Point(840, 82);
			this->groupBoxServer->Name = L"groupBoxServer";
			this->groupBoxServer->Size = System::Drawing::Size(282, 87);
			this->groupBoxServer->TabIndex = 12;
			this->groupBoxServer->TabStop = false;
			this->groupBoxServer->Text = L"Sever comunication";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageDatabase);
			this->tabControl1->Controls->Add(this->tabPageNew);
			this->tabControl1->Controls->Add(this->tabPageCalendar);
			this->tabControl1->Location = System::Drawing::Point(3, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1136, 736);
			this->tabControl1->TabIndex = 13;
			this->tabControl1->Visible = false;
			// 
			// tabPageDatabase
			// 
			this->tabPageDatabase->Controls->Add(this->dataGridView1);
			this->tabPageDatabase->Controls->Add(this->groupBoxColumns);
			this->tabPageDatabase->Controls->Add(this->groupBoxServer);
			this->tabPageDatabase->Location = System::Drawing::Point(4, 24);
			this->tabPageDatabase->Name = L"tabPageDatabase";
			this->tabPageDatabase->Padding = System::Windows::Forms::Padding(3);
			this->tabPageDatabase->Size = System::Drawing::Size(1128, 708);
			this->tabPageDatabase->TabIndex = 0;
			this->tabPageDatabase->Text = L"Database";
			this->tabPageDatabase->UseVisualStyleBackColor = true;
			// 
			// tabPageNew
			// 
			this->tabPageNew->Controls->Add(this->buttonCreate);
			this->tabPageNew->Controls->Add(this->textBoxNewName);
			this->tabPageNew->Controls->Add(this->label5);
			this->tabPageNew->Controls->Add(this->label4);
			this->tabPageNew->Location = System::Drawing::Point(4, 24);
			this->tabPageNew->Name = L"tabPageNew";
			this->tabPageNew->Padding = System::Windows::Forms::Padding(3);
			this->tabPageNew->Size = System::Drawing::Size(1128, 708);
			this->tabPageNew->TabIndex = 1;
			this->tabPageNew->Text = L"New";
			this->tabPageNew->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(32, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(231, 24);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Creating a new database";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(36, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 15);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Name:";
			// 
			// textBoxNewName
			// 
			this->textBoxNewName->Location = System::Drawing::Point(95, 94);
			this->textBoxNewName->Name = L"textBoxNewName";
			this->textBoxNewName->Size = System::Drawing::Size(134, 22);
			this->textBoxNewName->TabIndex = 2;
			// 
			// buttonCreate
			// 
			this->buttonCreate->Location = System::Drawing::Point(95, 140);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = System::Drawing::Size(75, 23);
			this->buttonCreate->TabIndex = 3;
			this->buttonCreate->Text = L"Create";
			this->buttonCreate->UseVisualStyleBackColor = true;
			// 
			// tabPageCalendar
			// 
			this->tabPageCalendar->Controls->Add(this->monthCalendar1);
			this->tabPageCalendar->Location = System::Drawing::Point(4, 24);
			this->tabPageCalendar->Name = L"tabPageCalendar";
			this->tabPageCalendar->Padding = System::Windows::Forms::Padding(3);
			this->tabPageCalendar->Size = System::Drawing::Size(1128, 708);
			this->tabPageCalendar->TabIndex = 2;
			this->tabPageCalendar->Text = L"Calendar";
			this->tabPageCalendar->UseVisualStyleBackColor = true;
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->CalendarDimensions = System::Drawing::Size(3, 4);
			this->monthCalendar1->Location = System::Drawing::Point(229, 53);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1141, 738);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->ConnectBtn);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Database master";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBoxColumns->ResumeLayout(false);
			this->groupBoxColumns->PerformLayout();
			this->groupBoxServer->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPageDatabase->ResumeLayout(false);
			this->tabPageNew->ResumeLayout(false);
			this->tabPageNew->PerformLayout();
			this->tabPageCalendar->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		DataTable^ table = gcnew DataTable;


#pragma endregion
	private: System::Void ConnectBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
		connect(); //pripojenie na databazu vid o kusok nizsie

		//ZOBRAZOVANIE PRVKOV AFTER CONNECT
		ConnectBtn->Visible = false;
		/* Moze byt zakomentovane lebo vsetky elementy su sucastov tabControl1
		this->LoadBtn->Visible = true;
		this->SaveBtn->Visible = true;
		this->buttonAddColumn->Visible = true;
		this->textBoxAddColumn->Visible = true;
		this->dataGridView1->Visible = true;
		this->comboBoxRemoveColumn->Visible = true;
		this->buttonRemoveColumn->Visible = true;
		this->comboBoxColumnType->Visible = true;
		this->label1->Visible = true;
		this->label2->Visible = true;
		this->groupBoxColumns->Visible = true;
		this->groupBoxServer->Visible = true;
		 */
		this->tabControl1->Visible = true;
	}

			 void connect() {
				 try
				 {
					 myTcpClient = gcnew TcpClient("localhost", 12150);
					 stream = myTcpClient->GetStream();
				 }
				 catch (System::Exception ^e)
				 {

					 if (MessageBox::Show("Unable to connect to the server", "Connection Error", MessageBoxButtons::RetryCancel, MessageBoxIcon::Error) == System::Windows::Forms::DialogResult::Retry)
					 {
						 connect();
					 }
					 else
					 {
						 Application::Exit();
					 }

				 }
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
				 bool quit = false;

				 do {

					 if (recvBufr[i] == '*') {
						 quit = true;
					 }

					 if (recvBufr[i] == ' ' || recvBufr[i] == '*') {
						 splitedStr = str->Split(':');
						 addColToTable(splitedStr[0], splitedStr[1]);
						 str = "";
					 }
					 else { str += Convert::ToChar(recvBufr[i]); }

					 i++;
					 if (quit) { break; }

				 } while (true);

				 i++;
				 quit = false;
				 do {

					 if (recvBufr[i] == '*') {
						 quit = true;
					 }

					 if (recvBufr[i] == ':' || recvBufr[i] == '*') {
						 splitedStr = str->Split(',');
						 DataRow^ row = table->NewRow();
						 for (int i = 0; i < table->Columns->Count; i++) {
							 row[i] = splitedStr[i];
						 }
						 table->Rows->Add(row);
						 str = "";
					 }
					 else { str += Convert::ToChar(recvBufr[i]); }

					 i++;
					 if (quit) { break; }

				 } while (true);

				 dataGridView1->DataSource = table;


			 }

			 String^ getDataFromServer() {
				 String^ str = "";
				 do {

					 if (stream->DataAvailable) {
						 stream->Read(receiveBuffer, 0, 150);

						 break;
					 }
				 } while (true);

				 str = System::Text::Encoding::ASCII->GetString(receiveBuffer);

				 return str;

			}


	private: System::Void LoadBtn_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ str = "LOAD:111\0";

		sendBuffer = System::Text::Encoding::ASCII->GetBytes(str);
		stream->Write(sendBuffer, 0, System::Text::Encoding::ASCII->GetByteCount(str));


		getDataFromServer();

		loadTableByStr(receiveBuffer);

		//Program precita nazvy v columns a hodi ich do comboboxu
		for (int i = 0; i < this->dataGridView1->ColumnCount; i++) 
		{
			this->comboBoxRemoveColumn->Items->Add(this->dataGridView1->Columns[i]->Name->ToString());
		}

	}

			String^ getActualData() {
				String ^ str = "";
				dataGridView1->AllowUserToAddRows = false; //pri nacitavani dat treba zakazat uzivatelovi editovat tabulku
				for (int i = 0; i < dataGridView1->Rows->Count; i++)
				{
					for (int j = 0; j < dataGridView1->Columns->Count; j++)
					{
						str += dataGridView1[j, i]->Value->ToString();
						if (j != dataGridView1->Columns->Count - 1)
						{
							str += ",";
						}
					}
					str += ":";
				}
				str += "*";
				dataGridView1->AllowUserToAddRows = true;

				return str;
	}


private: System::Void SaveBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str = "SAVE:111:";

	str += getActualData();
	str += "\0";

	sendBuffer = System::Text::Encoding::ASCII->GetBytes(str);
	stream->Write(sendBuffer, 0, System::Text::Encoding::ASCII->GetByteCount(str));

	
	if (!getDataFromServer()->Contains("SAVED")) {
		//TODO popup okno pre klienta, nepodarilo sa uloži dáta na server
	}
}
private: System::Void buttonAddColumn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->comboBoxRemoveColumn->Items->Add(textBoxAddColumn->Text);
	addColToTable(textBoxAddColumn->Text, comboBoxColumnType->SelectedItem->ToString()); //prida column do datagridview
	this->textBoxAddColumn->Text = ""; //po pridani column vymaze obsah txtboxu
}
private: System::Void button_Remove_Column_Click(System::Object^  sender, System::EventArgs^  e) { //neviem preco sa to nepremenovalo ale patri to buttonRemoveColumn
	for (int i = 0; i < this->dataGridView1->ColumnCount; i++) //Prechadza polom columov v datagridview a ked najde zhodny ako je zvoleny v comboboxe vymaze ho
	{
		if (this->dataGridView1->Columns[i]->Name->ToString() == this->comboBoxRemoveColumn->SelectedItem->ToString()) { 
			this->dataGridView1->Columns->RemoveAt(i);
			this->comboBoxRemoveColumn->Items->Remove(this->comboBoxRemoveColumn->SelectedItem);
			break;
		}		
	}
}
private: System::Void comboBoxColumnType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView1_DataError(System::Object^  sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^  e) {
	MessageBox::Show("You have entered a wrong data type!", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);	
}
private: System::Void groupBoxColumns_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
