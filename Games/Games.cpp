#include <iostream>
//////////////
//Задание 1 //
//////////////
/*
 Дана шахматная доска размером 8×8 и шахматный конь.
Программа должна запросить у пользователя
координаты клетки поля и поставить туда коня. Задача
программы найти и вывести путь коня, при котором он
обойдет все клетки доски, становясь в каждую клетку
только один раз. (Так как процесс отыскания пути для
разных начальных клеток может затянуться, то реко-
мендуется сначала опробовать задачу на поле размером
6×6). В программе необходимо использовать рекурсию.
*/

//Шаги коня
int step[8][2] = { {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2} };

//Количество ходов
int n;

//Шахматноя доска
#define DS 6
int desk[8][8];

//Функция которая будет печатать доску по первому требованию
void print_desk() {
	// printf("n = %d \n", n);
	for (int i = 0; i < DS; i++)
	{
		for (int j = 0; j < DS; j++)
			printf(" %2d", desk[i][j]);
		printf(" \n");
	}
}
//Функция рекурсия обхода доски
bool set_horse(int x, int y)
{
	//проверка параметров
	if ((x < 0) || (x >= DS) || (y < 0) || (y >= DS))
		return false;

	//проверка если конь уже стоял на этой клетке
	if (desk[x][y] != 0)
		return false;

	//стоп игра
	if (n == DS * DS)
		return true;

	//следущий ход
	n++;
	desk[x][y] = n;

	//стоп игра
	if (n == DS * DS)
		return true;

	//раскометирую для проверки хода конем !!
	/*printf("n = %d \n",n);
	print_desk();
	system("pause");*/

	for (int i = 0; i < 8; i++)
		if (set_horse(x + step[i][0], y + step[i][1]))
			return true;
	//откатываем ход назад , очищаем клетку
	n--;
	desk[x][y] = 0;
	return false;
}

int main()
{

	n = 0;
	for (int i = 0; i < DS; i++)
		for (int j = 0; j < DS; j++)
			desk[i][j] = 0;
	//начальные координаты коня (с координатами [0,0]  программа посчитает быстро,
		//                           с другими координатами уже дольше ,гораздо дольше)
	set_horse(1, 1);

	print_desk();
}
/////////////
//Задание 2//
/////////////
/*
Написать игру «Пятнашки».
*/


//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <iomanip>
//#include <conio.h>
//
//using std::vector;
//using std::cout;
//
//const unsigned short SIZE = 4; // размер игрового поля
//
//vector<int> in_game_map(SIZE);
//vector<vector<int>> game_map(SIZE, in_game_map); // игровая карта
//
//vector<int> in_right_map(SIZE);
//vector<vector<int>> right_map(SIZE, in_right_map); // правильная итоговая карта
//
//struct coordinate // хранилище координат нулевого элемента
//{
//    unsigned x;
//    unsigned y;
//} zero; // объект
//
//void create_right_map() // создаем правильную карту заполненую по порядку
//{
//    unsigned right_value = 1;
//    for (unsigned i = 0; i < SIZE; i++)
//    {
//        for (unsigned j = 0; j < SIZE; j++)
//            right_map[i][j] = right_value++;
//    }
//    right_map[SIZE - 1][SIZE - 1] = 0; // нулевой элемент в нижний правый угол
//}
//
//void create_game_map() // рандомно создаем игровую карту
//{
//    unsigned limit = SIZE * SIZE;
//    vector<int> temporary; // временный массив из которого будем брать значения в игровую карту
//    for (unsigned i = 0; i < limit; i++)
//        temporary.push_back(i);
//
//    int value;
//    for (unsigned i = 0; i < SIZE; i++)
//    {
//        for (unsigned j = 0; j < SIZE; j++)
//        {
//            value = rand() % limit--;
//            game_map[i][j] = temporary[value];
//            if (temporary[value] == 0) // сохраняем координаты нулевого элемента
//            {
//                zero.x = j;
//                zero.y = i;
//            }
//            temporary.erase(temporary.begin() + value);
//        }
//    }
//}
//
//bool check_map() // сравнение игровой и правильной карты для определения конца игры
//{
//    if (game_map == right_map)
//        return true;
//    return false;
//}
//
//void up_move() // ход вверх (нулевой элемент вниз)
//{
//    if (zero.y < SIZE - 1)
//    {
//        game_map[zero.y][zero.x] = game_map[zero.y + 1][zero.x];
//        zero.y++;
//        game_map[zero.y][zero.x] = 0;
//    }
//}
//
//void down_move() // ход вниз (нулевой элемент вверх)
//{
//    if (zero.y > 0)
//    {
//        game_map[zero.y][zero.x] = game_map[zero.y - 1][zero.x];
//        zero.y--;
//        game_map[zero.y][zero.x] = 0;
//    }
//}
//
//void right_move() // ход вправо (нулевой элемент влево)
//{
//    if (zero.x > 0)
//    {
//        game_map[zero.y][zero.x] = game_map[zero.y][zero.x - 1];
//        zero.x--;
//        game_map[zero.y][zero.x] = 0;
//    }
//}
//
//void left_move() // ход влево (нулевой элемент вправо)
//{
//    if (zero.x < SIZE - 1)
//    {
//        game_map[zero.y][zero.x] = game_map[zero.y][zero.x + 1];
//        zero.x++;
//        game_map[zero.y][zero.x] = 0;
//    }
//}
//
//void get_direction() // определяем нажатую игроком стрелку
//{
//    int move = static_cast<int> (_getch()); // UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75
//    switch (move)
//    {
//    case 72:
//    {
//        up_move(); break;
//    }
//    case 80:
//    {
//        down_move(); break;
//    }
//    case 77:
//    {
//        right_move(); break;
//    }
//    case 75:
//    {
//        left_move(); break;
//    }
//    default:
//    {
//        get_direction();
//    }
//    }
//}
//void screen() // выводим массив на экран
//{
//    system("cls");
//    for (unsigned i = 0; i < SIZE; i++)
//    {
//        for (unsigned j = 0; j < SIZE; j++)
//        {
//            if (game_map[i][j] != 0)
//                cout << std::setw(2) << std::setfill('0') << game_map[i][j] << ' ';
//            else
//                cout << "** "; // нулевой элемент
//        }
//        cout << '\n';
//    }
//}
//
//int main()
//{
//    srand(static_cast<int>(time(NULL)));
//
//    create_right_map(); // создание игровых карт
//    do
//    {
//        create_game_map();
//    } while (check_map());
//
//    do // игровой цикл
//    {
//        screen();
//        get_direction();
//    } while (!check_map());
//
//    cout << "\nYou win!\nGame over!\n";
//    _getch();
//}

///////////////
////Задание 3//
///////////////
///*
//Написать игру «Крестики нолики».
//*/
//
//
//
//#include <iostream>
//
//using namespace std;
//
//
//
//int main()
//{
//    setlocale(0, "");
//
//
//    char cells[9] = { '-','-','-','-','-','-','-','-','-', };
//
//    int cell;
//    int cell1;
//
//    cout << "------------" << "\n" << endl;
//    cout << "Номера клеток:" << endl;
//    cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << " |" << endl;
//    cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << " |" << endl;
//    cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << " |" << "\n" << endl;
//
//
//    cout << "Игровое поле (--- пусто):" << endl;
//    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |" << endl;
//    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |" << endl;
//    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n" << endl;
//
//    cout << "------------\n" << endl;
//
//
//
//    for (int o = 0; o <= 9; ++o) {
//        cout << "Введите номер клетки, куда ходить  X: ";
//        cin >> cell;
//        cells[cell - 1] = 'x';
//
//        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |" << endl;
//        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |" << endl;
//        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n" << endl;
//
//
//
//        cout << "Введите номер клетки, куда ходить 0: ";
//        cin >> cell1;
//        cells[cell1 - 1] = '0';
//
//        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << " |" << endl;
//        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << " |" << endl;
//        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << " |" << "\n" << endl;
//        if ((cells[0] == 'x') && (cells[1] == 'x') && (cells[2] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[3] == 'x') && (cells[4] == 'x') && (cells[5] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[6] == 'x') && (cells[7] == 'x') && (cells[8] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[0] == 'x') && (cells[3] == 'x') && (cells[6] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[1] == 'x') && (cells[4] == 'x') && (cells[7] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[2] == 'x') && (cells[5] == 'x') && (cells[8] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[0] == 'x') && (cells[4] == 'x') && (cells[8] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//        if ((cells[2] == 'x') && (cells[4] == 'x') && (cells[6] == 'x')) {
//            cout << "Победа! X" << endl;
//            break;
//        }
//
//    }
//    system("pause");
//    return 0;
//}