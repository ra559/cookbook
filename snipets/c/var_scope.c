#include <stdio.h>

// Global variable (visible to all functions in the program)
int global_var = 10;

// Function demonstrating local and static variables
void demonstrateScopes() {
    int local_var = 5;               // Local variable (scope limited to this function)
    static int static_var = 0;       // Static variable (retains its value between function calls)

    printf("Enter a new value for the global variable: ");
    scanf("%d", &global_var);        // User modifies the global variable
    
    local_var++;                     // Increment local variable (reset on every call)
    static_var++;                    // Increment static variable (retains value)

    printf("Local variable: %d\n", local_var);
    printf("Static variable: %d\n", static_var);
    printf("Global variable (modified by user): %d\n", global_var);
}

int main() {
    printf("Initial global variable: %d\n", global_var);

    printf("\nCalling demonstrateScopes() the first time:\n");
    demonstrateScopes();

    printf("\nCalling demonstrateScopes() the second time:\n");
    demonstrateScopes();  // Notice how the static variable retains its incremented value

    printf("\nFinal global variable in main: %d\n", global_var);

    return 0;
}

