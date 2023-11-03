#include <iostream>
#include <string>

std::string compressText(const std::string& text);

int main()
{
	setlocale(LC_ALL, "rus");
	std::string inputText;
	std::cout << "Введите строку текста: ";
	std::getline(std::cin, inputText);

	std::string compressed = compressText(inputText);
	std::cout << "Сжатый текст: " << compressed << std::endl;

	return 0;	
}

std::string compressText(const std::string& text)
{
	std::string compressedText = text;

	// нахожу первый "непробельный символ"
	size_t firstNotSpase = compressedText.find_first_not_of(" ");
	if (firstNotSpase != std::string::npos)
	{
		compressedText = compressedText.substr(firstNotSpase); // создание строки без начальных пробелов
	}

	// удаление пробелов между словами
	for (size_t i = 1; i < compressedText.size(); i++)
	{
		if (compressedText.at(i) == ' ' && compressedText.at(i - 1) == ' ')
		{
			compressedText.erase(i, 1); // если 2 пробела подряд, то удаляю первый
				i--;
		}
	}

	// нахожу последний "непробельный символ" и удаляю пробелы в конце
	size_t lastNotSpase = compressedText.find_last_not_of(" ");
	if (lastNotSpase != std::string::npos)
	{
		compressedText.resize(lastNotSpase + 1);
	}
	return compressedText;
}
