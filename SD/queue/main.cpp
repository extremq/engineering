/*
EXAMPLE IMPUT
18
2 2
3 2
3 4
3 5
3 6
3 7
5 3
5 5
5 7
6 5
7 7
7 8
7 2
8 3
6 4
4 5
6 7
8 7
*/

#include <iostream>
#include "queue.h"
#include <Windows.h>

#define WALL_VAL    -1
#define EMPTY_VAL    0
#define VISITED_VAL  1
#define CURRENT_VAL  2
#define QUEUED_VAL   3

constexpr char WALL	   = 219;
constexpr char VISITED = 178;
constexpr char CURRENT = 177;
constexpr char QUEUED  = 176;
constexpr char EMPTY   = ' ';

struct Position {
	int x, y;
};

void print_matrix(int matrix[][10]) {
	for (int i = -1; i < 10; ++i) {
		for (int j = -1; j < 10; ++j) {
			if (i == -1 && j == -1)
				std::cout << ' ';
			else if (i == -1) 
				std::cout << j;
			else if (j == -1) 
				std::cout << i;
			else {
				switch (matrix[i][j]) {
				case WALL_VAL:
					std::cout << WALL;
					break;
				case EMPTY_VAL:
					std::cout << EMPTY;
					break;
				case VISITED_VAL:
					std::cout << VISITED;
					break;
				case CURRENT_VAL:
					std::cout << CURRENT;
					break;
				case QUEUED_VAL:
					std::cout << QUEUED;
					break;
				}
			}
		}
		std::cout << '\n';
	}
}

int main()
{
	int matrix[10][10] = {0};

	for (int i = 0; i < 10; ++i) {
		matrix[i][0] = matrix[0][i] = matrix[9][i] = matrix[i][9] = WALL_VAL;
	}
	
	print_matrix(matrix);
	int wall_n;
	std::cout << "How many walls do you want to add?\n";
	std::cin >> wall_n;

	while (wall_n--) {
		system("cls");
		print_matrix(matrix);
		
		Position wall;
		std::cout << "Choose x and y (both between 1 and 8)\n";
		std::cin >> wall.x >> wall.y;

		matrix[wall.x][wall.y] = WALL_VAL;
	}
	system("cls");
	print_matrix(matrix);
	
	Queue<Position> q;
	Position start = { 1, 1 };

	q.push(start);
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};

	while (!q.empty()) {
		Position current = q.pop();
		matrix[current.x][current.y] = CURRENT_VAL;

		for (int d = 0; d < 4; ++d) {
			int new_x = current.x + dx[d];
			int new_y = current.y + dy[d];
			int current_matrix_val = matrix[new_x][new_y];
			if (current_matrix_val == WALL_VAL || current_matrix_val == VISITED_VAL || current_matrix_val == QUEUED_VAL)
				continue;

			Position new_pos = { new_x, new_y };
			matrix[new_x][new_y] = QUEUED_VAL;
			
			system("cls");
			print_matrix(matrix);
			Sleep(100);
			q.push(new_pos);
		}

		matrix[current.x][current.y] = VISITED_VAL;
		system("cls");
		print_matrix(matrix);
		Sleep(100);
	}

	std::cout << "FINISHED!!!";

	/*
	Queue<int> shobi;
	
	int n, x;
	while (1) {
		std::string op;
		std::cin >> op;
		if (op == "push") {
			std::cin >> x;
			shobi.push(x);
		}
		else if (op == "pop") {
			std::cout << shobi.pop() << '\n';
		}
		else if (op == "front") {
			std::cout << shobi.front() << '\n';
		}
		else if (op == "back") {
			std::cout << shobi.back() << '\n';
		}
		else if (op == "size") {
			std::cout << shobi.size() << '\n';
		}
		else if (op == "stop") {
			return 0;
		}
	}
	*/
}
