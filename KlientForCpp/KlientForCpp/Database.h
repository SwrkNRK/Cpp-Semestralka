#pragma once
#include <typeinfo>

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
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(213, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1063, 814);
			this->panel2->TabIndex = 1;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Database::panel2_Paint);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(106, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(830, 691);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Database::dataGridView1_CellContentClick);
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Database_Load(System::Object^  sender, System::EventArgs^  e) {
		DataTable^ table = gcnew DataTable;
		int i;
		table->Columns->Add("ID", int::typeid);
		table->Rows->Add(1);

		dataGridView1->DataSource = table;

	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
}
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}
