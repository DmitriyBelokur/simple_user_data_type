# Пользовательские типы данных
## Структуры (struct)
Структура это група элементов данных объединена вместе под одним именем. Элементы этой структуры называються членами этой структуры. Мемберы этой структуры могут быть разными типами. Еще структуры называют агрегированным типом данных, т.е. тип который групирирует множетсво индивидуальных элементов вместе имееющий какоето логическое обоснование, т.е. выразить этот тип как сущность. Т.е. к примеру у нас есть сущность человек, а вот мы есть конкретный экземпляр человека со своим именем и другими данными.
Так зачем нужны структуры, если например характеристики человека можно описать там например 4 переменными(Имя, фамилия, гражданство, пол и т.д.). Но это ок если один человек, а если их 2 то нам надо объявить еще таких 4 переменных, ну и т.д. Ну и в конце концов, настанет тот момент когда мы ошибимся в записях этой переменной. Конечно можно объявить например 4 массива, каждый из которых будет хранить одно из характеристик человека, но опять же путаница в индексах, плюс если добавим еще одну характеристику описывающую человека, то нам надо создать еще один массив. Но вообщем стоп. Для этого в языке есть прекрасное свойство как пользовательський тип данных в данном контектсе это структура, в которой мы объвляем необходимые нам характеристики. Дальше создаем экземпляр этой структуры как обычную переменную и работаем. Если мы решили добавить еще одно поле в структуру, то нам ничего не надо помнить ничего дополнительного созвать ненужно.

### Объявдление структуры
Объвляение структуры начинаеться с ключевого слова `struct` за котрорым идет называние структуры это и есть ее тип, и идет назовем ее телом структуры в котром указываеються мемберы структуры через `;`. Все просто

```
struct StructName {
  список мемберов структуры;
};
```

Важно не забывать что объявление структуры заканчиваеться `;`.
Список мемберов что это. Это перечень переменных которые будут описывать структуру разделенных `;`. Мемберами может быть как встроенные типы языка, указатели, массивы и также объекты структур(почему бы нет это же та же саммая переменная что и привычные нам встроенные переменные).

Давайте нарисуем пример объявление структуры
```
struct Point2D {
  double x;
  double y;
};

struct Person {
  const char *fio;
  unsigned int age;
};
```

Выше мы объявили две структуры одну для хранения кооординат, а вторая это характеристики какого либо человека. Это называеться объвлением!!!! Мы видим что после имени структуры мы перечисляем список параметров этой структуры, который может быть разных типов. Структура содержит только два вещественных мембера координаты `x и y`. Тогда как структура `Person` хранит два разнородных мембера один С-строку, а второй это целочисленный мембер хранящий возраст человека.
Другой важной особеностью структур то что они могут в себе содержать другие структуры. И также можно объвлять массивы структур, которые очень полезны при считываннии данных с БД или других например форматов межсетевого взаимодействия(например json, yml, xml и т.д.).

```
...
constexpr unsigned WORKER_SIZE_GROUP = 10;
struct Group {
  Person pm;
  Person worker[WORKER_SIZE_GROUP];
};

```
Как видно из примера мы просто объявили структуры команда или група, в которой в качестве мемберов используються другие структуры. Из этого вытикает важное свойство структур это то что структура это составной тип.
В стандартной библиотеке определена важная структура с которой работаю очень много разработчиков да используеться в стандартной библиотеке это структура `pair`. Она содержит в  себе только два поля `first` и `second`, как бы все просто но важность ее непередать словами.


Давайте объявим переменную пользовательского типа или проще сказать создадим. Сначало я покажу как создавать переменные до появления с++11. Ок, объявляеться переменная точно также как и обычные переменные, могут они быть как и константными так и указателями.

```cpp
  // будет ошибка компиляции
  // Point2D point (2.2, 3.2);

  // будет содержать неинециализированные мемберы
  Point2D point;
  point.x = 2.2;
  point.x = 4.2;

  Point2D point2 = Point2D();
  Point2D point3 {2.2, 3.2};
  Person person {"Mykola Solyanko", 21};

  Group gr{{"Ivanov Ivan", 21}, {}};

```

Как видимм что ничего сложного в инициализации структур нет, все как и обычными переменными. `point2` инициализируеться как и обычный встроенный тип 'int()' который инициализирует переменную дефолтным значением. `point3` и `person` инициализируеться так называемым списком инициализации. А вот переменная `point` инициализируеться муссором, и может также каждый отдельный мембер структуры инициализировать явно. Переменная `gr` выглядит немного сурово, но вспомните как вы инициализировали двумерный массив, т.е. вы каждым списком инициализации инициализирвали каждое пространство, точно и тут также только вы каждым списком инициализации инициализирует вложенную структуру.


Структуры точно также как и функции можно делать предварителое объявление просто это называеться как `forward declaration`. Идея заключается в том что если мы используем указатель в структуре на другую струтуру, то нам не объязательно нужно знать полный размер этой структуры, ведь указатель это просто адресс и делает арифметику он только с количеством байт, а вот при использовании, т.е. записи и считывания данных со структуры нам нужен полный тип структуры, т.е. определение структур, т.к. компилятору надо знать сколько байт надо записать или сосчитать. Т.е. при применении forward declaration мы просто сылаемся на этот тип, т.е. говорим что есть такой тип, а вот когда нам надо получить доступ к члену структуры тогда нам надо полное опредение структуры. Тоже касаеться и для ссылки

```cpp
struct Projects;

constexpr unsigned WORKER_SIZE_GROUP = 10;
struct Group {
  Person pm;
  Person worker[WORKER_SIZE_GROUP];
  Projects* list_project;
};

struct Projects {
  const char* name;
  const char* status;
};
...
```

Как видим с выше приведенного примера мы выше сделали forward declaration структуры `Project` и в структуре `Group` мы объвили указатель на структуру `Project`. Если бы мы объявили `Projects list_project;`, то получили бы ошибку компиляции что необходимо полное определение структуры `Project`

Ну объявление и определение это хорошо. А как же получить доступ к мемберам структуры. Тут все еще проще доступ к конкретному мемберу просходит с помощью символа `.`, т.е. указыветься объект структуры и через точку мембер который нас интересует. Большинство современных IDE предлагают перечень мемберов которые определены к структуре.
Но с указателями на структуру неомного по другому. Если у нас есть указатель на объект структуры то доступ к полю класса можно сделать двумя способами. Первый это использовать оператор `->` и второй это разыменовать указатель и через точку обратиться к конккретному мемберу, но тут есть одно важное замечание разменование необходимо взять в круглые скобочки. Т.к. приоритет операции `.` выше чем `*`.

```cpp
  Group gr{{"Ivanov Ivan", 21}, {}, nullptr};
  Projects owa{"OWA Project", "active"};
  gr.list_project = &owa;
  Projects device{"Device managment", "inactive"};
  gr.list_project = &device;

  std::cout << gr.list_project->name << " " << (*gr.list_project).status << std::endl;
```

Хотелось бы понять а какой же размер структуры, мы знаем что размер например `int` это не меньше 4 байт, размер массива это количество элементов умноржено на размер элемента в байтах. Так какой же размер структуры. Тут все насамом деле очень сложно. Компилятор принимает так называемое выравнивание, это не требование компилятора это больше требование процессора. Т.е. процессор за одну машиную инструкцию читает машинное слово, например на 32х разрядных машинах это 4 байт. Т.е. вместо например чтения 4 байт по 1 байту процессор сделает 4 операций чтения выполнит одну. Еще раз вот ссылки о выравнивании можно почитать подробно

https://ru.stackoverflow.com/questions/435726/%D0%92%D1%8B%D1%80%D0%B0%D0%B2%D0%BD%D0%B8%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85

https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/

Давайте посмотрим быстрый пример

```cpp
#include <iostream>

struct Byte24 {
  char a;
  long int b;
  int c;
};

struct Byte16 {
  char a;
  int b;
  long int c;
};

int main(int argc, char const *argv[]) {
  std::cout << sizeof(Byte24) << " " << sizeof(Byte16) << std::endl;
  return 0;
}

```

Такой код выведит на экран 24 байта и 16 байт. Вопрос откуда такие цифры?
Если просумировать структуру `Byte24` то получим 1 байт + 8 байт + 4 байт, что в итоге это 13 (тот же подсчет и для тсруктуры `Byte16`). Но не 16 не 24 как то не получаеться. Весь сахар в том как компилятор выравнивает в памяти структуру. Т.е. как он делает оптимизиреут под машинное слово каждое поле, для удобства доступа к нему. Компилятор добавляет так называемые падинги между полями, т.е дополнительные байты под машинное слово
Давайте рассшифруем для первой структуры получаем 1 байт(переменная а) + 7 байт падинга + 8 байт (переменная b) + 4 байт(переменная c) + 4 байт падинга, получаем 24. Ок получили первое понимание структуры
Для второй структуры 1 байт(переменная а) + 4 байта (для переменной b) + 3 байта падинга + 8 байт для переменной и того 16 байт.
Из выше перечисленного с размером структуры можно немного получить печаль, применив к ней указатель. Т.е. стандартом гарантировано что при применении адреса к объекту структуры мы гарантировано получим указатель на первый элемент. А вот при дальнейшей адресации с указателем мы можем получить печальку из за применении выравнивания. Поэтому будте осторожни)

С приходом нового стандарта появилась новая такая фича структур это возможность инициализации полей структуры при объявлении самой структуры.

```cpp
struct Point2DDefaultInit {
  double x = 0.0;
  double y = 0.0;
};
...
  Point2DDefaultInit point_def; // это эквивалентно с point_def = Point2DDefaultInit();
  std::cout << point_def.x << "" << point_def.x << std::endl;

  Point2DDefaultInit point_def_with_list_init {3.0, 10.5}; // возможно не будет работать до с++17
  std::cout << point_def_with_list_init.x << " " << point_def_with_list_init.y << std::endl;

```

Как видим из примера выше если мы до этого писали структуру без инициализации полей, и когда мы создавали структуры без инициализирующего списка, то получали при выводе полей муссор, то теперь у нас в таком случае явно будут указаны значения по умолчанию. Но если как видим из примера объявление объекта `point_def_with_list_init` можно еще явно указывать список параметров в списке инициализации. Но правда такое расширение может не работать до с++17

Структуры можно присваивать друг другу толь одного типа. При этом происходит копирование их полей как в с простыми переменными. Т.е. происходит побитовое копирование.
Пример
```cpp

  point2 = point;
  std::cout << point2.x << " " << point2.y << std::endl;

  // будет ошибка компиляции что типы не совпадают
  // point3 = owa;

```

но можно применить магию каламбура типов. Но не желательно

Структуры также применяються еще при передачи параметра в функцию, как возможность избавиться от большого количества параметров (согласно Core Guidelines), как и строгой типизации. Т.е. назвать объект `CoordX` и `CoordY` и при этом будет трудно ошибиться в координатах. Согласно Другой еще важной особеностью, это как пример стандартного объекта pair, возможность как вернуть несколько параметров с функции, так передать множество значений одной структурой. Но надо не забывать о том что структура может занимать много памяти, и передача по значению не есть уже хорошим вариантом. Т.е. чаще применяють передачу через указатель или по константной ссылке или обыной ссылке.

Другим такими маленькими применениями по применению структуры есть следующее
```
typedef struct {
  int x;
  int y;
} IntCoordXY;
``` 

Это аналогично
```
struct IntCoordXY{
  int x;
  int y;
};

```

Разница в том что это есть наследия языка С, т.е раньше в С когда мы создаем объект структуры, нам необходимо возле типа структуры писать ключевое слово `struct`. То таким образом пытались дать тип структури, без ключевого слова `struct` (`typedef` это алиас для типа, т.е. мы даем новое имя типа, например `typedef int Int;`)

Еще одним возможностью структуры есть создание переменой сразу после объявления структуры
```cpp

struct MyStruct {
  int a;
  int b;
} my_struct;

```

И дальше в коде можно использовать переменную my_struct как объект структуры для доступа к полям структуры. Зачем такое нужно, а нужно это для того что есть еще одна особеность это неименнованные структуры, т.е. структуру можно объявлять внутри функции, и вместо того чтобы давать тип этой структуре мы просто создаем объект этой структуры и работаем с ним
```cpp
void addColor(unsigned char r, unsigned char g, unsigned char b) {
  struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
  } rgb {r, g, b};

  std::cout << rgb.r << rgb.g << rgb.b << std::endl;
}
```
Раньше такое писали когда небыло лямбд для написания каких либо компараторов.

Очень важной особеностью появилось так назвываемый `struct binding` наччиная с с++17. В чем идея, идея очень простая, например если мы захотим пердать вссе поля структуры соответсвующим переменным такого же типа как элементы структуры, то нам необходимо было бы объвялть отдельно переменные, а потом этой переменной присваивать поле объевкта, ну вообщем не очень интересно. То в с++17 появилась привазяка полей структуры к переменным.
```cpp
#include <iostream>

struct StructBuinding {
  int a;
  double b;
  int ch;
};

// g++ -std=c++1z -Wall -pedantic struct_buinding.cpp
int main(int argc, char const *argv[]) {
  StructBuinding struct_buinding {10, 20.3, 'A'};

  std::cout << struct_buinding.a << " "
            << struct_buinding.b << " "
            << struct_buinding.ch
            << std::endl;

  auto[val_a, val_b, val_c] = struct_buinding;

  std::cout << val_a << " "
            << val_b << " "
            << val_c
            << std::endl;

  return 0;
}

```

Также можно применять биндинг и к переменным, но это не очень интерсно, т.к. массивы могут быть большими. И переменные в этом связывании могут быть по ссылке