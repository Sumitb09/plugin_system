#include <rclcpp/rclcpp.hpp>
#include "pluginlib/class_loader.hpp"
#include "plugin_system/string_processor.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("plugin_manager");

    pluginlib::ClassLoader<StringProcessor> loader("plugin_system", "StringProcessor");

    std::string plugin_choice;
    std::cout << "Enter plugin to use (reverse/count): ";
    std::cin >> plugin_choice;

    try
    {
        std::shared_ptr<StringProcessor> processor;
        if (plugin_choice == "reverse")
        {
            processor = loader.createSharedInstance("plugin_system/StringReverser");
        }
        else if (plugin_choice == "count")
        {
            processor = loader.createSharedInstance("plugin_system/StringCounter");
        }
        else
        {
            std::cerr << "Invalid choice!" << std::endl;
            return 1;
        }

        std::string input;
        std::cout << "Enter a string: ";
        std::cin.ignore();
        std::getline(std::cin, input);

        std::cout << "Processed result: " << processor->process(input) << std::endl;
    }
    catch (const pluginlib::PluginlibException &ex)
    {
        RCLCPP_ERROR(node->get_logger(), "Plugin failed to load: %s", ex.what());
    }

    rclcpp::shutdown();
    return 0;
}


