#include <string>
#include <iostream>
#include <memory>
#include <vector>
struct TextBuffer
{
    std::string text;
    TextBuffer(std::string t) : text(t) {}
    ~TextBuffer()
    {
        std::cout << "TextBuffer destroyed" << std::endl;
        text.clear();
    }
    TextBuffer(const TextBuffer &other)
    {
        std::cout << "TextBuffer Copy Constructor called" << std::endl;
        text = other.text;
    }
    TextBuffer &operator=(const TextBuffer &other)
    {

        std::cout << "TextBuffer Copy Assignment Operator called" << std::endl;
        text = other.text;
        return *this;
    }
    TextBuffer(TextBuffer &&other)
    {

        std::cout << "TextBuffer Move Constructor called" << std::endl;
        text = std::move(other.text);
    }
    TextBuffer &operator=(TextBuffer &&other)
    {

        std::cout << "TextBuffer Move Assignment Operator called" << std::endl;
        text = std::move(other.text);
        return *this;
    }
};
int main()
{
    std::vector<TextBuffer> vec;
    TextBuffer tb("Hello");
    vec.push_back(tb);            // This will call the copy constructor
    vec.push_back(std::move(tb)); // This should call the move constructor
}