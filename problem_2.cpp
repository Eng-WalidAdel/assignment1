
#include <iostream>
#include <string>
using namespace std;

// This function processes the input sentence to replace gender-specific pronouns
// with gender-neutral equivalents (e.g., "he" becomes "he or she").
string inclusive_speech_processor ( string& sentence ){

    string word, inclusive_speech; // 'word' holds each word being processed; 'inclusive_speech' stores the modified sentence.

    // Loop through each character in the input sentence.
    for (char letter : sentence){

        // Check if the current character is a separator (punctuation or space).
        if ( letter == ' ' || letter == '?' || letter == ',' || letter == '.' ||
             letter == ';' || letter == ':' || letter == '!' || letter == '-' ||
             letter == '"' || letter == '/' || letter == '(' || letter == ')' ){

            // Check if the current word is a gender-specific pronoun and replace it.
            if ( word == "he" || word == "she" ){
                inclusive_speech += "he or she"; // Replace "he" or "she" with "he or she".
            }

            else if ( word == "He" || word == "She" ){
                inclusive_speech += "He or She"; // Replace "He" or "She" with "He or She".
            }

            else if ( word == "him" || word == "her" ){
                inclusive_speech += "him or her"; // Replace "him" or "her" with "him or her".
            }

            else if ( word == "Him" || word == "Her" ){
                inclusive_speech += "Him or Her"; // Replace "Him" or "Her" with "Him or Her".
            }

            else if ( word == "his" || word == "hers" ){
                inclusive_speech += "his or hers"; // Replace "his" or "hers" with "his or hers".
            }

            else if ( word == "His" || word == "Hers" ){
                inclusive_speech += "His or Hers"; // Replace "His" or "Hers" with "His or Hers".
            }

            else if ( word == "himself" || word == "herself" ){
                // Replace "himself" or "herself" with "himself or herself".
                // Note: It's assumed "himself" or "herself" won't start a sentence.
                inclusive_speech += "himself or herself";
            }

            else {
                // If the word is not a gender-specific pronoun, add it to the result unchanged.
                inclusive_speech += word;
            }

            // Add the punctuation or space (the current letter) to the result.
            inclusive_speech += letter;
            word.clear(); // Clear the current word to start building the next word.
        }

        else {
            // If the current character is not punctuation or a space, it's part of a word.
            word += letter; // Add the character to the current word.
        }
    }

    return inclusive_speech; // Return the modified sentence.
}

int main() {
    string sentence;
    getline(cin, sentence); // Read the input sentence from the user.

    // Process the sentence and print the inclusive version.
    cout << inclusive_speech_processor(sentence) << endl;

    return 0;
}


// See an adviser and talk to him. He will guide you.
// Did you ask him?
// HE2 is a new store.