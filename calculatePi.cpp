#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

bool printProgress(string progress) {
    if (progress == "Y" || progress == "y" || progress == "yes" || progress == "Yes") {
        return true;
    } else {
        return false;
    }
}

double powerOf2(int x) {
    return x * x;   
}

double distance(int boxSize, int x, int y) {
    return sqrt(powerOf2(boxSize / 2 - x) + powerOf2(boxSize / 2 - y));   
}

int main() {

    int boxSize, radius, repeat, batch;
    
    double dots = 0, dotsInCircle = 0, circleArea = 0, pi = 0;

    string progress;
    
    cout << "Radius size: ";
    cin >> radius;
    
    cout << "Number of repeats: ";
    cin >> repeat;

    cout << "Do you want to print progress? (Y/N): ";
    cin >> progress;

    boxSize = radius * 2;
    
    for (int i = 0; i < repeat; i++) {

        batch = 90000 + (rand() % 90000);

        for (int j = 0; j < batch; j++) {
            int x = rand() % boxSize;
            int y = rand() % boxSize;
            
            dots++;
            
            if (distance(boxSize, x, y) < radius) {
                dotsInCircle++;   
            }
            
            circleArea = (dotsInCircle / dots) * ((powerOf2(boxSize)) - pi);
            
            pi = circleArea / powerOf2(radius);
        }

        if (printProgress(progress)) {
            cout << pi << endl;
        }
    }
    
    cout << pi << endl;

    return 0;
}
