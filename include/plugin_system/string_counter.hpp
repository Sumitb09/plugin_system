#ifndef STRING_COUNTER_HPP
#define STRING_COUNTER_HPP

#include "plugin_system/string_processor.hpp"
#include "pluginlib/class_list_macros.hpp"

class StringCounter : public StringProcessor
{
public:
    std::string process(const std::string &input) override
    {
        return "Character count: " + std::to_string(input.size());
    }
};

PLUGINLIB_EXPORT_CLASS(StringCounter, StringProcessor)

#endif // STRING_COUNTER_HPP

