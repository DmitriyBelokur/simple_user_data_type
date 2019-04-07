#include <iostream>

union MyUnion {
  double x;
  int y;
  char ch;
};

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

/*Type punning implementation */
struct Vector3D {
  int x;
  int y;
  int z;
};

struct Vector2d {
  int x;
  int y;
};

int main(int argc, char const *argv[]) {
  
  union {
    int value1;
    double value2;
  };
  
  std::cout << sizeof(MyUnion) << std::endl;

  value1 = 20;

  std::cout << "Unnamed union value1 = "<< value1 << " value2 = " << value2 <<std::endl;

  MyUnion my_union;
  my_union.ch = 'a';

  std::cout << "My union ch = "<< my_union.ch << " " << my_union.y << std::endl;

  my_union.x = 20.2;
  
  std::cout << "My union x = "<< my_union.x << " " << my_union.ch << std::endl;

  UnionRepresentation un_rep;
  un_rep.data_holder = UnionRepresentation::INT;
  un_rep.a = 20;
  selectPrintUnionType(un_rep);

  un_rep.data_holder = UnionRepresentation::STRUCT;
  un_rep.people = {"Ivo Bobul", 55};
  selectPrintUnionType(un_rep);

  /*Type punning=================================*/
  union _ {
   Vector3D vec3d;
   Vector2d vec2d;
  };
  
  Vector3D vector3d{1, 2, 3};

  Vector2d vector2d;
  // получим ошибку компиляции несовместимость типов 
  // vector2d = vector3d;

  vector2d = ((union _ *)&vector3d)->vec2d;
  std::cout << vector2d.x << " " << vector2d.y << std::endl;
  return 0;
}
