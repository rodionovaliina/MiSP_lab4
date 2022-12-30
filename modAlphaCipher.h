/** @file
 * @author Родионова А.А.
 * @version 1.0
 * @date 22.12.2022
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Интерфейс модуля main для шифрования методом Гронсвельда
 */
 #pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
class modAlphaCipher
{
private:
    std::wstring numAlpha =
        L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///<Алфавит русского языка, по порядку
    std::map <wchar_t,int> alphaNum; ///<ассоциативный массив 
    std::vector <int> key;  ///<Ключ
    /**
     * @brief Преобразование строка-вектор
     * @param [in] s Строка из символов
     * @return Вектор числовых значений
     */
    std::vector<int> convert(const std::wstring& s); ///<преобразование строка-вектор
     /**
     * @brief Преобразование вектор-строка
     * @param [in] v Вектор числовых значений
     * @return Строка из символов
     */
    std::wstring convert(const std::vector<int>& v); ///<преобразование вектор-строка
     /**
     * @brief Проверка и преобразование ключа
     * @details Ключ проверяется на наличие запрещённых символов и пустоту и преобразуется.
     * Строчные буквы преобразуются в заглавные
     * @warning Запрещёнными символами считаются все символы кроме букв русского языка
     * @param [in] s Строка с введёным ключом
     * @return Строка с преобразованным ключом
     * @throw cipher_error, если ключ пустой, слабый или имеет недопустимые символы
     */
    std::wstring getValidKey(const std::wstring & s); ///<проверка и преобразование ключа
    /**
     * @brief Проверка и преобразование нормального текста
     * @details Текст проверяется на пустоту и преобразуется.
     * Строчные буквы преобразуются в заглавные, запрещённые символы удаляются из текста
     * @warning Запрещёнными символами считаются все символы кроме букв русского языка
     * @param [in] s Строка с введёным текстом
     * @return Строка с преобразованным текстом
     * @throw cipher_error, если текст пустой
     */
    std::wstring getValidOpenText(const std::wstring & s); ///<проверка и преобразование нормального текста
    /**
     * @brief Проверка зашифрованного текста
     * @details Текст проверяется на пустоту и наличие запрещённых символов.
     * @warning Запрещёнными символами считаются все символы кроме букв русского языка
     * @param [in] s Строка с введёным текстом
     * @return Строка с проверенным текстом
     * @throw cipher_error, если текст пустой или содержит запрещённые символы
     */
    std::wstring getValidCipherText(const std::wstring & s); ///<проверка зашифрованного текста
public:
    modAlphaCipher()=delete; ///<запрет конструктора без параметров
    modAlphaCipher(const std::wstring& skey); ///<конструктор для установки ключа
    std::wstring encrypt(const std::wstring& open_text); ///<функция зашифрования
    std::wstring decrypt(const std::wstring& cipher_text); ///<функция расшифрования
};

class cipher_error : public std::invalid_argument
{
public:
    explicit cipher_error (const char* what_arg):std::invalid_argument(what_arg) {}
    explicit cipher_error (const std::string& what_arg):std::invalid_argument(what_arg) {}
};