#include<iostream>

using namespace std;

enum COLOR { RED, BLUE, WHITE};

//первый класс
class Airplane
{
public:
    Airplane(COLOR, int, int);
    virtual ~Airplane() { cout << "Airplane destructor...\n"; };

    virtual COLOR GetColor() const { return itsColor; }
    virtual int GetMaxSpeed() const { return itsMaxSpeed; }
    virtual int GetCrew() const { return itsCrew; }

    virtual void SetMaxSpeed(int speed) { itsMaxSpeed = speed; }
    virtual void SetCrew(int crew) { itsCrew = crew; }


private:
    COLOR itsColor;
    int itsMaxSpeed;
    int itsCrew;
};

//конструктор Airplane
Airplane::Airplane(COLOR color, int maxSpeed, int crew):itsColor(color), itsMaxSpeed(maxSpeed), itsCrew(crew)
{
    cout << "Airplane constructor...\n";
}

//второй класс
class Rocket
{
public:
    Rocket(COLOR, int, int, int);
    virtual ~Rocket() { cout << "Rocket destructor...\n"; };

    virtual COLOR GetColor() const { return itsColor; }
    virtual int GetMaxSpeed() const { return itsMaxSpeed; }
    virtual int GetCrew() const { return itsCrew; }
    virtual int GetCarrying() const { return itsCarrying; }

    virtual void SetMaxSpeed(int speed) { itsMaxSpeed = speed; }
    virtual void SetCrew(int crew) { itsCrew = crew; }
    virtual void SetCarrying(int carrying) { itsCarrying = carrying; }

private:
    COLOR itsColor;
    int itsMaxSpeed;
    int itsCrew;
    int itsCarrying;
};

//конструктор Rocket
Rocket::Rocket(COLOR color, int maxSpeed, int crew, int carrying):itsColor(color), itsMaxSpeed(maxSpeed), itsCrew(crew), itsCarrying(carrying)
{
    cout << "Rocket constructor...\n";
}

//кдасс потомок
class JetPlane : public Airplane, public Rocket
{
public:
    JetPlane(bool, COLOR, int, int, int); // конструктор JetPlane со всеми унаслед. параметрами
    virtual ~JetPlane() { cout << "JetPlane destructor...\n"; } // деструктор
    virtual bool GetHypersonic() const { return itsHypersonic; } // новый параметр

private:
    bool itsHypersonic;
};

//конструктор JetPlane
JetPlane::JetPlane(bool hup_sonic, COLOR aColor, int maxSpeed, int crew, int carring):Airplane(aColor, maxSpeed, crew), Rocket(aColor, maxSpeed, crew, carring), itsHypersonic(hup_sonic)
{
    cout << "JetPlane constructor...\n";
}


int main()
{
    JetPlane *a10 = new JetPlane(false, RED, 1200, 1, 500);
    int jcrew = a10->::Airplane::GetCrew();
    cout << "Crew Jetplane A-10 is " << jcrew << " peaple." << endl;
    delete a10;

    return 0;
}