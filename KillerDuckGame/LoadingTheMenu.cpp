#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "LoadingTheMenu.h"
#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;

std::vector<std::string> Loading_The_Menu_Image() {

	// открывает файл
	std::ifstream Opening_A_File("LoadingMenu", std::ios::binary | std::ios::in);
	// куда будет копировать файл
	std::string Copy_Of_The_Image;
	// перемещаем копированный файл
	std::vector<std::string> Original_Of_The_Image;
	if (Opening_A_File.is_open()) {
		for (int i = 0; std::getline(Opening_A_File, Copy_Of_The_Image); i++)
			Original_Of_The_Image.push_back(Copy_Of_The_Image);

		Opening_A_File.close();
		return Original_Of_The_Image;
	}
	else {
		std::string ec = "LoadingMenu";
		throw ec;
	}

};

void Loading_The_Menu() {


	std::unique_ptr<std::vector<std::string>> Original_Of_The_Image = std::make_unique<std::vector<std::string>>(Loading_The_Menu_Image());

	int Download_Percentage = 0;
	while (Download_Percentage != 100) {

		cout << "\t\t\t\tLoading: ";


		if (Download_Percentage >= 10)
			for (int i = 10; i <= Download_Percentage; i += 10)cout << '#';
		if (Download_Percentage != 100)
			for (int i = Download_Percentage; i < 100; i += 10)cout << '_';

		cout << (Download_Percentage += 2) << '%' << endl;

		for (auto i : *Original_Of_The_Image)cout << i << endl;





		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		system("cls");
	}

};




