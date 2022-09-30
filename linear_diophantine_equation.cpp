#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int main()
{
    int a,b,c,d;
    int u_prim = 1;
    int v_prim = 0;
    int u = 0;
    int v = 1;
    int u_tmp = 0;
    int v_tmp = 1;

    vector<int> b_v, r_v, q_v;

    cout << "ax + by = c  (Calculate int linear solutions for x and y Diophantine equation)" << endl;
    cout << "Input a=";
    cin >> a;
    cout << "Input b=";
    cin >> b;
    cout << "Input c=";
    cin >> c;

    // Using Bézout's identity
    d = gcd(a,b);
    //cout << "gcd = " << d << endl;
    if (c%d) {
        cout << "There are not integer solutions\n";
        return 1;
    }

    bool switched = false; //we my want to switch to use a>b then print it out a b
    if (b>a) {
        int a_tmp = a;
        int b_tmp = b;
        switched = true;
        a = b_tmp;
        b = a_tmp;
    }

    //first time (There is a first time for all of us)
    q_v.push_back(a/b);
    r_v.push_back(a%b);
    b_v.push_back(b);

    while (r_v.back() != 0) {
        int b = b_v.back();
        int r = r_v.back();
        q_v.push_back(b/r);
        r_v.push_back(b%r);
        b_v.push_back(r);
    }

    int factors =  q_v.size() -1;

    //for (int i = factors -1; i >= 0; i--) {
    //    if (i == 0)
    //        cout << r_v.at(i) << "=" << a <<  "-" << q_v.at(i) << "*" <<  b_v.at(i) << endl;
    //    else
    //        cout << r_v.at(i) << "=" << b_v.at(i-1) <<  "-" << q_v.at(i) << "*" <<  r_v.at(i-1) << endl;
    //}

    for (int i = 0; i < factors; i++) {
        //u -q*u´ = u`
        //v -q*v´ = v`

        u_tmp = u_prim;
        v_tmp = v_prim;

        u_prim = u - q_v.at(i) *u_prim;
        v_prim = v - q_v.at(i) *v_prim;

        u = u_tmp;
        v = v_tmp;

    }
    cout << endl;

    if (switched)
        cout << "Solution  " << "x=" << u_prim*c/d << "+" <<a/d << "n" <<  ",     " << "y=" << v_prim*c/d << "-" << b/d << "n" << endl;
    else
        cout << "Solution  " << "x=" << v_prim*c/d << "+" <<b/d << "n" <<  ",     " << "y=" << u_prim*c/d << "-" << a/d << "n" << endl;

    return 0;
}
