#ifndef XRECHNUNG_UTILS_HPP
#define XRECHNUNG_UTILS_HPP

#include <filesystem>
#include <fstream>
#include <format>
#include <string>

using namespace std::filesystem;

const path BASE_DIR = current_path().parent_path();


[[nodiscard]] inline bool reports_dir_exists()
{
    return std::filesystem::exists(std::format("{}/reports", BASE_DIR.string()).data());
}

inline void create_report_dir()
{
    std::filesystem::create_directory(std::format("{}/reports", BASE_DIR.string()).data());
}

inline void write_to_file(std::u8string content, const std::string &file_prefix)
{
    if (!reports_dir_exists())
        create_report_dir();

    std::ofstream file_stream;
    const auto filename = std::format("{}/reports/xrechnung_invoice_{}.xml", BASE_DIR.string(), file_prefix);
    file_stream.open(filename);
    if (!file_stream.is_open())
        throw std::runtime_error("Failed to open file");
    file_stream << reinterpret_cast<const char *>(content.data());
    file_stream.close();
}

#endif//XRECHNUNG_UTILS_HPP
