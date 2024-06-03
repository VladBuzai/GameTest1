#pragma once
#include <iostream>
#include <vector>

// открывает файл и копирует изображение в vector
extern std::vector<std::string> Loading_The_Menu_Image();
// получает вектор через unique_ptr и выводит изображение
extern void Loading_The_Menu();