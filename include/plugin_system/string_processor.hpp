#ifndef STRING_PROCESSOR_HPP
#define STRING_PROCESSOR_HPP

#include <string>
#include <memory>

class StringProcessor
{
public:
    using Ptr = std::shared_ptr<StringProcessor>;
    virtual ~StringProcessor() = default;

    // Process the input string and return the result
    virtual std::string process(const std::string &input) = 0;
};

#endif // STRING_PROCESSOR_HPP

