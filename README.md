# junma
cocos2d 代码

#include<iostream>
#define size 20
using namespace std;
class Vector
{
private:
    int rep[size];
public:
    const int& operator[](int index)const
    {
        return rep[index];
    }
    int& operator[](int index)
    {
        return rep[index];
    }
};
ostream& operator<<(ostream& out,const Vector& a)
{
    for (int i=0; i<size; i++) {
        out<<a[i]<<endl;
    }
    return out;
}
