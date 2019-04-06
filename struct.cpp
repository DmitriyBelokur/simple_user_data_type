#include <iostream>

struct Point2D {
  double x;
  double y;
};

struct Person {
  const char *fio;
  unsigned int age;
};

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

struct Point2DDefaultInit {
  double x = 0.0;
  double y = 0.0;
};

void addColor(unsigned char r, unsigned char g, unsigned char b) {
  struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
  } rgb {r, g, b};

  std::cout << (int)rgb.r << (int)rgb.g << (int)rgb.b << std::endl;
}


int main(int argc, char const *argv[]) {
  // будет ошибка компиляции
  // Point2D point (2.2, 3.2);
  // будет содержать неинециализированные мемберы
  Point2D point;
  std::cout << point.x << " " << point.x << std::endl;

  point.x = 2.2;
  point.x = 4.2;

  Point2D point2 = Point2D();
  Point2D point3 {2.2};
  Person person {"Mykola Solyanko", 21};

  // получим ошибку компиляции так как нельза выводить на печать нашу структуру
  // std::cout << point << std::endl;
  std::cout << point2.x << " " << point2.y << std::endl;
  std::cout << person.fio << " " << person.age << std::endl;

  Point2DDefaultInit point_def;
  std::cout << point_def.x << " " << point_def.x << std::endl;

  Point2DDefaultInit point_def_with_list_init {3.0, 10.5}; // возможно не будет работать до с++17
  std::cout << point_def_with_list_init.x << " " << point_def_with_list_init.y << std::endl;

  Group gr{{"Ivanov Ivan", 21}, {}, nullptr};
  Projects owa{"OWA Project", "active"};
  gr.list_project = &owa;
  Projects device{"Device managment", "inactive"};
  gr.list_project = &device;

  std::cout << gr.list_project->name << " " << (*gr.list_project).status << std::endl;

  point2 = point;
  std::cout << point2.x << " " << point2.y << std::endl;

  // будет ошибка компиляции что типы не совпадают
  // point3 = owa;
  addColor(255, 0, 0);
  return 0;
}
