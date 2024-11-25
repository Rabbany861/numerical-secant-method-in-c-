#include <bits/stdc++.h>
using namespace std;
#define E .0001
float f(float x)
{
    return pow(x, 3) - x - 1;
}

void secant(float x1, float x2 )
{
    float x0, c;
    int n = 0;

    // Check if the initial interval is valid
      if (f(x1) * f(x2) < 0)
      {
        while (true)
        {
            // Calculate the new approximate root
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

            // Check if x0 is the root of the equation
            c = f(x1) * f(x0);

            // Update the values for the next iteration
            x1 = x2;
            x2 = x0;

            // Increment iteration count
            n++;

            // If the function value is close to zero or the change in x is small, stop
            if (fabs(c) <= E || fabs(f(x0)) <= E)
                break;
        }

        cout << "Root of the given equation = " << x0 << endl;
        cout << "No. of iterations = " << n << endl;
    }
    else
     {
        cout << "Cannot find a root in the given interval." << endl;
      }
}

int main()
{
    float x1 = 1, x2 = 2;
    secant(x1, x2);

    return 0;
}

