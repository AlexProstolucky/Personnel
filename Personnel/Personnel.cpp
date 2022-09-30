#include <iostream>
#define down cout << endl;
using namespace std;

class Person 
{
protected:
    string name;
    string l_name;
    string b_day;
    string number;
public:
    Person(string n, string l, string b, string num) : name(n), l_name(l), b_day(b), number(num) { cout << "Person created" << endl; }

    Person() : Person("NULL", "NULL", "NULL", "NULL") {}
    
    virtual void set() 
    {
        string n, l, b, num;
        cout << "Input name of person: ";
        cin >> n; 
        down
        cout << "Input last name of person: ";
        cin >> l;
        down
        cout << "Input birthday of person: ";
        cin >> b; 
        down
        cout << "Input phone number of person: ";
        cin >> num;
        this->name = n;
        this->l_name = l;
        this->b_day = b;
        this->number = num;
    }
    virtual void info()
    {
        cout << "Person:" << endl;
        cout << "Name: " << name << endl;
        cout << "Last name: " << l_name << endl;
        cout << "Birthday: " << b_day << endl;
        cout << "Phone number: " << number << endl;
        down
    }
};

class Data
{
protected:
    string last_work;
    string data;
    int h_zp;
public:
    Data(string l_w, string dt, int zp) : last_work(l_w), data(dt), h_zp(zp)
    {
        cout << "Data of person created" << endl;
    }

    Data() : Data("NULL", "NULL", 0) {}

    virtual void set()
    {
        set_lastwork();
        set_data();
        set_zp();
    }

    void set_lastwork()
    {
        string l;
        cout << "Input last work: ";
        cin >> l;
        down
            this->last_work = l;
    }

    void set_data()
    {
        string d;
        cout << "Input data : ";
        cin >> d;
        down
            this->data = d;
    }

    
    void set_zp() 
    {
        int zp;
        cout << "Input hourly fee : ";
        cin >> zp;
        down
        this->h_zp = zp;
    }

    virtual void info()
    {
        cout << "Data:" << endl;
        cout << "Last work: " << last_work<< endl;
        cout << "Data: " << data <<endl;
        cout << "Hourly fee: "<< h_zp << endl;
    }
};

class IT_Programer : public Person, public Data
{
private:
    int projects;
public:
    IT_Programer(string n, string l, string b, string num, string l_w, string dt, int zp, int p) : Person(n, l, b, num), Data(l_w, dt, zp), projects(p) {}

    IT_Programer() : IT_Programer("NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0) {}

    void set() override
    {
        Person::set();
        Data::set();
        down
        set_p();
    }

    void set_p() 
    {
        int p;
        cout << "Specify the number of projects: ";
        cin >> p;
        down
        this->projects = p;
    }

    void info() override 
    {
        Person::info();
        Data::info();
        cout << "Projects: " << projects << endl;
    }
};
int main()
{
    IT_Programer person("Vova", "Penteleyichuk", "03.30.2007", "+380951685325", "Project manager", "24.02.2022", 20, 15);
    person.info();
}