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
            Size = x;    //队列长度
            Start = 0;
            Empty = 0;
            End = 0;
        }
        void push(T val)//入队
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
        void pop() //出队
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
        void clear() //消除所有元素
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
