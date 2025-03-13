#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no colors needed
#include "spdlog/sinks/basic_file_sink.h"

//#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
//#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging
#include "spdlog/sinks/daily_file_sink.h"

using std::cout;
using std::endl;

#define my_print1(...)  printf(__VA_ARGS__)  //正确打印

#define my_print2(fmt,...)  printf(fmt,__VA_ARGS__);


void stdout_example()
{
    // create a color multi-threaded logger
    spdlog::stdout_color_mt("console");    
    spdlog::stderr_color_mt("stderr");    
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

void basic_logfile_example()
{
    try 
    {
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");

        logger->set_level(spdlog::level::trace);
        logger->trace( "daasdasd");

        logger->flush();
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

// 结论，现在加不加##没区别
int main(void)
{
	int i=5, j = 7;
	my_print1("i=%d,j=%d\n", i, j);
	my_print2("iiiiiii\n");

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");    

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");

    stdout_example( );
    basic_logfile_example( );

    //try 
    //{
    //    // Create basic file logger (not rotated)
    //    //auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");

    //    // create a file rotating logger with 5mb size max and 3 rotated files
    //    auto file_logger = spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3);

    //    while( true ){
    //        file_logger->info( "aaaaa");
    //    }
    //}
    //catch (const spdlog::spdlog_ex& ex)
    //{
    //    std::cout << "Log initialization failed: " << ex.what() << std::endl;
    //}
    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logfile", 23, 59);
    // create synchronous  loggers
    auto net_logger = std::make_shared<spdlog::logger>("net", daily_sink);
    auto hw_logger  = std::make_shared<spdlog::logger>("hw",  daily_sink);
    auto db_logger  = std::make_shared<spdlog::logger>("db",  daily_sink); 
    db_logger->info("bbb");
    hw_logger->info("vvv");
    net_logger->info("aaa");

}