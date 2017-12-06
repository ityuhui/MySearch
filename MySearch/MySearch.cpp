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
/*    opt::options_description desc("All options");
    desc.add_options()
        ("reg,r", opt::value<std::string>()->required(), "Regular expression that to find")
        ("file,f", opt::value<std::string>()->required(), "File name to parse")
        ("debug,g", "Enable debug")
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

    std::string reg = vm["reg"].as<std::string>();
    std::string filename = vm["file"].as<std::string>();
    if (vm.count("debug")) {
        MySearch::log::getInstance()->setLogLevel(MySearch::log::LogLevel::LOG_DEBUG);
        std::cout << "Regular expression: " << reg << std::endl;
        std::cout << "Filename : " << filename << std::endl;
    }
    */

    if (argc != 3) {
        std::cout << "MySearch regex filename" << std::endl;
        return -1;
    }
    std::string reg = argv[1];
    std::string filename = argv[2];
    
    std::shared_ptr<MySearch::Search> sh = std::make_shared<MySearch::Search>();
    sh->execute(reg,filename);

    return 0;
}

