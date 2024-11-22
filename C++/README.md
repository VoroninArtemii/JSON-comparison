# Description

An algorithm for comparing two branches from https://rdb.altlinux.org/api/export/branch_binary_packages/{branch} using the two-pointer method. Algorithm complexity is O(N). This library _comparison_ uses some requirements which you need to install into your system. **If you want to use this library with other code you always need to install requirements and to build the project with flags `-lcrypto -lssl`. Don't forget to set the enviroment variable `LD_LIBRARY_PATH`**. That is already written in the _CMakeLists.txt_ for this repository. The _main.cpp_ is an example of using the library. It gets responses, compares branches and prints a result to files *json_1_only.json*, *json_2_only.json* and *json_1_more_version.json*.

# Installing dependencies

You need permissions of root. Execute:

```
su root
apt-get update
apt-get install git gcc-c++ cmake boost-asio-devel libssl-devel nlohmann-json-devel
git clone https://github.com/VoroninArtemii/JSON-comparison
cd JSON-comparison/C++
```

# Usage

You can choose one of two methods for building.

## CMake 

```
cd build/
cmake ..
make
./JSON-comparison {first branch} {second branch}
```

## Commands 

```
g++ -fpic -c comparison.cpp -o comparison.o
g++ -shared comparison.o -o libcomparison.so
g++ main.cpp -lcomparison -lssl -lcrypto -L. -o JSON-comparison
LD_LIBRARY_PATH=. ./JSON-comparison {first branch} {second branch}
```

# Recommendations for improvement

We can use OpenMP or asynchronous functions from Boost. For example, for faster getting data from the site or faster comparing of sorted lists for each architecture.
