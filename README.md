# Description

The algorithm of comparing uses the two pointer method. Algorithm complexity is O(N)

# Installation
You need permissions of root. Execute:
```
su root
apt-get install gcc-c++ cmake boost-asio-devel libssl-devel nlohmann-json-devel
```

# Usage
Move to the root directory of the repository. Execute:
```
cd build/
cmake ..
make
./JSON-comparison {first branch} {second branch}
```

There will be a result in the output file after the execution.

# Recommendations for improvement

We can use OpenMP or asynchronous functions from Boost. For example, for faster getting data from the site or faster comparing of sorted lists for each architecture.