#include "pch.h"
#include "CppUnitTest.h"

#include "Hospital.h"
#include "Person.h"
#include "MedicalWorker.h"
#include "Patient.h"
#include "Ward.h"
#include "Specialization.h"
#include "Observation.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HospitalTests
{
    TEST_CLASS(WardTests)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            Ward w;
            Assert::AreEqual(std::string(""), w.getNumber());
        }

        TEST_METHOD(ParameterizedConstructor)
        {
            Ward w("101");
            Assert::AreEqual(std::string("101"), w.getNumber());
        }
    };

    TEST_CLASS(SpecializationTests)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            Specialization s;
            Assert::AreEqual(std::string(""), s.getTitle());
        }

        TEST_METHOD(ParameterizedConstructor)
        {
            Specialization s("Терапевт");
            Assert::AreEqual(std::string("Терапевт"), s.getTitle());
        }
    };

    TEST_CLASS(ObservationTests)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            Observation o;
            Assert::AreEqual(std::string(""), o.getPatientName());
            Assert::AreEqual(0, o.getDays());
        }

        TEST_METHOD(GettersAndToString)
        {
            Observation o("Петров П.П.", "15.10.2023", 5);
            Assert::AreEqual(std::string("Петров П.П."), o.getPatientName());
            Assert::AreEqual(std::string("15.10.2023"), o.getDate());
            Assert::AreEqual(5, o.getDays());

            std::string s = o.toString();
            Assert::IsTrue(s.find("Петров П.П.") != std::string::npos);
        }
    };

    TEST_CLASS(PersonTests)
    {
    public:
        TEST_METHOD(DefaultConstructorHasValidId)
        {
            Person p;
            Assert::IsTrue(p.getId() > 0);
            Assert::AreEqual(std::string(""), p.getName());
        }

        TEST_METHOD(ConstructorWithExplicitId)
        {
            Person p("Петров П.П.", 42);
            Assert::AreEqual(42, p.getId());
            Assert::AreEqual(std::string("Петров П.П."), p.getName());
        }

        TEST_METHOD(GetInfo)
        {
            Person p("Сидоров С.С.", 10);
            std::string info = p.getInfo();
            Assert::IsTrue(info.find("ID: 10") != std::string::npos);
        }
    };

    TEST_CLASS(MedicalWorkerTests)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            MedicalWorker w;
            Assert::IsTrue(w.getId() > 0);
            Assert::IsTrue(w.getObservations().empty());
            Assert::IsTrue(w.getObservedPatients().empty());
        }

        TEST_METHOD(ObservedPatientsAndObservesPatient)
        {
            MedicalWorker w("Иванов И.И.", Specialization("Терапевт"), "Врач");
            Assert::IsFalse(w.observesPatient("Петров П.П."));

            w.addObservedPatient("Петров П.П.");
            w.addObservedPatient("Сидорова А.С.");

            Assert::IsTrue(w.observesPatient("Петров П.П."));
            Assert::IsFalse(w.observesPatient("Кузнецов Д.А."));
        }

        TEST_METHOD(AddAndGetObservations)
        {
            MedicalWorker w("Иванов И.И.", Specialization("Терапевт"), "Врач");
            w.addObservation(Observation("Петров П.П.", "15.10.2023", 5));
            w.addObservation(Observation("Сидорова А.С.", "20.10.2023", 3));

            Assert::AreEqual(size_t(2), w.getObservations().size());
        }
    };

    TEST_CLASS(PatientTests)
    {
    public:
        TEST_METHOD(ParameterizedConstructor)
        {
            Patient p("Петров П.П.", Ward("101"), "Иванов И.И.");
            Assert::AreEqual(std::string("101"), p.getWard().getNumber());
            Assert::AreEqual(std::string("Иванов И.И."), p.getDoctorName());
        }

        TEST_METHOD(DiagnosesAndHasDiagnosis)
        {
            Patient p("Петров П.П.", Ward("101"), "Иванов И.И.");
            Assert::IsFalse(p.hasDiagnosis("Гастрит"));

            p.addDiagnosis("Гастрит");
            Assert::IsTrue(p.hasDiagnosis("Гастрит"));
            Assert::IsFalse(p.hasDiagnosis("ОРВИ"));
        }
    };

    TEST_CLASS(HospitalTests)
    {
    public:
        TEST_METHOD(DefaultConstructorEmptyCollections)
        {
            Hospital h;
            Assert::IsTrue(h.getWorkers().empty());
            Assert::IsTrue(h.getPatients().empty());
        }

        TEST_METHOD(DuplicateIdRejectedAcrossLists)
        {
            Hospital h;
            MedicalWorker w1("Иванов И.И.", Specialization("Терапевт"), "Врач", 100);
            MedicalWorker w2("Петров П.П.", Specialization("Хирург"), "Врач", 100);
            Patient pSameId("Сидоров С.С.", Ward("101"), "Иванов И.И.", 100);

            h.addWorker(w1);
            h.addWorker(w2);
            h.addPatient(pSameId);

            Assert::AreEqual(size_t(1), h.getWorkers().size());
            Assert::AreEqual(size_t(0), h.getPatients().size());
        }

        TEST_METHOD(AddWardDeduplication)
        {
            Hospital h;
            h.addWard(Ward("101"));
            h.addWard(Ward("101"));
            h.addWard(Ward("102"));

            Assert::AreEqual(size_t(2), h.getWards().size());
        }

        TEST_METHOD(PrintWorkersForPatientOutput)
        {
            Hospital h;

            MedicalWorker w1("Иванов И.И.", Specialization("Терапевт"), "Врач");
            w1.addObservedPatient("Петров П.П.");

            MedicalWorker w2("Смирнов О.В.", Specialization("Хирург"), "Врач");
            w2.addObservedPatient("Сидорова А.С.");

            h.addWorker(w1);
            h.addWorker(w2);

            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream captured;
            std::cout.rdbuf(captured.rdbuf());

            h.printWorkersForPatient("Петров П.П.");

            std::cout.rdbuf(oldCout);
            std::string output = captured.str();

            Assert::IsTrue(output.find("Иванов И.И.") != std::string::npos);
            Assert::IsTrue(output.find("Смирнов О.В.") == std::string::npos);
        }

        TEST_METHOD(PrintPatientsByWardOutput)
        {
            Hospital h;
            h.addPatient(Patient("Петров П.П.", Ward("101"), "Иванов И.И."));
            h.addPatient(Patient("Кузнецов Д.А.", Ward("102"), "Смирнов О.В."));

            std::streambuf* oldCout = std::cout.rdbuf();
            std::ostringstream captured;
            std::cout.rdbuf(captured.rdbuf());

            h.printPatientsByWard("101");

            std::cout.rdbuf(oldCout);
            std::string output = captured.str();

            Assert::IsTrue(output.find("Петров П.П.") != std::string::npos);
            Assert::IsTrue(output.find("Кузнецов Д.А.") == std::string::npos);
        }
    };
}