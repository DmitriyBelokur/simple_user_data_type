# Пользовательские типы данных
## Структуры (struct)
Структура это група элементов данных объединена вместе под одним именем. Элементы этой структуры называються членами этой структуры. Мемберы этой структуры могут быть разными типами. Еще структуры называют агрегированным типом данных, т.е. тип который групирирует множетсво индивидуальных элементов вместе имееющий какоето логическое обоснование, т.е. выразить этот тип как сущность. Т.е. к примеру у нас есть сущность человек, а вот мы есть конкретный экземпляр человека со своим именем и другими данными.
Так зачем нужны структуры, если например характеристики человека можно описать там например 4 переменными(Имя, фамилия, гражданство, пол и т.д.). Но это ок если один человек, а если их 2 то нам надо объявить еще таких 4 переменных, ну и т.д. Ну и в конце концов, настанет тот момент когда мы ошибимся в записях этой переменной. Конечно можно объявить например 4 массива, каждый из которых будет хранить одно из характеристик человека, но опять же путаница в индексах, плюс если добавим еще одну характеристику описывающую человека, то нам надо создать еще один массив. Но вообщем стоп. Для этого в языке есть прекрасное свойство как пользовательський тип данных в данном контектсе это структура, в которой мы объвляем необходимые нам характеристики. Дальше создаем экземпляр этой структуры как обычную переменную и работаем. Если мы решили добавить еще одно поле в структуру, то нам ничего не надо помнить ничего дополнительного созвать ненужно.

### Объявдление структуры
Объвляение структуры начинаеться с ключевого слова `struct` за котрорым идет называние структуры это и есть ее тип, и идет назовем ее телом структуры в котром указываеються мемберы структуры через `;`. Все просто

```cpp
struct StructName {
  список мемберов структуры;
};
```

Важно не забывать что объявление структуры заканчиваеться `;`.
Список мемберов что это. Это перечень переменных которые будут описывать структуру разделенных `;`. Мемберами может быть как встроенные типы языка, указатели, массивы и также объекты структур(почему бы нет это же та же саммая переменная что и привычные нам встроенные переменные).

Давайте нарисуем пример объявление структуры
```cpp
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

```cpp
...
const unsigned WORKER_SIZE_GROUP = 10;
struct Group {
  Person pm;
  Person worker[WORKER_SIZE_GROUP];
};

```
Как видно из примера мы просто объявили структуры команда или група, в которой в качестве мемберов используються другие структуры. Из этого вытикает важное свойство структур это то что структура это составной тип.
В стандартной библиотеке определена важная структура с которой работаю очень много разработчиков да используеться в стандартной библиотеке это структура `pair`. Она содержит в  себе только два поля `first` и `second`, как бы все просто но важность ее непередать словами.


Давайте объявим переменную пользовательского типа или проще сказать создадим. Сначало я покажу как создавать переменные до появления с++11. Ок, объявляеться переменная точно также как и обычные переменные, могут они быть как и константными так и указателями.

```cpp

  // будет содержать неинециализированные мемберы
  Point2D point;
  // а теперь каждый мембер вручную проинициализируем
  point.x = 2.2;
  point.x = 4.2;

  Point2D point2 = Point2D();
  Point2D point3 {2.2, 3.2};
  Person person {"Mykola Solyanko", 21};

  Group gr{{"Ivanov Ivan", 21}, {}};

```

Как видимм что ничего сложного в инициализации структур нет, все как и обычными переменными. `point2` инициализируеться как и обычный встроенный тип 'int()' который инициализирует переменную дефолтным значением. `point3` и `person` инициализируеться так называемым списком инициализации. А вот переменная `point` инициализируеться муссором, и может также каждый отдельный мембер структуры инициализировать явно. Переменная `gr` выглядит немного сурово, но вспомните как вы инициализировали двумерный массив, т.е. вы каждым списком инициализации инициализирвали каждое пространство, точно и тут также только вы каждым списком инициализации инициализирует вложенную структуру.

Пример структуры с указателями

```cpp
struct Projects {
  const char* name;
  const char* status;
};

const unsigned WORKER_SIZE_GROUP = 10;
struct Group {
  Person pm;
  Person worker[WORKER_SIZE_GROUP];
  Projects* list_project;
};

...
```
А как же получить доступ к мемберам структуры. Тут все еще проще доступ к конкретному мемберу просходит с помощью символа `.`, т.е. указыветься объект структуры и через точку мембер который нас интересует. Большинство современных IDE предлагают перечень мемберов которые определены к структуре.
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

Структуры также применяються еще при передачи параметра в функцию, как возможность избавиться от большого количества параметров (согласно Core Guidelines), как и строгой типизации. Т.е. назвать объект `CoordX` и `CoordY` и при этом будет трудно ошибиться в координатах. Согласно Другой еще важной особеностью, это как пример стандартного объекта pair, возможность как вернуть несколько параметров с функции, так передать множество значений одной структурой. Но надо не забывать о том что структура может занимать много памяти, и передача по значению не есть уже хорошим вариантом. Т.е. чаще применяють передачу через указатель или по константной ссылке или обыной ссылке.

Другим такими маленькими применениями по применению структуры есть следующее
```cpp
typedef struct {
  int x;
  int y;
} IntCoordXY;
``` 

Это аналогично
```cpp
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

Очень важной особеностью появилось так назвываемый `struct binding` наччиная с с++17. В чем идея, идея очень простая, например если мы захотим пердать вссе поля структуры соответсвующим переменным такого же типа как элементы структуры, то нам необходимо было бы объвялть отдельно переменные, а потом этой переменной присваивать поле объевкта, ну вообщем не очень интересно. То в с++17 появилась привазяка полей структуры к переменным.
```cpp
#include <iostream>

struct StructBuinding {
  int a;
  double b;
  int ch;
};

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

## Перечисления
Перечисления есть также еще один вид пользовательских типов, содержащий набор именованых интегральных констант, известные как перечисления.
Мы до этого работали уже с перечислениями когда создавали константы вместо магических чисел в коде, при использовании их в `switch` операторе выбора. Или как размер массива. Все эти перечисления называються unscoped, т.е. не пренадлежащей своей области видимости, имя констаны распостраняеться на всю окружающую область видимости где определено перечисления. Как это понять, очень просто, например если мы берем структуру и у нее есть поле `x` то чтобы получить доступ к этому полю нам надо создавать например объект и говорить компилятору что это поле принадлежит этой структуре. Но все иначе с перечислением. Доступ к перечислению возможен без имени типа перечисления и создания объекта.
Ну приступим к объвлению перчисления.

```cpp
enum Day {
  Monday = 1,
  Tuesday,
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
...
```

Как видим объявление unscoped перечисления состоит из:

1. Имени индетификатора типа перечисления, которое как мы видели с предыдущих занятий может быть опущено. Если имя опущено, то мы не сможем создать переменную этого перечисления. Но в отличии от структур, которые также можно создавать как не именованные, значения перечисления распостраняеться на всю область видимости где объявлено перечисления, т.е. использования значения перечисления без имени типа.
2. В перечислении можно указывать тип констант указанных в перечислении, по умолчанию это `int`, но можно уточнить какого типа будут элементы перечисления. Но типом может быть только интегральный тип. Все элемнты должны быть одного типа, т.е. неможет быть что один элемент это беззнаковое целое, второй это знаковый.
3. Список элементов. Список элементов перечисления указываеться через запятую, имена перечислений должны быть уникальными в данном перечислении. Можно указать значение перечисления явно как с элементом `Monday`, а можно и не указывать. Правило такое что если не указывать значение перчисления, то первому элементу присваиваеться 0, а следующему значение предыдущего плюс 1. Т.е. если мы указали как в примере с `Monday` 1, то следующий `Tuesday` будет 2, и т.д. Но если бы мы явно указали например элементу `Thursday` 10, то элемент `Friday` был бы равено 11.

Элемент перечисления неявно преобразовуваеться в целое, но элементу перечисления нельзя присвоеть значение, т.к. элемент есть константа. Но если создать переменную перечисления то ей можно присваивать разные элементы перечисления.

Доступ к элементу перечисленияя возможен несколькими способами:

1. Это просто указав имя элемента. Например как с перечислением Day, можно указать просто `Monday`
2. Используя оператор разширения области видимости для типа перечисления, `Day::Monday`. Если не указать компилятору в каком скопе искать элемент перечисления, он будет это делать во всех внешних областях, пока не найдет, а если ненайдет, то выдаст ошибку компиляции, а если мы укажем явно область видимости, то мы таким образом облегчим жизнь компилятору
3. Это объявить переменную типа перечисления, и присваивать ей элемент перечисления. Если попытаться присвоить переменной одного перечисления дугой переменной, то получим ошибку несоответствия типов. Но если сделать это с целочисленной переменной, то все будет ок. Т.е. использования переменой типа перечисления, есть более безопасней, чем использовать целочисленую переменную.

```cpp
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

```

Стоит также упомянуть что мы элемент перечисления можем конвертнуть в целочислую переменную, а вот целочисленую переменную в пеерчисление не можем.
Также можно использовать арифметику над перечислением, и операторы отношения. Но логики в ней особо нет. Т.к. например у нас элемент может равняться 1, а следующий 90. То при применении сложения над первым элементом мы получим 2, а хотя такого элемента не существует.

Ок. Но проблема этих unscoped перечислений, в том что они, как было сказано ранее распотраняют свои элементы на всю область видимости в которой было объявлено перечисления. Начиная с С++ появилось новое понятие это scoped перечисление. Т.е. как видно с названия, элемент перечисления ограничываеться только своей областью перечисления в которой мы его определили. Т.е. для предыдущих перечислений, мы могли ссылатся на имя `Monday` без указания типа перечисления, то с ограниченными перечислениями, нам необходимо указать элемент перечисления только применив к ниму тип перечисления.
Важно еще  то что ограниценные областью видимости перечисления нельзя неявно преобразовать в целое.

```cpp
enum class /*struct*/ SafeEnum : unsigned {
  FIRST = 1,
  SECOND = 2,
  THIRD = 3,
  FOURTH = 4
};
...
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

  // арифметика для ограниченых обастью видимотстью переменных запрещена 
  // auto new_safe_enum = safe_enum + 1;
   SafeEnum safe{90};
```

Как видим из примера при объявлении scoped enum добавляеться только ключевое слово `class` или `struct`. Но при использовании уже scapoed enum есть много отличий.

1. Нельзя без имени типа перечисления сослаться на элемент перечисления.
2. Ошибка при преобразовании в тип int. Только применив явное преобразование.
3. Нельзя вывполнить арифметику

Но есть и больший минус что при опредедении переменной ей можно присвоить неизвестное интегральное значение, как в примере выше с переменной `safe`. Т.е. мы ей присволи значение 90, хотя такого значения в ее перечислении нет.

Важной но не упомянутой применением перечислений это есть установка битовых флагов. Которое очень часто применяеться в коде.

## Объединения

Идея объединения очень проста. Объединения это еще один из пользовательских типов данных где все переменные объединения разделяют в один момент времени одну область памяти. Причем размер объединения соответсвует самому большому типу поля объединения, который способен предстваить все возможные значения полей объединения.
Ок, пошли дальше. Объединение также как структура и перечисления начинаеться с ключевого слова `union` и имеет идентификатор, который может быть опущен в случае неименованого объедиения, являющийся типом объявленого объедиения. А дальше идет список полей объедиения.
```cpp
#include <iostream>

union MyUnion {
  double x;
  int y;
  char ch;
};

int main(int argc, char const *argv[]) {
  
  std::cout << sizeof(MyUnion) << std::endl;
  return 0;
}
```

Как видно из выше описаного примера, можно объвлять как именованный так и не именнованое объединения внутри тела функции. Если вывести размер объединения `MyUnion` то получим размер 8байт, т.е. размер самого большего поля данных объедиения.

Ок, а как же запись. Согласно стандарту в объедиение в один момент времени можно записать и считывать только одно поле, и время жизни поля продолжаеться пока мы не захотим записать другое знаение в другое поле. Чтение в поле в которое не было совершена запись значения являеться не определенным. Т.е. если мы записали например в поле `а` значение 10, то если мы попытаемся прочесть значение с поля `b`, то получим неопределенное поведение

```cpp
  value1 = 20;

  std::cout << "Unnamed union value1 = "<< value1 << " value2 = " << value2 <<std::endl;

  MyUnion my_union;
  my_union.ch = 'a';

  std::cout << "My union ch = "<< my_union.ch << " " << my_union.y << std::endl;

  my_union.x = 20.2;
  
  std::cout << "My union x = "<< my_union.x << " " << my_union.ch << std::endl;
```

Как видно из примера выше, доступ к полям неименованого объедиения происходит по имени поля, а вот доступ уже к именованому, необходимо создать переменную этого типа. Только без инициализации, компилятор не поймет что вам надо инициализировать, и дальше идет обращение к полю объединения. Как видно объединение может в один момент времени хранить только одно значение.

Но иногда возникает задача какую переменную сейчас держит(представляет) объдинение, для этого делают следующее

```cpp
struct People {
  const char *name;
  int  age;
};

struct UnionRepresentation {
  enum {
    INT = 1,
    FLOAT,
    STRUCT
  } data_holder;
  union {
    int a;
    double f;
    People people;
  };
};

void print (int a) {
  std::cout << "INT = " << a << std::endl;
}

void print (double d) {
  std::cout << "DOUBLE = " << d << std::endl;
}

void print (const People& people) {
  std::cout << "PEOPLE  name is  " << people.name << " Age is " << people.age << std::endl;
}

void selectPrintUnionType(const UnionRepresentation& union_rep) {
    switch (union_rep.data_holder) {
     case UnionRepresentation::INT: {
       print(union_rep.a);
       break;
     }
     case UnionRepresentation::FLOAT: {
       print(union_rep.f);
       break;
     }
     case UnionRepresentation::STRUCT: {
       print(union_rep.people);
       break;
     }
     default:
       break;
    }
}

int main() {
  UnionRepresentation un_rep;
  un_rep.data_holder = UnionRepresentation::INT;
  un_rep.a = 20;
  selectPrintUnionType(un_rep);

  un_rep.data_holder = UnionRepresentation::STRUCT;
  un_rep.people = {"Ivo Bobul", 55};
  selectPrintUnionType(un_rep);
  return 0;
}

Как видим мы объявили структуру `UnionRepresentation` в которой определили поле перечисление указывающее какой сейчас тип держит перечисление. И дальше выводим на печать в зависимости от установленого типа, значение на экран.

Объединения служат большей частью для хранения памяти. Т.е. в отличие от структуры где для каждого поля выделяеться память, объедиенияе хранит только одно значение, а память выделяеться для самого большого поля объедиения.