#include <bits/stdc++.h>
using namespace std;

void move_forward(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
        st[1]++;
        break;
    case 'S':
        st[1]--;
        break;
    case 'E':
        st[0]++;
        break;
    case 'W':
        st[0]--;
        break;
    case 'U':
        st[2]++;
        break;
    case 'D':
        st[2]--;
        break;
    }
}
void move_backward(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
        st[1]--;
        break;
    case 'S':
        st[1]++;
        break;
    case 'E':
        st[0]--;
        break;
    case 'W':
        st[0]++;
        break;
    case 'U':
        st[2]--;
        break;
    case 'D':
        st[2]++;
        break;
    }
}
void turn_left(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
        direction = 'W';
        break;
    case 'S':
        direction = 'E';
        break;
    case 'E':
        direction = 'N';
        break;
    case 'W':
        direction = 'S';
        break;
    case 'U':
        direction = 'W';
        break;
    case 'D':
        direction = 'W';
        break;
    }
}
void turn_right(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
        direction = 'E';
        break;
    case 'S':
        direction = 'W';
        break;
    case 'E':
        direction = 'S';
        break;
    case 'W':
        direction = 'N';
        break;
    case 'U':
        direction = 'E';
        break;
    case 'D':
        direction = 'E';
        break;
    }
}
void turn_upward(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
    case 'S':
    case 'E':
    case 'W':
        direction = 'U';
        break;
    case 'U':
        st[2]++;
        break;
    case 'D':
        direction = 'U';
        st[2]++;
        break;
    }
}
void turn_downward(vector<int> &st, char &direction)
{
    switch (direction)
    {
    case 'N':
    case 'S':
    case 'E':
    case 'W':
        direction = 'D';
        break;
    case 'U':
        direction = 'D';
        st[2]--;
        break;
    case 'D':
        st[2]--;
        break;
    }
}

void print(vector<int> st_point, char direction, char command)
{
    cout << command << "-(" << st_point[0] << "," << st_point[1] << "," << st_point[2] << ")-" << direction << endl;
}
int main()
{
    vector<int> st_point{0, 0, 0};
    cout << "Initial Direction from (N, S, E, W, Up, Down) : ";
    char direction;
    cin >> direction;
    vector<char> commands{'f', 'r', 'u', 'b', 'l'};
    for (auto c : commands)
    {
        switch (c)
        {
        case 'f':
            move_forward(st_point, direction);
            print(st_point, direction, 'f');
            break;
        case 'b':
            move_backward(st_point, direction);
            print(st_point, direction, 'b');
            break;
        case 'l':
            turn_left(st_point, direction);
            print(st_point, direction, 'l');
            break;
        case 'r':
            turn_right(st_point, direction);
            print(st_point, direction, 'r');
            break;
        case 'u':
            turn_upward(st_point, direction);
            print(st_point, direction, 'u');
            break;
        case 'd':
            turn_downward(st_point, direction);
            print(st_point, direction, 'd');
            break;
        default:
            cout << "Invalid Command";
            break;
        }
    }
    cout << "Final Position (" << st_point[0] << "," << st_point[1] << "," << st_point[2] << ")" << endl;
    cout << "Final Direction " << direction;
    return 0;
}
