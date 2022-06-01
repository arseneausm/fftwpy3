#!/bin/bash
echo building helloworld.pyx using setup.py

python setup.py build_ext --inplace

echo successfully built helloworld.pyd!
echo testing build

python runmodule.py

echo test successful!
read -p 'reset directory? [Y/N]' prompt

echo $prompt
