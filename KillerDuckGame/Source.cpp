#include "LoadingTheMenu.h"
#include "GameMechanics.h"


int main() {

	try {
		// Загрузка меню
		Loading_The_Menu();
		// игровойй движок XD
		Game_Information_Output();

		std::cout << "****Your win*****\n";
	}
	catch (std::string& e) {
		std::cout << "Sorry not opens a file: " << e;
	}
	catch (...) {
		std::cout << "Sorry error\n";
	}


	return 0;
}

