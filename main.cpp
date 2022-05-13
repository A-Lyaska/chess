// 0 вариант: 1 пешка, 2 ладьи, 3 коня
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

class figures
{
public:
    int x, y;
    bool check_obstacles(int x_obst, int y_obst)
    {
        if (((x_obst == 1) && (y_obst == 2)) || ((x_obst == 1) && (y_obst == 1)) || ((x_obst == 3) && (y_obst == 5)) || ((x_obst == 2) && (y_obst == 4)) || ((x_obst == 7) && (y_obst == 3)) || ((x_obst == 3) && (y_obst == 6)))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool check_destination(int x_current, int y_current, int x_dest, int y_dest)
    {
        if ((x_current == x_dest) && (y_current == y_dest))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class horse: public figures
{
public:
    int x, y, dest_x, dest_y, x_nach, y_nach;
    horse(int x_horse, int y_horse, int x_dest, int y_dest)
    {
        x_nach = x_horse, x = x_horse, y_nach = y_horse, y = y_horse, dest_x = x_dest, dest_y = y_dest;
    }
    void move(int direction)
    {
        switch (direction)
        {
            case 1:
                if (check_obstacles(x + 1, y + 2) == true)
                {
                    x = x + 1;
                    y = y + 2;
                }
                break;
            case 2:
                if (check_obstacles(x + 2, y + 1) == true)
                {
                    x = x + 2;
                    y = y + 1;
                }
                break;
            case 3:
                if (check_obstacles(x + 2, y - 1) == true)
                {
                    x = x + 2;
                    y = y - 1;
                }
                break;
            case 4:
                if (check_obstacles(x + 1, y - 2) == true)
                {
                    x = x + 1;
                    y = y - 2;
                }
                break;
            case 5:
                if (check_obstacles(x - 1, y - 2) == true)
                {
                    x = x - 1;
                    y = y - 2;
                    break;
                }
            case 6:
                if (check_obstacles(x - 2, y - 1) == true)
                {
                    x = x - 2;
                    y = y - 1;
                }
                break;
            case 7:
                if (check_obstacles(x - 2, y + 1) == true)
                {
                    x = x - 2;
                    y = y + 1;
                }
                break;
            case 8:
                if (check_obstacles(x - 1, y + 2) == true)
                {
                    x = x - 1;
                    y = y + 2;
                }
                break;
        }
        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Конь с начальными координатами х=" << x_nach << " y=" << y_nach << " успешно добрался до указанной точки!" << endl;
        }
    }
};

class pawn : public figures
{
public:
    int x, y, dest_x, dest_y, x_nach, y_nach;
    pawn(int x_pawn, int y_pawn, int x_dest, int y_dest)
    {
        x_nach = x_pawn, x = x_pawn, y_nach = y_pawn, y = y_pawn, dest_x = x_dest, dest_y = y_dest;
    }
    void move(int direction) // direction - код направления фигуры
    {
        switch (direction)
        {
            case 1: // вверх
                while ((y + 1 <= 7) && check_obstacles(x, y + 1) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    y++;
                }
                break;
        }
        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Пешка с начальными координатами х=" << x_nach << " y=" << y_nach << " успешно добралась до указанной точки!" << endl;
        }
    }
};

class rook: public figures
{
public:
    int x, y, dest_x, dest_y, x_nach, y_nach;
    rook(int x_rook, int y_rook, int x_dest, int y_dest)
    {
        x_nach = x_rook, x = x_rook, y_nach = y_rook, y = y_rook, dest_x = x_dest, dest_y = y_dest;
    }
    void move(int direction)
    {
        switch (direction)
        {
            case 1: // влево
                while ((x - 1 >= 0) && check_obstacles(x - 1, y) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    x--;
                }
                break;
            case 2: // вправо
                while ((x + 1 < 8) && check_obstacles(x + 1, y) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    x++;
                }
                break;
            case 3: // вверх
                while ((y + 1 <= 7) && check_obstacles(x, y + 1) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    y++;
                }
                break;
            case 4: // вниз
                while ((y - 1 >= 0) && check_obstacles(x, y - 1) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    y--;
                }
                break;
        }

        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Ладья с начальными координатами х=" << x_nach << " y=" << y_nach << " успешно добралась до указанной точки!" << endl;
        }
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int destination_x, destination_y;

    vozvrat_k_zaprosu:
    cout << "Укажите координаты точки назначения (сперва х, затем у) " << endl;
    cin >> destination_x >> destination_y;

    if ( (destination_x >=8) || (destination_x < 0) || (destination_y >= 8) || (destination_y < 0) || ((destination_x == 1) && (destination_y == 2)) || ((destination_x == 1) && (destination_y == 1)) || ((destination_x == 3) && (destination_y == 5)) || ((destination_x == 2) && (destination_y == 4)) || ((destination_x == 7) && (destination_y == 3)) || ((destination_x == 3) && (destination_y == 6)))
    {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_zaprosu;
    }
    cout << "\n";

    pawn p1(1, 1, destination_x, destination_y);
    for (int i = 1; i <= 1; i++) {
        p1.move(i);
        p1.x = 1;
        p1.y = 1;
    }

    rook r1(1, 3, destination_x, destination_x);
    rook r2(4, 7, destination_x, destination_x);
    for(int i = 1; i <= 4; i++) {
        r1.move(i);
        r1.x = 1;
        r1.y = 3;
    }
    for(int i = 1; i <= 4; i++) {
        r2.move(i);
        r2.x = 4;
        r2.y = 7;
    }

    horse h1(7, 5, destination_x, destination_y);
    horse h2(4, 3, destination_x, destination_y);
    horse h3(6, 2, destination_x, destination_y);
    for (int i = 1; i <= 8; i++)
    {
        h1.move(i);
        h1.x = 7;
        h1.y = 5;
    }
    for (int i = 1; i <= 8; i++)
    {
        h2.move(i);
        h2.x = 4;
        h2.y = 3;
    }
    for (int i = 1; i <= 8; i++)
    {
        h3.move(i);
        h3.x = 5;
        h3.y = 2;
    }

}
