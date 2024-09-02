#include "MySnake.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Snake::MySnake snake;
	Application::Run(% snake);
}

struct Vector2 {
	int X, Y;
}; 
Vector2 Derection;
Vector2 PositionFruit;
Vector2 PositionBomd;
Vector2 gameArea;

Snake::MySnake::MySnake(void)
{
	InitializeComponent();
	gameArea.X = 500;
	gameArea.Y = 500;
	firstLauncher = true;
	NewGame();
	creat_file_cache();
}

void Snake::MySnake::GeneratePositionfruit()
{
	Random^ rand = gcnew Random();
	bool positionValid = false;
	while(!positionValid)
	{
		PositionFruit.X = rand->Next(10, gameArea.X / step) * step;
		PositionFruit.Y = rand->Next(10, gameArea.Y / step) * step;
		positionValid = true;
		for (int i = 0; i < score; i++)
		{
			if (PositionFruit.X == Serpens[i]->Location.X && PositionFruit.Y == Serpens[i]->Location.Y)
			{
				positionValid = false;
				break;
			}
		}
		if (PositionBomd.X == PositionFruit.X && PositionBomd.Y == PositionFruit.Y)
		{
			positionValid = false; 
		}
	}
	
	fruit->Location = Point(PositionFruit.X, PositionFruit.Y);
	this->Controls->Add(fruit);  
}
void Snake::MySnake::GeneratePositionBomb()
{
	if(BombOnOff == true)
	{
		Random^ rand = gcnew Random();
		bool positionValid = false;
		while (!positionValid)
		{
			PositionBomd.X = rand->Next(10, gameArea.X / step) * step;
			PositionBomd.Y = rand->Next(10, gameArea.Y / step) * step;

			positionValid = true;

			for (int i = 0; i < score; i++)
			{
				if (PositionBomd.X == Serpens[i]->Location.X && PositionBomd.Y == Serpens[i]->Location.Y)
				{
					positionValid = false;
					break;
				}
			}
			if (PositionBomd.X == PositionFruit.X && PositionBomd.Y == PositionFruit.Y)
			{
				positionValid = false;
			}
		}
		Bomb->Location = Point(PositionBomd.X, PositionBomd.Y);
		this->Controls->Add(Bomb);
	}
	else
	{
		return;
	}
}
void Snake::MySnake::Eating()
{
	if (Serpens[0]->Location.X == PositionFruit.X && Serpens[0]->Location.Y == PositionFruit.Y) {
		labelScore->Text = "Счет: " + ++score;

		Serpens[score] = gcnew PictureBox();
		Serpens[score]->Location = Point(Serpens[score - 1]->Location.X + step * Derection.X, Serpens[score - 1]->Location.Y + step * Derection.Y);
		Serpens[score]->BackColor = Color::Red;
		Serpens[score]->Width = step;
		Serpens[score]->Height = step;

		this->Controls->Add(Serpens[score]); 
		GeneratePositionfruit(); 
		if(BombOnOff)
		{
			GeneratePositionBomb();
		}
	}
	else if (Serpens[0]->Location.X == PositionBomd.X && Serpens[0]->Location.Y == PositionBomd.Y)
	{
		GameOver();
	}
}
void Snake::MySnake::Movement()
{
	for (int i = score; i >= 1; i--) {
		Serpens[i]->Location = Serpens[i - 1]->Location;
	}
	Serpens[0]->Location = Point(Serpens[0]->Location.X + step * Derection.X, Serpens[0]->Location.Y + step * Derection.Y);
}
void Snake::MySnake::EatYourself()
{
	for (int i = 1; i < score; i++) {
		if (Serpens[0]->Location == Serpens[i]->Location) {
			GameOver(); 
		}
	}
}
void Snake::MySnake::GameOver()
{
	play = true;
	die = true;
	labelGameOver->Visible = true;
}
void Snake::MySnake::NewGame()
{
	if (!firstLauncher) {
		this->Controls->Remove(fruit);
		this->Controls->Remove(Bomb);
		for (int i = 0; i <= score; i++)
		{
			this->Controls->Remove(Serpens[i]);
		}
		score = 0;
	}
	else 
		firstLauncher = false;
	

	Serpens = gcnew array <PictureBox^, 1>(400);
	Serpens[0] = gcnew PictureBox();
	Serpens[0]->Location = Point(200, 200);
	Serpens[0]->BackColor = Color::Green;
	Serpens[0]->Width = step;
	Serpens[0]->Height = step;

	score = 0;
	this->Controls->Add(Serpens[0]);

	fruit = gcnew PictureBox();
	fruit->BackColor = Color::Yellow;
	fruit->Width = step;
	fruit->Height = step;
	GeneratePositionfruit();	

	if (BombOnOff) {
		Bomb = gcnew PictureBox();
		Bomb->BackColor = Color::Black;
		Bomb->Width = step;
		Bomb->Height = step;
		GeneratePositionBomb();
	}

	timer->Interval = updateInterval;
	timer->Start();

	Derection.X = 1;
	Derection.Y = 0;

	play = true;
	die = false;

	labelScore->Text = "Счет: 0";
	groupBox_Setting->Visible = false;
	labelGameOver->Visible = false;
}
void Snake::MySnake::ChackBorders()
{
	if (Serpens[0]->Location.X >= pictureBox_RightLimit->Location.X || Serpens[0]->Location.X <= pictureBox_LeftLimit->Location.X) {
		GameOver(); 
	}
	if (Serpens[0]->Location.Y <= pictureBox_UpperLimit->Location.Y || Serpens[0]->Location.Y >= pictureBox_DownLimit->Location.Y) {
		GameOver();  
	}
}
void Snake::MySnake::Rercord()
{
	if (score > loadRecord()) {
		record = score;
		label_record->Text = "Рекорд: " + record;
	}
	else
	{
		label_record->Text = "Рекорд: " + loadRecord();
	}
}

void Snake::MySnake::saveRecord()
{
	std::ofstream fout;
	std::ifstream fin;
	fin.open("Cache/RecCache.txt");
	if(fin.is_open())
	{
		std::string recordtemp;
		std::getline(fin, recordtemp);
		if(record > std::stoi(recordtemp))
		{
			fout.open("Cache/RecCache.txt");
			std::string recordtxt = std::to_string(record);
			if (fout.is_open())
			{
				fout << recordtxt;
				fout.close();
			}
			else
			{
				MessageBox::Show("Не удалось открыть кэшфайл!\nError:001");
			}
		}
	}
	else
	{
		MessageBox::Show("Не удалось открыть кэшфайл!\nError:002");
	}
}

int Snake::MySnake::loadRecord()
{
	std::ifstream fin;
	fin.open("Cache/RecCache.txt");
	if (fin.is_open())
	{
		std::string recordtemp;
		std::getline(fin, recordtemp);
		return std::stoi(recordtemp);
		fin.close();
	}
	else
	{
		fin.close();
		return 0;
	}
}

void Snake::MySnake::creat_file_cache()
{
	std::ifstream fin("Cache/RecCache.txt");
	if (fin.is_open())
	{
		return;
	}
	else
	{
		std::ofstream fout("Cache/RecCache.txt");
		fout << "0";
		fin.close();
	}
}



System::Void Snake::MySnake::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
System::Void Snake::MySnake::инфаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Правила игры: \n1. Для упровления используйет стрелки или WASD\n2. Ешьте фрукты для набора веса\n3. Не врезаться в стенки, самого себя и бомбы\n4.Esc - Пауза/Продолжить\n  .R - Новая игра", "Правила игры!");
	return System::Void();
}
System::Void Snake::MySnake::новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();
	return System::Void();
}
System::Void Snake::MySnake::паузаПродолжитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (play) {
		play = false;
	}
	else {
		play = true;
		timer->Start();
	}
	return System::Void();
}
System::Void Snake::MySnake::настройкиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBox_Setting->Visible == false) {
		play = false;

		button_ApplaySpeed->Enabled = true;
		groupBox_Setting->Visible = true;
		numericUpDownSpeedSnake->Enabled = true;
		checkBox_Bomb->Enabled = true;
	}
	else {
		play = true;
		timer->Start();
		button_ApplaySpeed->Enabled = false;
		groupBox_Setting->Visible = false;
		numericUpDownSpeedSnake->Enabled = false;
		checkBox_Bomb->Enabled = false;
	}

	return System::Void();
}
System::Void Snake::MySnake::button_ApplaySpeed_Click(System::Object^ sender, System::EventArgs^ e)
{
	updateInterval = Convert::ToSingle(numericUpDownSpeedSnake->Value);
	timer->Interval = updateInterval;
	button_ApplaySpeed->Enabled = false;
	groupBox_Setting->Visible = false;
	numericUpDownSpeedSnake->Enabled = false;
	play = true;
	timer->Start();
	return System::Void();
}
System::Void Snake::MySnake::MySnake_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode.ToString() == "Right" || e->KeyCode.ToString() == "D") 
	{
		Derection.X = 1;
		Derection.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Left" || e->KeyCode.ToString() == "A") 
	{
		Derection.X = -1;
		Derection.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Down" || e->KeyCode.ToString() == "S") 
	{
		Derection.Y = 1;
		Derection.X = 0;
	}
	else if (e->KeyCode.ToString() == "Up" || e->KeyCode.ToString() == "W") 
	{
		Derection.X = 0;
		Derection.Y = -1;
	}
	else if (e->KeyCode.ToString() == "Escape") 
	{
		паузаПродолжитьToolStripMenuItem_Click(nullptr, nullptr);
	}
	else if (e->KeyCode.ToString() == "R")
	{
		NewGame();
	}
	else if (e->KeyCode.ToString() == "E") {
		настройкиToolStripMenuItem_Click(nullptr, nullptr);
	}

	return System::Void();
}
System::Void Snake::MySnake::checkBox_Bomb_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if(BombOnOff == true)
	{
		BombOnOff = false;
		Bomb->Visible = false;
		Bomb->Enabled = false;
		this->Controls->Remove(Bomb);
	}
	else
	{
		BombOnOff = true;
		Bomb->Visible = true;
		Bomb->Enabled = true;
		this->Controls->Add(Bomb);
	}
}
void Snake::MySnake::MySnake_Update(Object^ ogect, EventArgs^ e)
{
	if (!die && play) {
		Movement();
		Eating();
		EatYourself();
		ChackBorders();	
		Rercord(); 
	}
	else if (die && play) {
		timer->Stop(); 
		saveRecord();
		MessageBox::Show("Игра окночена!", "Внимание"); 
	}
	else if (!die && !play) {
		timer->Stop(); 
		saveRecord();
		MessageBox::Show("Игра на паузе!", "Внимание");
	}
}