#include <iostream>
#include <vector>
#include <functional>
#include "Hospital.h"
#include "Person.h"
#include "MedicalWorker.h"
#include "Patient.h"
#include "Ward.h"
#include "Specialization.h"
#include "Observation.h"

int main() {
    system("chcp 65001 > nul");

    Hospital hospital;

    hospital.addWard(Ward("101"));
    hospital.addWard(Ward("102"));
    hospital.addSpecialization(Specialization("Терапевт"));
    hospital.addSpecialization(Specialization("Хирург"));

    MedicalWorker w1("Иванов Иван Иванович", Specialization("Терапевт"), "Врач-терапевт");
    w1.addObservedPatient("Петров Пётр Петрович");
    w1.addObservedPatient("Сидорова Анна Сергеевна");
    w1.addObservation(Observation("Петров Пётр Петрович", "15.10.2023", 5));

    MedicalWorker w2("Смирнов Олег Викторович", Specialization("Хирург"), "Врач-хирург");
    w2.addObservedPatient("Петров Пётр Петрович");
    w2.addObservation(Observation("Петров Пётр Петрович", "20.10.2023", 3));

    hospital.addWorker(w1);
    hospital.addWorker(w2);

    Patient p1("Петров Пётр Петрович", Ward("101"), "Иванов Иван Иванович");
    p1.addDiagnosis("Гастрит");

    Patient p2("Сидорова Анна Сергеевна", Ward("101"), "Иванов Иван Иванович");
    p2.addDiagnosis("ОРВИ");

    Patient p3("Кузнецов Дмитрий Андреевич", Ward("102"), "Смирнов Олег Викторович");
    p3.addDiagnosis("Перелом");

    hospital.addPatient(p1);
    hospital.addPatient(p2);
    hospital.addPatient(p3);

    hospital.printWorkers();
    hospital.printPatients();
    hospital.printWorkersForPatient("Петров Пётр Петрович");
    hospital.printPatientsForWorker("Иванов Иван Иванович");
    hospital.printPatientsByWard("101");

    Person basePerson("Базовый человек", 999);
    MedicalWorker derivedWorker("Алексеев Алексей Алексеевич",
        Specialization("Терапевт"), "Врач", 1000);

    std::vector<std::reference_wrapper<const Person>> baseCollection;
    baseCollection.push_back(std::cref(basePerson));
    baseCollection.push_back(std::cref(derivedWorker));

    std::cout << "\n=== Коллекция базового типа ===" << std::endl;
    for (const Person& item : baseCollection)
        std::cout << item.getInfo() << "\n" << std::endl;

    return 0;
}
