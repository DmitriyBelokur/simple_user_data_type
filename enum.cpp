#include <iostream>

enum Day {
  Monday = 1,
  Tuesday = 90,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};


enum Alpabet : char {
  A = 'a',
  B,
  C,
  D
};

enum class /*struct*/ SafeEnum : unsigned {
  FIRST = 1,
  SECOND = 2,
  THIRD = 3,
  FOURTH = 4
};

enum class byte : unsigned char {};

int main(int argc, char const *argv[]) {
  std::cout << Monday << " next day is " << Day::Tuesday << std::endl;
  std::cout << Alpabet::A << " next letter is " << Alpabet::B << std::endl;

  Day day = Monday;

  day = Day::Saturday;

  int days = day;

  std::cout << "Day is " << days << " Using enum variable " << day << std::endl;

  // такое компилироваться не будет, т.к. элемент перечисления это константа.
  // Day::Monday = 35;
  // будет ошибка компиляции, из за несоответсвия типов
  // day = Alpabet::A;
  // получим ошибку преобразования int в Day
  // day = 40;

  day = Monday;
  std::cout << (day + 1) << std::endl;

  /*=====================Scoped enum=============================*/
  // получим ошибку компиляции что неизвестное имя
  // std::cout << FIRST << std::endl;
  // и такое даже работать не будет
  // std::cout << SafeEnum::FIRST << std::endl;
  std::cout << static_cast<int>(SafeEnum::FIRST) << std::endl; // а так ок
  // будет также ошибка компиялции так как запрещено преобразование
  // unsigned value = SafeEnum::FIRST;
  SafeEnum safe_enum = SafeEnum::FIRST;

  // тоже получим ошибку компиялции что несоответсвия типов
  // std::cout << safe_enum << std::endl;

  // арифметика для ограниченых обастью видимотстью переменных 
  // auto new_safe_enum = safe_enum + 1;

  SafeEnum safe{90};
  byte b {42};

  // получим ошибку преобразования типа
  // int bytei = b;

  return 0;
}
