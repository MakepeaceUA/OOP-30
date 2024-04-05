#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int size;
    static int count;

public:
    MyString()
    {
        size = 80;
        str = new char[size + 1];
        count++;
    }

    MyString(const MyString& copy)
    {
        size = copy.size;
        str = copy.str;
        count++;
    }

    MyString(int Size)
    {
        size = Size;
        str = new char[size + 1];
        count++;
    }

    MyString(const char* arr)
    {
        size = strlen(arr);
        str = new char[size + 1];
        strcpy_s(str, size + 1, arr);
        count++;
    }

    MyString(MyString&& other) 
    {
        str = other.str;
        size = other.size;
        other.str = nullptr;
        other.size = 0;
        count++;
    }

    friend istream& operator>>(istream& is, MyString& Str);
    friend ostream& operator<<(ostream& os, const MyString& Str);


    void SetStr(char* string)
    {
        str = string;
    }

    char* GetStr()
    {
        return str;
    }


    void Input()
    {
        cout << "Input string:";
        cin.getline(str, size + 1);
    }

    void Output()
    {
        if (str == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "String: " << str << "\n\n\n";
    }

    static int GetCount()
    {
        return count;
    }

    /* ~MyString()
     {
         delete[] str;
         count--;
     }*/

    MyString operator++()
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 2];

        strcpy_s(new_str, sz + 2, str);

        new_str[sz] = 'x';
        new_str[sz + 1] = '\0';

        delete[] str;
        str = new_str;

        return *this;
    }
    MyString operator++(int)
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 2];

        strcpy_s(new_str, sz + 2, str);

        new_str[sz] = 'x';
        new_str[sz + 1] = '\0';

        delete[] str;
        str = new_str;

        return *this;
    }

    MyString operator--()
    {
        str[size - 1] = '\0';

        return *this;
    }
    MyString operator--(int)
    {
        str[size - 1] = '\0';

        return *this;
    }

    MyString operator+(int value)
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 1 + value];

        strcpy_s(new_str, sz + 1 + value, str);

        for (int i = 0; i < value; i++)
        {
            new_str[sz + i] = 'x';
        }

        new_str[sz + value] = '\0';

        return MyString(new_str);
    }


    MyString operator-(int value)
    {
        int sz = strlen(str);
        str[sz - value] = '\0';

        return *this;
    }
    MyString& operator=(const MyString& obj)
    {
        if (!(this == &obj))
        {
            if (str != nullptr)
            {
                delete[] str;
            }
            if (obj.str == nullptr)
            {
                str = nullptr;
                size = obj.size;
                return *this;
            }
            str = new char[strlen(obj.str) + 1];
            strcpy_s(str, strlen(obj.str) + 1, obj.str);
            size = obj.size;
        }
        return *this;
    }
    MyString& operator=(MyString&& other) 
    {

        if(this != &other) 
        {
            cout << "MOVE\n";
            delete[] str;
            str = other.str;
            size = other.size;
            other.str = nullptr;
            other.size = 0;
        }
        return *this;
    }

};

int MyString::count = 0;

MyString operator+(int size, MyString& obj)
{
    char* str = obj.GetStr();
    int sz = strlen(str);

    char* new_str = new char[sz + 1 + size];

    for (int i = 0; i < size; i++)
    {
        new_str[i] = 'x';
    }

    strcpy_s(new_str + size, sz + 1, str);

    return MyString(new_str);
}

istream& operator>>(istream& is, MyString& Str) 
{
    cout << "Enter your string: ";
    char buf[100];
    
    is.getline(buf, 100);
    Str.size = strlen(buf);
    delete[] Str.str;
    
    Str.str = new char[Str.size + 1];
    strcpy_s(Str.str, Str.size + 1, buf);
    
    return is;
}

ostream& operator<<(ostream& os, const MyString& Str)
{
    os << "String: " << Str.str << '\t';
    return os;
}

MyString Func() 
{
    MyString Str = "Hello world";
    return Str;
}


int main()
{
    MyString obj1;
    MyString obj2 = "Hello world";
    MyString obj3 = move(obj2);

    obj3.Output(); 

    obj1 = move(obj3); 

    obj1.Output(); 

}

