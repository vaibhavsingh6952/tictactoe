#include <iostream>
using namespace std;

char player;
static char board[3][3] = { {'-', '-', '-'},
                            {'-', '-', '-'},
                            {'-', '-', '-'}};

void print_board() {
    cout << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << endl;
    cout << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << endl;
    cout << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << endl;
}

bool check_winner() {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')) { 
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')) { 
        return true;
    }
    return false;
}

bool is_draw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') return false;
        }
    }
    return true;
}

void move() {
    int i, j;
    cout << "Enter the position (row and column) in ordered pair: ";
    cin >> i >> j;

    int p = i - 1, q = j - 1;

    if (board[p][q] == 'x' || board[p][q] == 'o') {
        cout << "Invalid move, try again.\n";
    } else {
        board[p][q] = player;
        // Switch the player after a valid move
        player = (player == 'x') ? 'o' : 'x';
    }
}

void main_loop() {
    cout << "Choose x or o to start: ";
    cin >> player;

    if (player != 'x' && player != 'o') {
        cout << "Invalid player, defaulting to 'x'\n";
        player = 'x';
    }

    while (true) {
        print_board();
        move();

        if (check_winner()) {
            player = (player == 'x') ? 'o' : 'x';
            cout << player << " won the game!\n";
            print_board();
            break;
        } else if (is_draw()) {
            cout << "It's a draw!\n";
            print_board();
            break;
        }
    }
}

int main() {
    main_loop();
    return 0;
}
