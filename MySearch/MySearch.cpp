// MySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Search.h"
#include <memory>
#include <boost/program_options.hpp> 
#include <iostream>
#include "log.h"
namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");
    desc.add_options()
        ("reg,r", opt::value<std::string>(), "Regular expression that to find")
        ("file,f", opt::value<std::string>(), "File or directory to parse, the default is current working directory")
        ("debug,g", "Enable debug log")
        ("help,h", "Print help message");

    if (argc == 1) {
        std::cout << desc << "\n";
        return 1; 
    }

    opt::variables_map vm;
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);
    
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1; 
    }
    
    std::string filename = ".\\"; // current working directory
    if (vm.count("file")) {
        std::string filename = vm["file"].as<std::string>();
    }

    if (!vm.count("reg")) {
        std::cout << "The --reg must be specified." << std::endl;
        return 1; 
    }
    std::string reg = vm["reg"].as<std::string>();

    if (vm.count("debug")) {
        MySearch::log::getInstance()->setLogLevel(MySearch::log::LogLevel::LOG_DEBUG);
        std::cout << "Regular expression: " << reg << std::endl;
    }

    std::shared_ptr<MySearch::Search> sh = std::make_shared<MySearch::Search>();
    sh->execute(reg,filename);

    return 0;
}

