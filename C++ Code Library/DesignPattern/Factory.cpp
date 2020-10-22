class Shape{
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape{

    // Shape interface
public:
    void draw() override
    {
        std::cout << "Drawing Rectangle";
    }
};

class Circle : public Shape{

    // Shape interface
public:
    void draw() override
    {
        std::cout << "Drawing Cirle";
    }
};

class ShapeFactory{
public:
    static Shape * createShape(std::string type){
        if(type == "RECTANGLE"){
            return new Rectangle();
        }
        else if(type == "CIRCLE"{
            return new Circle();
        }
        return new Rectangle();        
    }
};

int main(){
    Shape * rectangle = ShapeFactory::createShape("RECTANGLE");
    Shape * circle = ShapeFactory::createShape("CIRCLE");

    rectangle->draw();
    circle->draw();
}
