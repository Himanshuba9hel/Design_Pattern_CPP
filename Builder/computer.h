#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>

#include <iostream>
#include <string>

using namespace std;

// 1. Product
class Computer
{
public:
    void setCPU(const std::string &cpu) { cpu_ = cpu; }
    void setRAM(const std::string &ram) { ram_ = ram; }
    void setStorage(const std::string &storage) { storage_ = storage; }
    void setGPU(const std::string &gpu) { gpu_ = gpu; }
    void setThunderbolt(bool hasThunderbolt) { thunderbolt_ = hasThunderbolt; }

    void displayInfo() const
    {
        std::cout << "Computer Configuration:\n"
                  << "CPU: " << cpu_ << "\n"
                  << "RAM: " << ram_ << "\n"
                  << "Storage: " << storage_ << "\n"
                  << "GPU: " << (gpu_.empty() ? "None (Integrated)" : gpu_) << "\n"
                  << "Thunderbolt Port: " << (thunderbolt_ ? "Yes" : "No") << "\n"
                  << "---------------------------\n";
    }

private:
    string cpu_ = "Unknown";
    string ram_ = "Unknown";
    string storage_ = "Unknown";
    string gpu_ = "";            // Optional
    bool thunderbolt_ = false;   // Optional
};

// 2. Builder interface
class Builder
{
public:
    virtual ~Builder() = default;

    // Mandatory steps (Pure Virtual)
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;

    // Optional steps (Default empty implementation)
    // Concrete builders only override these if the computer actually has them.
    virtual void buildGPU() {}
    virtual void buildThunderbolt() {}

    virtual Computer getResult() = 0;
};

// 3. ConcreteBuilder: Gaming Computer (Has Everything)
class GamingComputerBuilder : public Builder
{
private:
    Computer computer_;

public:
    void buildCPU() override { computer_.setCPU("High-End Gaming CPU"); }
    void buildRAM() override { computer_.setRAM("32GB DDR5"); }
    void buildStorage() override { computer_.setStorage("2TB NVMe SSD"); }

    // Overriding optional steps
    void buildGPU() override { computer_.setGPU("NVIDIA RTX 4090"); }
    void buildThunderbolt() override { computer_.setThunderbolt(true); }

    Computer getResult() override { return computer_; }
};

// 4. ConcreteBuilder: Office Computer (No GPU, No Thunderbolt)
class OfficeComputerBuilder : public Builder
{
private:
    Computer computer_;

public:
    void buildCPU() override { computer_.setCPU("Standard Office CPU"); }
    void buildRAM() override { computer_.setRAM("8GB DDR4"); }
    void buildStorage() override { computer_.setStorage("512GB SSD"); }

    // Does not override buildGPU() or buildThunderbolt()
    // The default empty implementations from the base class will be used.

    Computer getResult() override { return computer_; }
};

// 5. Director
class ComputerDirector
{
public:
    // The Director calls all steps, but optional steps will safely do
    // nothing if the concrete builder didn't override them.
    void construct(Builder &builder)
    {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
        builder.buildGPU();
        builder.buildThunderbolt();
    }
};
/*
// 6. Client

int main()
{
    ComputerDirector director;

    // Build a Gaming Computer (With GPU and Thunderbolt)
    GamingComputerBuilder gamingBuilder;
    director.construct(gamingBuilder);
    Computer gamingComputer = gamingBuilder.getResult();
    std::cout << "--- Building Gaming PC ---\n";
    gamingComputer.displayInfo();

    // Build an Office Computer (No GPU, No Thunderbolt)
    OfficeComputerBuilder officeBuilder;
    director.construct(officeBuilder);
    Computer officeComputer = officeBuilder.getResult();
    std::cout << "--- Building Office PC ---\n";
    officeComputer.displayInfo();

    return 0;
}

*/

#endif // COMPUTER_H
