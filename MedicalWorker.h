#pragma once
#include "Person.h"
#include "Specialization.h"
#include "Observation.h"
#include <vector>

/**
 * @brief Класс MedicalWorker - представляет медицинского работника.
 *
 * Наследник Person. Хранит специализацию, должность, список наблюдений
 * и список ФИО пациентов, за которыми наблюдает.
 */
class MedicalWorker : public Person
{
private:
    /**
     * @brief Специализация медработника.
     */
    Specialization specialization;

    /**
     * @brief Должность медработника.
     */
    std::string position;

    /**
     * @brief Список записей о наблюдениях.
     */
    std::vector<Observation> observations;

    /**
     * @brief Список ФИО пациентов, за которыми наблюдает.
     */
    std::vector<std::string> observedPatients;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    MedicalWorker();

    /**
     * @brief Конструктор с параметрами.
     * @param name - ФИО медработника.
     * @param specialization - специализация.
     * @param position - должность.
     * @param id - ID (0 для автогенерации).
     */
    MedicalWorker(const std::string &name,
                  const Specialization &specialization,
                  const std::string &position,
                  const int id = 0);

    /**
     * @brief Получить специализацию.
     * @return Ссылка на объект Specialization.
     */
    const Specialization &getSpecialization() const noexcept;

    /**
     * @brief Получить должность.
     * @return Ссылка на строку с должностью.
     */
    const std::string &getPosition() const noexcept;

    /**
     * @brief Получить список наблюдений.
     * @return Ссылка на вектор наблюдений.
     */
    const std::vector<Observation> &getObservations() const noexcept;

    /**
     * @brief Получить список ФИО наблюдаемых пациентов.
     * @return Ссылка на вектор строк с ФИО.
     */
    const std::vector<std::string> &getObservedPatients() const noexcept;

    /**
     * @brief Добавить запись о наблюдении.
     * @param observation - запись наблюдения.
     */
    void addObservation(const Observation &observation);

    /**
     * @brief Добавить пациента в список наблюдаемых.
     * @param patientName - ФИО пациента.
     */
    void addObservedPatient(const std::string &patientName);

    /**
     * @brief Проверить, наблюдает ли медработник за пациентом.
     * @param patientName - ФИО пациента.
     * @return true, если наблюдает, иначе false.
     */
    bool observesPatient(const std::string &patientName) const noexcept;

    /**
     * @brief Получить информацию о медработнике.
     * @return Строка с ID, ФИО, специализацией и должностью.
     */
    std::string getInfo() const override;
};
