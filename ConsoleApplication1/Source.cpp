/*
ИСКЛЮЧЕНИЯ - EXCEPTIONS


{
Правосторонние значения -  КОРОТКОЖИВУЩИЕ ОБЕКТЫ (правосторонние ссылки) value это результаты работы функции, конструктора, операторов.
( В него записать ничего нельзя )
Левосторонние заняения -  ДОЛГОЖИВУЩИЕ ОБЪЕКТЫ (левосторонние ссылки) rvelue Это переменные. const  которые могут принимать значения 
(В которые можем что либо поместить ) ТОесть  

rvalue - это безименные объекты, маложивущие, левосторонние объекты. 
lvalue - это именные аргументы. Которые 
&& - Это ссылки на правосторонние объекты (Он не предписывает уничтожать переданные объекты)

Конструктор переноса - Введен для того чтобы отдельно обрабатывать КОРОТКОЖИВУЩИЕ ОБЪЕКТЫ

}

Система исключкений - нужна для того чтобы можно было заранее обнаружить ошибки и произвести изменение в коде/
Ошибка к чужой памяти доступа- 
User Define - Это можно уддловить с помощю try catch () 

Errors

Runtime   User Define

Ошибки бываю двух типов Runtime и  User Define  ОТЛИЧИЕ!!!
User Define - Это исключения которые определяются пользователем( Они могут обрабатываться программистом)
Runtime - ошибки времени выполнения которые генерируются самой программой (Она не позволит работать программе) - Она не сможет быть обработана Программистом


Extentions - это возможность отследить ошибку Runtime на этапе программирования!! (Можно прописать что где произошло)
ОГРАНИЧЕНИЯ - (рекомендательные ) Классы Extentions не должны работать с КУЧЕЙ запрещено Категорически . Это операторы new и Delete

Runtime
Domain - это ошибки связанные с доменной логикой (Если запрещено, что не входит в доменную логику, то выдаст ошибку( Допустим не подходят ТИПЫ)
Logic - Это массивы (Отрицательных размеров)

В месте где возникла ошибка (Это исключение нельзя обрабатывать) Нельзя обрабатывать свои исключения.

пример: Вызываем функцию (и  try catch ()  - обрабатываем исключения)
Обработка Исключений Это мобуль который вшивается в нашу программу. 

Программа многопоточная Полностью преостанавливает работу пока необработает его!!!(хотя каждый поток является отдельным подпроццессом)
Библиотека Rnoti зваляет возвращать  (Это означает, что если исходное выражение имеет значение true, то rnoti вернет false, и наоборот.)
Пример использования:

#include <iostream>
using namespace std;

int main() {
    int x = 5;
    if (x == 5) {
        cout << "x is 5" << endl;
    } else {
        cout << "x is not 5" << endl;
    }
    if (!rnoti(x)) {
        cout << "x not equal to 5" << endl;
    } else {
        cout << "x equal to 5" << endl;
    }
}
В этом примере мы проверяем, равно ли x 5, используя оператор ==.
Затем мы используем rnoti для инвертирования значения x и сравниваем его с 5.
Если x равно 5, то мы выводим сообщение “x is 5”, а если нет, то выводим “x is not 5”.
Затем мы проверяем, не равно ли x 5 с помощью оператора != и выводим соответствующее сообщение.

В C++ есть ключевое слово noexcept, которое может использоваться для указания, 
что функция не вызывает исключений. Это позволяет компилятору оптимизировать 
код и избежать ненужных проверок на исключение.

Вот пример использования ключевого слова noexcept:

#include <exception>

void my_function() noexcept {
    // Здесь может быть любой код, который не вызывает исключений
}

int main() {
    try {
        my_function();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
Здесь функция my_function объявлена как noexcept, что означает, что она не может вызывать исключений.
Если функция вызывает исключение, компилятор выдаст ошибку.

// В  конструкторах такого тиапа  && тоесть перемещения exception - писать нельзя ( Исключения кидать нельзя ) 
Конструктор вызываетс я Перед  throw - Бросать(тобешь Исключения)


Такьтика применения   try catch () 
 В блоках int main(){}  Если что то пошло не так то пишем непосредственно в данной функции ловим.
 Весь код в  try catch () оборачиват не нужно. 

 если в определенном месте возникают ошибки то там ловим ошибку try catch ()

 throw - мы прописываем там где точно есть исключение . 

*/
#include<iostream>
#include<exception> // У данной библиотеки конструкторов нет . Надо унаследоваться у нашего класса и передать исключение 
#include<string>

#include<format> // Позволяет создавать  форматированные строки Со стандарта С++17 или 20 Он нужен для ускорения формирования строк.

// noexcept - При данной записи конструкция throw не генерирует сключения 

//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//}
//
//int main() {
//	setlocale(LC_ALL, "Rus");
//
//    try {
//        std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);
//    }
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
//
//    // в  catch (...) - лучше писать так чтобы уловить непредвиденную ошибку 
//    //(...) - может принять все. Вообще  (...) - это Элипсис(Принимает любое количество чего либо)
//
//	return 0;
//}

// Используем блок try catch ()  с дополнительным catch (int &val) { //  (int val)  - используем конкретный параметр НО ПО ССЫЛКЕ!!! 

//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//
//    try {
//        std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);
//    }
//    catch (int &val) {
//        std::cerr << " somefing wrong with error code  "<< val << std::endl;
//    }
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
    // в  catch (...) - лучше писать так чтобы уловить непредвиденную ошибку 
    //(...) - может принять все. Вообще  (...) - это Элипсис(Принимает любое количество чего либо)


// exception  Используем в конструктор принимает в тексовую строчка massage Всю инфу (Имя функции, название аргументов, указатель объектов) 
// Но строго определено что он не работает только с С - шными строками c std::string 

//void F00(int a) {
//    throw std::exception((std::string("massage") + std::to_string(a)).c_str());
//}
//
//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//
//    try {
//        std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);
//    }
//    catch (int& val) {
//        std::cerr << " somefing wrong with error code  " << val << std::endl;
//    }
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
//
//    return 0;
//}



//void F00(int a) {
//    throw std::exception((std::string("massage") + std::to_string(a)).c_str());
//}
//
//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//
//    try {
//        std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);
//    }
//    catch (int& val) {
//        std::cerr << " somefing wrong with error code  " << val << std::endl;
//    }
//    catch (std::exception& ex) {  //  Тут ссылка на наше исключение
//        std::cerr << ex.what(); // Метода what() Что случилось.
//    }
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
//
//    return 0;
//}

//
//void F00(int a) {
//    if (a < 0) {
//        throw std::runtime_error("arg \"a\" whith ERROR code");
//    }
//
//    int* p = new int[a]; // Это будет Runtime ошибка но обработать Исключением не сможем!!!
//
//    throw std::exception((std::string("massage") + std::to_string(a)).c_str());
//
//    delete[]p;
//}
//
//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//   
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//
//    try {
//        std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);
//    }
//    catch (int& val) {
//        std::cerr << " somefing wrong with error code  " << val << std::endl;
//    }
//    catch (std::exception& ex) {  //  Тут ссылка на наше исключение
//        std::cerr << ex.what(); // Метода what() Что случилось.
//    }
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
//
//    return 0;
//}


//// Сам throw так же эффективно работает как return !!!!
//void F00(int a) {
//    std::string word{ "qwertyuiop" };
//    if (a < 0) {
//        throw std::runtime_error("arg \"a\" whith ERROR code");
//    }
//
//    int* p = new int[a]; // Это будет Runtime ошибка но обработать Исключением не сможем!!!
//
//    // Тут переместили delete в  if (true)  
//
//    if (true) {  
//        delete[]p;
//
//        throw std::exception((std::string("massage") + std::to_string(a)).c_str()
//        );
//    }
//}
//
//int NoexeptSumm(int a, int b)noexcept {
//    throw 1;
//    return a + b;
//}
//// throw -  прерывает работу функции досрочно 
//int ExeptDivide(int a, int b) {
//    if (!b) {
//        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
//    }
//
//    return a / b;
//
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    // Тут мы используем Точку Останова И  вписываем функцию Тоесть в том блоке кода который собираемся отслеживать. А именно F00(-1); 
//    // Когда дошли до ошибки то мы можем дальше отследить и поставить точку останова в нужную нам функцию
//    try {
//       /* std::cout << NoexeptSumm(6, 2);
//        std::cout << NoexeptSumm(1, 0);*/
//        F00(-1);
//    }
//
//    // Поменяем их catch местами Гланое и Дочернее.
//
//    catch (std::exception& ex) {  //  Тут ссылка на наше исключение
//        std::cerr << ex.what(); // Метода what() Что случилось.
//    }
//
//    catch (int& val) {
//        std::cerr << " somefing wrong with error code  " << val << std::endl;
//    }
//    
//    catch (...) {
//        std::cerr << "Whote somefing wrong: ";
//    }
//
//    return 0;
//}


// Есть еще одно Исключение Для функций созданий Указателей _make_unique  make_shared  Все Функции не будут вызывать работку с кучей
//Он работает просто с указателямию Если мы работает с _make_exception  Он будет работать с указателями. (но это немного потребует расход Памяти!!!)

// Сам throw так же эффективно работает как return !!!!
void F00(int a) {
    std::string word{ "qwertyuiop" };
    if (a < 0) {
        throw std::runtime_error("arg \"a\" whith ERROR code");
    }

    int* p = new int[a]; // Это будет Runtime ошибка но обработать Исключением не сможем!!!

    // Тут переместили delete в  if (true)  

    if (true) {
        delete[]p;

        throw std::exception((std::string("massage") + std::to_string(a)).c_str()
        );
    }
}

int NoexeptSumm(int a, int b)noexcept {
    throw 1;
    return a + b;
}
// throw -  прерывает работу функции досрочно 
// b wasn't be 0
int ExeptDivide(int a, int b) {
    if (!b) {
        throw 1; // Конструкция throw принимает любой тип в качестве аргумента 
    }

    return a / b;

}

int main() {
    setlocale(LC_ALL, "Rus");
    // Тут мы используем Точку Останова И  вписываем функцию Тоесть в том блоке кода который собираемся отслеживать. А именно F00(-1); 
    // Когда дошли до ошибки то мы можем дальше отследить и поставить точку останова в нужную нам функцию
    try {
        /* std::cout << NoexeptSumm(6, 2);
         std::cout << NoexeptSumm(1, 0);*/
        F00(-1);
    }

    // Поменяем их catch местами Гланое и Дочернее.
    // Это указатели на exception_ptr b и ссылки на это.

    catch (std::exception& ex) {  //  Тут ссылка на наше исключение
        std::cerr << ex.what(); // Метода what() Что случилось.
    }

    catch (int& val) {
        std::cerr << " somefing wrong with error code  " << val << std::endl;
    }

    catch (...) {
        std::cerr << "Whote somefing wrong: ";
    }

    return 0;
}