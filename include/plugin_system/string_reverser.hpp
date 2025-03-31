#ifndef STRING_REVERSER_HPP
#define STRING_REVERSER_HPP

#include "plugin_system/string_processor.hpp"
#include "pluginlib/class_list_macros.hpp"

class StringReverser : public StringProcessor
{
public:
    std::string process(const std::string &input) override
    {
        return std::string(input.rbegin(), input.rend());
    }
};

PLUGINLIB_EXPORT_CLASS(StringReverser, StringProcessor)

#endif // STRING_REVERSER_HPP

