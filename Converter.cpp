#include <iostream>
#include <stdexcept>

using namespace std;

class LengthConverter {
private:
    int feet;
    int inches;

public:
    LengthConverter(int ft, int in) : feet(ft), inches(in) {}

    double convertToCentimeters() const {
        return (feet * 30.48) + (inches * 2.54);
    }
};

int main() {
    int feet, inches;

    while (true) {
        try {
            cout << "Enter length in feet: ";
            cin >> feet;
            if (feet < 0 || !cin) {
                throw runtime_error("Invalid input. Length must be a non-negative integer.");
            }

            cout << "Enter length in inches: ";
            cin >> inches;
            if (inches < 0 || !cin) {
                throw runtime_error("Invalid input. Inches must be a non-negative integer.");
            }

            LengthConverter converter(feet, inches);
            double centimeters = converter.convertToCentimeters();

            cout << "Equivalent length in centimeters: " << centimeters << " cm" << endl;
            break;  // Exit the loop if input is valid
        } catch (const exception& e) {
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Error: " << e.what() << " Please try again." << endl;
        }
    }

    return 0;
}
