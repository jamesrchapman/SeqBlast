# SeqBlast

SeqBlast is a sequence similarity search tool implemented in C++ using the BLAST algorithm. It allows users to input a DNA or protein sequence, perform a BLAST search against NCBI's non-redundant database, and retrieve the top matching sequences.

## Features

- Perform BLAST searches against the NCBI non-redundant database.
- Retrieve the top matching sequences based on similarity.
- Display sequence alignments for each hit.

## Prerequisites

- NCBI BLAST+: Install the NCBI BLAST+ package on your system. You can download it from the [NCBI website](https://blast.ncbi.nlm.nih.gov/Blast.cgi?CMD=Web&PAGE_TYPE=BlastDocs&DOC_TYPE=Download).

## Usage

1. Clone the repository:

   ```
   git clone https://github.com/jamesrchapman/seqblast.git
   ```

2. Modify the necessary paths in the `main.cpp` file:

   - Set the `dbPath` variable to the path of your NCBI database.
   - Set the `programName` variable to the appropriate BLAST program you want to use (`blastn`, `blastp`, etc.).
   - Adjust the `MAX_HITS` constant if needed to control the number of top hits to display.

3. Build the project:

   ```
   g++ -o seqblast main.cpp
   ```

4. Run the program:

   ```
   ./seqblast
   ```

5. Enter the DNA or protein sequence when prompted.

6. The program will perform a BLAST search and display the top matching sequences along with their alignment details.

## License

[MIT](LICENSE)

Feel free to fork this project and adapt it to your needs.

## Disclaimer

This project is for educational and demonstration purposes only. Use it responsibly and ensure compliance with any data usage policies and guidelines provided by NCBI.

## Contributing

Contributions are welcome! If you find any bugs or want to enhance the functionality of SeqBlast, please submit an issue or a pull request.

## Acknowledgements

- [NCBI BLAST+](https://blast.ncbi.nlm.nih.gov/Blast.cgi?CMD=Web&PAGE_TYPE=BlastDocs&DOC_TYPE=Download) - The BLAST algorithm and database used for sequence similarity searches.

## Contact

For any questions or inquiries, please contact [jameschapman17@gmail.com](mailto:jameschapman17@gmail.com).