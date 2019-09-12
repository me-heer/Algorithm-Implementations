#include <iostream>

using namespace std;

int main()
{
    int i,j,l,k,n=6;
    cout << "l: 2 to " << n << endl;
    for(l = 2; l <= n; l++)
    {
        cout << "i: 1 to " << n-l+1 << endl;
        for(i = 1; i <= n-l+1; i++)
        {
            j = i + l - 1;
            cout << "j: " << j << endl;
            cout << "m[" << i << "," << j << "] = infinity" << endl;
            //m[i,j] == infinity;
            cout << "k: " << i << "to " << j-1 << endl;
            for(k = i; k <= j-1; k++)
            {
                cout << "q = m["<<i<<","<<k<<"] + m["<<k+1<<","<<j<<"] + p["<<i-1<<"]p["<<k<<"]p["<<j<<"]" <<endl;
                cout << "if q < m[" << i <<"," << j << "]" << endl;
                cout << "\tm[" << i <<"," << j << "] = q" << endl;
                cout << "\ts[" << i <<"," << j << "] = "  << k << endl;
            }

        }
    }
    cin.get();
}
