# C++ DSA Revision

Practice problems in C++, grouped by **topic -> pattern**. Every file starts with a
comment header stating the problem, the input/output format, the idea and the
complexity, and is a standalone `main()` that reads from stdin.

## Layout

```
cpp_basics/          language warm-ups (not DSA)
arrays/              everything solved so far - one folder per pattern
  01_array_basics/
  02_prefix_sum/
  03_sorting/
  04_binary_search/
  05_binary_search_on_answer/
  06_hashing/
  07_two_pointers/
notes/               written notes, video scripts, roadmap context
build/               compiled binaries (git-ignored, safe to delete)
_scratch/            throwaway Code Runner files (git-ignored)
```

As new topics come up, add them as siblings of `arrays/` - `strings/`,
`linked_list/`, `stacks_and_queues/`, `recursion/`, `trees/` - each with its own
numbered pattern folders inside.

## Conventions

- One problem per file, `snake_case.cpp`, named after the **problem**, not the approach.
- Multiple approaches to the same problem = same base name + an approach suffix:
  `two_sum_brute.cpp` / `two_sum_hashmap.cpp`, `trapping_rain_water_brute.cpp` /
  `..._prefix_suffix.cpp` / `..._two_pointers.cpp`.
- Every file opens with the same comment header block:
  `Problem / Input / Output / Idea / Complexity`, plus `TODO` when something is broken.
- Pattern folders are numbered in the order they were learned, so the folder list
  doubles as a roadmap.
- `cpp_basics/` files keep a numeric prefix because they are meant to be read in order.

## Running a file

```sh
g++ -std=c++17 -O2 arrays/01_array_basics/maximum_subarray_sum_kadane.cpp -o build/kadane && ./build/kadane
```

## Progress

| Topic | Pattern | Files |
|---|---|---|
| cpp_basics | - | 4 |
| arrays | `01_array_basics` | 23 |
| arrays | `02_prefix_sum` | 3 |
| arrays | `03_sorting` | 6 |
| arrays | `04_binary_search` | 7 |
| arrays | `05_binary_search_on_answer` | 7 |
| arrays | `06_hashing` | 7 |
| arrays | `07_two_pointers` | 7 |
| notes | - | 2 |

**Total solutions: 64**

## Known issues to fix

Flagged as `TODO` in the file headers - found while writing the problem statements, left unfixed so they stay as practice:

- [rotate_left_by_one.cpp](arrays/01_array_basics/rotate_left_by_one.cpp) - the shifting loop runs to i = n-1 and reads arr[n], which is out of bounds. It should stop at i < n-1.
- [lower_bound.cpp](arrays/04_binary_search/lower_bound.cpp) - the condition moves left on arr[mid] <= target, so this currently returns the UPPER bound (first element > target). Use arr[mid] < target to get the lower bound.
- [search_insert_position.cpp](arrays/04_binary_search/search_insert_position.cpp) - same body as lower_bound.cpp and the same off-by-one: it returns the first index > target, so a target already present reports the index after it.
- [split_array_largest_sum.cpp](arrays/05_binary_search_on_answer/split_array_largest_sum.cpp) - the search is inverted and the else branch is empty, so the loop never ends once the greedy count drops below k. It should be: count > k -> left = mid+1, otherwise answer = mid and right = mid-1.
- [contains_duplicate.cpp](arrays/06_hashing/contains_duplicate.cpp) - the result is returned from main (which sets the exit code) instead of being printed, so the program prints nothing.
- [first_repeating_element.cpp](arrays/06_hashing/first_repeating_element.cpp) - the answer is returned from main instead of being printed, so nothing is written to stdout.
- [intersection_of_two_arrays.cpp](arrays/06_hashing/intersection_of_two_arrays.cpp) - arr2 is declared with size 2 but n values are read into it, which writes out of bounds. It should be int arr2[n].
- [two_sum_hashmap.cpp](arrays/06_hashing/two_sum_hashmap.cpp) - arr[i] is never inserted into the map and the function does not return after printing, so this always falls through to -1. Add seen[arr[i]] = i at the end of the loop and return after printing the pair.
- [three_sum.cpp](arrays/07_two_pointers/three_sum.cpp) - the triplets are collected into the vector but never printed, so the program compiles and runs but produces no output. Loop over triplets at the end and print each one.

## Index

### cpp_basics/

- [01_io_and_datatypes.cpp](cpp_basics/01_io_and_datatypes.cpp)
- [02_conditionals.cpp](cpp_basics/02_conditionals.cpp)
- [03_loops.cpp](cpp_basics/03_loops.cpp)
- [04_functions_and_parameters.cpp](cpp_basics/04_functions_and_parameters.cpp)

### arrays/01_array_basics/

- [best_time_to_buy_and_sell_stock_brute.cpp](arrays/01_array_basics/best_time_to_buy_and_sell_stock_brute.cpp)
- [best_time_to_buy_and_sell_stock_optimised.cpp](arrays/01_array_basics/best_time_to_buy_and_sell_stock_optimised.cpp)
- [check_array_palindrome.cpp](arrays/01_array_basics/check_array_palindrome.cpp)
- [check_non_decreasing_array.cpp](arrays/01_array_basics/check_non_decreasing_array.cpp)
- [last_occurrence_of_target.cpp](arrays/01_array_basics/last_occurrence_of_target.cpp)
- [leaders_in_array_brute.cpp](arrays/01_array_basics/leaders_in_array_brute.cpp)
- [leaders_in_array_optimised.cpp](arrays/01_array_basics/leaders_in_array_optimised.cpp)
- [linear_search.cpp](arrays/01_array_basics/linear_search.cpp)
- [majority_element_brute.cpp](arrays/01_array_basics/majority_element_brute.cpp)
- [majority_element_moores_voting.cpp](arrays/01_array_basics/majority_element_moores_voting.cpp)
- [maximum_subarray_sum_brute.cpp](arrays/01_array_basics/maximum_subarray_sum_brute.cpp)
- [maximum_subarray_sum_kadane.cpp](arrays/01_array_basics/maximum_subarray_sum_kadane.cpp)
- [print_duplicates_using_frequency_array.cpp](arrays/01_array_basics/print_duplicates_using_frequency_array.cpp)
- [rotate_left_by_k.cpp](arrays/01_array_basics/rotate_left_by_k.cpp)
- [rotate_left_by_one.cpp](arrays/01_array_basics/rotate_left_by_one.cpp)
- [rotate_right_by_one.cpp](arrays/01_array_basics/rotate_right_by_one.cpp)
- [rotate_using_extra_array.cpp](arrays/01_array_basics/rotate_using_extra_array.cpp)
- [rotate_using_reversal_algorithm.cpp](arrays/01_array_basics/rotate_using_reversal_algorithm.cpp)
- [second_largest_element.cpp](arrays/01_array_basics/second_largest_element.cpp)
- [smallest_non_repeating_element.cpp](arrays/01_array_basics/smallest_non_repeating_element.cpp)
- [trapping_rain_water_brute.cpp](arrays/01_array_basics/trapping_rain_water_brute.cpp)
- [trapping_rain_water_prefix_suffix.cpp](arrays/01_array_basics/trapping_rain_water_prefix_suffix.cpp)
- [trapping_rain_water_two_pointers.cpp](arrays/01_array_basics/trapping_rain_water_two_pointers.cpp)

### arrays/02_prefix_sum/

- [equilibrium_index.cpp](arrays/02_prefix_sum/equilibrium_index.cpp)
- [multiple_range_sum_queries.cpp](arrays/02_prefix_sum/multiple_range_sum_queries.cpp)
- [prefix_sum_array.cpp](arrays/02_prefix_sum/prefix_sum_array.cpp)

### arrays/03_sorting/

- [bubble_sort.cpp](arrays/03_sorting/bubble_sort.cpp)
- [insertion_sort.cpp](arrays/03_sorting/insertion_sort.cpp)
- [merge_sort.cpp](arrays/03_sorting/merge_sort.cpp)
- [quick_sort.cpp](arrays/03_sorting/quick_sort.cpp)
- [selection_sort.cpp](arrays/03_sorting/selection_sort.cpp)
- [stl_sort_custom_comparator.cpp](arrays/03_sorting/stl_sort_custom_comparator.cpp)

### arrays/04_binary_search/

- [binary_search_basic.cpp](arrays/04_binary_search/binary_search_basic.cpp)
- [ceil_and_floor_in_sorted_array.cpp](arrays/04_binary_search/ceil_and_floor_in_sorted_array.cpp)
- [find_minimum_in_rotated_sorted_array.cpp](arrays/04_binary_search/find_minimum_in_rotated_sorted_array.cpp)
- [find_peak_element.cpp](arrays/04_binary_search/find_peak_element.cpp)
- [lower_bound.cpp](arrays/04_binary_search/lower_bound.cpp)
- [search_in_rotated_sorted_array.cpp](arrays/04_binary_search/search_in_rotated_sorted_array.cpp)
- [search_insert_position.cpp](arrays/04_binary_search/search_insert_position.cpp)

### arrays/05_binary_search_on_answer/

- [aggressive_cows.cpp](arrays/05_binary_search_on_answer/aggressive_cows.cpp)
- [allocate_minimum_number_of_pages.cpp](arrays/05_binary_search_on_answer/allocate_minimum_number_of_pages.cpp)
- [koko_eating_bananas.cpp](arrays/05_binary_search_on_answer/koko_eating_bananas.cpp)
- [minimum_days_to_make_m_bouquets.cpp](arrays/05_binary_search_on_answer/minimum_days_to_make_m_bouquets.cpp)
- [ship_packages_within_d_days.cpp](arrays/05_binary_search_on_answer/ship_packages_within_d_days.cpp)
- [smallest_divisor_given_a_threshold.cpp](arrays/05_binary_search_on_answer/smallest_divisor_given_a_threshold.cpp)
- [split_array_largest_sum.cpp](arrays/05_binary_search_on_answer/split_array_largest_sum.cpp)

### arrays/06_hashing/

- [contains_duplicate.cpp](arrays/06_hashing/contains_duplicate.cpp)
- [first_repeating_element.cpp](arrays/06_hashing/first_repeating_element.cpp)
- [frequency_of_elements.cpp](arrays/06_hashing/frequency_of_elements.cpp)
- [intersection_of_two_arrays.cpp](arrays/06_hashing/intersection_of_two_arrays.cpp)
- [longest_consecutive_sequence.cpp](arrays/06_hashing/longest_consecutive_sequence.cpp)
- [two_sum_brute.cpp](arrays/06_hashing/two_sum_brute.cpp)
- [two_sum_hashmap.cpp](arrays/06_hashing/two_sum_hashmap.cpp)

### arrays/07_two_pointers/

- [container_with_most_water.cpp](arrays/07_two_pointers/container_with_most_water.cpp)
- [move_zeroes.cpp](arrays/07_two_pointers/move_zeroes.cpp)
- [remove_duplicates_from_sorted_array.cpp](arrays/07_two_pointers/remove_duplicates_from_sorted_array.cpp)
- [squares_of_a_sorted_array.cpp](arrays/07_two_pointers/squares_of_a_sorted_array.cpp)
- [three_sum.cpp](arrays/07_two_pointers/three_sum.cpp)
- [two_sum_in_sorted_array.cpp](arrays/07_two_pointers/two_sum_in_sorted_array.cpp)
- [valid_palindrome.cpp](arrays/07_two_pointers/valid_palindrome.cpp)

### notes/

- [dsa_journey_recovery_context.md](notes/dsa_journey_recovery_context.md)
- [minimum_days_to_make_m_bouquets_video_script.md](notes/minimum_days_to_make_m_bouquets_video_script.md)
