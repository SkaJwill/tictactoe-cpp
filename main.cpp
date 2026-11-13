#include <iostream>
#include <array>

using Board = std::array<char, 9>;

const int WINS[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

void printBoard(const Board& board) {
    for (int row = 0; row < 3; ++row) {
        std::cout << ' ';
        for (int col = 0; col < 3; ++col) {
            char cell = board[row * 3 + col];
            std::cout << (cell == ' ' ? '0' + row * 3 + col + 1 : cell);
            if (col < 2) std::cout << " | ";
        }
        std::cout << '\n';
        if (row < 2) std::cout << "---+---+---\n";
    }
}

char winnerOf(const Board& board) {
    for (const auto& w : WINS) {
        if (board[w[0]] != ' ' && board[w[0]] == board[w[1]] && board[w[1]] == board[w[2]]) {
            return board[w[0]];
        }
    }
    return ' ';
}

bool place(Board& board, int cell, char mark) {
    if (cell < 1 || cell > 9 || board[cell - 1] != ' ') {
        return false;
    }
    board[cell - 1] = mark;
    return true;
}

int main() {
    Board board{};
    board.fill(' ');
    char player = 'X';
    int moves = 0;

    std::cout << "Tic-Tac-Toe - two players, cells 1..9\n\n";

    while (true) {
        printBoard(board);
        std::cout << "\nPlayer " << player << ", pick a cell: ";

        int cell;
        if (!(std::cin >> cell)) {
            std::cout << "Invalid input, exiting.\n";
            return 1;
        }

        if (!place(board, cell, player)) {
            std::cout << "Cell is taken or out of range. Try again.\n\n";
            continue;
        }

        ++moves;
        if (char winner = winnerOf(board); winner != ' ') {
            std::cout << '\n';
            printBoard(board);
            std::cout << "\nPlayer " << winner << " wins!\n";
            return 0;
        }
        if (moves == 9) {
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
        std::cout << '\n';
    }
    return 0;
}
