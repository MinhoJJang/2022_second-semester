# General Guideline

- You must write the first 4 problem solving steps in detail, plus the working sourcecode (step 5).

- The overall structure of the entire program in terms of functions is very important.

- This is a team project.

- After defining the overall structure of the program, the team should assign different functions to different members of the team.

- Each team member should test and document his/her own functions.

- The team should put the pieces together, and do the testing of the entire program together, and update the documentation together.

- When submitting the project, each team member must sign off on percentage contribution and the work done.

- The submission should include the problem solving step writeup, source code, result screen capture, and the individual contributions signoff – all in a single WORD file. The output file should be separate, and the WORD file and the output file should be zipped into a single zip file. (The zip file name should be the list of team member names.)

---

# Term Project Specification: (1) Setup

- practice file I/O, struct array, basic data structures
- Read a text file provided (conference registrations data).
- Store the data in a struct array.
- Store the data in a linked list.

---

# Registration Data

(30 records -- including some “Choi”, and some “Gachon
University”)

```
tag# (registration number – unique integer)
date registered (yyyy-mm-dd)
fee-paid (“yes” or “no”)
name (char[25])
age (integer)
organization (company or university; char[30])
job (student, professor, staff, executive, engineer, marketer; char[15])
```

---

# Term Project Specification: (2) Search, Reorganize

- Search for “Choi” (if found, print all information about the persons)
  
- Search for all from Gachon University (if found, print all information about the persons).

  - in the array
  - in the linked list

- Sort the data in the array in tag# order
- Create a linked list using the sorted data.
- Sort the data in the array in age group order (using selection sort –self-study)
  - “age group” means 10, 20, 30,….
- Write the sorted data to a text file.

---

# Term Project Specification:(2) Update

- All “Choi”s canceled registration. Remove the data from
  _ the array (fill the memory)
  _ the linked list
  
- One “Paik” registered late. Add the data to
  - the array (in the sorted order; shift all affected data)
  - the linked list (in the right sorted order)
