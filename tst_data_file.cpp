#include "3rdparty/catch.hpp"
#include "data_file.h"

#include <vector>
#include <sstream>
#include <iostream>

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

static const char* twoDocs = R"(
<?xml version="1.0" encoding="UTF-8"?>
<teiCorpus>
<TEI>
  <text>
    <body>
      <div1>
        <head>
          <s>
            <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="1" depType="PNC" depHead="3">William</w>
          </s>
        </head>
      </div1>
    </body>
  </text>
</TEI>
<TEI>
  <text>
    <body>
      <div1>
        <head>
          <s>
            <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="1" depType="PNC" depHead="3">William</w>
          </s>
        </head>
      </div1>
    </body>
  </text>
</TEI>
</teiCorpus>
)";

static const char* simpleFile = R"(
<?xml version="1.0" encoding="UTF-8"?>
<teiCorpus>
<TEI>
  <text>
    <body>
      <div1>
        <head>
          <s>
            <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_MPN" depIndex="1" depType="PNC" depHead="3">William</w>
          </s>
        </head>
      </div1>
    </body>
  </text>
</TEI>
</teiCorpus>
)";

TEST_CASE("file reading")
{
    auto featureExtractor = [](Word& word) -> std::vector<std::string_view> {
        return {word.attributes["lemma"], word.attributes["type"]};
    };

    pugi::xml_document doc;
    std::stringstream output;
    auto data_file = make_data_file(output, featureExtractor);
    std::string_view expected;

    SECTION("one long document") {
        doc.load_string(radcliffBirt);
        data_file << TeiFileParsed{"astronomie", doc};
        expected = "\n__label__astronomie William_NE Radcliffe_NE Birt_NE der_ART Krater_NN Birt_NE und_KON der_ART Rima_NE Birt_NE auf_APPR der_ART Erdmond_NN sein_VAFIN nach_APPR ihm_PPER benennen_VVPP";
    }

    SECTION("one file, two documents") {
        doc.load_string(twoDocs);
        data_file << TeiFileParsed{"astronomie", doc};
        expected = "\n__label__astronomie William_NE" \
                   "\n__label__astronomie William_NE";
    }

    SECTION("two files") {
        doc.load_string(simpleFile);
        data_file << TeiFileParsed{"astronomie", doc}
                  << TeiFileParsed{"chemie", doc};
        expected = "\n__label__astronomie William_NE" \
                   "\n__label__chemie William_NE";
    }

    std::string result(std::istreambuf_iterator<char>(output), {});
    REQUIRE(result == expected);
}