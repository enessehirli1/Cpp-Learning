#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <string_view>

class Patient;

class Doctor
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
    Doctor(std::string_view name)
        : m_name {name} {}

    void addPatient(Patient& patient);
    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);
    const std::string& getName() const { return m_name; }
};

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

    void addDoctor(const Doctor& d)
    {
        m_doctor.emplace_back(d);
    }

public:
    Patient(std::string_view name)
        : m_name {name} {}

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
    friend void Doctor::addPatient(Patient& patient);

    const std::string& getName() const { return m_name; }
};


void Doctor::addPatient(Patient& patient)
{
    // Our doctor will add this patient
    m_patient.push_back(patient);

    // and the patient will also add this doctor
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
    if (doctor.m_patient.empty())
    {
        out << doctor.m_name << " has no patients right now";
        return out;
    }

    out << doctor.m_name << " is seeing patients: ";
    for (const auto& patient : doctor.m_patient)
        out << patient.get().getName() << ' ';

    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
    if (patient.m_doctor.empty())
    {
        out << patient.getName() << " has no doctors right now";
        return out;
    }

    out << patient.m_name << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctor)
        out << doctor.get().getName() << ' ';

    return out;
}

int main()
{
    // Create a Patient outside the scope of the Doctor
    Patient dave{ "Dave" };
    Patient frank{ "Frank" };
    Patient betsy{ "Betsy" };

    Doctor james{ "James" };
    Doctor scott{ "Scott" };

    james.addPatient(dave);

    scott.addPatient(dave);
    scott.addPatient(betsy);

    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout << dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << '\n';

    return 0;
}












/*
class Teacher
{ 
private:
    std::string m_name{}; 
public:
    Teacher(std::string_view name)
        : m_name{ name } {}
    
    std::string_view getName() const { return m_name; }

};


class Department
{ 
private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
    Department() = default;

    void add(const Teacher& t)
    {
        m_teachers.emplace_back(t);
    }

    friend std::ostream& operator<<(std::ostream& out, const Department& d)
    {
        out << "Departments: ";

        for (const auto& e : d.m_teachers)
        {
            out << e.get().getName() << " ";
        }

        out << '\n';
        return out;
    }


};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}
*/