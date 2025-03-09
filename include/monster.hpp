#include <string>
class Monster {
public:
  Monster() : name("") {}
  Monster(std::string name) : name(name) {}

  void sayHello();
private:
  std::string name;
};