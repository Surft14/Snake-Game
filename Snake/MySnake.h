#pragma once
#include <fstream>
#include <string>
namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MySnake
	/// </summary>
	public ref class MySnake : public System::Windows::Forms::Form
	{
	public:
		MySnake(void);


	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MySnake()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ íîâàÿÈãğàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïàóçàÏğîäîëæèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ íàñòğîéêèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ èíôàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox_GameInfo;
	private: System::Windows::Forms::Label^ labelScore;

	private: System::Windows::Forms::GroupBox^ groupBox_Setting;
	private: System::Windows::Forms::Button^ button_ApplaySpeed;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSpeedSnake;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox_UpperLimit;
	private: System::Windows::Forms::PictureBox^ pictureBox_DownLimit;
	private: System::Windows::Forms::PictureBox^ pictureBox_RightLimit;
	private: System::Windows::Forms::PictureBox^ pictureBox_LeftLimit;
	private: System::Windows::Forms::Timer^ timer;

	private: System::Windows::Forms::Label^ labelGameOver;
	private: System::Windows::Forms::Label^ label_record;

	private: System::Windows::Forms::CheckBox^ checkBox_Bomb;


	private: System::ComponentModel::IContainer^ components;





	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íîâàÿÈãğàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïàóçàÏğîäîëæèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íàñòğîéêèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èíôàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_GameInfo = (gcnew System::Windows::Forms::GroupBox());
			this->label_record = (gcnew System::Windows::Forms::Label());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->groupBox_Setting = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_Bomb = (gcnew System::Windows::Forms::CheckBox());
			this->button_ApplaySpeed = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSpeedSnake = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_UpperLimit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_DownLimit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_RightLimit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_LeftLimit = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelGameOver = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox_GameInfo->SuspendLayout();
			this->groupBox_Setting->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_UpperLimit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_DownLimit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_RightLimit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_LeftLimit))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ìåíşToolStripMenuItem,
					this->èíôàToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(548, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->íîâàÿÈãğàToolStripMenuItem,
					this->ïàóçàÏğîäîëæèòüToolStripMenuItem, this->íàñòğîéêèToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// íîâàÿÈãğàToolStripMenuItem
			// 
			this->íîâàÿÈãğàToolStripMenuItem->Name = L"íîâàÿÈãğàToolStripMenuItem";
			this->íîâàÿÈãğàToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->íîâàÿÈãğàToolStripMenuItem->Text = L"Íîâàÿ èãğà";
			this->íîâàÿÈãğàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MySnake::íîâàÿÈãğàToolStripMenuItem_Click);
			// 
			// ïàóçàÏğîäîëæèòüToolStripMenuItem
			// 
			this->ïàóçàÏğîäîëæèòüToolStripMenuItem->Name = L"ïàóçàÏğîäîëæèòüToolStripMenuItem";
			this->ïàóçàÏğîäîëæèòüToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->ïàóçàÏğîäîëæèòüToolStripMenuItem->Text = L"Ïàóçà/Ïğîäîëæèòü";
			this->ïàóçàÏğîäîëæèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MySnake::ïàóçàÏğîäîëæèòüToolStripMenuItem_Click);
			// 
			// íàñòğîéêèToolStripMenuItem
			// 
			this->íàñòğîéêèToolStripMenuItem->Name = L"íàñòğîéêèToolStripMenuItem";
			this->íàñòğîéêèToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->íàñòğîéêèToolStripMenuItem->Text = L"Íàñòğîéêè";
			this->íàñòğîéêèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MySnake::íàñòğîéêèToolStripMenuItem_Click);
			// 
			// èíôàToolStripMenuItem
			// 
			this->èíôàToolStripMenuItem->Name = L"èíôàToolStripMenuItem";
			this->èíôàToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->èíôàToolStripMenuItem->Text = L"Èíôà";
			this->èíôàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MySnake::èíôàToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MySnake::âûõîäToolStripMenuItem_Click);
			// 
			// groupBox_GameInfo
			// 
			this->groupBox_GameInfo->Controls->Add(this->label_record);
			this->groupBox_GameInfo->Controls->Add(this->labelScore);
			this->groupBox_GameInfo->Location = System::Drawing::Point(0, 27);
			this->groupBox_GameInfo->Name = L"groupBox_GameInfo";
			this->groupBox_GameInfo->Size = System::Drawing::Size(272, 63);
			this->groupBox_GameInfo->TabIndex = 1;
			this->groupBox_GameInfo->TabStop = false;
			this->groupBox_GameInfo->Text = L"Äàííûå îá èãğå";
			// 
			// label_record
			// 
			this->label_record->AutoSize = true;
			this->label_record->Font = (gcnew System::Drawing::Font(L"NSimSun", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_record->Location = System::Drawing::Point(123, 20);
			this->label_record->Name = L"label_record";
			this->label_record->Size = System::Drawing::Size(121, 15);
			this->label_record->TabIndex = 1;
			this->label_record->Text = L"Ğåêîğä: 0";
			// 
			// labelScore
			// 
			this->labelScore->AutoSize = true;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"NSimSun", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelScore->Location = System::Drawing::Point(7, 20);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(91, 15);
			this->labelScore->TabIndex = 0;
			this->labelScore->Text = L"Ñ÷åò: 0";
			// 
			// groupBox_Setting
			// 
			this->groupBox_Setting->Controls->Add(this->checkBox_Bomb);
			this->groupBox_Setting->Controls->Add(this->button_ApplaySpeed);
			this->groupBox_Setting->Controls->Add(this->numericUpDownSpeedSnake);
			this->groupBox_Setting->Controls->Add(this->label2);
			this->groupBox_Setting->Location = System::Drawing::Point(144, 196);
			this->groupBox_Setting->Name = L"groupBox_Setting";
			this->groupBox_Setting->Size = System::Drawing::Size(281, 155);
			this->groupBox_Setting->TabIndex = 2;
			this->groupBox_Setting->TabStop = false;
			this->groupBox_Setting->Text = L"Íàñòğîéêè";
			this->groupBox_Setting->Visible = false;
			// 
			// checkBox_Bomb
			// 
			this->checkBox_Bomb->AutoSize = true;
			this->checkBox_Bomb->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_Bomb->Location = System::Drawing::Point(55, 101);
			this->checkBox_Bomb->Name = L"checkBox_Bomb";
			this->checkBox_Bomb->Size = System::Drawing::Size(168, 26);
			this->checkBox_Bomb->TabIndex = 3;
			this->checkBox_Bomb->Text = L"áîìáû íåâåäèìêà";
			this->checkBox_Bomb->UseVisualStyleBackColor = true;
			this->checkBox_Bomb->CheckedChanged += gcnew System::EventHandler(this, &MySnake::checkBox_Bomb_CheckedChanged);
			// 
			// button_ApplaySpeed
			// 
			this->button_ApplaySpeed->Location = System::Drawing::Point(86, 63);
			this->button_ApplaySpeed->Name = L"button_ApplaySpeed";
			this->button_ApplaySpeed->Size = System::Drawing::Size(75, 23);
			this->button_ApplaySpeed->TabIndex = 2;
			this->button_ApplaySpeed->Text = L"Ïğèìåíèòü";
			this->button_ApplaySpeed->UseVisualStyleBackColor = true;
			this->button_ApplaySpeed->Click += gcnew System::EventHandler(this, &MySnake::button_ApplaySpeed_Click);
			// 
			// numericUpDownSpeedSnake
			// 
			this->numericUpDownSpeedSnake->Location = System::Drawing::Point(112, 37);
			this->numericUpDownSpeedSnake->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Name = L"numericUpDownSpeedSnake";
			this->numericUpDownSpeedSnake->Size = System::Drawing::Size(138, 20);
			this->numericUpDownSpeedSnake->TabIndex = 1;
			this->numericUpDownSpeedSnake->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Ñêîğîñòü çìåéêè:";
			// 
			// pictureBox_UpperLimit
			// 
			this->pictureBox_UpperLimit->BackColor = System::Drawing::Color::Black;
			this->pictureBox_UpperLimit->Location = System::Drawing::Point(0, 92);
			this->pictureBox_UpperLimit->Name = L"pictureBox_UpperLimit";
			this->pictureBox_UpperLimit->Size = System::Drawing::Size(550, 10);
			this->pictureBox_UpperLimit->TabIndex = 3;
			this->pictureBox_UpperLimit->TabStop = false;
			// 
			// pictureBox_DownLimit
			// 
			this->pictureBox_DownLimit->BackColor = System::Drawing::Color::Black;
			this->pictureBox_DownLimit->Location = System::Drawing::Point(0, 632);
			this->pictureBox_DownLimit->Name = L"pictureBox_DownLimit";
			this->pictureBox_DownLimit->Size = System::Drawing::Size(550, 10);
			this->pictureBox_DownLimit->TabIndex = 4;
			this->pictureBox_DownLimit->TabStop = false;
			// 
			// pictureBox_RightLimit
			// 
			this->pictureBox_RightLimit->BackColor = System::Drawing::Color::Black;
			this->pictureBox_RightLimit->Location = System::Drawing::Point(540, 92);
			this->pictureBox_RightLimit->Name = L"pictureBox_RightLimit";
			this->pictureBox_RightLimit->Size = System::Drawing::Size(10, 550);
			this->pictureBox_RightLimit->TabIndex = 5;
			this->pictureBox_RightLimit->TabStop = false;
			// 
			// pictureBox_LeftLimit
			// 
			this->pictureBox_LeftLimit->BackColor = System::Drawing::Color::Black;
			this->pictureBox_LeftLimit->Location = System::Drawing::Point(0, 92);
			this->pictureBox_LeftLimit->Name = L"pictureBox_LeftLimit";
			this->pictureBox_LeftLimit->Size = System::Drawing::Size(10, 550);
			this->pictureBox_LeftLimit->TabIndex = 6;
			this->pictureBox_LeftLimit->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MySnake::MySnake_Update);
			// 
			// labelGameOver
			// 
			this->labelGameOver->AutoSize = true;
			this->labelGameOver->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameOver->Location = System::Drawing::Point(76, 137);
			this->labelGameOver->Name = L"labelGameOver";
			this->labelGameOver->Size = System::Drawing::Size(457, 30);
			this->labelGameOver->TabIndex = 7;
			this->labelGameOver->Text = L"Game over! Ïåğåçàïóñòèòå èãğó";
			this->labelGameOver->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelGameOver->Visible = false;
			// 
			// MySnake
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 640);
			this->Controls->Add(this->labelGameOver);
			this->Controls->Add(this->pictureBox_LeftLimit);
			this->Controls->Add(this->pictureBox_RightLimit);
			this->Controls->Add(this->pictureBox_DownLimit);
			this->Controls->Add(this->pictureBox_UpperLimit);
			this->Controls->Add(this->groupBox_Setting);
			this->Controls->Add(this->groupBox_GameInfo);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MySnake";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Èãğà Çìåéêà";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MySnake::MySnake_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox_GameInfo->ResumeLayout(false);
			this->groupBox_GameInfo->PerformLayout();
			this->groupBox_Setting->ResumeLayout(false);
			this->groupBox_Setting->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_UpperLimit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_DownLimit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_RightLimit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_LeftLimit))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: PictureBox^ fruit;
	private: PictureBox^ Bomb;
	private: array<PictureBox^>^ Serpens;
	private: bool play;
	private: bool die = false;
	private: bool firstLauncher;
	private: bool BombOnOff = true;
	private: int step = 20;
	private: float updateInterval = 100;
	private: int score = 0;
	private: int record = 0;

	private: void GeneratePositionfruit();
	private: void GeneratePositionBomb();
	private: void Eating();
	private: void Movement();
	private: void EatYourself();
	private: void GameOver();
	private: void NewGame();
	private: void ChackBorders();
	private: void Rercord();
	private: void saveRecord();
	private: int loadRecord();
	private: void creat_file_cache();

private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void èíôàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void íîâàÿÈãğàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïàóçàÏğîäîëæèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e); 
private: System::Void íàñòğîéêèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_ApplaySpeed_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox_Bomb_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

private: System::Void MySnake_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

private: void MySnake_Update(Object^ ogect, EventArgs^ e); 
};
}