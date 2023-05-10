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


#define N 10// Kích thước buf
semaphore s1 = N;
semaphore s2 = 0;
semaphore s3 = 1;

void Producer()
{
    Produce_item(&item);
    Down(s1);
    Down(s3);
    Enter_Item(item, buffer);
    Up(s3);
    Up(s2);

}

void Consumer()
{
    Down(s2);
    Down(s3);
    Remove_item(&item, buffer);
    Up(s3);
    Up(s1);
    Consume_item(item);

}

int main()
{
    return 0;
}