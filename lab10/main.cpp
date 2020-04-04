#include <iostream>

using std::cout;
using std::endl;

// [x] Write try/catch block
// [x] Put runtime_error in functionC
// [ ] Write object with constructor/destructor message

class MyObj {
    public:
        MyObj() {
            cout << "Construction obj object" << endl;
        }

        ~MyObj() {
            cout << "Destruction of object" << endl;
        }
    private:
};

void functionC()
{
    throw std::runtime_error("FunctionC() threw std::runtime_error");
}

void functionB()
{
    //your code here
    cout << "Starting functionB()\n";
    functionC();
    cout << "Ending functionB()\n";
}

void functionA()
{
    try {
        functionB();
        cout << "This code should not be reached." << endl;
    } catch (std::runtime_error& e) {
        cout << "Caught an exception: " << e.what() << std::endl;

    }
    cout << "This code should be reached." << endl;
}

int main()
{
    cout << endl;
    cout << "Starting main()" << std::endl;
    functionA();
    cout << "Ended normally." << std::endl;
    return 0;
}
