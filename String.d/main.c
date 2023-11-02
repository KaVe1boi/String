#include <stdio.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1024

void insertDateLine(FILE *file) {
    // Get the current date and time
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime); // Hent alle sekunder siden 1970
    timeinfo = localtime(&rawtime); // Formater disse sekunder som beskrevet i

    // Format the date and time
    char currentDate[80];
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Insert the date line and prompt
    fprintf(file, "Diary entry for %s\n", currentDate); // Gem i filen
}

int main() {
    // Åben filen til tilføjelse/append (a+)
    FILE *file = fopen("C:/Users/TT/skrald/diary.txt", "a+");

    if (!file) {
        perror("Error: Unable to open diary file");
        return 1;
    }

    insertDateLine(file);

    printf("Enter your diary entry below (Ctrl+Z to save and exit):\n");
    char entry[MAX_ENTRY_LENGTH]; // Deklarér entry med den korrekte makro
    while (fgets(entry, sizeof(entry), stdin) != NULL) {
        fprintf(file, "%s", entry);
    }

    fclose(file); // Husk at lukke filen, når du er færdig med at skrive i den

    return 0;
}
