/**
* @file demo.cpp
* @brief Demo program for the tercol.h
*/
#include <tercol.h>
#include <unistd.h>

int main() {
    using namespace color;

    // Demo
    printc(RED,     "This is red text");
    printc(GREEN,   "This is green text");
    printc(BLUE,    "This is blue text");

    // Demo
    printc(BOLD,          "This is bold text");
    printc(UNDERLINE,     "This is underlined text");
    printc(ITALIC,        "This is italic text (if supported)");
    printc(STRIKETHROUGH, "This is strikethrough text");

    // Demo 256-color foreground
    for (int i = 16; i < 32; ++i) {
        printcf(fg_256(i), "█");
    }
    std::cout << RESET << std::endl;

    // Demo RGB foreground color
    printc(fg_rgb(255, 128, 0), "This is orange using RGB");

    // Demo RGB background color
    printc(bg_rgb(0, 128, 255) + BLACK, "Black text on blue background");

    // Demo Colorize without printing
    std::string fancy = colorize(BRIGHT_MAGENTA, "Fancy colored string");
    std::cout << "Buffered output: " << fancy << std::endl;

    // Show a progress bar
    for (int i = 0; i <= 100; i += 1) {
        progress_bar(i);
        usleep(50000);
    }
    std::cout << std::endl;

    return 0;
}

