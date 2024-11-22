# Description

An algorithm for comparing two branches from https://rdb.altlinux.org/api/export/branch_binary_packages/{branch} using the two-pointer method. Algorithm complexity is O(N). This library _comparison_ uses some requirements which you need to install into your system. The _main.py_ is an example of using the library. It gets responses, compares branches and prints a result to files *json_1_only.json*, *json_2_only.json* and *json_1_more_version.json*.

# Installing dependencies

You need permissions of root. Execute:

```
su root
apt-get update
apt-get install git python3 pip
pip install requests
git clone https://github.com/VoroninArtemii/JSON-comparison
cd JSON-comparison/Python/
```

# Usage

```
python3 main.py
{first branch}
{second branch}
```

# Recommendations for improvement

We can use asynchronous functions. For example, for faster getting data from the site or faster comparing of sorted lists for each architecture.
