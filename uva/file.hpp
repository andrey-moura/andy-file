#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>

namespace uva
{
    namespace file
    {
        void write_all_bytes(const std::filesystem::path& path, const uint8_t* bytes, size_t len);
        void write_all_bytes(const std::string& path, const uint8_t* bytes, size_t len);
        uint8_t* read_all_bytes(const std::string& path, size_t& len);
        template<typename T>
        void write_all(const std::string& path, const std::vector<T>& bytes)
        {
            write_all_bytes(path, (uint8_t*)bytes.data(), bytes.size()*sizeof(T));
        }
        template<typename char_type>
        void write_all_text(const std::filesystem::path& path, const std::basic_string<char_type>& text)
        {
            write_all_bytes(path, (uint8_t*)text.data(), text.size()*sizeof(char_type));
        }
        template<typename char_type>
        void write_all_text(const std::filesystem::path& path, const std::basic_string_view<char_type>& text)
        {
            write_all_bytes(path, (uint8_t*)text.data(), text.size()*sizeof(char_type));
        }
        template<typename Container>
        Container __read_all(const std::string& path)
        {
            Container bytes;

            std::ifstream stream(path, std::ios::binary);
            if(stream.is_open()) {
                stream.seekg(0, std::ios::end);

                size_t len = stream.tellg();

                stream.seekg(0, std::ios::beg);

                bytes.resize(len/sizeof(typename Container::value_type));

                stream.read((char*)bytes.data(), len);
            }

            return bytes;
        }
        template<typename T>
        std::vector<T> read_all(const std::string& path)
        {
            return __read_all<std::vector<T>>(path);
        }
        template<typename char_type>
        std::basic_string<char_type> read_all_text(const std::string& path)
        {
            return __read_all<std::basic_string<char_type>>(path);
        }
        template<typename char_type>
        std::basic_string<char_type> read_all_text(const std::filesystem::path& path)
        {
            return __read_all<std::basic_string<char_type>>(path.string());
        }
        template<typename char_type>
        std::vector<std::basic_string<char_type>> read_all_lines(const std::filesystem::path& path)
        {
            std::vector<std::basic_string<char_type>> lines;
            std::ifstream stream(path, std::ios::in);

            std::basic_string<char_type> text;

            if(stream.is_open()) {
                while(std::getline(stream, text)) {
                    lines.push_back(text);
                }
            }

            return lines;
        }
        std::filesystem::path executable_path();
    }; // namespace file
    
}; // namespace uva
