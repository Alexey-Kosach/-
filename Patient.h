#pragma once
#include "Person.h"
#include "Ward.h"
#include <vector>
#include <string>

/**
 * @brief Класс Patient - представляет пациента больницы.
 *
 * Наследник Person. Хранит палату, ФИО лечащего врача и список диагнозов.
 */
class Patient : public Person
{
private:
    /**
     * @brief Палата пациента.
     */
    Ward ward;

    /**
     * @brief ФИО лечащего врача.
     */
    std::string doctorName;

    /**
     * @brief Список диагнозов пациента.
     */
    std::vector<std::string> diagnoses;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Patient();

    /**
     * @brief Конструктор с параметрами.
     * @param name - ФИО пациента.
     * @param ward - палата.
     * @param doctorName - ФИО лечащего врача.
     * @param id - ID (0 для автогенерации).
     */
    Patient(const std::string &name,
            const Ward &ward,
            const std::string &doctorName,
            const int id = 0);

    /**
     * @brief Получить палату.
     * @return Ссылка на объект Ward.
     */
    const Ward &getWard() const noexcept;

    /**
     * @brief Получить ФИО лечащего врача.
     * @return Ссылка на строку с ФИО.
     */
    const std::string &getDoctorName() const noexcept;

    /**
     * @brief Получить список диагнозов.
     * @return Ссылка на вектор строк с диагнозами.
     */
    const std::vector<std::string> &getDiagnoses() const noexcept;

    /**
     * @brief Добавить диагноз.
     * @param diagnosis - название диагноза.
     */
    void addDiagnosis(const std::string &diagnosis);

    /**
     * @brief Проверить наличие диагноза у пациента.
     * @param diagnosis - название диагноза.
     * @return true, если диагноз есть, иначе false.
     */
    bool hasDiagnosis(const std::string &diagnosis) const noexcept;

    /**
     * @brief Получить информацию о пациенте.
     * @return Строка с ID, ФИО, палатой и врачом.
     */
    std::string getInfo() const override;
};
