// 0 вариант: 1 пешка, 2 ладьи, 3 коня

#include <iostream>
#include <clocale>
#include <stdio.h>
#include <windows.h>

using namespace std;


class figures
{
public:
    int x, y, a, b, c, d, f, g, q, w, e, r, t, u;
    bool check_obstacles(int x_obst, int y_obst)
    {
        if (((x_obst == a) && (y_obst == b)) || ((x_obst == c) && (y_obst == d)) || ((x_obst == f) && (y_obst == g)) || ((x_obst == q) && (y_obst == w)) || ((x_obst == e) && (y_obst == r)) || ((x_obst == t) && (y_obst == u)))
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
                if (check_obstacles(x - 1, y + 2) == true)
                {
                    x = x - 1;
                    y = y + 2;
                }
                break;
            case 3:
                if (check_obstacles(x - 2, y + 1) == true)
                {
                    x = x - 2;
                    y = y + 1;
                }
                break;
            case 4:
                if (check_obstacles(x - 2, y - 1) == true)
                {
                    x = x - 2;
                    y = y - 1;
                }
                break;
            case 5:
                if (check_obstacles(x - 1, y - 2) == true)
                {
                    x = x - 1;
                    y = y - 2;
                }
                break;
            case 6:
                if (check_obstacles(x + 1, y - 2) == true)
                {
                    x = x + 1;
                    y = y - 2;
                }
                break;
            case 7:
                if (check_obstacles(x + 2, y - 1) == true)
                {
                    x = x + 2;
                    y = y - 1;
                }
                break;
            case 8:
                if (check_obstacles(x + 2, y + 1) == true)
                {
                    x = x + 2;
                    y = y + 1;
                }
                break;
        }
        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Конь с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добрался до указанной точки!" << endl;
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
            case 1: // вверх
                if (check_obstacles(x, y + 1) == true) {
                    y++;
                }
                break;
        }
        if (check_destination(x, y, dest_x, dest_y) == true)
        {
            cout << "Пешка с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добралась до указанной точки!" << endl;
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
            cout << "Ладья с начальными координатами х = " << x_nach << " y = " << y_nach << " успешно добралась до указанной точки!" << endl;
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

    int a, b;
    cout << "Введите координаты пешки (сперва х, затем у): ";
    cin >> a >> b;
    pawn p1(a, b, destination_x, destination_y);
    for (int i = 1; i <= 1; i++)
    {
        p1.move(i);
        p1.x = a;
        p1.y = b;
    }

    int c, d, f, g;
    cout << "Введите координаты ладьи №1 (сперва х, затем у): ";
    cin >> c >> d;
    cout << "Введите координаты ладьи №2 (сперва х, затем у): ";
    cin >> f >> g;
    rook r1(c, d, destination_x, destination_y);
    rook r2(f, g, destination_x, destination_y);
    for (int i = 1; i <= 4; i++)
    {
        r1.move(i);
        r1.x = c;
        r1.y = d;
    }
    for (int i = 1; i <= 4; i++)
    {
        r2.move(i);
        r2.x = f;
        r2.y = g;
    }

    int q, w, e, r, t, u;
    cout << "Введите координаты коня №1 (сперва х, затем у): ";
    cin >> q >> w;
    cout << "Введите координаты коня №2 (сперва х, затем у): ";
    cin >> e >> r;
    cout << "Введите координаты коня №3 (сперва х, затем у): ";
    cin >> t >> u;
    horse h1(q, w , destination_x, destination_y);
    horse h2(e, r , destination_x, destination_y);
    horse h3(t, u, destination_x, destination_y);
    for (int i = 1; i <= 8; i++)
    {
        h1.move(i);
        h1.x = q;
        h1.y = w;
    }
    for (int i = 1; i <= 8; i++)
    {
        h2.move(i);
        h2.x = e;
        h2.y = r;
    }
    for (int i = 1; i <= 8; i++)
    {
        h3.move(i);
        h3.x = t;
        h3.y = u;
    }
}
