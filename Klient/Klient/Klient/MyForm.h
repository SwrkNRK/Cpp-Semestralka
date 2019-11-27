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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(33, 107);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(542, 368);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MyForm::dataGridView1_DataError);
			// 
			// ConnectBtn
			// 
			this->ConnectBtn->Location = System::Drawing::Point(33, 22);
			this->ConnectBtn->Name = L"ConnectBtn";
			this->ConnectBtn->Size = System::Drawing::Size(114, 43);
			this->ConnectBtn->TabIndex = 1;
			this->ConnectBtn->Text = L"Connect";
			this->ConnectBtn->UseVisualStyleBackColor = true;
			this->ConnectBtn->Click += gcnew System::EventHandler(this, &MyForm::ConnectBtn_Click);
			// 
			// LoadBtn
			// 
			this->LoadBtn->Location = System::Drawing::Point(33, 22);
			this->LoadBtn->Name = L"LoadBtn";
			this->LoadBtn->Size = System::Drawing::Size(122, 43);
			this->LoadBtn->TabIndex = 2;
			this->LoadBtn->Text = L"Load Data";
			this->LoadBtn->UseVisualStyleBackColor = true;
			this->LoadBtn->Visible = false;
			this->LoadBtn->Click += gcnew System::EventHandler(this, &MyForm::LoadBtn_Click);
			// 
			// SaveBtn
			// 
			this->SaveBtn->Location = System::Drawing::Point(170, 22);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(122, 43);
			this->SaveBtn->TabIndex = 3;
			this->SaveBtn->Text = L"Save Data";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Visible = false;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &MyForm::SaveBtn_Click);
			// 
			// buttonAddColumn
			// 
			this->buttonAddColumn->Location = System::Drawing::Point(668, 160);
			this->buttonAddColumn->Name = L"buttonAddColumn";
			this->buttonAddColumn->Size = System::Drawing::Size(106, 28);
			this->buttonAddColumn->TabIndex = 4;
			this->buttonAddColumn->Text = L"Add Column";
			this->buttonAddColumn->UseVisualStyleBackColor = true;
			this->buttonAddColumn->Visible = false;
			this->buttonAddColumn->Click += gcnew System::EventHandler(this, &MyForm::buttonAddColumn_Click);
			// 
			// textBoxAddColumn
			// 
			this->textBoxAddColumn->Location = System::Drawing::Point(668, 110);
			this->textBoxAddColumn->Name = L"textBoxAddColumn";
			this->textBoxAddColumn->Size = System::Drawing::Size(93, 20);
			this->textBoxAddColumn->TabIndex = 5;
			this->textBoxAddColumn->Visible = false;
			// 
			// buttonRemoveColumn
			// 
			this->buttonRemoveColumn->Location = System::Drawing::Point(600, 230);
			this->buttonRemoveColumn->Name = L"buttonRemoveColumn";
			this->buttonRemoveColumn->Size = System::Drawing::Size(106, 29);
			this->buttonRemoveColumn->TabIndex = 6;
			this->buttonRemoveColumn->Text = L"Remove Column";
			this->buttonRemoveColumn->UseVisualStyleBackColor = true;
			this->buttonRemoveColumn->Visible = false;
			this->buttonRemoveColumn->Click += gcnew System::EventHandler(this, &MyForm::button_Remove_Column_Click);
			// 
			// comboBoxRemoveColumn
			// 
			this->comboBoxRemoveColumn->FormattingEnabled = true;
			this->comboBoxRemoveColumn->Location = System::Drawing::Point(721, 230);
			this->comboBoxRemoveColumn->Name = L"comboBoxRemoveColumn";
			this->comboBoxRemoveColumn->Size = System::Drawing::Size(121, 21);
			this->comboBoxRemoveColumn->TabIndex = 7;
			this->comboBoxRemoveColumn->Visible = false;
			// 
			// comboBoxColumnType
			// 
			this->comboBoxColumnType->FormattingEnabled = true;
			this->comboBoxColumnType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Integer", L"Double", L"String", L"Boolean" });
			this->comboBoxColumnType->Location = System::Drawing::Point(668, 133);
			this->comboBoxColumnType->Name = L"comboBoxColumnType";
			this->comboBoxColumnType->Size = System::Drawing::Size(121, 21);
			this->comboBoxColumnType->TabIndex = 8;
			this->comboBoxColumnType->Visible = false;
			this->comboBoxColumnType->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxColumnType_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(597, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Name:";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(597, 136);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Data Type:";
			this->label2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 532);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxColumnType);
			this->Controls->Add(this->comboBoxRemoveColumn);
			this->Controls->Add(this->buttonRemoveColumn);
			this->Controls->Add(this->textBoxAddColumn);
			this->Controls->Add(this->buttonAddColumn);
			this->Controls->Add(this->SaveBtn);
			this->Controls->Add(this->LoadBtn);
			this->Controls->Add(this->ConnectBtn);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		DataTable^ table = gcnew DataTable;


#pragma endregion
	private: System::Void ConnectBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
		connect(); //pripojenie na databazu vid o kusok nizsie

		//ZOBRAZOVANIE PRVKOV AFTER CONNECT
		ConnectBtn->Visible = false;
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
};
}
