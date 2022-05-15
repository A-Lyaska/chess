// 0 вариант: 1 пешка, 2 ладьи, 3 коня

#include <iostream>
#include <stdio.h>
#include <windows.h>


using namespace std;

class figures
{
public:
    int x, y, a[6], b[6];
    bool check_obstacles(int x_obst, int y_obst)
    {
        if (((x_obst == a[0]) && (y_obst == b[0])) || ((x_obst == a[1]) && (y_obst == b[1])) || ((x_obst == a[2]) && (y_obst == b[2])) || ((x_obst == a[3]) && (y_obst == b[3])) || ((x_obst == a[4]) && (y_obst == b[4])) || ((x_obst == a[5]) && (y_obst == b[5])))
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
            cout << "Конь с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добрался до указанной точки!\n" << endl;
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
    void move(int direction)
    {
        switch (direction)
        {
            case 1:
                while ((y + 1 < 8) && (check_obstacles(x, y + 1) == true) && (check_destination(x, y, dest_x, dest_y) == false))
                {
                    y++;
                }
                break;
        }
        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Пешка с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добралась до указанной точки!\n" << endl;
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
            case 1:
                while ((x - 1 >= 0) && check_obstacles(x - 1, y) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    x--;
                }
                break;
            case 2:
                while ((x + 1 < 8) && check_obstacles(x + 1, y) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    x++;
                }
                break;
            case 3:
                while ((y + 1 <= 7) && check_obstacles(x, y + 1) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    y++;
                }
                break;
            case 4:
                while ((y - 1 >= 0) && check_obstacles(x, y - 1) == true && check_destination(x, y, dest_x, dest_y) == false)
                {
                    y--;
                }
                break;
        }

        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Ладья с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добралась до указанной точки!\n" << endl;
        }
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int destination_x, destination_y, a[6], b[6];

    vozvrat_k_zaprosu:
    cout << "Укажите координаты точки назначения:\n" << endl;
    cout << "\n    X = ";
    cin >> destination_x;
    cout << "\n    Y = ";
    cin >> destination_y;

    if ( (destination_x >=8) || (destination_x < 0) || (destination_y >= 8) || (destination_y < 0) || ((destination_x == 1) && (destination_y == 2)) || ((destination_x == 1) && (destination_y == 1)) || ((destination_x == 3) && (destination_y == 5)) || ((destination_x == 2) && (destination_y == 4)) || ((destination_x == 7) && (destination_y == 3)) || ((destination_x == 3) && (destination_y == 6)))
    {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_zaprosu;
    }
    cout << "\n";

    cout << "Введите координаты пешки:\n";
    cout << "\n    X = ";
    cin >> a[0];
    cout << "\n    Y = ";
    cin >> b[0];

    pawn p1(a[0], b[0], destination_x, destination_y);
    int p = 1;
    p1.x = a[0];
    p1.y = b[0];
    p1.move(p);

    vozvrat_k_vvodu_1:
    cout << "Введите координаты ладьи #1:\n";
    cout << "\n    X = ";
    cin >> a[1];
    cout << "\n    Y = ";
    cin >> b[1];

    if ((a[1] == a[0]) && (b[1] == a[0])) {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_vvodu_1;
    }
    cout << "\n";

    rook r1(a[1], b[1], destination_x, destination_x);
    for(int i = 1; i <= 4; i++) {
        r1.move(i);
        r1.x = a[1];
        r1.y = b[1];
    }

    vozvrat_k_vvodu_2:
    cout << "Введите координаты ладьи #2:\n";
    cout << "\n    X = ";
    cin >> a[2];
    cout << "\n    Y = ";
    cin >> b[2];

    if ((a[2] == a[0]) && (b[2] == b[0]) || (a[2] == a[1]) && (b[2] == b[1])) {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_vvodu_2;
    }
    cout << "\n";

    rook r2(a[2], b[2], destination_x, destination_x);
    for(int i = 1; i <= 4; i++) {
        r2.move(i);
        r2.x = a[2];
        r2.y = b[2];
    }

    vozvrat_k_vvodu_3:
    cout << "Введите координаты коня #1:\n";
    cout << "\n    X = ";
    cin >> a[3];
    cout << "\n    Y = ";
    cin >> b[3];

    if (((a[3] == a[0]) && (b[3] == b[0])) || ((a[3] == a[1]) && (b[3] == b[1])) || ((a[3] == a[2]) && (b[3] == b[2]))) {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_vvodu_3;
    }
    cout << "\n";

    horse h1(a[3], b[3], destination_x, destination_y);
    for (int i = 1; i <= 8; i++)
    {
        h1.move(i);
        h1.x = a[3];
        h1.y = b[3];
    }

    vozvrat_k_vvodu_4:
    cout << "Введите координаты коня #2:\n";
    cout << "\n    X = ";
    cin >> a[4];
    cout << "\n    Y = ";
    cin >> b[4];

    if (((a[4] == a[0]) && (b[4] == b[0])) || ((a[4] == a[1]) && (b[4] == b[1])) || ((a[4] == a[2]) && (b[4] == b[2])) || ((a[4] == a[3]) && (b[4] == b[3]))) {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_vvodu_4;
    }
    cout << "\n";

    horse h2(a[4], b[4], destination_x, destination_y);
    for (int i = 1; i <= 8; i++)
    {
        h2.move(i);
        h2.x = a[4];
        h2.y = b[4];
    }

    vozvrat_k_vvodu_5:
    cout << "Введите координаты коня #3:\n";
    cout << "\n    X = ";
    cin >> a[5];
    cout << "\n    Y = ";
    cin >> b[5];

    if (((a[5] == a[0]) && (b[5] == b[0])) || ((a[5] == a[1]) && (b[5] == b[1])) || ((a[5] == a[2]) && (b[5] == b[2])) || ((a[5] == a[3]) && (b[5] == b[3])) || ((a[5] == a[4]) && (b[5] == b[4]))) {
        cout << "\nВведите другие координаты! Здесь занято.\n" << endl;
        goto vozvrat_k_vvodu_5;
    }
    cout << "\n";

    horse h3(a[5], b[5], destination_x, destination_y);

    for (int i = 1; i <= 8; i++)
    {
        h3.move(i);
        h3.x = a[5];
        h3.y = b[5];
    }
}

