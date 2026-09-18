class Car {
    String model;

    // Constructor
    Car(String model) {
        // 'this.model' refers to the class variable
        // 'model' refers to the parameter
        this.model = model; 
    }

    void display() {
        System.out.println("Car Model: " + model);
    }
}


public class Main {
    public static void main(String[] args) {
        Car myCar = new Car("Tesla Model S"); // Creating an Object
        myCar.display();
    }
}