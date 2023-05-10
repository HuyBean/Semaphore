#include <iostream>
using namespace std;

//  Không được ghi dữ liệu vào buf đầy
//  Không được đọc dữ liệu từ buf trống
//  Produce và Consume không thao tác cùng lúc

typedef int semaphore;

void Down(semaphore S)
{
    return;
}
void Up(semaphore S)
{
    return;
}

semaphore s = 0;
semaphore s1 = 0;
semaphore s2 = 1;

void Make_H()
{
    Make_Hydro();
    Up(s);
    Up(s);
}

void Make_O()
{
    Make_Oxy();
    Up(s1);

}

void Make_Water()
{
    while(True)
    {
        Down(s);
        Down(s);
        Down(s1);
        Make_H2O();
        
    }
}

int main()
{
    return 0;
}