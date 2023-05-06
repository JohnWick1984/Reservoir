#include <iostream>
#include <string>

using namespace std;

class Reservoir {
public:
    // explicit конструктор
    explicit Reservoir(const string& name = "", double width = 0.0, double length = 0.0, double depth = 0.0, const string& type = "")
        : name_(name), width_(width), length_(length), depth_(depth), type_(type) {}

    // конструктор копирования
    Reservoir(const Reservoir& other)
        : name_(other.name_), width_(other.width_), length_(other.length_), depth_(other.depth_), type_(other.type_) {}

    // деструктор
    ~Reservoir() {}

    // методы для получения значений полей
    const string& getName() const { return name_; }
    double getWidth() const { return width_; }
    double getLength() const { return length_; }
    double getDepth() const { return depth_; }
    const string& getType() const { return type_; }

    // методы для установки значений полей
    void setName(const string& name) { name_ = name; }
    void setWidth(double width) { width_ = width; }
    void setLength(double length) { length_ = length; }
    void setDepth(double depth) { depth_ = depth; }
    void setType(const string& type) { type_ = type; }

    // константные методы-члены
    double getVolume() const { return width_ * length_ * depth_; }
    double getSurfaceArea() const { return width_ * length_; }
    bool isSameType(const Reservoir& other) const { return type_ == other.type_; }

private:
    string name_;
    double width_;
    double length_;
    double depth_;
    string type_;
};

// пример использования класса Reservoir
int main()


{
    setlocale(0, "");
    Reservoir lake("Онежское озеро", 53.5, 136.2, 127.1, "озеро");
    cout << "Название: " << lake.getName() << endl;
    cout << "Ширина: " << lake.getWidth() << endl;
    cout << "Длина: " << lake.getLength() << endl;
    cout << "Максимальная глубина: " << lake.getDepth() << endl;
    cout << "Тип: " << lake.getType() << endl;
    cout << "Объем: " << lake.getVolume() << endl;
    cout << "Площадь водной поверхности: " << lake.getSurfaceArea() << endl;

    Reservoir pond("Рыбное озеро", 25.0, 40.0, 4.0, "пруд");
    if (lake.isSameType(pond)) {
        cout << "Водоемы относятся к одному типу." << endl;
    }
    else {
        cout << "Водоемы относятся к разным типам." << endl;
    }

    return 0;
}
