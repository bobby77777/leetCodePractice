# LeetCode Practice

Practice repository for LeetCode and related algorithm problems in C and C++.

## Structure

- `src/leetcode/`: main problem solutions, one file per problem
- `src/playground/`: scratch files and extra experiments
- `build/bin/`: local compiled binaries
- `.vscode/`: local editor/debug settings

## Conventions

- Keep one standalone problem per file.
- Use `main()` only for quick local testing.
- Treat `build/` as generated output and do not commit binaries.

## Build

Use `make` as the default workflow.

```sh
make all
make list
make run FILE=1_twoSum
make run FILE=15_3Sum
make clean
```

Manual examples:

```sh
cc src/leetcode/1_twoSum.c -o build/bin/1_twoSum
c++ -std=c++17 src/leetcode/15_3Sum.cpp -o build/bin/15_3Sum
```
