#include "token_extractor.h"

#include "3rdparty/catch.hpp"

#include <cstring>
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
            <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NM 11_MPN" depIndex="1" depType="PNC" depHead="3">William</w>
            <c />
            <w lemma="Radcliffe" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NM 11_MPN" depIndex="2" depType="PNC" depHead="3">Radcliffe</w>
            <c />
            <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NM 11_MPN" depIndex="3" depType="--">Birt</w>
            <c />
            <c type="$(" constPath="0_ROOT 1_NUR 4_NM" depIndex="4" depType="--" depHead="3">(</c>
            <c type="$(" constPath="0_ROOT 1_NUR 4_NM" depIndex="5" depType="--" depHead="4">*</c>
            <c />
            <w lemma="15" type="CARD" constPath="0_ROOT 1_NUR 4_NM" depIndex="6" depType="NK" depHead="5">15</w>
            <c type="$." constPath="0_ROOT 1_NUR" depIndex="7" depType="--" depHead="6">.</c>
          </s>
          <s>
            <c />
            <w lemma="Juli" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 11_NP" depIndex="1" depType="--">Juli</w>
            <c />
            <w lemma="1804" type="CARD" constPath="0_ROOT 1_NUR 11_NP" depIndex="2" depType="NK" depHead="1">1804</w>
            <c />
            <w lemma="in" type="APPR" constPath="0_ROOT 1_NUR 11_NP 12_PP" depIndex="3" depType="MO" depHead="1">in</w>
            <c />
            <w lemma="London" type="NE" case="dat" gender="neut" number="sg" constPath="0_ROOT 1_NUR 11_NP 12_PP" depIndex="4" depType="NK" depHead="3">London</w>
            <c />
            <c type="$(" constPath="0_ROOT 1_NUR 4_NM" depIndex="5" depType="--" depHead="4">;</c>
            <c />
            <c type="$(" constPath="0_ROOT 1_NUR 4_NM" depIndex="6" depType="--" depHead="5">†</c>
            <c />
            <w lemma="14" type="CARD" constPath="0_ROOT 1_NUR 4_NM" depIndex="7" depType="NK" depHead="1">14</w>
            <c type="$." constPath="0_ROOT 1_NUR" depIndex="8" depType="--" depHead="7">.</c>
          </s>
          <s>
            <c />
            <w lemma="Dezember" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_CS 25_NP" depIndex="1" depType="MO" depHead="8">Dezember</w>
            <c />
            <w lemma="1881" type="CARD" constPath="0_ROOT 1_CS 25_NP" depIndex="2" depType="NK" depHead="1">1881</w>
            <c />
            <w lemma="in" type="APPR" constPath="0_ROOT 1_CS 25_NP 26_PP" depIndex="3" depType="MO" depHead="1">in</w>
            <c />
            <w lemma="Leytonstone" type="NE" case="dat" gender="neut" number="sg" constPath="0_ROOT 1_CS 25_NP 26_PP" depIndex="4" depType="NK" depHead="3">Leytonstone</w>
            <c />
            <c type="$," constPath="0_ROOT 1_CS" depIndex="5" depType="--" depHead="4">,</c>
            <c />
            <w lemma="Essex" type="NE" case="dat" gender="neut" number="sg" constPath="0_ROOT 1_CS" depIndex="6" depType="CJ" depHead="4">Essex</w>
            <c />
            <c type="$(" constPath="0_ROOT 1_CS 4_S" depIndex="7" depType="--" depHead="6">)</c>
            <c />
            <w lemma="sein" type="VAFIN" mood="ind" number="sg" person="3" tense="past" constPath="0_ROOT 1_CS 4_S" depIndex="8" depType="--">war</w>
            <c />
            <w lemma="ein" type="ART" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_CS 4_S 10_NP" depIndex="9" depType="NK" depHead="11">ein</w>
            <c />
            <w lemma="englisch" type="ADJA" case="nom" degree="pos" gender="masc" number="sg" constPath="0_ROOT 1_CS 4_S 10_NP" depIndex="10" depType="NK" depHead="11">englischer</w>
            <c />
            <w lemma="Amateur" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_CS 4_S 10_NP" depIndex="11" depType="PD" depHead="8">Amateur</w>
            <c type="$(" constPath="0_ROOT 1_CS 4_S 5_NP" depIndex="12" depType="--" depHead="11">-</c>
            <c />
            <w lemma="Astronom" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_CS 4_S 5_NP" depIndex="13" depType="APP" depHead="11">Astronom</w>
            <c />
            <c type="$." constPath="0_ROOT 1_CS" depIndex="14" depType="--" depHead="13">.</c>
          </s>
          <s>
            <c />
            <w lemma="er" type="PPER" case="nom" gender="masc" number="sg" person="3" constPath="0_ROOT 1_S" depIndex="1" depType="SB" depHead="2">Er</w>
            <c />
            <w lemma="arbeiten" type="VVFIN" mood="ind" number="sg" person="3" tense="past" constPath="0_ROOT 1_S" depIndex="2" depType="--">arbeitete</w>
            <c />
            <w lemma="eng" type="ADJD" degree="pos" constPath="0_ROOT 1_S" depIndex="3" depType="MO" depHead="2">eng</w>
            <c />
            <w lemma="mit" type="APPR" constPath="0_ROOT 1_S 6_PP" depIndex="4" depType="MO" depHead="2">mit</w>
            <c />
            <w lemma="John" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 6_PP 7_MPN" depIndex="5" depType="PNC" depHead="6">John</w>
            <c />
            <w lemma="Herschel" type="NE" case="dat" gender="masc" number="sg" constPath="0_ROOT 1_S 6_PP 7_MPN" depIndex="6" depType="NK" depHead="4">Herschel</w>
            <c />
            <w lemma="zusammen" type="PTKVZ" constPath="0_ROOT 1_S" depIndex="7" depType="SVP" depHead="2">zusammen</w>
            <c type="$." constPath="0_ROOT 1_S" depIndex="8" depType="--" depHead="7">.</c>
          </s>
          <s>
            <c />
            <w lemma="sein" type="PPOSAT" case="nom" gender="neut" number="sg" constPath="0_ROOT 1_S 36_NP" depIndex="1" depType="NK" depHead="2">Sein</w>
            <c />
            <w lemma="Hauptaugenmerk" type="NN" case="nom" gender="neut" number="sg" constPath="0_ROOT 1_S 36_NP" depIndex="2" depType="OA" depHead="3">Hauptaugenmerk</w>
            <c />
            <w lemma="richten" type="VVFIN" mood="ind" number="sg" person="3" tense="past" constPath="0_ROOT 1_S" depIndex="3" depType="--">richtete</w>
            <c />
            <w lemma="er" type="PPER" case="nom" gender="masc" number="sg" person="3" constPath="0_ROOT 1_S" depIndex="4" depType="SB" depHead="3">er</w>
            <c />
            <w lemma="in" type="APPR" constPath="0_ROOT 1_S 18_PP" depIndex="5" depType="MO" depHead="3">in</w>
            <c />
            <w lemma="der" type="ART" case="dat" gender="neut" number="pl" constPath="0_ROOT 1_S 18_PP" depIndex="6" depType="NK" depHead="7">den</w>
            <c />
            <w lemma="Jahr" type="NN" case="dat" gender="neut" number="pl" constPath="0_ROOT 1_S 18_PP" depIndex="7" depType="NK" depHead="5">Jahren</w>
            <c />
            <w lemma="1843" type="CARD" constPath="0_ROOT 1_S 18_PP 19_CAP" depIndex="8" depType="NK" depHead="7">1843</w>
            <c />
            <w lemma="bis" type="KON" constPath="0_ROOT 1_S 18_PP 19_CAP" depIndex="9" depType="CD" depHead="8">bis</w>
            <c />
            <w lemma="1850" type="CARD" constPath="0_ROOT 1_S 18_PP 19_CAP" depIndex="10" depType="CJ" depHead="9">1850</w>
            <c />
            <w lemma="auf" type="APPR" constPath="0_ROOT 1_S 4_PP" depIndex="11" depType="OP" depHead="3">auf</w>
            <c />
            <w lemma="meteorologisch" type="ADJA" case="acc" degree="pos" gender="fem" number="pl" constPath="0_ROOT 1_S 4_PP" depIndex="12" depType="NK" depHead="13">meteorologische</w>
            <c />
            <w lemma="Studie" type="NN" case="acc" gender="fem" number="pl" constPath="0_ROOT 1_S 4_PP" depIndex="13" depType="NK" depHead="11">Studien</w>
            <c />
            <w lemma="der" type="ART" case="gen" gender="fem" number="pl" constPath="0_ROOT 1_S 4_PP 5_NP" depIndex="14" depType="NK" depHead="16">der</w>
            <c />
            <w lemma="atmosphärisch" type="ADJA" case="gen" degree="pos" gender="fem" number="pl" constPath="0_ROOT 1_S 4_PP 5_NP" depIndex="15" depType="NK" depHead="16">atmosphärischen</w>
            <c />
            <w lemma="Welle" type="NN" case="acc" gender="fem" number="pl" constPath="0_ROOT 1_S 4_PP 5_NP" depIndex="16" depType="AG" depHead="13">Wellen</w>
            <c type="$." constPath="0_ROOT 1_S" depIndex="17" depType="--" depHead="16">.</c>
          </s>
          <s>
            <c />
            <w lemma="der" type="ART" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 28_NP" depIndex="1" depType="NK" depHead="2">Der</w>
            <c />
            <w lemma="Großteil" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_S 28_NP" depIndex="2" depType="SB" depHead="5">Großteil</w>
            <c />
            <w lemma="sein" type="PPOSAT" case="gen" gender="neut" number="pl" constPath="0_ROOT 1_S 28_NP 29_NP" depIndex="3" depType="NK" depHead="4">seiner</w>
            <c />
            <w lemma="Werk" type="NN" case="gen" gender="neut" number="pl" constPath="0_ROOT 1_S 28_NP 29_NP" depIndex="4" depType="AG" depHead="2">Werke</w>
            <c />
            <w lemma="befinden" type="VVFIN" mood="ind" number="sg" person="3" tense="pres" constPath="0_ROOT 1_S" depIndex="5" depType="--">befindet</w>
            <c />
            <w lemma="sich" type="PRF" case="acc" number="sg" person="3" constPath="0_ROOT 1_S" depIndex="6" depType="OA" depHead="5">sich</w>
            <c />
            <w lemma="in" type="APPR" constPath="0_ROOT 1_S 4_PP" depIndex="7" depType="MO" depHead="5">in</w>
            <c />
            <w lemma="der" type="ART" case="dat" gender="fem" number="sg" constPath="0_ROOT 1_S 4_PP 5_NP" depIndex="8" depType="NK" depHead="11">der</w>
            <c />
            <w lemma="Scientist" type="FM" constPath="0_ROOT 1_S 4_PP 15_MPN" depIndex="9" depType="PNC" depHead="11">Scientist</w>
            <w lemma="es" type="FM" constPath="0_ROOT 1_S 4_PP 15_MPN" depIndex="10" depType="PNC" depHead="11">'s</w>
            <c />
            <w lemma="Collection" type="FM" constPath="0_ROOT 1_S 4_PP 15_MPN" depIndex="11" depType="NK" depHead="7">Collection</w>
            <c />
            <w lemma="der" type="ART" case="gen" gender="fem" number="sg" constPath="0_ROOT 1_S 4_PP 5_NP" depIndex="12" depType="NK" depHead="15">der</w>
            <c />
            <w lemma="American" type="FM" constPath="0_ROOT 1_S 4_PP 5_NP 6_MPN" depIndex="13" depType="PNC" depHead="15">American</w>
            <c />
            <w lemma="Philosophical" type="FM" constPath="0_ROOT 1_S 4_PP 5_NP 6_MPN" depIndex="14" depType="PNC" depHead="15">Philosophical</w>
            <c />
            <w lemma="Society" type="FM" constPath="0_ROOT 1_S 4_PP 5_NP 6_MPN" depIndex="15" depType="NK" depHead="7">Society</w>
            <c />
            <c type="$." constPath="0_ROOT 1_S" depIndex="16" depType="--" depHead="15">.</c>
          </s>
        </p>
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
        <div2>
          <head>
            <s>
              <w lemma="Weblink" type="XY" constPath="0_ROOT 1_NUR" depIndex="1" depType="--">Weblinks</w>
            </s>
          </head>
          <list>
            <item>
              <s>
                <w lemma="Vladimir" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 36_MPN" depIndex="1" depType="PNC" depHead="2">Vladimir</w>
                <c />
                <w lemma="Jankovic" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 36_MPN" depIndex="2" depType="--">Jankovic</w>
                <c type="$," constPath="0_ROOT 1_NUR 4_NP" depIndex="3" depType="--" depHead="2">,</c>
                <c />
                <c type="$(" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP" depIndex="4" depType="--" depHead="3">`</c>
                <w lemma="John" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 27_MPN" depIndex="5" depType="PNC" depHead="6">John</w>
                <c />
                <w lemma="Herschel" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 27_MPN" depIndex="6" depType="AG" depHead="16">Herschel</w>
                <w lemma="es" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="7" depType="PNC" depHead="16">'s</w>
                <c />
                <w lemma="and" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="8" depType="PNC" depHead="16">and</w>
                <c />
                <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="9" depType="PNC" depHead="16">William</w>
                <c />
                <w lemma="Radcliffe" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="10" depType="PNC" depHead="16">Radcliffe</w>
                <c />
                <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="11" depType="PNC" depHead="16">Birt</w>
                <w lemma="es" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 17_NP 18_MPN" depIndex="12" depType="PNC" depHead="16">'s</w>
                <c />
                <w lemma="research" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 6_MPN" depIndex="13" depType="PNC" depHead="16">research</w>
                <c />
                <w lemma="on" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 6_MPN" depIndex="14" depType="PNC" depHead="16">on</w>
                <c />
                <w lemma="atmospheric" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 6_MPN" depIndex="15" depType="PNC" depHead="16">atmospheric</w>
                <c />
                <w lemma="wav" type="FM" constPath="0_ROOT 1_NUR 4_NP 5_S 6_MPN" depIndex="16" depType="NK" depHead="3">waves</w>
                <c type="$." constPath="0_ROOT 1_NUR" depIndex="17" depType="--" depHead="16">'</c>
              </s>
            </item>
            <item>
              <s>
                <w lemma="Scientist" type="NE" case="gen" gender="*" number="sg" constPath="0_ROOT 1_NUR 2_NP" depIndex="1" depType="NK" depHead="2">Scientists</w>
                <c />
                <w lemma="Collection" type="NN" case="nom" gender="fem" number="sg" constPath="0_ROOT 1_NUR 2_NP" depIndex="2" depType="--">Collection</w>
              </s>
            </item>
            <item>
              <s>
                <c type="$(" constPath="0_ROOT 1_NUR" depIndex="1" depType="--" depHead="2">`</c>
                <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_S 18_MPN" depIndex="2" depType="PNC" depHead="4">William</w>
                <c />
                <w lemma="R." type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_S 18_MPN" depIndex="3" depType="PNC" depHead="4">R.</w>
                <c />
                <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_S 18_MPN" depIndex="4" depType="--">Birt</w>
                <c />
                <w lemma="in" type="APPRART" case="dat" gender="neut" number="sg" constPath="0_ROOT 1_NUR 2_S 11_PP" depIndex="5" depType="MNR" depHead="4">im</w>
                <c />
                <w lemma="Project" type="NN" case="dat" gender="neut" number="sg" constPath="0_ROOT 1_NUR 2_S 11_PP" depIndex="6" depType="NK" depHead="5">Project</w>
                <c />
                <w lemma="Gutenberg" type="NE" case="nom" gender="*" number="sg" constPath="0_ROOT 1_NUR 2_S 11_PP" depIndex="7" depType="NK" depHead="6">Gutenberg</w>
                <c />
                <c type="$(" constPath="0_ROOT 1_NUR 2_S" depIndex="8" depType="--" depHead="7">(</c>
                <w lemma="PG" type="NE" case="nom" gender="*" number="sg" constPath="0_ROOT 1_NUR 2_S" depIndex="9" depType="APP" depHead="6">PG</w>
                <c type="$(" constPath="0_ROOT 1_NUR 2_S" depIndex="10" depType="--" depHead="9">)</c>
                <c type="$." constPath="0_ROOT 1_NUR 2_S" depIndex="11" depType="--" depHead="10">'</c>
              </s>
            </item>
            <item>
              <s>
                <w lemma="Veröffentlichung" type="NN" case="acc" gender="fem" number="pl" constPath="0_ROOT 1_NUR 2_S 13_NP" depIndex="1" depType="--">Veröffentlichungen</w>
                <c />
                <w lemma="von" type="APPR" constPath="0_ROOT 1_NUR 2_S 13_NP 14_PP" depIndex="2" depType="PG" depHead="1">von</w>
                <c />
                <w lemma="W.R." type="NE" case="*" gender="*" number="*" constPath="0_ROOT 1_NUR 2_S 13_NP 14_PP 15_MPN" depIndex="3" depType="PNC" depHead="4">W.R.</w>
                <c />
                <w lemma="Birt" type="NE" case="dat" gender="*" number="sg" constPath="0_ROOT 1_NUR 2_S 13_NP 14_PP 15_MPN" depIndex="4" depType="NK" depHead="2">Birt</w>
                <c />
                <w lemma="in" type="APPRART" case="dat" gender="*" number="sg" constPath="0_ROOT 1_NUR 2_S 3_PP" depIndex="5" depType="MNR" depHead="1">im</w>
                <c />
                <w lemma="Astrophysics" type="NE" case="*" gender="*" number="*" constPath="0_ROOT 1_NUR 2_S 3_PP 6_MPN" depIndex="6" depType="PNC" depHead="8">Astrophysics</w>
                <c />
                <w lemma="Data" type="NE" case="*" gender="*" number="*" constPath="0_ROOT 1_NUR 2_S 3_PP 6_MPN" depIndex="7" depType="PNC" depHead="8">Data</w>
                <c />
                <w lemma="System" type="NN" case="acc" gender="neut" number="sg" constPath="0_ROOT 1_NUR 2_S 3_PP" depIndex="8" depType="NK" depHead="5">System</w>
              </s>
            </item>
            <item>
              <s>
                <w lemma="N.N." type="NE" case="nom" gender="neut" number="sg" constPath="0_ROOT 1_NUR 4_MPN" depIndex="1" depType="--">N.N.</w>
                <c type="$(" constPath="0_ROOT 1_NUR 4_MPN" depIndex="2" depType="--" depHead="1">:</c>
                <c />
                <w lemma="William" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_MPN 5_MPN" depIndex="3" depType="PNC" depHead="5">William</w>
                <c />
                <w lemma="Radcliff" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_MPN 5_MPN" depIndex="4" depType="PNC" depHead="5">Radcliff</w>
                <c />
                <w lemma="Birt" type="NE" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 4_MPN 5_MPN" depIndex="5" depType="RS" depHead="1">Birt</w>
                <c type="$." constPath="0_ROOT 1_NUR" depIndex="6" depType="--" depHead="5">.</c>
              </s>
              <s>
                <c />
                <w lemma="Astronomical" type="FM" constPath="0_ROOT 1_NUR 4_NP 9_MPN" depIndex="1" depType="PNC" depHead="2">Astronomical</w>
                <c />
                <w lemma="register" type="FM" constPath="0_ROOT 1_NUR 4_NP 9_MPN" depIndex="2" depType="--">register</w>
                <c type="$," constPath="0_ROOT 1_NUR 4_NP" depIndex="3" depType="--" depHead="2">,</c>
                <c />
                <w lemma="vol" type="XY" constPath="0_ROOT 1_NUR 4_NP" depIndex="4" depType="NK" depHead="2">vol</w>
                <c type="$." constPath="0_ROOT 1_NUR" depIndex="5" depType="--" depHead="4">.</c>
              </s>
              <s>
                <c />
                <w lemma="20" type="CARD" constPath="0_ROOT 1_NUR 2_NM" depIndex="1" depType="NK" depHead="9">20</w>
                <c />
                <c type="$(" constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="2" depType="--" depHead="1">(</c>
                <w lemma="1882" type="CARD" constPath="0_ROOT 1_NUR 2_NM 3_NP" depIndex="3" depType="PAR" depHead="9">1882</w>
                <c type="$(" constPath="0_ROOT 1_NUR 2_NM 3_NP" depIndex="4" depType="--" depHead="3">)</c>
                <c type="$," constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="5" depType="--" depHead="4">,</c>
                <c />
                <w lemma="pp." type="XY" constPath="0_ROOT 1_NUR 2_NM 3_NP" depIndex="6" depType="PNC" depHead="7">pp.</w>
                <c />
                <w lemma="12-13" type="CARD" constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="7" depType="CJ" depHead="3">12-13</w>
                <c />
                <c type="$(" constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="8" depType="--" depHead="7">(</c>
                <w lemma="Nachruf" type="NN" case="nom" gender="masc" number="sg" constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="9" depType="--">Nachruf</w>
                <c type="$," constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP" depIndex="10" depType="--" depHead="9">,</c>
                <c />
                <w lemma="englisch" type="ADJD" degree="pos" constPath="0_ROOT 1_NUR 2_NM 3_NP 4_NP 5_S" depIndex="11" depType="PAR" depHead="9">englisch</w>
                <c type="$." constPath="0_ROOT 1_NUR 2_NM 3_NP" depIndex="12" depType="--" depHead="11">)</c>
              </s>
            </item>
          </list>
          <div>
            Normdaten (Person):
            <ref target="Gemeinsame_Normdatei" type="internal">GND</ref>
            :
            <ref target="http://d-nb.info/gnd/117605069" type="external">117605069</ref>
            (
            <ref target="http://dispatch.opac.d-nb.de/DB=4.1/SET=4/TTL=1/PRS=PP%7F/PPN?PPN=117605069" type="external">PICA</ref>
            ,
            <ref target="http://beacon.findbuch.de/seealso/pnd-aks?format=sources&amp;id=117605069" type="external">AKS</ref>
            )   |
            <ref target="Virtual_International_Authority_File" type="internal">VIAF</ref>
            :
            <ref target="http://viaf.org/viaf/222780358/" type="external">222780358</ref>
            | [//tools.wmflabs.org/persondata/p/
            <table type="transclusion" cols="2">
              <head>SEITENNAME_URL</head>
            </table>
            Wikipedia-Personensuche]
          </div>
          <p />
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          NAME
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="font-weight: bold;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          Birt, William Radcliffe
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          KURZBESCHREIBUNG
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          englischer Amateur-Astronom
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          GEBURTSDATUM
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          15. Juli 1804
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          GEBURTSORT
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          <ref target="London" type="internal">London</ref>
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          STERBEDATUM
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          14. Dezember 1881
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          style="color: #aaa;"
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          STERBEORT
          <table type="transclusion" cols="2">
            <head>!</head>
          </table>
          <ref target="Leytonstone" type="internal">Leytonstone</ref>
          <ref target="Essex" type="internal">Essex</ref>
          <table>
            <row>
              <cell>
                <p>
                  <ref target="Hilfe:Personendaten" type="internal">Personendaten</ref>
                </p>
              </cell>
            </row>
            <row />
            <row />
            <row />
            <row />
            <row />
            <row />
            <row />
          </table>
        </div2>
      </div1>
    </body>
  </text>
</TEI>
</teiCorpus>
)";

static const std::map<std::string_view, int> lemmataTemplate{
    {"William", 0},
    {"Radcliffe", 0},
    {"Birt", 0},
    {"William", 0},
    {"Radcliffe", 0},
    {"Birt", 0},
    {"15", 0},
    {"Juli", 0},
    {"1804", 0},
    {"in", 0},
    {"London", 0},
    {"14", 0},
    {"Dezember", 0},
    {"1881", 0},
    {"in", 0},
    {"Leytonstone", 0},
    {"Essex", 0},
    {"sein", 0},
    {"ein", 0},
    {"englisch", 0},
    {"Amateur", 0},
    {"Astronom", 0},
    {"er", 0},
    {"arbeiten", 0},
    {"eng", 0},
    {"mit", 0},
    {"John", 0},
    {"Herschel", 0},
    {"zusammen", 0},
    {"sein", 0},
    {"Hauptaugenmerk", 0},
    {"richten", 0},
    {"er", 0},
    {"in", 0},
    {"der", 0},
    {"Jahr", 0},
    {"1843", 0},
    {"bis", 0},
    {"1850", 0},
    {"auf", 0},
    {"meteorologisch", 0},
    {"Studie", 0},
    {"der", 0},
    {"atmosphärisch", 0},
    {"Welle", 0},
    {"der", 0},
    {"Großteil", 0},
    {"sein", 0},
    {"Werk", 0},
    {"befinden", 0},
    {"sich", 0},
    {"in", 0},
    {"der", 0},
    {"Scientist", 0},
    {"es", 0},
    {"Collection", 0},
    {"der", 0},
    {"American", 0},
    {"Philosophical", 0},
    {"Society", 0},
    {"der", 0},
    {"Krater", 0},
    {"Birt", 0},
    {"und", 0},
    {"der", 0},
    {"Rima", 0},
    {"Birt", 0},
    {"auf", 0},
    {"der", 0},
    {"Erdmond", 0},
    {"sein", 0},
    {"nach", 0},
    {"ihm", 0},
    {"benennen", 0},
    {"Weblink", 0},
    {"Vladimir", 0},
    {"Jankovic", 0},
    {"John", 0},
    {"Herschel", 0},
    {"es", 0},
    {"and", 0},
    {"William", 0},
    {"Radcliffe", 0},
    {"Birt", 0},
    {"es", 0},
    {"research", 0},
    {"on", 0},
    {"atmospheric", 0},
    {"wav", 0},
    {"Scientist", 0},
    {"Collection", 0},
    {"William", 0},
    {"R.", 0},
    {"Birt", 0},
    {"in", 0},
    {"Project", 0},
    {"Gutenberg", 0},
    {"PG", 0},
    {"Veröffentlichung", 0},
    {"von", 0},
    {"W.R.", 0},
    {"Birt", 0},
    {"in", 0},
    {"Astrophysics", 0},
    {"Data", 0},
    {"System", 0},
    {"N.N.", 0},
    {"William", 0},
    {"Radcliff", 0},
    {"Birt", 0},
    {"Astronomical", 0},
    {"register", 0},
    {"vol", 0},
    {"20", 0},
    {"1882", 0},
    {"pp.", 0},
    {"12-13", 0},
    {"Nachruf", 0},
    {"englisch", 0},
};

TEST_CASE("reads tokens")
{
    auto lemmata(lemmataTemplate);
    auto docCount = 0;

    auto docHandler = [&docCount]() {
        docCount++;
    };
    auto wordHandler = [&lemmata](Word&& word) {
        lemmata.erase(word.attributes["lemma"]);
    };

    token_extractor extractor(docHandler, wordHandler);

    pugi::xml_document doc;
    doc.load_string(radcliffBirt);
    doc.traverse(extractor);

    REQUIRE(docCount == 1);
    REQUIRE(lemmata.empty());
}