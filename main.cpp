#include <iostream>
#include <string>
#include <fstream>

extern "C" {
#include <ncbi-blast-2.10.1+/include/blast.h>
}

#define MAX_HITS 10

void printSequenceAlignment(const BlastHSP* hsp) {
    std::cout << "Alignment: " << std::endl;
    std::cout << hsp->hseq << std::endl;
    std::cout << hsp->midline << std::endl;
    std::cout << hsp->qseq << std::endl;
    std::cout << std::endl;
}

void performBlastSearch(const std::string& querySeq) {
    const char* programName = "blastn";  // Change this according to your needs

    const char* dbPath = "/path/to/ncbi/database";  // Change this to the path of your NCBI database

    const char* queryFileName = "/path/to/query.fasta";  // Change this to the path where you want to save the query file

    std::ofstream queryFile(queryFileName);
    queryFile << ">query\n";
    queryFile << querySeq << std::endl;
    queryFile.close();

    const char* argv[] = {
        programName,
        "-query", queryFileName,
        "-db", dbPath,
        "-outfmt", "5",  // XML output format
        "-num_threads", "4",  // Number of threads to use
        nullptr
    };

    int argc = sizeof(argv) / sizeof(argv[0]) - 1;

    BlastAppOptions* appOptions = BlastAppOptionsNew(programName);

    BlastCmdLineArgs* cmdLineArgs = NULL;
    BlastCmdLineArgsNew(appOptions, &cmdLineArgs);

    int returnValue = BlastAppMain(argc, argv, appOptions, cmdLineArgs);

    if (returnValue == 0) {
        std::string xmlFileName = std::string(queryFileName) + ".xml";
        Blast_Record* blastRecord = Blast_RecordLoad(xmlFileName.c_str());

        if (blastRecord) {
            for (int i = 0; i < std::min(MAX_HITS, blastRecord->num_hits); i++) {
                BlastHit* hit = blastRecord->hitlist_array[i];
                BlastHSP* hsp = hit->hsplist->hsp_array[0];  // Take the top HSP for each hit

                std::cout << "Hit: " << hit->def << std::endl;
                std::cout << "Score: " << hsp->score << std::endl;
                std::cout << "E-value: " << hsp->evalue << std::endl;
                std::cout << "Identity: " << hsp->identity << std::endl;
                std::cout << "Alignment length: " << hsp->align_length << std::endl;

                printSequenceAlignment(hsp);
            }

            Blast_RecordFree(blastRecord);
        }
    }

    BlastCmdLineArgsFree(cmdLineArgs);
    BlastAppOptionsFree(appOptions);

    // Clean up the query file
    remove(queryFileName);
}

int main() {
    std::string querySeq;

    std::cout << "Enter the DNA or protein sequence: ";
    std::getline(std::cin, querySeq);

    performBlastSearch(querySeq);

    return 0;
}
