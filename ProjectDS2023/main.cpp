#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <chrono>
#include "Pair.h"
#include "Functions.h"
#include "UnorderedArray.h"
#include "SortedArray.h"
#include "BST.h"
#include "AVLTree.h"
#include "HashTable.h"

#define Q_size 15000

using namespace std;

int main(int argc, char** argv)
{

    // Check if the input file argument is provided
    if (argc < 2)
    {
        cerr << "Usage: main.exe input_file" << endl;
        return 1;
    }

    // Get the input file name from the command line arguments
    string inputFile = argv[1];

    // Open the input file
    ifstream inFile(inputFile);
    if (!inFile)
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    //Create the data structures
    UnorderedArray ua = UnorderedArray();
    SortedArray sa = SortedArray();
    BST bst = BST();
    AVLTree avl = AVLTree();
    HashTable ht = HashTable();

    //Read each line from the input file
    string line;
    string word1, word2;
    bool isFirstWord = true; //flag to check if it's the first word in a line

    //declaration of creation time for each data structure
    chrono::duration<double> uaCreation = chrono::duration<double>::zero();
    chrono::duration<double> saCreation = chrono::duration<double>::zero();
    chrono::duration<double> bstCreation = chrono::duration<double>::zero();
    chrono::duration<double> avlCreation = chrono::duration<double>::zero();
    chrono::duration<double> htCreation = chrono::duration<double>::zero();

    while (getline(inFile, line))
    {
        //Skip empty lines
        if (line.empty() || line.find_first_not_of(' ') == string::npos)
        {
            continue;
        }

        clearLine(line); //Preprocess line - remove non-alphanumeric & convert to lowercase

        //Split the line into words
        stringstream ss(line);
        string word;

        if (isFirstWord)
        {
            ss >> word;
            word1 = word;
            isFirstWord = false;
        }
        else
        {
            ss >> word;
            word2 = word;
            Pair newPair = {word1, word2};
            //Add the pair of words to the unordered array
            auto startTime = chrono::high_resolution_clock::now();
            ua.add(newPair);
            auto endTime = chrono::high_resolution_clock::now();
            uaCreation += endTime - startTime;
            //Add the pair of words to the Sorted Array
            startTime = chrono::high_resolution_clock::now();
            sa.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            saCreation += endTime - startTime;
            //Add the pair of words to the BST
            startTime = chrono::high_resolution_clock::now();
            bst.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            bstCreation += endTime - startTime;
            //Add the pair of words to the AVL Tree
            startTime = chrono::high_resolution_clock::now();
            avl.insert(newPair);
            endTime = chrono::high_resolution_clock::now();
            avlCreation += endTime - startTime;
            //Add the pair of words in the HashTable
            startTime = chrono::high_resolution_clock::now();
            ht.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            htCreation += endTime - startTime;
            //Set word2 as the new word1 for the next pair
            word1 = word2;
        }

        while (ss >> word)
        {
            word2 = word;
            Pair newPair = {word1, word2};
            //Add the pair of words to the unordered array
            auto startTime = chrono::high_resolution_clock::now();
            ua.add(newPair);
            auto endTime = chrono::high_resolution_clock::now();
            uaCreation += endTime - startTime;
            //Add the pair of words to the Sorted Array
            startTime = chrono::high_resolution_clock::now();
            sa.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            saCreation += endTime - startTime;
            //Add the pair of words to the BST
            startTime = chrono::high_resolution_clock::now();
            bst.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            bstCreation += endTime - startTime;
            //Add the pair of words to the AVL Tree
            startTime = chrono::high_resolution_clock::now();
            avl.insert(newPair);
            endTime = chrono::high_resolution_clock::now();
            avlCreation += endTime - startTime;
            //Add the pair of words in the HashTable
            startTime = chrono::high_resolution_clock::now();
            ht.add(newPair);
            endTime = chrono::high_resolution_clock::now();
            htCreation += endTime - startTime;
            //Set word2 as the new word1 for the next pair
            word1 = word2;
        }
    }

    //Create Q set
    Pair* Q = new Pair[Q_size];
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber;
    for (int i = 0; i < Q_size; i++)
    {
        randomNumber = rand() % ua.getSize();
        Q[i] = ua.getPair(randomNumber);
    }

    //declaration of creation time for each data structure
    chrono::duration<double> uaSearch = chrono::duration<double>::zero();
    chrono::duration<double> saSearch = chrono::duration<double>::zero();
    chrono::duration<double> bstSearch = chrono::duration<double>::zero();
    chrono::duration<double> avlSearch = chrono::duration<double>::zero();
    chrono::duration<double> htSearch = chrono::duration<double>::zero();

    int uaTotalOccurrences = 0;
    int saTotalOccurrences = 0;
    int bstTotalOccurrences = 0;
    int avlTotalOccurrences = 0;
    int htTotalOccurrences = 0;

    for (int i = 0; i < Q_size; i++)
    {
        //search in Unordered Array
        auto startTime = chrono::high_resolution_clock::now();
        if (ua.search(Q[i]))
        {
            uaTotalOccurrences += ua.getPairCount(Q[i]);
        }
        auto endTime = chrono::high_resolution_clock::now();
        uaSearch += endTime - startTime;

        //search in Sorted Array
        startTime = chrono::high_resolution_clock::now();
        if (sa.search(Q[i]))
        {
            saTotalOccurrences += sa.getPairCount(Q[i]);
        }
        endTime = chrono::high_resolution_clock::now();
        saSearch += endTime - startTime;

        //search in BST
        startTime = chrono::high_resolution_clock::now();
        if (bst.search(Q[i]))
        {
            bstTotalOccurrences += bst.getPairCount(Q[i]);
        }
        endTime = chrono::high_resolution_clock::now();
        bstSearch += endTime - startTime;

        //search in AVL
        startTime = chrono::high_resolution_clock::now();
        if (avl.search(Q[i]))
        {
            avlTotalOccurrences += avl.getPairCount(Q[i]);
        }
        endTime = chrono::high_resolution_clock::now();
        avlSearch += endTime - startTime;

        //search in HashTable
        startTime = chrono::high_resolution_clock::now();
        if (ht.search(Q[i]))
        {
            htTotalOccurrences += ht.getPairCount(Q[i]);
        }
        endTime = chrono::high_resolution_clock::now();
        htSearch += endTime - startTime;

    }

    cout<<"creating output"<<endl;
    //Write the results to the output file
    ofstream outputFile("output.txt");
    if (outputFile.is_open())
    {
        outputFile << std::fixed << std::setprecision(5);
        outputFile << "---------------------------------------------\n";
        outputFile << "Unordered Array:\n";
        outputFile << "Unordered Array creation time: " << uaCreation.count() << " seconds\n";
        outputFile << "Total pairs: " << Q_size << "\n";
        outputFile << "Total occurrences: " << uaTotalOccurrences << "\n";
        outputFile << "Search time: " << uaSearch.count() << " seconds\n";
        outputFile << "---------------------------------------------\n";
        outputFile << "Sorted Array:\n";
        outputFile << "Sorted Array creation time: " << saCreation.count() << " seconds\n";
        outputFile << "Total pairs: " << Q_size << "\n";
        outputFile << "Total occurrences: " << saTotalOccurrences << "\n";
        outputFile << "Search time: " << saSearch.count() << " seconds\n";
        outputFile << "---------------------------------------------\n";
        outputFile << "BST:\n";
        outputFile << "BST creation time: " << bstCreation.count() << " seconds\n";
        outputFile << "Total pairs: " << Q_size << "\n";
        outputFile << "Total occurrences: " << bstTotalOccurrences << "\n";
        outputFile << "Search time: " << bstSearch.count() << " seconds\n";
        outputFile << "---------------------------------------------\n";
        outputFile << "AVL Tree:\n";
        outputFile << "AVL Tree creation time: " << avlCreation.count() << " seconds\n";
        outputFile << "Total pairs: " << Q_size << "\n";
        outputFile << "Total occurrences: " << avlTotalOccurrences << "\n";
        outputFile << "Search time: " << avlSearch.count() << " seconds\n";
        outputFile << "---------------------------------------------\n";
        outputFile << "HashTable:\n";
        outputFile << "HashTable creation time: " << htCreation.count() << " seconds\n";
        outputFile << "Total pairs: " << Q_size << "\n";
        outputFile << "Total occurrences: " << htTotalOccurrences << "\n";
        outputFile << "Search time: " << htSearch.count() << " seconds\n";
        outputFile.close();
    }
    else
    {
        cout << "Unable to write to output file." << endl;
    }

    //Clean up
    delete[] Q;

    return 0;
}
