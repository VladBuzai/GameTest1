#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <boost/any.hpp>

using std::cout;
using std::endl;



// обьект классов ботов
struct Object_The_Game_Bot {
	// щит
	virtual void Shield() = 0;
	// атака
	virtual void Attack() = 0;
	// урон
	virtual int Attack_Damgae() = 0;
	// принятие
	virtual void Acceptance() = 0;
	// возвращает сроку в векторе
	virtual std::string Heal(int val) = 0;
	int Health = 100;

		// Bot
	// Сравнивание строк Bot
	virtual std::string BotStrings(int i) = 0;
	// Возращает тип для записи Bot
	virtual std::vector<boost::any>& BotVecAny() = 0;
	// Создает рандом для механики
	virtual bool BothRandom(std::vector<boost::any>& Botobj, std::string e) = 0;
	// Механика выбора приемов робота
	virtual void MechanikBot() = 0;

	// Содержит изображение персонажа
	std::vector<std::string> Original_Of_The_Image;
	// ищет файл персонажа и копирует вектор для вывода
	virtual std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) = 0;
	//удаляет данные векторе
	virtual void Del_Vect() = 0;
};

struct Truc :Object_The_Game_Bot {

	// щит
	void Shield() override {
		Recording_A_Selection.push_back(std::string("Shield"));
	}
	// атака
	void Attack() override {
		Recording_A_Selection.push_back(std::string("Attack"));
	}
	// атака
	int Attack_Damgae() override {
		return 20;
	}
	// принятие
	void Acceptance() override {
		Recording_A_Selection.push_back(std::string("Acceptance"));
	}
	// Сравнивание строк Bot
	std::string BotStrings(int i) override {
		switch (i) {
		case 0:
			return "Shield";
			break;
		case 1:
			return "Attack";
			break;
		case 2:
			return "Acceptance";
			break;
		default:
			return "Acceptance";
			break;
		}
	}
	// Возращает тип для записи Bot
	std::vector<boost::any>& BotVecAny() override {
		return Recording_A_Selection;
	}
	// Создает рандом
	bool BothRandom(std::vector<boost::any>& Botobj, std::string e) {

		bool k = true;
		if (Botobj.size() == 0)return true;
		else for (int i = 0; i < Botobj.size(); i++)
			if (boost::any_cast<std::string>(Botobj[i]) == e) {
				return false;
			}

		return true;
	};
	// Механика выбора приемов робота
	void MechanikBot() {

		if (this->Recording_A_Selection.size() != 0)
			for (int i = Recording_A_Selection.size(); i > 0; i--)
				Recording_A_Selection.pop_back();


//		cout << "Bots" << endl;
		for (int i = 0; i < 3; i++) {
			int ValuVariant = 0;

			while (true) {

				srand(unsigned(time(0)));
				std::this_thread::sleep_for(std::chrono::milliseconds(340));

				ValuVariant = rand() % 3;
				if (BothRandom(this->BotVecAny(), this->BotStrings(ValuVariant))) {
					switch (ValuVariant) {
					case 0:
						this->Shield();
						break;
					case 1:
						this->Attack(); break;
					case 2:
						this->Acceptance(); break;
					default:this->Acceptance(); break;
					}
					break;
				}
			}
//			cout << this->BotStrings(i) << endl;
		};
	}
	// возвращает сроку в векторе
	std::string Heal(int val) override {

		return boost::any_cast<std::string>(Recording_A_Selection[val]);
	}
	// ищет файл персонажа и копирует вектор для вывода
	std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) override {
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
		else {
			throw Name_Object;
		}

	}
	// удаляет данные векторе
	void Del_Vect() {
		for (int i = Original_Of_The_Image.size(); i > 0; i--)
			Original_Of_The_Image.pop_back();
	}


private:
	std::vector<boost::any>Recording_A_Selection;
	// редактирует строку убирая ненужные символы
	void Preparing_A_Line(std::string& Name_Object) {
		for (int i = 0; i < Name_Object.size(); i++)
			if (Name_Object[i] == '\n')Name_Object[i] = ' ';
	}

};

struct Little_Girl :Object_The_Game_Bot {
	
	// щит
	void Shield() override {
		Recording_A_Selection.push_back(std::string("Shield"));
	}
	// атака
	void Attack() override {
		Recording_A_Selection.push_back(std::string("Attack"));
	}
	// атака
	int Attack_Damgae() override {
		return 20;
	}
	// принятие
	void Acceptance() override {
		Recording_A_Selection.push_back(std::string("Acceptance"));
	}
	// Сравнивание строк Bot
	std::string BotStrings(int i) override {
		switch (i) {
		case 0:
			return "Shield";
			break;
		case 1:
			return "Attack";
			break;
		case 2:
			return "Acceptance";
			break;
		default:
			return "Acceptance";
			break;
		}
	}
	// Возращает тип для записи Bot
	std::vector<boost::any>& BotVecAny() override {
		return Recording_A_Selection;
	}
	// Создает рандом
	bool BothRandom(std::vector<boost::any>& Botobj, std::string e) {

		bool k = true;
		if (Botobj.size() == 0)return true;
		else for (int i = 0; i < Botobj.size(); i++)
			if (boost::any_cast<std::string>(Botobj[i]) == e) {
				return false;
			}

		return true;
	};
	// Механика выбора приемов робота
	void MechanikBot() {

		if (this->Recording_A_Selection.size() != 0)
			for (int i = Recording_A_Selection.size(); i > 0; i--)
				Recording_A_Selection.pop_back();


		//		cout << "Bots" << endl;
		for (int i = 0; i < 3; i++) {
			int ValuVariant = 0;

			while (true) {

				srand(unsigned(time(0)));
				std::this_thread::sleep_for(std::chrono::milliseconds(340));

				ValuVariant = rand() % 3;
				if (BothRandom(this->BotVecAny(), this->BotStrings(ValuVariant))) {
					switch (ValuVariant) {
					case 0:
						this->Shield();
						break;
					case 1:
						this->Attack(); break;
					case 2:
						this->Acceptance(); break;
					default:this->Acceptance(); break;
					}
					break;
				}
			}
			//			cout << this->BotStrings(i) << endl;
		};
	}
	// возвращает сроку в векторе
	std::string Heal(int val) override {

		return boost::any_cast<std::string>(Recording_A_Selection[val]);
	}
	// ищет файл персонажа и копирует вектор для вывода
	std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) override {
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
		else {
			throw Name_Object;
		}

	}
	// удаляет данные векторе
	void Del_Vect() {
		for (int i = Original_Of_The_Image.size(); i > 0; i--)
			Original_Of_The_Image.pop_back();
	}


private:
	std::vector<boost::any>Recording_A_Selection;
	// редактирует строку убирая ненужные символы
	void Preparing_A_Line(std::string& Name_Object) {
		for (int i = 0; i < Name_Object.size(); i++)
			if (Name_Object[i] == '\n')Name_Object[i] = ' ';
	}

};