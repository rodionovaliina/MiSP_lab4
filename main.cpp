/** @file
 * @author Родионова А.А.
 * @version 1.0
 * @date 22.12.2022
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Интерфейс модуля main для шифрования методом Гронсвельда
 */
#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout<<"key="<<key<<endl;
    wcout<<Text<<endl;
    wcout<<cipherText<<endl;
    wcout<<decryptedText<<endl;
    if (Text == decryptedText)
        wcout<<"Ok\n";
    else
        wcout<<"Error\n";
}
int main(int argc, char **argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc); // установка глобальной локали
    check(L"Hello",L"World");
    check(L"hi",L"friend");
    return 0;
}