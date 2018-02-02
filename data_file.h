#ifndef TT1_FASTTEXT_DATA_CONVERTER_H
#define TT1_FASTTEXT_DATA_CONVERTER_H

#include "pugixml.hpp"
#include "token_extractor.h"

#include <ostream>
#include <algorithm>
#include <numeric>
#include <vector>

struct TeiFileParsed {
    std::string_view category;
    pugi::xml_document& root;
};

template<typename FeatureExtractor>
class data_file
{
public:
    explicit data_file(std::ostream& targetFile, FeatureExtractor extractor);

    void add(TeiFileParsed& teiFile);

protected:
    void newLine();
    const FeatureExtractor extractor;
    std::ostream& targetFile;

private:
    class DocumentHandler {
    public:
        explicit DocumentHandler(data_file<FeatureExtractor>* parent);
        void operator()();
    private:
        data_file<FeatureExtractor>* mParent;
    };

    class WordHandler {
    public:
        explicit WordHandler(data_file<FeatureExtractor>* parent);
        void operator()(Word&& word);
    private:
        data_file<FeatureExtractor>* mParent;
    };

    std::string mCategory;
    token_extractor<DocumentHandler, WordHandler> mTokenExtractor;
};

template<typename FeatureExtractor>
data_file<FeatureExtractor>::data_file(std::ostream& targetFile,
                                       FeatureExtractor extractor)
    : extractor(extractor)
    , targetFile(targetFile)
    , mTokenExtractor(token_extractor<DocumentHandler, WordHandler>(DocumentHandler(this),
                                                                    WordHandler(this)))
{

}

template<typename FeatureExtractor>
void data_file<FeatureExtractor>::add(TeiFileParsed& teiFile)
{
    mCategory = teiFile.category;
    teiFile.root.traverse(mTokenExtractor);
}

template<typename FeatureExtractor>
void data_file<FeatureExtractor>::newLine()
{
    targetFile << std::endl;
    targetFile << "__label__" << mCategory;
}

template<typename FeatureExtractor>
void data_file<FeatureExtractor>::DocumentHandler::operator()()
{
    mParent->newLine();
}

template<typename FeatureExtractor>
data_file<FeatureExtractor>::DocumentHandler::DocumentHandler(data_file<FeatureExtractor>* parent)
        : mParent(parent)
{

}

template<typename FeatureExtractor>
void data_file<FeatureExtractor>::WordHandler::operator()(Word&& word)
{
    auto concat = [](std::string lhs, std::string_view rhs) -> std::string {
        std::string rhsString;
        rhsString.reserve(rhs.length());
        std::copy_if(rhs.cbegin(), rhs.cend(), std::back_inserter(rhsString),
                     [](const char& s) { return s != ' '; });
        return lhs + '_' + rhsString;
    };
    std::vector<std::string_view> values = mParent->extractor(word);
    auto token = std::accumulate(++values.cbegin(), values.cend(), std::string(*values.cbegin()), concat);
    mParent->targetFile << " " << token;
}

template<typename FeatureExtractor>
data_file<FeatureExtractor>::WordHandler::WordHandler(data_file<FeatureExtractor>* parent)
        : mParent(parent)
{

}

template<typename FeatureExtractor>
data_file<FeatureExtractor>& operator<<(data_file<FeatureExtractor>& dataFile,
                                        TeiFileParsed&& teiFile)
{
    dataFile.add(teiFile);
    return dataFile;
}

template<typename FeatureExtractor>
data_file<FeatureExtractor> make_data_file(std::ostream& targetFile,
                                           FeatureExtractor extractor)
{
    return data_file<FeatureExtractor>(targetFile, extractor);
}

#endif //TT1_FASTTEXT_DATA_CONVERTER_H