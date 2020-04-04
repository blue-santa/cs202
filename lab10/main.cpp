#include <iostream>

// [ ] Put runtime_error in functionC
// [ ] Write object with constructor/destructor message
// [ ] Write try/catch block

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
    try {
    } catch(std::runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
    }
}

void functionB()
{
  //your code here
  std::cout << "Starting functionB()\n";
  functionC();
  std::cout << "Ending functionB()\n";
}

void functionA()
{
  // your code here
  functionB();
  // your code here
  std::cout << "Caught an exception: " << e.what() << std::endl;
  // your code here
}

int main()
{
  std::cout << "Starting main()" << std::endl;
  functionA();
  std::cout << "Ended normally." << std::endl;
  return 0;
}
