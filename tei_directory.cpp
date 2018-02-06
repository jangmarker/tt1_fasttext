#include "tei_directory.h"

namespace fs = std::experimental::filesystem;

tei_directory::tei_directory(const std::experimental::filesystem::path& path)
{
    if (!fs::is_directory(path))
        throw "Not a directory";

    for (const auto& entry : fs::directory_iterator(path)) {
        loadFile(entry);
    }

}

void tei_directory::loadFile(const std::experimental::filesystem::path& file)
{
    std::string category;
    std::string testSet;
    std::string stem(file.stem().string());
    auto it = stem.cbegin();
    while (*it != '_' && it != stem.cend()) {
        category.push_back(*it);
        it++;
    }
    it++;
    while (it != stem.cend()) {
        testSet.push_back(*it);
        it++;
    }

    mTeiFiles[testSet].emplace_back(category, file);
}
