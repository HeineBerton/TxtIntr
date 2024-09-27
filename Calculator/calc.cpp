#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

double squarecircle(double r)
{
    const float pi = 3.14;
    double res = pi * r * r;
    return res;
}

double squaretriangle(double a, double b, double c)
{
    double semi_per = (a + b + c) / 2;
    double res = sqrt(semi_per * (semi_per - a) * (semi_per - b) * (semi_per - c));
    return res;
}

void help()
{
    cout << "Площадь треугольника: ./calc -o t <а> <b> <c>" << endl;
    cout << "Площадь круга:        ./calc -o c <r>" << endl;
    cout << "Справка:              ./calc -h" << endl;
}

int main(int argc, char** argv)
{
    int opt;

    if(argc == 1) {
        help();
        return 0;
    }

    while((opt = getopt(argc, argv, "o:h")) != -1) {
        switch(opt) {
        case 'h':
            help();
            return 0;
        case '?':
            help();
            return 1;

        case 'o':
            string type = string(optarg);

            if(type == "c") {
                if(argc < 4) {
                    help();
                    return 1;
                } else {
                    double r = stod(argv[3]);
                    double s = squarecircle(r);
                    cout << "Площадь круга равна: " << s << endl;
                    return 0;
                }
            }

            if(type == "t") {
                if(argc < 6) {
                    help();
                    return 1;
                } else {
                    double x = stod(argv[3]);
                    double y = stod(argv[4]);
                    double z = stod(argv[5]);
                    double s = squaretriangle(x, y, z);
                    cout << "Площадь треугольника равна " << s
                         << endl;
                    return 0;
                }
            }

            if((type != "c") || (type != "t")) {
                help();
                return 1;
            }
        }
    }

    return 0;
}
