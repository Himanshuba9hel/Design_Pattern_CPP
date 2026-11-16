#ifndef MEMORYMANAGEMENT_H
#define MEMORYMANAGEMENT_H

#include <string>
#include <atomic>

class IdGenerator
{
public:
    static unsigned int getId() {
        static std::atomic<unsigned int> counter{1};
        return counter.fetch_add(1, std::memory_order_relaxed);
    }
};

class MemoryManagement
{
public:
    MemoryManagement(std::string &message);
    MemoryManagement();
    ~MemoryManagement();
protected:
    unsigned int id_;
private:
    std::string message_;
public:
    void readMessage();
    std::string &getMessage(){ return message_; }
    void setMessage(std::string &message){  message_ = message; }

    void sendMessageTo(MemoryManagement* receiver);
    void receiveMessageFrom(MemoryManagement* sender);

};



#endif // MEMORYMANAGEMENT_H
