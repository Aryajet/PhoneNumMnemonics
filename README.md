# PhoneNumMnemonics
 Given a list of words, outputs a file of combinations from an input number in the format of ###-#### from 2-9.

For this project, I had initially thought to itterate over each number iterating over each possible value in a hashmap. this solution is still possible; however, I found it simpler to convert the words in the "ShortList.txt" file to their corresponding number. After doing so I had populated a vector for the lengths of each matching string of numbers. finally for the output this solution loops through each 3 letter word looping through each 4 letter word ending with the 7 letter words.
