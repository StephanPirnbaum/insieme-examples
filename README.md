# insieme-examples
Insieme is used to transform hardware independent parallel C code implemented with OpenMP into hardware-optimizable C code using the intermediate representation code INSPIRE. This repository contains a few examples that show all source code steps.

Following is an overview of all examples including a short description:

|Example | Description |
| ------ | ----------- |
| exp1   | Mapping from OpenMP's _parallel_ construct to INSPIRE |
| exp2   | Mapping from OpenMP's _num\_threads_ restriction to INSPIRE |
| exp3   | Mapping from OpenMP's _critical_ section to INSPIRE |
| exp4   | Mapping from OpenMP's _atomic_ section to INSPIRE |
| exp5   | Mapping from OpenMP's work-sharing with variable synchronization to INSPIRE |
| exp6   | Mapping from OpenMP's work-sharing with loop-carried dependency to INSPIRE |
| exp7   | Mapping from OpenMP's work-sharing and reduction of loop-carried dependency to INSPIRE |
| exp8   | Mapping from OpenMP's synchronization using barriers to INSPIRE |

Each example directory contains six files. These are:

| File             | Description |
| ---------        | ----------- |
| exp\*.cpp        | The OpenMP source code |
| exp\*\_ir.cpp    | The INSPIRE intermediate representation |
| exp\*\_json.json | The INSPIRE intermediate representation as JSON |
| exp\*\_tree.txt  | The INSPIRE intermediate representation as a tree |
| exp\*\_trg.cpp   | The target code deduced from the intermediate representation |
| exp\*\_tu.txt    | The translation unit |
