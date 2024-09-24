#include <iostream>
#include <vector>
#define Eps 1E-15

using namespace std;

double Func (double y, double t)
{
    return 2 * t * y;
}

double KN (double h, double t, double y, double k)
{
    return Func(t + h, y + h * k);
}

void Runge_Kutta(vector<double> grid, double h)
{
    
        double x0 = 0;
        double cur_y = 0;
        double y = 1;
        double k1, k2, k3, k4;
        for (int i = 0; i < grid.size() - 1; i++)
        {
            k1 = Func(y, grid[i]);
            k2 = KN(h/2, grid[i], y, k1);
            k3 = KN(h/2, grid[i], y, k2);
            k4 = KN(h, grid[i], y, k3);
            cur_y = y + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
            printf("%.15lf\n", cur_y);
            y = cur_y;
        }
    
}

void SimpleE(vector<double> grid, double h)
{
    double cur_y = 0;
    double y = 1;
    cout << "Простой метод Эйлера" << endl;
    for (int i = 1; i < grid.size(); i++) { // Изменил начало цикла с 0 на 1
        cur_y = y + h * Func(y, grid[i-1]);
        printf("%g %.15lf\n", grid[i], cur_y);
        y = cur_y;
    }
    cout << endl;

    double x0 = 0;
    cur_y = 0;
    y = 1;
    //простой неявный метод Эйлера
    cout << "Неявный метод Эйлера" << endl;
    for (int i = 1; i < grid.size(); i++)
    {
        x0 = y + h * Func(y, grid[i-1]); //находим первое значение y(n+1)
        while (abs(x0 - cur_y) > Eps)
        {
            cur_y = x0;
            x0 = y + h * Func(cur_y, grid[i]);
        }
        printf("%g %.15lf\n", grid[i], x0);
        y = cur_y;
    }

    
}

void Other (vector<double> grid, double h)
{

    double cur_y = 0;
    double y = 1;

    // Модифицированный метод Эйлера
    cout << "Модифицированный метод Эйлера" << endl;
    for (int i = 1; i < grid.size(); i++) { // Изменил начало цикла с 0 на 1
        cur_y = y + (h / 2) * (Func(y, grid[i-1]) + Func((y + h * Func(y, grid[i-1])), grid[i]));
        printf("%.15lf\n", cur_y);
        y = cur_y;
    }
    cout << endl;

    double x0 = 0;
    cur_y = 0;
    y = 1;
    //метод (правило) трапеций
    cout << "Трапеций" << endl;
    for (int i = 1; i < grid.size(); i++)
    {
        x0 = y + h * Func(y, grid[i-1]);//находим первое значение y(n+1)
        while (abs(x0 - cur_y) > Eps)
        {
            cur_y = x0;
            x0 = y + (h/2)*(Func(y,grid[i-1]) + Func(cur_y, grid[i]));
        }
        printf("%.15lf\n", x0);
        y = cur_y;
    }
}
int main()
{
    double h;
    
    cin >> h;
    vector<double> grid;
    grid.push_back(0);
    for (int i = 1; i <= 1 / h; i++)
        grid.push_back(i * h);
    Other(grid, h);
}