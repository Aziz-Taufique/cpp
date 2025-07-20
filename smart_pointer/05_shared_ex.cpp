#include <bits/stdc++.h>
using namespace std;
#include <memory>

class Tyre
{
public:
    void doRepair()
    {
        cout << "Reparing tyre..." << endl;
    }
};

class Car
{
private:
    shared_ptr<Tyre> wheel1;

public:
    Car()
    {
        wheel1 = make_shared<Tyre>(new Tyre());
    }
    shared_ptr<Tyre> getWheel1()
    {
        return wheel1;
    }
};

int main()
{
    Car car1;
    shared_ptr<Tyre> wheel1 = car1.getWheel1();
    wheel1->doRepair();

    cout << "Use count of shared_ptr: " << wheel1.use_count() << endl;

    return 0;
}