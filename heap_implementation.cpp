#include <bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> v;
    bool minHeap;

    public:
    heap(bool type = true)
    {
        minHeap = type;
        v.push_back(-1);
    }

    bool compare(int a,int b)
    {
        if(minHeap)
        {
            return a<b;
        }
        return a>b;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx = v.size()-1;
        int par = idx/2;
        while(idx >1 && compare(v[idx] , v[par]))
        {
            swap(v[idx] , v[par]);
            idx = par;
            par=idx/2;
        }
    }

    int top()
    {
        return v[1];
    }

    bool empty()
    {
        return v.size() == 1;
    }

    void heapify(int i)
    {
        int l = 2*i;
        int r = l+1;

        int mn = i;

        if(l<v.size() && compare(v[l] , v[mn]))
        {
            mn = l;
        }
        if(r<v.size() && compare(v[r] , v[mn]))
        {
            mn = r;
        }

        if(mn != i)
        {
            swap(v[mn] , v[i]);
            heapify(mn);
        }
    }

    void pop()
    {
        int idx = v.size()-1;
        swap(v[1],v[idx]);
        v.pop_back();
        heapify(1);
    }
};
int main()
{
    heap h(false);
    h.push(4);
    h.push(1);
    h.push(5);
    h.push(3);
    h.push(41);
    h.push(9);

    while(!h.empty())
    {
        cout<<h.top() <<" ";
        h.pop();
    }
}
