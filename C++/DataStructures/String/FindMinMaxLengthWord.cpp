/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andresfe24
 *
 * Created on June 2, 2017, 8:47 PM
 */

/* Libraries */

/* Standard input/output streams library */
#include <iostream>

/* Functions to manipulate C strings and arrays */
#include <cstring>

/* C standard general utilities library */
#include <cstdlib>

/* Methods */

/*
 * Find smallest and largest word in input string
 * 
 * @param str string Input string to be processed
 * @param minWord reference to string Reference to store smallest length word
 * @param maxWord reference to string Reference to store largest length word
 */
void findMinMaxLengthWords(std::string str, std::string &minWord, std::string &MaxWord)
{
    /* input string length */
    int len = str.length();
    
    /* Start and end of word index to keep track of words */
    int si = 0;
    int ei = 0;
    
    /* Initialize lengths and indexes for min and max cases */
    int minLength = len;
    int minStartIndex = 0;
    int maxLength = 0;
    int maxStartIndex = 0;
    
    /* Loop through string until the end is reached */
    while (ei <= len)
    {
        /* If end has not been reached and not a space, increase end of word index */
        if ( (ei < len) && (str.at(ei) != ' ') )
        {
            /* Increase end of word index */
            ei++;
        }
        /* End of a word found */
        else
        {
            /* Current word length */
            int currLength = ei - si;
            
            /* If smaller than smallest so far */
            if (currLength < minLength)
            {
                /* Update smallest length of word and its start index in string */
                minLength = currLength;
                minStartIndex = si;
            }
            
            /* If larger than largest word so far */
            if (currLength > maxLength)
            {
                /* Update max length of word and its start index in string */
                maxLength = currLength;
                maxStartIndex = si;
            }
            
            /* Increase end index so that next character is checked*/
            ei++;
            
            /* Update start index to the next character */
            si = ei;
        }
        
        // Store minimum and maximum length words
        minWord = str.substr(minStartIndex, minLength);
        MaxWord = str.substr(maxStartIndex, maxLength); 
    }
}

/*
 * Main method
 */
int main(int argc, char** argv)
{
    /* Input string */
    std::string input = "GeeksforGeeks A Computer Science portal for Geek";
    
    /* Strings to store smallest and largest word in input string */
    std::string minWord, maxWord;
    
    /* Find smallest and larget word in string */
    findMinMaxLengthWords(input, minWord, maxWord);
    
    /* Print strings */
    std::cout << "Min length word: "
            << minWord << std::endl
            << "Max length word: "
            << maxWord << std::endl;

    /* Return success */
    return 0;
}

