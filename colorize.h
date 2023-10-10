#ifndef COLORIZE_H
#define COLORIZE_H

// Define color codes for different text colors
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

// Define macros for colorizing output
#define RED(text) COLOR_RED text COLOR_RESET
#define GREEN(text) COLOR_GREEN text COLOR_RESET
#define YELLOW(text) COLOR_YELLOW text COLOR_RESET
#define BLUE(text) COLOR_BLUE text COLOR_RESET
#define MAGENTA(text) COLOR_MAGENTA text COLOR_RESET
#define CYAN(text) COLOR_CYAN text COLOR_RESET

#endif // COLORIZE_H
