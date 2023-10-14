#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	vector<string> dictionary = { "HANDMAN", "BICYCLE", "HOUSE" };
	const string HIDDEN_WORD = dictionary[rand() % dictionary.size()];
	const int MAX_WRONG = (26 - HIDDEN_WORD.size()) / 3;
	string wrongLetters;

	cout << "\tWelcomde to HandMan Game!\n\n";
	cout << "Your word contains " << HIDDEN_WORD.length() << " letters.\n";
	cout << "You have " << MAX_WRONG << " attempts\n";

	string answer;
	for (auto i = HIDDEN_WORD.begin(); i != HIDDEN_WORD.end(); ++i) answer.push_back('-');

	cout << "\n\t" << answer;

	while ((wrongLetters.length() < MAX_WRONG) && (answer != HIDDEN_WORD))
	{
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess);
		while ((find(wrongLetters.begin(), wrongLetters.end(), guess) != wrongLetters.end()) || (find(answer.begin(), answer.end(), guess) != answer.end()))
		{
			cout << "This letter was already there, enter a new one: ";
			cin >> guess;
			guess = toupper(guess);
		}
		int f = 0;
		for (int i = 0; i < HIDDEN_WORD.size(); i++)
		{
			if (guess == HIDDEN_WORD[i])
			{
				answer[i] = guess;
				f++;
			}
		}
		if (f == 0)
		{
			cout << "\n\nIt's wrong!\n";
			wrongLetters.push_back(guess);
		}
		else
		{
			cout << "\n\nYou guessed " << f << " letters!\n";
		}
		cout << "Wrong letters: " << wrongLetters << "\n";
		cout << "You have " << MAX_WRONG - wrongLetters.size() << " attempts left!\n\n";
		cout << "\t" << answer;
	}

	if (wrongLetters.length() == MAX_WRONG)
	{
		cout << "\n\n\t\tGame Over!!!";
		cout << "\n\t\t\tThe correct answer is " << HIDDEN_WORD << "\n\n";
	}
	else cout << "\n\n\t\t You Won!!!\n\n";
	return 0;
}