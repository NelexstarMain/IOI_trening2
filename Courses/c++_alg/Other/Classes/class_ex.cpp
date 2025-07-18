#include <iostream>
using namespace std;

class Cookie {
    private:
        int age;
    public:
        Cookie (int age){
            this->age = age;
        }
        int Getage () {
            return age;
        }
};



int main() {
    Cookie* cok1 = new Cookie(56);
    cout << "The cookie is " << cok1->Getage() << " years old" << endl;
    return 0;
}