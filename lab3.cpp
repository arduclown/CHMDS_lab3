#include <iostream>
#include <vector>

using namespace std;

double Func (double y, double t)
{
    return 2 * t * y;
}

double KN (double h, double t, double y, double k)
{
    return Func(t + h, y + h * k);
}

int main()
{
    double h;
    
    cin >> h;
    vector<double> grid;
    grid.push_back(0);
    for (int i = 1; i <= 1 / h; i++)
        grid.push_back(i * h);
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
        printf("%g %.15lf\n", grid[i+1], cur_y);
        y = cur_y;
    }
}