/**
 * @mainpage TERCOL - Terminal Color Utility
 *
 * TERCOL is an ANSI color utility header-only library that simplifies terminal text formatting
 * using standard SGR escape sequences.
 *
 * ## Features:
 * - Text color and background formatting
 * - Attributes like bold, underline, italic
 * - Progress bar rendering
 *
 * @file tercol.h
 * @brief TERCOL is an ANSI Color Utility Library for terminal text formatting.
 * @author PRASHANT KUMAR JHA
 * @license MIT
 *
 *
 * MIT License
 *
 * Copyright (c) 2025 Prashant Kumar Jha
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @date 11-06-2025
 * @warning This code will only work if your terminal supports SELECT GRAPHIC RENDITION (SGR).
 */

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>


#ifndef TERCOL_LIBRARY_H
#define TERCOL_LIBRARY_H

/**
 * @namespace color
 * @brief Contains ANSI escape sequences and printing utilities for terminal styling.
 */
namespace color {
    /** @name RESET CODE */
    ///@{
    constexpr auto RESET = "\033[0m"; ///< ALL ATTRIBUTES BECOME TURNED OFF
    ///@}

    /** @name TEXT ATTRIBUTES */
    ///@{
    constexpr auto BOLD = "\033[1m";
    constexpr auto DIM = "\033[2m";
    constexpr auto ITALIC = "\033[3m"; ///< NOT WIDELY SUPPORTED. Sometimes treated as inverse or blink
    constexpr auto UNDERLINE = "\033[4m";
    constexpr auto BLINK = "\033[5m"; ///< Sets blinking to <150 times per minute
    constexpr auto RAPID_BLINK  = "\033[6m"; ///< NOT WIDELY SUPPORTED
    constexpr auto REVERSE = "\033[7m"; /// <Swap foreground and background colors
    constexpr auto HIDE = "\033[8m"; /** NOT WIDELY SUPPORTED */
    constexpr auto STRIKETHROUGH = "\033[9m";
    ///@}

    /** @name Font Selection. Not widely supported */
    ///@{
    constexpr auto PRIMARY_FONT = "\033[10m";
    constexpr auto FONT_1 = "\033[11m";
    constexpr auto FONT_2 = "\033[12m";
    constexpr auto FONT_3 = "\033[13m";
    constexpr auto FONT_4 = "\033[14m";
    constexpr auto FONT_5 = "\033[15m";
    constexpr auto FONT_6 = "\033[16m";
    constexpr auto FONT_7 = "\033[17m";
    constexpr auto FONT_8 = "\033[18m";
    constexpr auto FONT_9 = "\033[19m";
    ///@}

    /** @name ATTRIBUTE RESETS */
    ///@{
    constexpr auto NORMAL_INTENSITY = "\033[22m";  /** RESETS BOLD AS WELL AS DIM */
    constexpr auto NO_BOLD = "\033[22m";
    constexpr auto NO_ITALIC = "\033[23m";
    constexpr auto NO_UNDERLINE = "\033[24m";
    constexpr auto NO_BLINK = "\033[25m";
    constexpr auto NO_REVERSE = "\033[27m";
    constexpr auto NO_HIDE = "\033[28m";
    constexpr auto NO_STRIKETHROUGH = "\033[29m";
    ///@}

    /** @name STANDARD FOREGROUND COLORS */
    ///@{
    constexpr auto BLACK = "\033[30m";
    constexpr auto RED = "\033[31m";
    constexpr auto GREEN = "\033[32m";
    constexpr auto YELLOW = "\033[33m";
    constexpr auto BLUE = "\033[34m";
    constexpr auto PURPLE = "\033[35m";
    constexpr auto CYAN = "\033[36m";
    constexpr auto WHITE = "\033[37m";
    ///@}

    /** @name RESET FOREGROUND COLOR */
    ///@{
    constexpr auto DEFAULT_FG = "\033[39m";
    ///@}

    /** @name STANDARD BACKGROUND COLORS */
    ///@{
    constexpr auto BG_BLACK = "\033[40m";
    constexpr auto BG_RED = "\033[41m";
    constexpr auto BG_GREEN = "\033[42m";
    constexpr auto BG_YELLOW = "\033[43m";
    constexpr auto BG_BLUE = "\033[44m";
    constexpr auto BG_MAGENTA = "\033[45m";
    constexpr auto BG_CYAN = "\033[46m";
    constexpr auto BG_WHITE = "\033[47m";
    ///@}

    /** @name RESET BACKGROUND COLOR */
    ///@{
    constexpr auto DEFAULT_BG = "\033[49m";

    /** @name DECORATIVE (Limited support) */
    ///@{
    constexpr auto FRAMED = "\033[51m";
    constexpr auto ENCIRCLED = "\033[52m";
    constexpr auto OVERLINED = "\033[53m";
    constexpr auto NO_FRAME_ENCIRCLE = "\033[54m";
    constexpr auto NO_OVERLINE = "\033[55m";
    ///@}

    /** @name BRIGHT COLORS (High intensity) */
    ///@{
    constexpr auto BRIGHT_BLACK = "\033[90m";
    constexpr auto BRIGHT_RED = "\033[91m";
    constexpr auto BRIGHT_GREEN = "\033[92m";
    constexpr auto BRIGHT_YELLOW = "\033[93m";
    constexpr auto BRIGHT_BLUE = "\033[94m";
    constexpr auto BRIGHT_MAGENTA = "\033[95m";
    constexpr auto BRIGHT_CYAN = "\033[96m";
    constexpr auto BRIGHT_WHITE = "\033[97m";
    ///@}

    /** @name BRIGHT BACKGROUNDS */
    ///@{
    constexpr auto BG_BRIGHT_BLACK = "\033[100m";
    constexpr auto BG_BRIGHT_RED = "\033[101m";
    constexpr auto BG_BRIGHT_GREEN = "\033[102m";
    constexpr auto BG_BRIGHT_YELLOW = "\033[103m";
    constexpr auto BG_BRIGHT_BLUE = "\033[104m";
    constexpr auto BG_BRIGHT_MAGENTA = "\033[105m";
    constexpr auto BG_BRIGHT_CYAN = "\033[106m";
    constexpr auto BG_BRIGHT_WHITE = "\033[107m";
    ///@}


        /**
     * @brief Generates ANSI escape code for 256-color foreground.
     *
     * @param color An integer between 0 and 255 representing the desired foreground color.
     * @return std::string ANSI escape sequence to set the terminal's foreground color.
     *
     * @note Requires terminal support for 256-color mode (e.g., xterm-compatible terminals).
     */
    inline std::string fg_256(int color) {
        return "\033[38;5;" + std::to_string(color) + "m";
    }

    /**
     * @brief Generates ANSI escape code for 256-color background.
     *
     * @param color An integer between 0 and 255 representing the desired background color.
     * @return std::string ANSI escape sequence to set the terminal's background color.
     *
     * @note Requires terminal support for 256-color mode (e.g., xterm-compatible terminals).
     */
    inline std::string bg_256(int color) {
        return "\033[48;5;" + std::to_string(color) + "m";
    }

    /**
     * @brief Generates ANSI escape code for RGB true-color FOREGROUND.
     *
     * @param r Red component (0–255)
     * @param g Green component (0–255)
     * @param b Blue component (0–255)
     * @return std::string ANSI escape sequence to set the terminal's foreground color.
     *
     * @note Requires terminal support for 24-bit true color (most modern terminals support this).
     */
    inline std::string fg_rgb(int r, int g, int b) {
        return "\033[38;2;" + std::to_string(r) + ";"
                          + std::to_string(g) + ";"
                          + std::to_string(b) + "m";
    }

    /**
     * @brief Generates ANSI escape code for RGB true-color BACKGROUND.
     *
     * @param r Red component (0–255)
     * @param g Green component (0–255)
     * @param b Blue component (0–255)
     * @return std::string ANSI escape sequence to set the terminal's background color.
     *
     * @note Requires terminal support for 24-bit true color (most modern terminals support this).
     */
    inline std::string bg_rgb(int r, int g, int b) {
        return "\033[48;2;" + std::to_string(r) + ";"
                          + std::to_string(g) + ";"
                          + std::to_string(b) + "m";
    }


    /**
     * @brief Prints the given text with a color followed by a newline.
     * @tparam T The type of text to print (supports std::string, const char*, etc.)
     * @param color ANSI color code to apply.
     * @param text The text to print.
     */
    template<typename T>
    void printc(const std::string& color, const T& text) {
        std::cout << color << text << RESET << std::endl;
    }

    /**
     * @brief Prints the given text with a color without adding a newline.
     * @tparam T The type of text to print (supports std::string, const char*, etc.)
     * @param color ANSI color code to apply.
     * @param text The text to print.
     */
    template<typename T>
    void printcf(const std::string& color, const T& text) {
        std::cout << color << text << RESET;
    }

    /**
     * @brief Builds and returns a colored string without printing it.
     *
     * This function wraps the given text with ANSI color codes and returns it
     * as a std::string. It is useful for preparing formatted output to be printed later.
     *
     * @tparam T The type of the text (e.g., std::string, int, float, etc.).
     * @param color The ANSI color escape code to use.
     * @param text The content to wrap with color.
     * @return std::string The formatted colored string with reset code.
     *
     * @note The string is not printed to the terminal — it is returned to the caller.
     */
    template<typename T>
    std::string colorize(const std::string& color, const T& text) {
        std::ostringstream oss;
        oss << color << text << RESET;
        return oss.str();
    }

    /**
     * @brief Displays a colored progress bar on the terminal.
     * @param percentage float showing the percentage of progress (0–100).
     * @param width The total width of the progress bar (default is 50).
     * @param color ANSI color code for the progress bar (default is bright green).
     */
    void progress_bar(float percentage, int width = 50,
                     const std::string& color = BRIGHT_GREEN) {
        int pos = static_cast<int>(width * percentage / 100.0);
        std::cout << "[";
        for (int i = 0; i < width; ++i) {
            if (i < pos) std::cout << color << "=";
            else std::cout << " ";
        }
        std::cout << RESET << "] " << int(percentage) << " %\r";
        std::cout.flush();

    }
}

#endif //TERCOL_LIBRARY_H