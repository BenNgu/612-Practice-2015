
#include <cstdio>

int main()
{
    int x = 0;
    int y = 0;
    int a = 0;
    while (x * 5 <= 1000)
    {
        a += x * 5;
        x++;
    }
    while (y * 3 <= 1000)
    {
        a += y * 3;
        y++;
    }
    printf("%d",a);
}
