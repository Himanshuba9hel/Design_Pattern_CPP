#ifndef FILESYSTEMCOMPONENT_H
#define FILESYSTEMCOMPONENT_H
#include <iostream>
#include <vector>

class FileSystemComponent {
public:
    virtual void display() const = 0;
};
class File : public FileSystemComponent {
public:
    File(const std::string& name, int size)
        : name(name)
        , size(size)
    {
    }

    void display() const override
    {
        std::cout << "File: " << name << " (" << size
                  << " bytes)" << std::endl;
    }

private:
    std::string name;
    int size;
};
class Directory : public FileSystemComponent {
public:
    Directory(const std::string& name)
        : name(name)
    {
    }

    void display() const override
    {
        std::cout << "Directory: " << name << std::endl;
        for (const auto& component : components) {
            component->display();
        }
    }

    void addComponent(FileSystemComponent* component)
    {
        components.push_back(component);
    }

private:
    std::string name;
    std::vector<FileSystemComponent*> components;
};

#endif // FILESYSTEMCOMPONENT_H
