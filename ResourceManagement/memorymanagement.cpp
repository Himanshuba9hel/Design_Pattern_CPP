#include "memorymanagement.h"
#include <iostream>

MemoryManagement::MemoryManagement(std::string &message):
    message_(message)
{
    id_ = IdGenerator::getId();
    std::cout<<"Created"<<"ID: "<<id_<<", Message: "<<message_<<std::endl;
}

MemoryManagement::MemoryManagement()
{
    id_ = IdGenerator::getId();
    std::cout<<"Created"<<"ID: "<<id_<<std::endl;
}

MemoryManagement::~MemoryManagement()
{
    std::cout<<"Deleted"<<"ID: "<<id_<<", Message: "<<message_<<std::endl;
}

void MemoryManagement::readMessage()
{
    std::cout<<message_<<std::endl;
}


void MemoryManagement::sendMessageTo(MemoryManagement* receiver)
{
    receiver->receiveMessageFrom(this);
    message_.clear();
}

void MemoryManagement::receiveMessageFrom(MemoryManagement* sender)
{
    if(message_.empty()){
        setMessage(sender->getMessage());
        std::cout<<"Received Message From:"<<"ID: "<<sender->id_<<", Message (Copy it): "<<sender->getMessage()<<std::endl;
    }else {
        setMessage(sender->getMessage());
        std::cout<<"Received Message From:"<<"ID: "<<sender->id_<<", Message (Replacing it): "<<sender->getMessage()<<std::endl;
    }
}

