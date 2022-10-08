#include <iostream>
#include <cmath>
using namespace std;

inline int gcd_sig(int a, int b)
{
   if (b == 0)
   return a;
   return gcd_sig(b, a % b);
}

inline int gcd(int a, int b) { return abs(gcd_sig(a,b)); }

void bezoutEE(int a, int b, int &u, int &v)
{
    // Extended Euclidean from wikipedia
    int s = 0;
    int old_s = 1;
    int r = b;
    int old_r = a;
    int t;

    while (r != 0)
    {
        int q = old_r / r;
        int tmp_r = r;
        int tmp_s = s;

        r = old_r - q* tmp_r;
        s = old_s - q* tmp_s;

        old_r = tmp_r;
        old_s = tmp_s;
    }

    (b != 0) ? t = (old_r - old_s * a) / b: t = 0;

    u = old_s;
    v = t;
}

int main()
{
    int a,b,c,d,u,v,x_0,y_0,x_n,y_n;

    cout << "ax + by = c  (Calculate int linear solutions for x and y Diophantine equation)" << endl;
    cout << "Input a=";
    cin >> a;
    cout << "Input b=";
    cin >> b;
    cout << "Input c=";
    cin >> c;

    // Using Bézout's identity
    if (a==0 && b==0)
    {
        cerr << "Both a and b cant be 0\n";
        return 1;
    }
    d = abs(gcd_sig(a,b));
    if (c%d) {
        cerr << "There are not integer solutions\n";
        return 1;
    }

    bezoutEE(abs(a),abs(b), u, v);

    x_0 = u*(c/d);
    y_0 = v*(c/d);

    y_n = -1*(a/d);
    x_n = (b/d);

    if (a < 0) x_0 = -x_0;
    if (b < 0) y_0 = -y_0;

    cout << "x=" << x_0;
    if (x_n>=0) cout << "+";
    cout << x_n << "n" << endl;

    cout << "y=" << y_0;
    if (y_n>=0) cout << "+";
    cout << y_n << "n" << endl;

    return 0;
}
