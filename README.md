# grep-lite
Lightweight grep alternative in C. Search for keywords in plain text files and optionally save matches to an output file.
Searches for a given string in a text file (`.txt`, `.log`, etc.) and optionally writes matches to an output file.

## Features


- Case-insensitive search
- Works with any plain text file
- Outputs matching lines with their line numbers
- Optional output to a separate file

## Compilation


`gcc main.c -o grep-lite`

## Usage


> Search and print matches to the terminal:

`./grep-lite input_file text_to_search`

> Search and write matches to an output file:

`./grep-lite input_file output_file text_to_search`

### Example

`./grep-lite example_logs.txt error`
> Output

    Line 4 -> [2025-08-12 10:15:27] error   failed to open configuration file.
    Line 7 -> [2025-08-12 10:15:35] error   unable to connect to database.
    Line 12 -> [2025-08-12 10:15:55] error   network timeout while fetching data.

## Licence

This project is licensed under the [MIT License](https://github.com/erenyata/grep-lite/blob/main/LICENSE).

## Notes

> If no matches are found program will output:

    Match does not exist.
