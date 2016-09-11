# General parametric scheme for the uniform scheduling problem with two different speeds 
===========================
This is a scientific project.
This repository contains source code and Wolfram Mathematica notebook for the paper 
"General parametric scheme for the uniform scheduling problem with two
different speeds".
The code is a proof of concept on how to find upper bound and scheme parameters of the algorithm presented in the paper. 

The structure of repository is the following:

1. Folder `code` contains source code written in C++. 
This code is used to provide bounds for algorithms of Cho and Sahni 
and our algorithm (bound is obtained by optimization of Parametric Schema presented in paper). 
Makefile is presented, so compilation is done with command:
`make release`.
Note that we need GNU g++ with version > 5.3.1 supporting C++17.
One can run code by executing `code/main`. Result of execution is written to folder `group_evaluation`. 
In main.cpp one can specify amounts of fast and unit processors, and algorithm will provide bounds obtained by 
our algorithm and by algorithm of Cho and Sahni.

2. Folder `result_and_processing` contains our launch results (in folder `group_evaluation`), as well as folder `process`.
The folder `result_and_processing/process` contains script
`process.py` (written in Python), which is used to prepare tables and graphs for publishing. Tables and graphs are presented
in folder `result_and_processing/process/result`

3. Wolfram Mathematica notebook is situated at `wolfram_notebook` folder.

