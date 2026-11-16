#ifndef CHATROOM_H
#define CHATROOM_H
#include <variant>

class ChatRoom
{
public:
    ChatRoom();
};

using MessageData = std::variant<std::string, int>;

class Message
{
public:
    virtual ~Message() = default;

    virtual void setMessage(const MessageData& data) = 0;
    virtual MessageData getMessage() const = 0;
};

class TextMessage : public Message
{
private:
    MessageData data_;

public:
    TextMessage() = default;
    ~TextMessage() override = default;

    void setMessage(const MessageData& data) override
    {
        // Type Safety: Enforce that TextMessage ONLY accepts strings
        if (std::holds_alternative<std::string>(data)) {
            data_ = data;
        } else {
            std::cerr << "Error: TextMessage only accepts text.\n";
        }
    }

    MessageData getMessage() const override
    {
        return data_;
    }
};

class Recipient
{
public:
    ~Recipient();
    virtual void sendMessage(Message* message) = 0;
    virtual Message* receiveMessage() = 0;
};

#endif // CHATROOM_H
