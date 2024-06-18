#include <iostream>  // Включение библиотеки для работы с вводом-выводом
#include <vector>    // Включение библиотеки для использования векторов
#include <iomanip>   // Включение библиотеки для форматирования вывода

using namespace std; // Использование пространства имен std

// Функция для генерации случайного вектора байтов заданного размера
vector<unsigned char> generate_random_bytes(size_t size) {
    vector<unsigned char> bytes(size);  // Создание вектора заданного размера
    for (size_t i = 0; i < size; ++i) {
        bytes[i] = rand() % 256;  // Генерация случайного байта
    }
    return bytes;  // Возврат сгенерированного вектора байтов
}

// Функция для отображения байтов в шестнадцатеричном формате
void print_hex(const vector<unsigned char>& data) {
    for (unsigned char byte : data) {
        // Форматирование байтов в шестнадцатеричном формате
        cout << setw(2) << setfill('0') << hex << static_cast<int>(byte);
    }
    cout << dec << endl;  // Возвращение к десятичному формату и новая строка
}

// Фиктивная функция шифрования (просто копирует данные)
vector<unsigned char> encrypt(const vector<unsigned char>& plaintext, const vector<unsigned char>& key, const vector<unsigned char>& iv) {
    // На практике здесь должно быть шифрование с использованием библиотеки, такой как OpenSSL
    vector<unsigned char> ciphertext = plaintext;  // Копирование текста (в реальности тут шифрование)
    return ciphertext;  // Возврат зашифрованного текста
}

// Фиктивная функция дешифрования (просто копирует данные)
vector<unsigned char> decrypt(const vector<unsigned char>& ciphertext, const vector<unsigned char>& key, const vector<unsigned char>& iv) {
    // На практике здесь должно быть дешифрование с использованием библиотеки, такой как OpenSSL
    vector<unsigned char> plaintext = ciphertext;  // Копирование текста (в реальности тут дешифрование)
    return plaintext;  // Возврат расшифрованного текста
}

int main() {
    srand(time(0));  // Установка начального значения для генератора случайных чисел

    // Генерация случайного ключа длиной 16 байт (128 бит)
    vector<unsigned char> key = generate_random_bytes(16);
    // Генерация случайного вектора инициализации длиной 16 байт (128 бит)
    vector<unsigned char> iv = generate_random_bytes(16);

    // Исходный текст для шифрования
    string plaintext_str = "Pomogite poluchit' dopusk k ekzamenu";
    // Преобразование строки в вектор байтов
    vector<unsigned char> plaintext(plaintext_str.begin(), plaintext_str.end());

    // Шифрование исходного текста
    vector<unsigned char> ciphertext = encrypt(plaintext, key, iv);
    cout << "Зашифрованный текст: ";
    print_hex(ciphertext);  // Вывод зашифрованного текста в шестнадцатеричном формате

    // Дешифрование зашифрованного текста
    vector<unsigned char> decryptedtext = decrypt(ciphertext, key, iv);
    cout << "Расшифрованный текст: ";
    cout << string(decryptedtext.begin(), decryptedtext.end()) << endl;  // Вывод расшифрованного текста

    return 0;  // Завершение программы
}
