//
// Created by TriD on 28.09.2015.
//

#ifndef FAMILY_BUSINESS_SAVES_H
#define FAMILY_BUSINESS_SAVES_H

#include <fstream>
#include <string>
#include <type_traits>
#include <vector>

namespace MEng {
    namespace Utils {
        template <bool B, typename T = void>
        using EnableIf = typename std::enable_if<B,T>::type;

        template <typename T> constexpr bool IsTrivial() {
            return std::is_trivial<T>::value;
        }

        template <typename T> constexpr bool IsPolymorphic() {
            return std::is_polymorphic<T>::value;
        }

        template <typename T> constexpr bool IsClass() {
            return std::is_class<T>::value;
        }

        template <typename T> constexpr bool IsString() {
            return std::is_same<T, std::string>::value;
        }

        template <typename T>
        inline void save(std::ofstream& out, const T& item) {
            out.write(reinterpret_cast<const char*>(&item), sizeof(item));
        }

        template <typename T>
        inline void load(std::ifstream& in, T& item) {
            in.read(reinterpret_cast<char*>(&item), sizeof(item));
        }

        template <>
        inline void save<std::string>(std::ofstream& out, const std::string& item) {
            auto size = item.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            out.write(item.c_str(), size);
        }

        template <>
        inline void load<std::string>(std::ifstream& in, std::string& item) {
            std::string::size_type size{0};
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            char* buff = new char[size + 1];
            buff[size] = '\0';
            in.read(buff, size);
            item = std::string(buff);
            delete[] buff;
        }

        template <typename T>
        inline EnableIf<IsClass<T>() && !IsString<T>()> save(std::ofstream& out, std::vector<T*>& items) {
            auto size = items.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            for (auto& item: items) {
                item->save(out);
            }
        }

        template <typename T>
        inline EnableIf<IsClass<T>() && !IsString<T>()> load(std::ifstream& in, std::vector<T*>& items) {
            typename std::vector<T>::size_type size{0};
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            for (int i = 0; i < size; i++) {
                items.emplace_back(new T(in));
            }
        }

        template <typename T>
        inline EnableIf<IsClass<T>() && !IsString<T>()> save(std::ofstream& out, std::vector<T>& items) {
            auto size = items.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            for (auto& item: items) {
                item.save(out);
            }
        }

        template <typename T>
        inline EnableIf<IsClass<T>() && !IsString<T>()> load(std::ifstream& in, std::vector<T>& items) {
            typename std::vector<T>::size_type size{0};
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            for (int i = 0; i < size; i++) {
                items.emplace_back(in);
            }
        }

        template <typename T>
        inline EnableIf<IsTrivial<T>()> save(std::ofstream& out, std::vector<T>& items) {
            auto size = items.size();
            out.write(reinterpret_cast<char*>(&size), sizeof(size));
            for (auto& item: items) {
                save(out, item);
            }
        }

        template <typename T>
        inline EnableIf<IsTrivial<T>()> load(std::ifstream& in, std::vector<T>& items) {
            typename std::vector<T>::size_type size{0};
            in.read(reinterpret_cast<char*>(&size), sizeof(size));
            for (int i = 0; i < size; i++) {
                T item;
                load(in, item);
                items.push_back(item);
            }
        }

        template <>
        inline void save<std::vector<std::string>>(std::ofstream& out, const std::vector<std::string>& items) {
            auto size = items.size();
            save(out, size);
            for (auto& item: items) {
                save(out, item);
            }
        }

        template <>
        inline void load<std::vector<std::string>>(std::ifstream& in, std::vector<std::string>& items) {
            std::string::size_type size{};
            load(in, size);
            for (int i = 0; i < size; i++) {
                std::string str;
                load(in, str);
                items.push_back(str);
            }
        }
    }
}

#endif //FAMILY_BUSINESS_SAVES_H
