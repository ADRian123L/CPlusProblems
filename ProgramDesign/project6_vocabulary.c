/**
 * @file     project6_vocabulary.c
 * @author   Adrian Lozada
 * @date     2023-03-21
 * @brief    This program reads a text file, sorts the words alphabetically,
 *           removes duplicates, and writes the unique words into another file.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes:
void sort(char *str[]);
int compare(const char *first, const char *second);
void copy(int argc, char *argv[]);
void cap(char *str);
int string_exists_in_array(char *str, char *array[], int index);
void write_unique_strings_to_file(char *array[], char *name_of_file_to_write_to);
void read_and_print_strings(const char *file_name);
int read_words_into_array(const char *filename, char array[1000][1000]);

int main(int argc, char *argv[]) {
    /// @brief This function is the main function of the program.
    if (argc < 3) {
        printf("Please provide input and output file names.\n");
        return 0;
    }
    // Read the strings from the input file. Sort the strings. Write the unique strings to the output file.
    copy(argc, argv);
    return 0;
}

int compare(const char *first, const char *second) {
    /// @brief This function compares two strings.
    return strcmp(first, second);
}

void sort(char *str[]) {
    /// @brief This function sorts the strings in the array.
    char **p;
    p = &str[1];
    for (char **j, *key; *p; ++p) {
        j = (p - 1);
        key = *p;
        while (j >= &str[0] && compare(*j, key) > 0) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

void copy(int argc, char *argv[]) {
    /// @brief This function copies the strings from the input file to the output file.
    FILE *pfile;
    pfile = fopen(argv[1], "r");
    if (pfile == NULL) {
        printf("Could not open %s\n", argv[1]);
        return;
    }
    // char str[1000][1000];
    char *str[1000] = {NULL}, **p = &str[0];
    char word[1000][1000];
    read_words_into_array(argv[1], word);
    // Copy the strings from the input file to the output file.
    for (int i = 0; i < 1000; i++) {
        if (word[i][0] == '\0') {
            break;
        }
        *p = word[i];
        cap(*p);
        p++;
    }
    // Add a NULL pointer to the end of the array.
    *p = NULL;
    fclose(pfile);
    // Sort the strings in the array.
    sort(str);
    // Write the unique strings to the output file.
    write_unique_strings_to_file(str, argv[2]);
    // Print the strings in the output file.
    read_and_print_strings(argv[2]);
}

void read_and_print_strings(const char *file_name) {
    /// @brief This function reads the strings from the output file and prints them.
    /// @param file_name The name of the file to be read.
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Could not open the file: %s\n", file_name);
        return;
    }
    
    char buffer[1000];
    int count = 1;
    while (fscanf(file, "%s", buffer) != EOF) {
        printf("%s\n", buffer);
    }

    fclose(file);
}

void cap(char *str) {
    /// @brief This function capitalizes the first letter of each word.
    /// @param str The string to capitalize
    if (str == NULL || *str == '\0') {
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        /// @note The toupper function will return the upper case
        /// version of the given character if it is a lower case
        /// character. If the character is already upper case, it
        /// will return the character unchanged.
        str[i] = toupper(str[i]);
    }
}

int string_exists_in_array(char *str, char *array[], int index) {
    /// @brief This function checks if a string exists in an array.
    // Loop through the array
    for (int i = 0; i < index; i++) {
        // Check if the string exists in the array
        if (strcmp(str, array[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void write_unique_strings_to_file(char *array[], char *name_of_file_to_write_to) {
    /// @brief This function writes the unique strings to the output file.
    char *unique[1000] = {NULL}; // Creates an array of 1000 pointers to characters.
    int unique_index = 0; // Counter for the unique array.

    for (char **current = array; *current != NULL; ++current) {
        // Loop through the array of pointers to characters.
        if (!string_exists_in_array(*current, unique, unique_index)) {
            // If the string does not exist in the unique array, add it.
            unique[unique_index++] = *current;
        }
    }
    unique[unique_index] = NULL; // Make sure the last element is NULL.

    FILE *file = fopen(name_of_file_to_write_to, "w");
    if (file == NULL) {
        printf("Could not open the file: %s\n", name_of_file_to_write_to);
        return;
    }
    int count = 1;
    for (char **current = unique; *current != NULL; ++current) {
        cap(*current);
        fprintf(file, "%d%s\n", count++, *current);
    }

    fclose(file);
}

int read_words_into_array(const char *filename, char array[1000][1000]) {
    // Open the file for reading.
    FILE *file = fopen(filename, "r");

    // Check that the file was opened successfully.
    if (file == NULL) {
        printf("Could not open the file: %s\n", filename);
        return -1;
    }

    // Read words from the file into the array.
    int word_count = 0;
    while (fscanf(file, "%999s", array[word_count]) != EOF && word_count < 1000) {
        word_count++;
    }

    // Close the file.
    fclose(file);

    // Return the number of words read from the file.
    return word_count;
}