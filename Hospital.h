#pragma once
#include "Person.h"
#include "MedicalWorker.h"
#include "Patient.h"
#include "Ward.h"
#include "Specialization.h"
#include <vector>
#include <string>

/**
 * @brief Класс Hospital - представляет больницу.
 *
 * Хранит коллекции людей, медработников, пациентов, палат и специализаций.
 * Предоставляет методы для добавления сущностей и вывода отчётов.
 */
class Hospital
{
private:
    /**
     * @brief Коллекция базовых объектов Person.
     */
    std::vector<Person> persons;

    /**
     * @brief Коллекция медработников.
     */
    std::vector<MedicalWorker> workers;

    /**
     * @brief Коллекция пациентов.
     */
    std::vector<Patient> patients;

    /**
     * @brief Коллекция палат.
     */
    std::vector<Ward> wards;

    /**
     * @brief Коллекция специализаций.
     */
    std::vector<Specialization> specializations;

    /**
     * @brief Проверить наличие объекта с заданным ID во всех коллекциях.
     * @param id - проверяемый ID.
     * @return true, если объект с таким ID уже есть.
     */
    bool containsId(const int id) const;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Hospital() = default;

    /**
     * @brief Деструктор.
     */
    ~Hospital() = default;

    /**
     * @brief Добавить базового человека.
     * @param person - объект Person.
     */
    void addPerson(const Person &person);

    /**
     * @brief Добавить медработника.
     * @param worker - объект MedicalWorker.
     */
    void addWorker(const MedicalWorker &worker);

    /**
     * @brief Добавить пациента.
     * @param patient - объект Patient.
     */
    void addPatient(const Patient &patient);

    /**
     * @brief Добавить палату (с дедупликацией по номеру).
     * @param ward - объект Ward.
     */
    void addWard(const Ward &ward);

    /**
     * @brief Добавить специализацию (с дедупликацией по названию).
     * @param specialization - объект Specialization.
     */
    void addSpecialization(const Specialization &specialization);

    /**
     * @brief Получить коллекцию базовых людей.
     */
    const std::vector<Person> &getPersons() const noexcept;

    /**
     * @brief Получить коллекцию медработников.
     */
    const std::vector<MedicalWorker> &getWorkers() const noexcept;

    /**
     * @brief Получить коллекцию пациентов.
     */
    const std::vector<Patient> &getPatients() const noexcept;

    /**
     * @brief Получить коллекцию палат.
     */
    const std::vector<Ward> &getWards() const noexcept;

    /**
     * @brief Получить коллекцию специализаций.
     */
    const std::vector<Specialization> &getSpecializations() const noexcept;

    /**
     * @brief Вывести сведения о всех медицинских работниках.
     */
    void printWorkers() const;

    /**
     * @brief Вывести сведения о медработниках, наблюдающих за пациентом.
     * @param patientName - ФИО пациента.
     */
    void printWorkersForPatient(const std::string &patientName) const;

    /**
     * @brief Вывести сведения о всех пациентах.
     */
    void printPatients() const;

    /**
     * @brief Вывести сведения о пациентах у определённого медработника.
     * @param workerName - ФИО медработника.
     */
    void printPatientsForWorker(const std::string &workerName) const;

    /**
     * @brief Вывести сведения о пациентах в указанной палате.
     * @param wardNumber - номер палаты.
     */
    void printPatientsByWard(const std::string &wardNumber) const;
};
