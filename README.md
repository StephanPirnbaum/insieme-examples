# insieme-examples
Insieme is used to transform hardware independent parallel C code implemented with OpenMP into hardware-optimizable C code using the intermediate representation code INSPIRE. This repository contains a few examples that show all source code steps.

|Example | Description |
| ------ | ----------- |
| exp1   | Mapping from OpenMP's _parallel_ construct to INSPIRE |
| exp2   | Mapping from OpenMP's _num\_threads_ restriction to INSPIRE |
| exp3   | Mapping from OpenMP's _critical_ section to INSPIRE |
| exp4   | Mapping from OpenMP's _atomic_ section to INSPIRE |
| exp5   | Mapping from OpenMP's work-sharing with variable synchronization to INSPIRE |
| exp6   | Mapping from OpenMP's work-sharing with loop-carried dependency to INSPIRE |
