#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <experimental/filesystem>
#include <numeric>
#include <cmath>

std::string path;


namespace fs = std::experimental::filesystem;
std::uintmax_t get_directory_size(fs::path const& dir,
    bool const follow_symlinks = false)
{
    auto iterator = fs::recursive_directory_iterator(
        dir,
        follow_symlinks ? fs::directory_options::follow_directory_symlink :
        fs::directory_options::none);
    return std::accumulate(
        fs::begin(iterator), fs::end(iterator),
        0ull,
        [](std::uintmax_t const total, 
        fs::directory_entry const& entry) {
        return total + (fs::is_regular_file(entry) ?
            fs::file_size(entry.path()) : 0);
    });
}

std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> Size(std::uintmax_t s)
{
    uint16_t b{}, k{}, m{}, g{};
    uint16_t temp{};
    k = s / 1024;
    temp = std::remainder(s, 1024);
    if (k > 1024)
    {
        m = k / 1024;
        temp = std::remainder(k, 1024);
        if (m > 1024)
        {
            g = m / 1024;
            temp = std::remainder(g, 1024);
            return std::make_tuple(temp, std::remainder(m, 1024), std::remainder(g, 1024), g);
        }
        else
            return std::make_tuple(temp, std::remainder(m, 1024), m, g);
    }
    else
        return std::make_tuple(temp, k, m, g);
}

int main() {
    
    std::cout << "Path: ";
    std::cin >> path;
    std::uintmax_t size = get_directory_size(path);
    std::tuple tup = Size(size);

    std::cout << "This folder has the size of: " << std::get<3>(tup) << " GB, " << std::get<2>(tup) << " MB, " 
        << std::get<1>(tup) << " KB and " << std::get<0>(tup) << " B\n";
    std::cout << "Size: " << get_directory_size(path);
}
