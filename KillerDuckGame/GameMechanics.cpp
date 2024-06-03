#include <vector>
#include <chrono>
#include <thread>
#include "GameMechanics.h"
#include <iostream>
#include <memory>


bool Game_Information_Output() {

	int level = 0;
	
	cout << "Your ready? :";
	char ch;
	cin >> ch;
	system("cls");

	// Создание обьекта персонажа
	std::unique_ptr<Object_The_Game>Object_Player = std::make_unique<Tank>();

	while (ch != 'q') {


		// bot
		std::unique_ptr<Object_The_Game_Bot>ObjBot;
		if (level == 0) {
			ObjBot = std::make_unique<Truc>();

			ObjBot->Del_Vect();
			ObjBot->Original_Of_The_Image = ObjBot->Loading_The_Game_Image("Truc");

		}
		else if (level == 1) {
			ObjBot = std::make_unique<Little_Girl>();

			ObjBot->Del_Vect();
			ObjBot->Original_Of_The_Image = ObjBot->Loading_The_Game_Image("LittleGirl");

		}
		else break;

		Object_Player->Health = 100;
		cout << "Heatpoin Players: " << Object_Player->Health << "\t\t";



		if (Object_Player->Original_Of_The_Image.size() > 0);
		else Object_Player->Original_Of_The_Image = Object_Player->Loading_The_Game_Image("Tank");

		
		cout << "Heatpoin Bots: " << ObjBot->Health << endl << endl;

		// выводит информацию о бойцах
		Player_Information_Output(Object_Player->Original_Of_The_Image, ObjBot->Original_Of_The_Image);
		cout << endl;
;
		while (Object_Player->Health > 0 && ObjBot->Health > 0) {
			Game_Logic_Output(*Object_Player, *ObjBot,
				Object_Player->Original_Of_The_Image, ObjBot->Original_Of_The_Image);
		}
		if (Object_Player->Health > 0)level++;

		if (Object_Player->Health > 0 && ObjBot->Health <= 0)std::cout << "\t\tYourWins\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		system("cls");
		if (level < 2) {
			cout << "Your ready y - yes q - exit: ";
			cin >> ch;
		}

	}
	

	return false;
	
}

void Game_Logic_Output(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot,
	const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One)
{

	std::thread ThBot([&]() {
		ObjBot.MechanikBot();
		});
	
	ObjPlayer.Recording_Selection();

	ThBot.join();

	system("cls");

	for (int i = 0; i < 3; i++) {
		cout << "\t\t";
		if (ObjPlayer.Heal(i) == "Shield") {
			if (ObjBot.Heal(i) == "Shield")
				cout << "PLayer and Bots Shield\n";
			else if (ObjBot.Heal(i) == "Attack")
				cout << "PLayer Shield and Bots Attack\n";
			else if(ObjBot.Heal(i) == "Acceptance")
				cout << "PLayer Shield and Bots Acceptance\n";
		}
		else if (ObjPlayer.Heal(i) == "Attack") {
			if (ObjBot.Heal(i) == "Shield")
				cout << "PLayer Attack and Bots Shield\n";
			else if (ObjBot.Heal(i) == "Attack") {
				cout << "PLayer and Bots Attack\n";
				ObjPlayer.Health -= ObjBot.Attack_Damgae();
				ObjBot.Health -= ObjPlayer.Attack_Damgae();
			}
			else if (ObjBot.Heal(i) == "Acceptance") {
				cout << "PLayer Attack and Bots Acceptance\n";
				ObjBot.Health -= ObjPlayer.Attack_Damgae();
			}
		}
		else if (ObjPlayer.Heal(i) == "Acceptance") {
			if (ObjBot.Heal(i) == "Shield")
				cout << "PLayer Acceptance and Bots Shield\n";
			else if (ObjBot.Heal(i) == "Attack") {
				cout << "PLayer Acceptance and Bots Attack\n";
				ObjPlayer.Health -= ObjBot.Attack_Damgae();
			}
			else if (ObjBot.Heal(i) == "Acceptance") 
				cout << "PLayer and Bots Acceptance\n";
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	Inside_Information_Life(ObjPlayer, ObjBot);
	Player_Information_Output(Original_Of_The_Image, Original_Of_The_Image_One);
};

void Inside_Information_Life(Object_The_Game& ObjPlayer, Object_The_Game_Bot& ObjBot) {
	cout << "Heatpoin Players: " << ObjPlayer.Health << "\t\t";
	cout << "Heatpoin Bots: " << ObjBot.Health << endl << endl;

}


void Player_Information_Output(const std::vector<std::string>& Original_Of_The_Image, const std::vector<std::string>& Original_Of_The_Image_One) {
	// выводит информацию о бойцах
	for (int i = 0, j = 0; i < Original_Of_The_Image.size() || j < Original_Of_The_Image_One.size();) {

		if (i < Original_Of_The_Image.size())
			cout << Original_Of_The_Image[i++];
		if (j < Original_Of_The_Image_One.size())
			cout << Original_Of_The_Image_One[j++];
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout << '\n';
	}
	cout << endl;
}