# Frankentext

This project is all about implementing the markov chain principle as a text generator.
It takes "Frankenstein" book, and analyzes it to find how words follow each other. After that,
it generates new random sentences that sound like they come from the same book. 

The program firsst embeds the text file directly into the code, cleans it up so only printable characteers
remain. Then, it splits the entire text into tokens which are basically unique words with corresponding ID's. 
Each word is stored together with a list of possible successor words that can naturally follow it based
oin the original text. 

When generating a sentence, the program picks a random word that looks like a valid sentence start. It then
keeps choosing random successor words one by one, until it reaches a word that ends with a period, exclamation mark or question mark.
The result is a randomly generated sentence that imitates the writing style of the original text. 

Compared to the original assignment, this version makes it modular and organized differently. Each part of the
program, such as text cleaning, tokenizing, Markov building, and sentence generation is placed in it's own header and .c file. 
There are also extra safety checks and fallbacks added to prevent buffer overflows and to handle edge cases better. 
The main logic however stays true to the orginal assignment. 
