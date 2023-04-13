#include "/workspaces/motion/src/include/errors.h"

#include <stdlib.h>
#include <string.h>

#include "/workspaces/motion/src/include/scanner.h"

char* stringWithArrows(const char* text, const int pos_start,
                       const int pos_end) {
    // Calculate indices
    int idx_start = pos_start;
    while (idx_start > 0 && text[idx_start - 1] != '\n') {
        idx_start--;
    }
    int idx_end = pos_end;
    while (idx_end < strlen(text) && text[idx_end] != '\n') {
        idx_end++;
    }

    // Calculate maximum size of result string
    int line_count = 1;
    for (int i = idx_start; i < idx_end; i++) {
        if (text[i] == '\n') {
            line_count++;
        }
    }
    int max_result_size =
        idx_end - idx_start + line_count + 1;  // Add 1 for null terminator

    // Allocate memory for result string
    char* result = malloc(max_result_size);
    if (result == NULL) {
        return NULL;  // Allocation failed
    }
    result[0] = '\0';

    // Generate each line
    int line_start = idx_start;
    for (int i = 0; i < line_count; i++) {
        // Calculate line columns
        int line_end = idx_end;
        for (int j = line_start; j < idx_end; j++) {
            if (text[j] == '\n') {
                line_end = j;
                break;
            }
        }
        int col_start = (i == 0) ? pos_start - idx_start : 0;
        int col_end =
            (i == line_count - 1) ? pos_end - idx_start : line_end - idx_start;

        // Append to result
        strncat(result, text + line_start, line_end - line_start);
        strcat(result, "\n");
        for (int j = 0; j < col_start; j++) {
            strcat(result, " ");
        }
        for (int j = col_start; j < col_end; j++) {
            strcat(result, "^");
        }
        strcat(result, "\n");

        // Update line_start
        line_start = line_end + 1;
    }

    // Replace tabs with spaces
    char* tab = "\t";
    char* space = " ";
    char* tab_pos = strstr(result, tab);
    while (tab_pos != NULL) {
        memcpy(tab_pos, space, 1);
        memmove(tab_pos + 1, tab_pos + 1 + strlen(tab),
                strlen(tab_pos + 1 + strlen(tab)) + 1);
        tab_pos = strstr(result, tab);
    }

    return result;
}
