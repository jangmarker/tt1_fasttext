#!/bin/bash

name=$1
shift

fasttext supervised $* -input $name.train -output $name.model
fasttext test $name.model.bin $name.test | tee "${name}__$*.log"
