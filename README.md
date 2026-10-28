# Challenge7

Problem Statement:
A campus event uses ticket IDs from 1 to N. The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned
twice. Your job is to audit the scan log, identify the missing and duplicate IDs, and measure how far the scan sequence is out of order. Plan your
logic before writing code.

Algorithm:
1. Start.
2. Read `N`. If `N` is less than 5 or greater than 15, ask again.
3. Read the `N` ticket IDs. If any ID is outside the range `1` to `N`, ask again.
4. Display the original scan sequence.
5. Check the frequency of each ID from `1` to `N` using loops.
6. Identify the missing ID and duplicated ID.
7. If the sequence does not contain exactly one missing ID and one duplicated ID, display "Invalid scan log" and stop.
8. Compare each ticket with every ticket to its right.
9. If the first ticket is greater than the second ticket, count that pair as out of order.
10. Display the duplicated ID, missing ID, and total out-of-order pairs.
11. Read the last two digits `R` of the registration number. If `R` is outside `0` to `99`, ask again.
12. Calculate the target ID using:
Target = (R % N) + 1
13. Find and display all positions of the target ID in the original sequence.
14. Display the occurrence count of the target ID.
15. Stop.
