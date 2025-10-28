#include <stdio.h>
#include <stddef.h> // for size_t

// ---------- Hjælpefunktioner ----------

// Byttefunktion for tal
void int_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Byttefunktion for bogstaver
void char_swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Sammenligningsfunktion for tal
int int_pair_is_in_order(int a, int b) {
    return a > b; // returnerer 1 (true), hvis venstre tal er større end højre
}

// Sammenligningsfunktion for bogstaver
int char_pair_is_in_order(char a, char b) {
    return a > b; // returnerer 1 (true), hvis venstre bogstav skal byttes med højre
}

// ---------- Sorteringsfunktioner ----------

// Bubblesort for heltal
void bubbleSortInt(int *arr, size_t size) {
    for (size_t pass = 0; pass < size; pass++) {
        for (size_t i = 0; i < size - 1; i++) {
            if (int_pair_is_in_order(arr[i], arr[i + 1])) {
                int_swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

// Bubblesort for bogstaver
void bubbleSortChar(char *arr, size_t size) {
    for (size_t pass = 0; pass < size; pass++) {
        for (size_t i = 0; i < size - 1; i++) {
            if (char_pair_is_in_order(arr[i], arr[i + 1])) {
                char_swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

// ---------- Hovedprogram ----------

int main(void) {
    int n_nums, n_chars;

    // Læs tal fra brugeren
    printf("Hvor mange tal vil du indtaste? ");
    scanf("%d", &n_nums);

    int nums[n_nums];
    printf("Indtast %d tal (adskilt med mellemrum): ", n_nums);
    for (int i = 0; i < n_nums; i++) {
        scanf("%d", &nums[i]);
    }

    // Læs bogstaver fra brugeren
    printf("Hvor mange bogstaver vil du indtaste? ");
    scanf("%d", &n_chars);

    char chars[n_chars + 1]; // +1 til '\0'
    printf("Indtast %d bogstaver (ingen mellemrum, fx abcde): ", n_chars);
    scanf("%s", chars);

    // Sortér begge arrays
    bubbleSortInt(nums, n_nums);
    bubbleSortChar(chars, n_chars);

    // Udskriv resultater
    printf("\nSorterede tal: ");
    for (int i = 0; i < n_nums; i++) {
        printf("%d ", nums[i]);
    }

    printf("\nSorterede bogstaver: ");
    for (int i = 0; i < n_chars; i++) {
        printf("%c ", chars[i]);
    }

    printf("\n");
    return 0;
}
