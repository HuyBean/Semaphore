#include <iostream>
using namespace std;

//  W không được cập nhật dữ liệu khi có ít nhất 1 R đang truy xuất CSDL
//  Rs không được truy cập CSDL khi một W đang cập nhật nội dung CSDL
//  Tại 1 thời điểm, chỉ cho phép 1 W được sửa đổi nội dung CSDL

typedef int semaphore;

void Down(semaphore S)
{
    return;
}
void Up(semaphore S)
{
    return;
}


semaphore s1 = 1; // Thỏa ĐK 2, 3
semaphore s2 = 1; // Bảo vệ miền găng của if thứ 1

int rc = 0;

void Reader()
{
    Down(s2); // Bảo vệ miền găng cho s1, nhận biết thời điểm rc = 0 để W truy cập
    if( rc == 0)
    {
        Down(s1); 
    }
    rc++;
    Up(s2);
    Read_DB(Database);
    Down(s2);
    rc--;
    if(rc == 0)
    {
        Up(s1);
    }
    Up(s2);

}

void Writer()
{
    Down(s1); // Tại 1 thời điểm chỉ có 1 W được truy cập CSDL
    Write_DB(&Database);
    Up(s1);

}

int main()
{
    return 0;
}