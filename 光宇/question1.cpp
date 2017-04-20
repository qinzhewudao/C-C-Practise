#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class arrayQueue
{
    public:
        arrayQueue(int x)
        {
            Data = new T[x];
            Size = x;    //���г���
            Start = 0;
            Empty = 0;
            End = 0;
        }
        void push(T val)//���
        {
            if (Size == Empty)
            {
                cout << "queue is full" << endl;
                return;
            }
            Data[End++] = val;
            Empty++;
            End = End%Size;
        }
        T Front()
        {
            T temp = Data[Start];
            return temp;
        }
        void pop() //����
        {
            if (Empty > 0)
            {
                Start++;
                Empty--;
            }
            else
            {
                cout << "queue is empty please push some number" << endl;
                return;
            }
        }
        void clear() //��������Ԫ��
        {
            while(Empty > 0)
            {
                Start++;
                Empty--;
            }
        }
    private:
        T  *Data;
        int Start;
        int End;
        int Empty;
        int Size;
};
