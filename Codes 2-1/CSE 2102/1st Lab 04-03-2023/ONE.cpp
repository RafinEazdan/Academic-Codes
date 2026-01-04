#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool p, q;
    cout << "p\tq\t!p^(p->q)\tp v (!q->p)\n" << endl;
    for (int i = 0; i < 4; i++)
    {
        p = i / 2;
        q = i % 2;
        cout << p << "      " << q << "          ";
        bool exp1 = !p && (!p || q);
        bool exp2 = p || (q || p);
        cout << exp1 << "        " << exp2 << endl;
    }

    return 0;
}

