#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

void playBeep(const string& sound)
{
    if (sound == "invalid")
    {
        MessageBeep(MB_ICONHAND); 
    }
    else if (sound == "success")
    {
        MessageBeep(MB_ICONASTERISK); 
    }
}

void game(int num, int chances)
{
    system("CLS");
    srand(time(0));
    int num_to_find = 1 + (rand() % num);
    int user_choice;

    for (int i = 1; i <= chances; i++)
    {
        cout << "\033[38;5;75m\nEnter your guess: \033[0m";
        cin >> user_choice;

        while (cin.fail() || user_choice > num)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[38;5;167m\nInvalid input! Please enter a valid number: \033[0m";
            playBeep("invalid");
            cin >> user_choice;
        }

        if (user_choice > num_to_find)
        {
            cout << "\033[38;5;167m\nToo high! Try a smaller number.\033[0m" << endl;
            cout << "\033[38;5;142m" << chances - i << " attempts remaining.\033[0m" << endl;
        }
        else if (user_choice < num_to_find)
        {
            cout << "\033[38;5;167m\nToo low! Try a bigger number.\033[0m" << endl;
            cout << "\033[38;5;142m" << chances - i << " attempts remaining.\033[0m" << endl;
        }
        else
        {
            cout << "\033[38;5;120m\nCongratulations! You've guessed the number!\033[0m" << endl;
            cout << "\033[38;5;114mPlay again? (y/n): \033[0m";
            playBeep("success");
            char yn;
            cin >> yn;
            if (yn == 'y')
            {
                return;
            }
            else if (yn == 'n')
            {
                cout << "\033[38;5;120m\nThank you for playing! Goodbye!\033[0m";
                exit(0);
            }
            else
            {
                cout << "\033[38;5;167m\nInvalid choice! Please enter 'y' or 'n': \033[0m";
                cin >> yn;
                if (yn == 'y')
                {
                    return;
                }
                else
                {
                    cout << "\033[38;5;120m\nThank you for playing! Goodbye!\033[0m";
                    exit(0);
                }
            }
        }
    }

    cout << "\033[38;5;167m\nOut of attempts! You lost the game.\033[0m" << endl;
    cout << "\033[38;5;142m\nThe secret number was " << num_to_find << ".\033[0m" << endl;
    cout << "\033[38;5;114mPlay again? (y/n): \033[0m";
    char yn;
    cin >> yn;

    if (yn == 'y')
    {
        return;
    }
    else
    {
        cout << "\033[38;5;120m\nThank you for playing! Goodbye!\033[0m";
        exit(0);
    }
}

void printWelcomeMessage()
{
    cout << "\033[38;5;135m";
    cout << "\n\t\t**********************************************************";
    cout << "\n\t\t*                                                        *";
    cout << "\n\t\t*                Welcome to the Number Game!             *";
    cout << "\n\t\t*                                                        *";
    cout << "\n\t\t*         Guess the secret number to win the game!       *";
    cout << "\n\t\t*                                                        *";
    cout << "\n\t\t**********************************************************";
    cout << "\033[0m\n";
}

void loadingAnimation()
{
    cout << "\033[38;5;142m\nLoading";
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 100000000; j++)
        {
            // Delay loop
        }
        cout << ".";
        cout.flush();
    }
    cout << "\033[0m\n";
}

int main()
{
    system("CLS");
    printWelcomeMessage();

    cout << "\033[38;5;75m\nPress Enter to start...\033[0m" << endl;
    cin.get();

    int diff_level;

    while (true)
    {
        system("CLS");

        cout << "\033[38;5;114m\nChoose a difficulty level:\033[0m" << endl;
        cout << "\033[38;5;114m1 - Easy (1 to 20)\033[0m" << endl;
        cout << "\033[38;5;114m2 - Medium (1 to 50)\033[0m" << endl;
        cout << "\033[38;5;114m3 - Hard (1 to 80)\033[0m" << endl;
        cout << "\033[38;5;114mYour choice: \033[0m";
        cin >> diff_level;

        while (cin.fail() || diff_level < 1 || diff_level > 3)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[38;5;167m\nInvalid input! Please enter a valid option (1-3): \033[0m";
            playBeep("invalid");
            cin >> diff_level;
        }

        switch (diff_level)
        {
        case 1:
            cout << "\033[38;5;120m\nEasy difficulty selected. Guess the number between 1 to 20. You have 10 attempts. Good luck!\033[0m" << endl;
            loadingAnimation();
            game(20, 10);
            break;
        case 2:
            cout << "\033[38;5;120m\nMedium difficulty selected. Guess the number between 1 to 50. You have 8 attempts. Good luck!\033[0m" << endl;
            loadingAnimation();
            game(50, 8);
            break;
        case 3:
            cout << "\033[38;5;120m\nHard difficulty selected. Guess the number between 1 to 80. You have 5 attempts. Good luck!\033[0m" << endl;
            loadingAnimation();
            game(80, 5);
            break;
        }
    }

    return 0;
}

