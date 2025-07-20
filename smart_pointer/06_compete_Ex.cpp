#include <bits/stdc++.h>
using namespace std;
#include <memory>

class Tyre
{
public:
    void doRepair(int wheelNumber)
    {
        cout << "Repairing Tyre " << wheelNumber << "..." << endl;
    }
};

class Car
{
private:
    shared_ptr<Tyre> wheel1;
    shared_ptr<Tyre> wheel2;
    shared_ptr<Tyre> wheel3;
    shared_ptr<Tyre> wheel4;

public:
    Car()
    {
        wheel1 = make_shared<Tyre>();
        wheel2 = make_shared<Tyre>();
        wheel3 = make_shared<Tyre>();
        wheel4 = make_shared<Tyre>();
    }

    shared_ptr<Tyre> getWheel1() { return wheel1; }
    shared_ptr<Tyre> getWheel2() { return wheel2; }
    shared_ptr<Tyre> getWheel3() { return wheel3; }
    shared_ptr<Tyre> getWheel4() { return wheel4; }
};

int main()
{
    Car car1;

    shared_ptr<Tyre> frontLeft = car1.getWheel1();
    shared_ptr<Tyre> frontRight = car1.getWheel2();
    shared_ptr<Tyre> rearLeft = car1.getWheel3();
    shared_ptr<Tyre> rearRight = car1.getWheel4();

    frontLeft->doRepair(1);
    frontRight->doRepair(2);
    rearLeft->doRepair(3);
    rearRight->doRepair(4);

    cout << "\nUse count of front left tyre: " << frontLeft.use_count() << endl;
    cout << "Use count of front right tyre: " << frontRight.use_count() << endl;
    cout << "Use count of rear left tyre: " << rearLeft.use_count() << endl;
    cout << "Use count of rear right tyre: " << rearRight.use_count() << endl;

    return 0;
}
