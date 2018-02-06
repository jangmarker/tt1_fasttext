#ifndef TT1_FASTTEXT_TEI_DIRECTORY_H
#define TT1_FASTTEXT_TEI_DIRECTORY_H

#include "data_file.h"

#include <experimental/filesystem>
#include <vector>
#include <map>
#include <fstream>
#include <ostream>

class tei_directory
{
public:
    explicit tei_directory(const std::experimental::filesystem::path& path);

    template<typename FeatureExtractor>
    void writeTrainingFile(const std::experimental::filesystem::path& path,
                           FeatureExtractor extractor);

    template<typename FeatureExtractor>
    void writeTestFile(const std::experimental::filesystem::path& path,
                       FeatureExtractor extractor);

private:
    template<typename FeatureExtractor>
    void writeFile(std::string_view dataSetName,
                   const std::experimental::filesystem::path& path,
                   FeatureExtractor extractor);

    void loadFile(const std::experimental::filesystem::path& file);

private:
    std::map<std::string, std::vector<TeiFileParsed>> mTeiFiles;
};


template<typename FeatureExtractor>
void tei_directory::writeTrainingFile(const std::experimental::filesystem::path& path, FeatureExtractor extractor)
{
    writeFile("train", path, extractor);
}

template<typename FeatureExtractor>
void tei_directory::writeTestFile(const std::experimental::filesystem::path& path, FeatureExtractor extractor)
{
    writeFile("test", path, extractor);
}

template<typename FeatureExtractor>
void tei_directory::writeFile(std::string_view dataSetName, const std::experimental::filesystem::path& path,
                              FeatureExtractor extractor)
{
    std::ofstream ostream(path);
    data_file output = make_data_file(ostream, extractor);
    for (auto& tei : mTeiFiles[std::string(dataSetName)]) {
        output << tei;
    }

}


#endif //TT1_FASTTEXT_TEI_DIRECTORY_H
