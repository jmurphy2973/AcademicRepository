#include<iostream>
#include<string>
#include"utilities.hpp"

using namespace std;

int get_int(int min, string userprompt)
{
	int returnval;

	cout << userprompt;
	cin >> returnval;

	while (cin.fail())
	{
		cout << "Error. You must enter an integer value: " << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> returnval;
	}
	return returnval;
}

void clearScreen()
{
//	cout << string(100, '\n');
	cout << "\033[2J\033[1;1H" << endl;
}

int optionsMenu(int numitems, std::string *menuData)
{
	int selection;
	
	int cnt = 0;
	while (cnt < numitems)
	{
		cout << cnt + 1 << ". " << menuData[cnt] << endl;
		cnt++;
	}
 selection = get_int(1, "\nPlease enter your selection: ");
	selection = checkMenuInput(selection, numitems);

	return selection;
}

int checkArrayElement(int coord, int sizeArray)
{
	while (coord < 0 || coord > sizeArray - 1)
	{
		cout << "Your input is invalid. Please value between 0 and " << sizeArray - 1 << ". " << endl;
		coord = get_int(1, "\nPlease re-enter value: ");
	}
	return coord;
}

int checkMenuInput(int input, int sizeArray)
{
	while (input < 1 || input > sizeArray)
	{
		cout << "Your input is invalid. Please value between 1 and " << sizeArray << ". " << endl;
		input = get_int(1, "\nPlease re-enter value: ");
	}
	return input;
}
