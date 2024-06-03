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

// ������ ������� ����������
struct Object_The_Game {
	// ���
	virtual void Shield() = 0;
	// �����
	virtual void Attack() = 0;
	// ����
	virtual int Attack_Damgae() = 0;
	// ��������
	virtual void Acceptance() = 0;
	// ���������� ������������������ ������ ������������
	virtual void Recording_Selection() = 0;
	// ��������
	int Health = 100;

	// ���������� ����� � �������
	virtual std::string Heal(int val) = 0;
	// �������� ����������� ���������
	std::vector<std::string> Original_Of_The_Image;
	// ���� ���� ��������� � �������� ������ ��� ������
	virtual std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) = 0;

};



struct Tank :Object_The_Game {

	// ���
	void Shield() override {
		Recording_A_Selection.push_back(std::string("Shield"));
	}
	// �����
	void Attack() override {
		Recording_A_Selection.push_back(std::string("Attack"));
	}
	// ����
	int Attack_Damgae() override {
		return 15;
	}
	// ��������
	void Acceptance() override {
		Recording_A_Selection.push_back(std::string("Acceptance"));
	}
	// ���������� ����� � �������
	std::string Heal(int val) override {
		
		return boost::any_cast<std::string>(Recording_A_Selection[val]);
	}
	// �������� ������ �����
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
	// ���� ���� ��������� � �������� ������ ��� ������
	std::vector<std::string> Loading_The_Game_Image(std::string Name_Object) override{
		// ��������� ����
		std::ifstream Opening_A_File(Name_Object, std::ios::binary | std::ios::in);
		// ���� ����� ���������� ����
		std::string Copy_Of_The_Image;
		// ���������� ������������ ����
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

	// ����������� ������ ������ �������� �������
	void Preparing_A_Line(std::string& Name_Object) {
		for (int i = 0; i < Name_Object.size(); i++)
			if (Name_Object[i] == '\n')Name_Object[i] = ' ';
	}

};



// ����� ���������� ���� ����
extern bool Game_Information_Output();

// ����� ���������� ������
extern void Inside_Information_Life(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot);
// ����� ���������� ������
extern void Player_Information_Output(const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One);
// ����� ������ ����
extern void Game_Logic_Output(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot,
	const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One);


