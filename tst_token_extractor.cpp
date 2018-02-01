#include "token_extractor.h"

#include "3rdparty/catch.hpp"

#include <cstring>
#include <iostream>
#include <vector>

static const char* radcliffBirt = R"(
<?xml version="1.0" encoding="UTF-8"?>
<teiCorpus>
<TEI>
  <teiHeader>
    <fileDesc>
      <publicationStmt>
        <idno type="pageURL">https://de.wikipedia.org/wiki/William Radcliffe Birt</idno>
        <idno type="pageID">4161560</idno>
        <idno type="revisionID">150678490</idno>
        <idno type="namespaceID">0</idno>
        <idno type="namespace" />
        <idno type="timestamp">2016-01-25T17:37:35Z</idno>
      </publicationStmt>
      <sourceDesc>
        <p>Wom3TEIConverter</p>
      </sourceDesc>
    </fileDesc>
    <titleStmt>
      <title>William Radcliffe Birt</title>
    </titleStmt>
  </teiHeader>
  <text>
    <body>
      <div1>
        <head>
          <s>
            <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="1" depType="PNC" depHead="3">William</w>
            <c />
            <w lemma="Radcliffe" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="2" depType="PNC" depHead="3">Radcliffe</w>
            <c />
            <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="3" depType="--">Birt</w>
          </s>
        </head>
        <p>
          <s>
            <w lemma="der" type="ART" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 14_CNP 32_NP" depIndex="1" depType="NK" depHead="2">Der</w>
            <c />
            <w lemma="Krater" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 14_CNP 32_NP" depIndex="2" depType="SB" depHead="11">Krater</w>
            <c />
            <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 14_CNP 32_NP" depIndex="3" depType="NK" depHead="2">Birt</w>
            <c />
            <w lemma="und" type="KON" constPath="0_ROOT 1_S 14_CNP" depIndex="4" depType="CD" depHead="2">und</w>
            <c />
            <w lemma="der" type="ART" case="nom" gender="fem" number="sg" constPath="0_ROOT 1_S 14_CNP 15_NP" depIndex="5" depType="NK" depHead="7">die</w>
            <c />
            <w lemma="Rima" type="NE" case="nom" gender="fem" number="sg" constPath="0_ROOT 1_S 14_CNP 15_NP 23_MPN" depIndex="6" depType="PNC" depHead="7">Rima</w>
            <c />
            <w lemma="Birt" type="NE" case="nom" gender="fem" number="sg" constPath="0_ROOT 1_S 14_CNP 32_NP" depIndex="7" depType="CJ" depHead="4">Birt</w>
            <c />
            <w lemma="auf" type="APPR" constPath="0_ROOT 1_S 14_CNP 15_NP 16_PP" depIndex="8" depType="MNR" depHead="7">auf</w>
            <c />
            <w lemma="der" type="ART" case="acc" gender="masc" number="sg" constPath="0_ROOT 1_S 14_CNP 15_NP 16_PP" depIndex="9" depType="NK" depHead="10">den</w>
            <c />
            <w lemma="Erdmond" type="NN" case="acc" gender="masc" number="sg" constPath="0_ROOT 1_S 14_CNP 15_NP 16_PP" depIndex="10" depType="NK" depHead="8">Erdmond</w>
            <c />
            <w lemma="sein" type="VAFIN" mood="ind" number="pl" person="3" tense="pres" constPath="0_ROOT 1_S" depIndex="11" depType="--">sind</w>
            <c />
            <w lemma="nach" type="APPR" constPath="0_ROOT 1_S 4_VP 7_PP" depIndex="12" depType="MO" depHead="14">nach</w>
            <c />
            <w lemma="ihm" type="PPER" case="dat" gender="masc" number="sg" person="3" constPath="0_ROOT 1_S 4_VP 7_PP" depIndex="13" depType="NK" depHead="12">ihm</w>
            <c />
            <w lemma="benennen" type="VVPP" constPath="0_ROOT 1_S 4_VP" depIndex="14" depType="OC" depHead="11">benannt</w>
            <c type="$." constPath="0_ROOT 1_S" depIndex="15" depType="--" depHead="14">.</c>
          </s>
        </p>
      </div1>
    </body>
  </text>
</TEI>
</teiCorpus>
)";

static const std::vector<std::string_view> lemmataTemplate{
    "William",
    "Radcliffe",
    "Birt",
    "der",
    "Krater",
    "Birt",
    "und",
    "der",
    "Rima",
    "Birt",
    "auf",
    "der",
    "Erdmond",
    "sein",
    "nach",
    "ihm",
    "benennen",
};

TEST_CASE("reads tokens")
{
    std::decay_t<decltype(lemmataTemplate)> lemmata;
    auto docCount = 0;

    auto docHandler = [&docCount]() {
        docCount++;
    };
    auto wordHandler = [&lemmata](Word&& word) {
        lemmata.emplace_back(word.attributes["lemma"]);
    };

    auto extractor = make_extractor(docHandler, wordHandler);

    pugi::xml_document doc;
    doc.load_string(radcliffBirt);
    doc.traverse(extractor);

    REQUIRE(docCount == 1);
    REQUIRE(lemmata.size() == lemmataTemplate.size());
    REQUIRE(lemmata == lemmataTemplate);
}