#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/any.hpp>
#include "BotObject.h"

using std::cout;
using std::cin;
using std::endl;

// обьект классов персонажей
struct Object_The_Game {
	// щит
	virtual void Shield() = 0;
	// атака
	virtual void Attack() = 0;
	// урон
	virtual int Attack_Damgae() = 0;
	// принятие
	virtual void Acceptance() = 0;
	// Записывает последовательность выбора пользователя
	virtual void Recording_Selection() = 0;
	// здоровье
	int Health = 100;

	// возвращает сроку в векторе
	virtual std::string Heal(int val) = 0;
	// Содержит изображение персонажа
	std::vector<std::string> Original_Of_The_Image;
	// ищет файл персонажа и копирует вектор для вывода
	virtual std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) = 0;

};



struct Tank :Object_The_Game {

	// щит
	void Shield() override {
		Recording_A_Selection.push_back(std::string("Shield"));
	}
	// атака
	void Attack() override {
		Recording_A_Selection.push_back(std::string("Attack"));
	}
	// урон
	int Attack_Damgae() override {
		return 15;
	}
	// принятие
	void Acceptance() override {
		Recording_A_Selection.push_back(std::string("Acceptance"));
	}
	// возвращает сроку в векторе
	std::string Heal(int val) override {
		
		return boost::any_cast<std::string>(Recording_A_Selection[val]);
	}
	// персонаж делает выбор
	void Recording_Selection()override {

		if (this->Recording_A_Selection.size() != 0)
			for (int i = Recording_A_Selection.size(); i > 0; i--)
				Recording_A_Selection.pop_back();


		cout << "Choose an action:\n"
			<< "1)Shield\n"
			<< "2)Attack\n"
			<< "3)Acceptance\n"
			"User's Choice: ";

		int p = 0;
		int value;
		while (p++ < 3 && cin >> value)
			switch (value) {
			case 1:
				Shield();
				break;
			case 2:
				Attack();
				break;
			case 3:
				Acceptance();
				break;
			default:
				Acceptance();
				break;
			}
		system("cls");
	}
	// ищет файл персонажа и копирует вектор для вывода
	std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) override{
		// открывает файл
		std::ifstream Opening_A_File(Name_Object, std::ios::binary | std::ios::in);
		// куда будет копировать файл
		std::string Copy_Of_The_Image;
		// перемещаем копированный файл
		std::vector<std::string> Original_Of_The_Image;

		if (Opening_A_File.is_open()) {
			for (; std::getline(Opening_A_File, Copy_Of_The_Image, '\r');) {

				Preparing_A_Line(Copy_Of_The_Image);
				Original_Of_The_Image.push_back(Copy_Of_The_Image);

			}
			Opening_A_File.close();
			return Original_Of_The_Image;
		}

		// ????????
	//	else return;

	}


private:
	
	std::vector<boost::any>Recording_A_Selection;

	// редактирует строку убирая ненужные символы
	void Preparing_A_Line(std::string& Name_Object) {
		for (int i = 0; i < Name_Object.size(); i++)
			if (Name_Object[i] == '\n')Name_Object[i] = ' ';
	}

};



// вывод информации всей игры
extern bool Game_Information_Output();

// Вывод Информации Жизней
extern void Inside_Information_Life(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot);
// Вывод Информации игрока
extern void Player_Information_Output(const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One);
// Вывод логики игры
extern void Game_Logic_Output(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot,
	const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One);


