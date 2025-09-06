# Get Next Line (get_next_line)
A project to deepen my knowledge about static memory management. The goal is to create a function that, when called repeatedly, is able to read an entire file, one line at a time.
The function is able to manage multiple file's reading at the same time, without losing the reading "progress" of each one. The function:
* Returns the line read with a '\n' at the end (if there's one).
* Returns `NULL` at the reading's end (EOF) or in case of an error.

## Key learnings
The main point was to realize that I constantly needed to allocate and deallocate the static buffer so that I could manipulate the input files content at will, because while that data needed to persist
in some way, it also needed to be updated with each new function call.
