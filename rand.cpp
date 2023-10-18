#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool isIlluminated(int Ox, int Oy, int Px, int Py, int Ax, int Ay, int Bx, int By, double w) {
    double d1 = distance(Ox, Oy, Ax, Ay);
    double d2 = distance(Ox, Oy, Bx, By);
    double d3 = distance(Ax, Ay, Px, Py);
    double d4 = distance(Bx, By, Px, Py);
    double dis = distance(Ax,Ay,Bx,By);
    double mid = dis/2.0;
    if(w>=d4 && (w>=d1 || w>=d2) && w > mid){
        return true;
    }
    else if(w>=d3 && (w>=d1 || w>=d2) && w > mid){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int Px, Py, Ax, Ay, Bx, By;
        cin >> Px >> Py >> Ax >> Ay >> Bx >> By;

        double left = 0, right = 1e9; 
        double result = 0;

        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (isIlluminated(0, 0, Px, Py, Ax, Ay, Bx, By, mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << fixed << setprecision(10) << result << endl;
    }

    return 0;
}
