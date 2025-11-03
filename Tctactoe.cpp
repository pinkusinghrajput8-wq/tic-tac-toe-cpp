
#include <iostream>
#include <string>
using namespace std;

// ✅ Corrected: changed int → char
char space[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

int row, column;
char token = 'X';
bool tie = false;
string n1, n2;

void functionOne() {
    cout << "\n      |     |     \n";
    cout << "   " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "\n";
    cout << " _____|_____|_____\n";
    cout << "      |     |     \n";
    cout << "   " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "\n";
    cout << " _____|_____|_____\n";
    cout << "      |     |     \n";
    cout << "   " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "\n";
    cout << "      |     |     \n\n";
}

void functionTwo() {
    int digit;

    // ✅ Clear prompts
    if (token == 'X') {
        cout << n1 << ", please enter your move (1-9): ";
        cin >> digit;
    } else {
        cout << n2 << ", please enter your move (1-9): ";
        cin >> digit;
    }

    // ✅ Validate input properly
    if (digit < 1 || digit > 9) {
        cout << "Invalid Move !!!\n";
        functionTwo();
        return;
    }

    // ✅ Simplified calculation
    row = (digit - 1) / 3;
    column = (digit - 1) % 3;

    // ✅ Use 'O' instead of '0'
    if (space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "Cell already taken! Try again.\n";
        functionTwo();
    }

    functionOne();
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
            return true;
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
        return true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O')
                return false;
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of Player 1: ";
    getline(cin, n1);
    cout << "Enter the name of Player 2: ";
    getline(cin, n2);

    cout << "\n" << n1 << " is Player 1 (X)\n";
    cout << n2 << " is Player 2 (O)\n";

    cout << "\nHere is the Tic Tac Toe board:\n";
    functionOne();

    // ✅ Removed duplicate functionThree() call
    while (!functionThree()) {
        functionTwo();
    }

    if (tie == false && token == 'O') {
        cout << n1 << " wins !!! 🎉\n";
    } else if (tie == false && token == 'X') {
        cout << n2 << " wins !!! 🎉\n";
    } else {
        cout << "It's a tie !!! 🤝\n";
    }

    return 0;
}
