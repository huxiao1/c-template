#include<iostream>
#include<string>
using namespace std;
#include "myArray.hpp"

void printIntArray(MyArray<int>& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout<<arr[i]<<endl;
    }
}

void test01()
{
    MyArray <int>arr1(5);

    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i); //利用尾插法像数组中插入数据
    }

    printIntArray(arr1);
    

    MyArray<int>arr2(arr1); //有参拷贝析构析构
    printIntArray(arr2);
    arr2.Pop_Back();
    printIntArray(arr2);

    MyArray<int>arr3(100); //有参operator等号调用析构析构
    arr3=arr1;
}

//测试自定义数据类型
class Person
{
public:
    Person() {};
    Person(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printPerosnArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name:" << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
	}
}

void test02()
{
    MyArray <Person> arr(10);
    Person p1("A",999);
    Person p2("B",20);
    Person p3("C",30);
    Person p4("D",200);
    Person p5("E",2100);

    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    printPerosnArray(arr);

    /*
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout<<"name"<<arr[i].m_Name<<"age:"<<arr[i].m_Age<<endl;
    }
    */
}


int main()
{
    test02();
    return 0;
}