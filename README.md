# cppcubesolver

## Description
An open-source framework for implementing and comparing Rubik's cube solving algorithms

## Installation
- clone the project
- set up googletest unit testing using `<git submodule update --init>`
- to build:
	1. create/navigate to the `build/'>` directory
	2. run `<cmake ..>` to create makefiles in relevant directories automatically
	3. run `<make all>` to build libraries and executables from source files in `<../src/>` and `<../test/>`
- to run:
	1. navigate to `<build/src>` and run `<cppcubesolver>`
- to test:
	1. add any tests/test suites in existing or new .cpp files in `<../test/>`
	2. build and navigate to `<build/test/>`
	3. run `<cppcubesolvertest>`
