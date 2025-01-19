#include <uva/file.hpp>

#ifdef _WIN32
#   include <Windows.h>
#   undef min
#endif

void uva::file::write_all_bytes(const std::filesystem::path& path, const uint8_t* bytes, size_t len)
{
    write_all_bytes(path.string(), bytes, len);
}

void uva::file::write_all_bytes(const std::string& path, const uint8_t* bytes, size_t len)
{
    std::ofstream stream(path, std::ios::binary);
    stream.write((char*)bytes, len);
}

void uva::file::insert_text(const std::filesystem::path &path, size_t position, const char *text, size_t len)
{
    std::string content = read_all_text<char>(path);

    std::ofstream stream(path, std::ios::binary);
    stream.write(content.c_str(), std::min(content.size(), position));
    stream.write(text, len);

    if(position < content.size()) {
        stream.write(content.c_str()+position, content.size()-position);
    }
}

std::filesystem::path uva::file::executable_path()
{
#ifdef __linux__
    return std::filesystem::read_symlink("/proc/self/exe");
#elif _WIN32
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::filesystem::path(buffer);
#else
    throw std::runtime_error("unsupported platform");
#endif
}