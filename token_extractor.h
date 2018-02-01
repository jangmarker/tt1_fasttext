#ifndef TT1_FASTTEXT_TOKEN_EXTRACTOR_H
#define TT1_FASTTEXT_TOKEN_EXTRACTOR_H

#include "pugixml.hpp"

#include <map>
#include <string_view>

struct Word {
    std::map<std::string_view, std::string_view> attributes;
    std::string_view data;
};

template<typename DocumentHandler, typename WordHandler>
class token_extractor : public pugi::xml_tree_walker
{
public:
    explicit token_extractor(DocumentHandler docHandler, WordHandler wordHandler);

    bool for_each(pugi::xml_node& node) override;

private:
    DocumentHandler mDocHandler;
    WordHandler mWordHandler;
};

template<typename DocumentHandler, typename WordHandler>
token_extractor<DocumentHandler, WordHandler>::token_extractor(DocumentHandler docHandler,
                                                               WordHandler wordHandler)
    : mDocHandler(docHandler)
    , mWordHandler(wordHandler)
{ }

template<typename DocumentHandler, typename WordHandler>
bool token_extractor<DocumentHandler, WordHandler>::for_each(pugi::xml_node& node)
{
    // very crude data extraction, but it's enough
    std::string_view name(node.name());
    if (name == "TEI") {
        mDocHandler();
    } else if (name == "w") {
        Word word;
        word.data = node.text().as_string();
        for (auto attr : node.attributes()) {
            word.attributes.emplace(attr.name(), attr.as_string());
        }
        mWordHandler(std::move(word));
    }

    return true;
}


#endif //TT1_FASTTEXT_TOKEN_EXTRACTOR_H
