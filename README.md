*This project has been created as part of the 42 curriculum by durisosa, emmmilla.*

# push_swap

## Description

`push_swap` sorts a stack of integers using only two stacks (`a` and `b`) and a
restricted instruction set, aiming for the shortest possible sequence of
operations. Complexity is measured in **number of emitted push_swap
operations**, not in the theoretical complexity of the underlying array
algorithm.

The program implements four sorting strategies of different complexity classes
and selects one at runtime based on a **disorder index** computed from the
input before any movement is performed.

### Allowed operations

`sa` `sb` `ss` — swap the top two elements of a stack (or both).
`pa` `pb` — move the top element from one stack to the other.
`ra` `rb` `rr` — rotate a stack up (first element becomes last).
`rra` `rrb` `rrr` — rotate a stack down (last element becomes first).

## Instructions

### Build

```sh
make            # builds push_swap
make bonus      # builds checker (bonus part)
make clean      # removes object files
make fclean     # removes objects and binaries
make re         # fclean + all
```

The project compiles with `cc -Wall -Wextra -Werror`. `libft` is built first
from its own Makefile.

### Usage

```sh
./push_swap 3 2 1                  # numbers as separate arguments
./push_swap "3 2 1"                # numbers in a single quoted argument
./push_swap --simple 5 4 3 2 1     # force the O(n²) strategy
./push_swap --medium 5 4 3 2 1     # force the O(n√n) strategy
./push_swap --complex 5 4 3 2 1    # force the O(n log n) strategy
./push_swap --radix 5 4 3 2 1      # force the radix implementation
./push_swap --adaptive 5 4 3 2 1   # adaptive selection (default)
./push_swap --bench 5 4 3 2 1      # benchmark metrics on stderr
```

Operations are printed to `stdout`, one per line. Errors print `Error` followed
by a newline to `stderr`. With no arguments the program prints nothing and
returns control.

### Benchmark mode

`--bench` writes to `stderr` the disorder index, the selected strategy with its
complexity class, the total operation count, and a per-operation breakdown:

```
[bench] disorder: 49.00%
[bench] strategy: Adaptive -> Medium (Chunk Sort) / O(n√n)
[bench] total_ops: 5788
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 2212 rb: 1289 rr: 0 rra: 0 rrb: 1287 rrr: 0
```

When the strategy was chosen automatically the line reads
`Adaptive -> <method>`, showing both that adaptive selection took place and
which internal method it picked.

### Checker (bonus)

```sh
./push_swap $ARG | ./checker $ARG
```

`checker` reads instructions from `stdin`, applies them to the stack given as
arguments, and prints `OK` if stack `a` ends up sorted with `b` empty, `KO`
otherwise. Invalid instructions print `Error` to `stderr`.

## The disorder index

The disorder index is a value between 0 and 1 measuring how far the input is
from being sorted. It counts inversions — pairs where a larger value appears
before a smaller one — over the total number of pairs:

```
disorder = inversions / total_pairs
```

A sorted input yields 0.00; a reverse-sorted input yields 1.00. It is computed
once, before any operation is emitted.

**Note on random inputs.** A uniformly random permutation has, by construction,
about half of its pairs inverted, so its disorder converges to ≈0.50 with small
variance. This places random test inputs exactly on the boundary between the
medium and high regimes, which is visible in the performance figures below.

## Strategies

### Simple — Insertion sort, O(n²)

Pushes elements from `a` to `b` one at a time, rotating `b` so that each element
lands in its sorted position. `b` is therefore always sorted and the pull-back
phase is cheap; the cost is dominated by the insertion rotations, which grow
quadratically.

Measured: **1404** operations for n=100, **31030** for n=500.

### Medium — Chunk sort, O(n√n)

Splits the index range into chunks whose count grows proportionally to √n
(`count² · 5 ≥ n`, giving 5 chunks for n=100 and 10 for n=500; the constant was
tuned empirically by measuring operation counts). Each chunk is pushed to `b`,
rotating `b` when the element belongs to the lower half of the chunk so that
`b` stays roughly partitioned. The pull phase repeatedly brings the maximum of
`b` to the top and pushes it back.

Measured: **642** operations for n=100, **5718** for n=500. The ratio
`ops / (n·√n)` stays between 0.64 and 0.49 for n from 100 to 1000, which
confirms the O(n√n) bound empirically.

### Complex — Turkish sort, O(n log n)

For every element it computes the cost of bringing it to the top of its stack
plus the cost of positioning its target in the other stack, then moves the
cheapest one. When both rotations go in the same direction `rr`/`rrr` overlap
them, so the real cost is `max(cost_a, cost_b)` rather than their sum — this is
what the `combined_cost` helper implements.

Measured: **574** operations for n=100, **5169** for n=500.

A **radix sort (LSD)** is also implemented and reachable through `--radix`. It
sorts by the binary representation of normalised indices: for each bit from
least to most significant, elements with a 0 bit go to `b` and the rest rotate
in `a`, then everything returns to `a`. Its cost is ≈1.5·n·bits, giving ~6784
operations for n=500 — essentially its floor, and above the Turkish sort in
this range. We measured the crossover between the two at roughly **1400
elements**: below it the Turkish sort wins on constants, above it radix's
asymptotics take over. Since the project is evaluated up to 500 elements,
`--complex` exposes the Turkish sort.

### Adaptive — regime selection by disorder

| Disorder | Regime | Method | Required bound |
|---|---|---|---|
| < 0.20 | low | Extraction sort (`sort_nearly`) | O(n) |
| 0.20 – 0.50 | medium | Chunk sort | O(n√n) |
| ≥ 0.50 | high | Turkish sort | O(n log n) |

**Low-disorder method.** With disorder below 0.20 most elements are already in
relative order, so sorting everything from scratch is wasteful. A single greedy
pass marks the elements that break the increasing sequence; only those are
extracted to `b`, and each is reinserted in its place. With `k` misplaced
elements the cost is O(n + k·n), which is linear while `k` stays bounded — the
condition the regime itself guarantees. Measured: the `ops/n` ratio holds
constant at ≈2.8 from n=100 to n=1000 with bounded `k`.

**Threshold justification.** The 0.20 and 0.50 cut-offs are the ones defined by
the subject. Below 0.20 the residual structure is strong enough for linear
extraction. Between 0.20 and 0.50 partial structure remains but not enough, and
block partitioning amortises better. Above 0.50 the input is effectively random
and only a method with logarithmic behaviour keeps the operation count low.

## Complexity analysis

| Strategy | Operations (time) | Auxiliary space |
|---|---|---|
| Extraction (`sort_nearly`) | O(n) with bounded `k` | O(1) |
| Insertion | O(n²) | O(1) |
| Chunk | O(n√n) | O(1) |
| Turkish | O(n log n) empirically | O(1) |
| Radix | O(n · log n) | O(1) |

All strategies work in place over the two stacks; the only heap allocation is
the node list itself, so auxiliary space is constant beyond the input.

**On the Turkish sort's bound.** Its exact asymptotic class is debatable — the
cost-based selection makes a closed-form analysis hard. Measured on this
implementation it scales close to O(n^1.4), below O(n√n) = O(n^1.5) and
comparable to O(n log n) in the evaluated range.

**On the extraction sort's bound.** It is linear only while the number of
misplaced elements stays bounded. Near the upper edge of its regime the
reinsertion cost O(k·n) degrades towards quadratic; the 0.20 threshold keeps it
within its useful range.

## Performance

Measured with `shuf -i 1-1000 -n <size>`, averaged over several runs and
verified with the provided `checker_linux`.

| Strategy | n = 100 | n = 500 |
|---|---|---|
| `--simple` | 1404 | 31030 |
| `--medium` | 642 | 5718 |
| `--complex` | 574 | 5169 |
| `--adaptive` (default) | 606 | 5490 |

Reference thresholds: for n=100, under 2000 passes, under 1500 is good, under
700 is excellent. For n=500, under 12000 passes, under 8000 is good, under 5500
is excellent.

**Reading the adaptive figures.** At n=100 the result is consistently in the
excellent range. At n=500 the average sits at 5490, but that average hides a
bimodal distribution: random permutations land on the 0.50 boundary, so roughly
half of the runs take the medium regime (~5718) and half the high regime
(~5169). We kept the subject's thresholds rather than tuning them to favour the
benchmark input.

## Design notes

### Why the stacks are passed by reference

Working with the address of the stacks rather than their values avoids copying
the structure on every call and lets called functions modify the original data
directly. The trade-off is that pointers must be validated before dereferencing
and state changes are harder to track, since any function holding the pointer
can alter it.

## Project structure

```
include/          push_swap.h
src/
  bench/          benchmark output
  core/           strategy dispatch
    simple/       insertion sort, extraction sort
    medium/       chunk sort
    complex/      Turkish sort, radix sort
    metadata/     index, position, target, cost, cheapest
  operations/     the eleven push_swap instructions
  parse/          argument validation and parsing
  stack/          stack and node management
bonus/            checker
lib/              libft and ft_printf
```

## Contributions

| Area | Durian Sosa (`durisosa`) | Emmanuel Millán (`emmmilla`) |
|---|---|---|
| Parser | ✔ | |
| Stacks | ✔ | |
| Metadata | | ✔ |
| Operations | ✔ | ✔ |
| Sorting algorithms | | ✔ |
| Strategy dispatcher | ✔ | |
| Benchmark mode | ✔ | |
| Checker (bonus) | ✔ | ✔ |
| Debugging | ✔ | ✔ |
| Memory checks | | ✔ |

Both authors reviewed and can explain the entire codebase.

## Troubleshooting

To check for memory leaks during development:

```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--verbose --log-file=valgrind-out.txt ./push_swap $ARG
```

## Resources

### References

- Donald E. Knuth, *The Art of Computer Programming*, Vol. 3 — Sorting and
  Searching
- Robert Sedgewick, *Algorithms in C, Parts 1–4: Fundamentals, Data Structures,
  Sorting, Searching*, 3rd edition
- 42 `push_swap` subject
- Unix `man` pages, Stack Overflow

Repositories from other cursus students that served as reference:
[youssef-be](https://github.com/youssef-benchaaboun),
[jdecorte-be](https://github.com/jdecorte-be),
[mcombeau](https://github.com/mcombeau),
[suspectedoceano](https://github.com/suspectedoceano)

<!-- add any further links here -->

### Use of AI

Artificial Intelligence tools were used exclusively as learning, documentation and review aids.

Rather than generating the final implementation, AI assistance was used for:

* Measurement and complexity analysis.
* Identifying potential edge cases  and bug detection.
* Generating and formatting this README document.

All source code was designed, implemented, tested and validated by the authors.

**What we did not use it for.** The architecture, the modular design, the
metadata model and the sorting algorithms themselves are our own work. We did
not delegate design decisions.

---

## Authors

### Durian Sosa
**durisosa**

**42 Madrid Student**

Repository:
https://github.com/durisosa/ps


### Emmanuel Millán Contreras
**emmmilla**

**Electronic Engineer | Data Engineer | 42 Madrid Student**

Repository:
https://github.com/emmmilla/Push_Swap


---
