#include "cli.h"

#include "tei_directory.h"

#include <experimental/filesystem>
#include <vector>

namespace fs = std::experimental::filesystem;

int cli(int argc, char** argv, std::ostream& ostream)
{
    tei_directory dir(fs::path("./data"));

    auto lemmaType = [](Word& word) -> std::vector<std::string_view> {
        return {word.attributes["lemma"], word.attributes["type"]};
    };
    dir.writeTrainingFile(fs::path("./lemma_type.train"), lemmaType);
    dir.writeTestFile(fs::path("./lemma_type.test"), lemmaType);

    auto onlyNouns = [](Word& word) -> std::vector<std::string_view> {
        if (word.attributes.find("type") == word.attributes.end())
            return {};
        if (word.attributes["type"][0] == 'N')
            return {word.attributes["lemma"]};
        return {};
    };
    dir.writeTrainingFile(fs::path("./nouns_lemma.train"), onlyNouns);
    dir.writeTestFile(fs::path("./nouns_lemma.test"), onlyNouns);

    auto onlyVerbs = [](Word& word) -> std::vector<std::string_view> {
        if (word.attributes.find("type") == word.attributes.end())
            return {};
        if (word.attributes["type"][0] == 'V')
            return {word.attributes["lemma"]};
        return {};
    };
    dir.writeTrainingFile(fs::path("./verbs_lemma.train"), onlyVerbs);
    dir.writeTestFile(fs::path("./verbs_lemma.test"), onlyVerbs);

    return 0;
}
