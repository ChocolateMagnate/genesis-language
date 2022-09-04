/* MIT License (C) Genesis Contributors
 * This file contains the source code for the process of compilation of the
 * Genesis programming language broken down into the following components:
 * tokenisation, parsing, semantic analysis. For the language-specific 
 * feature parsing, take a look at the Source/Genesis.h*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>

enum TokenSort{
    Keyword, Number, String, Boolean, Identifier, Operator, Delimiter, Unknown
};

/// @brief The basic type that represents the token as its value and type.
typedef struct Lexeme {
    std::string content;
    TokenSort type;  //The type of lexeme: identifier, number, string, an operator, keyword, etc.
} Lexeme;


/// @brief The hierarchical tree model of the tokens. 
class Block {
    public:
        Block *parent;
        std::list<Block*> children;
        Lexeme *lexeme;
        Block(Block *parent, Lexeme *lexeme) {
            this->parent = parent;
            this->lexeme = lexeme;
        }
        void addChild(Block *child) {
            children.push_back(child);
        }
        void Show(int depth) {
            for (int i = 0; i < depth; i++) {
                std::cout << "  ";
            }
            std::cout << lexeme->content << std::endl;
            for (Block *child : children) {
                child->Show(depth + 1);
            }
        }
};

/// @brief Generates the standard lexemes used in the language.
/// @return The map of standard tokens to their codes with the array of the keywords.
auto generateTokens() {
    //This function tokenises the source code 
    //into a list of predefined lexemes.
    std::map<std::string, Lexeme> tokens;
    //Algebraic Operators:
    tokens["+"]  = {"Add", Operator};
    tokens["-"]  = {"Subtract", Operator};
    tokens["*"]  = {"Multiply", Operator};
    tokens["/"]  = {"Divide", Operator};
    tokens["="]  = {"Assign", Operator};
    tokens["%"]  = {"Modulo", Operator};
    tokens["^"]  = {"Power", Operator};
    tokens["\\"] = {"Root", Operator};
    //Boolean Operators:
    tokens["=="] = {"Equals", Operator};
    tokens["!" ] = {"Not", Operator};
    tokens["!="] = {"Not equals", Operator};
    tokens["<"]  = {"Less", Operator};
    tokens["<="] = {"Not more", Operator};
    tokens[">"]  = {"More", Operator};
    tokens[">="] = {"Not less", Operator};
    //Equation Operators:
    tokens["+="] = {"Add to", Operator};
    tokens["-="] = {"Subtract from", Operator};
    tokens["*="] = {"Multiply by", Operator};
    tokens["/="] = {"Divide by", Operator};
    tokens["%="] = {"Modulo by", Operator};
    tokens[":="] = {"Strict assign", Operator};
    //Special symbols:
    tokens[")"]  = {"Round opening", Delimiter};
    tokens[")"]  = {"Round closing", Delimiter};
    tokens["{"]  = {"Curly opening", Delimiter};
    tokens["}"]  = {"Curly closing", Delimiter};
    tokens["["]  = {"Square opening", Delimiter};
    tokens["]"]  = {"Square closing", Delimiter};
    tokens[";"]  = {"Semicolon", Delimiter};
    tokens[":"]  = {"Colon", Delimiter};
    tokens[","]  = {"Comma", Delimiter};
    tokens["."]  = {"Dot", Delimiter};

    return tokens;
}
/// @brief (0/4) Generates the list of the keywords used in Genesis.
/// @return The array of the keywords.
auto generateKeywords(){
    std::string keywords[] = {"if", "else", "as", "for", "while", "break", "return",
                "class", "do", "private", "protected", "public", "static",  "delete", 
                "import", "this", "and", "or", "not", "true", "false", "void", "with",
                "extends", "interface", "export", "readonly", "go", "in", "out"};
    return &keywords;
}
//Global lexemes:
const auto tokens = generateTokens();
const auto keywords = generateKeywords();

/// @brief (1/4) Removes the the characters to be ignored (comments) from the source code 
/// and flags if the multiline /* comment was closed.
/// @return The formatted string with only meaningful content.
std::tuple<std::string, bool> cleanseComments(std::string source, bool commentClosed = true) {
    //Section 1. Remove everything before the closing comment.
    if (!commentClosed){
        int commentEnd = source.find("*/");
        if (commentEnd == std::string::npos) {
            return {"", false};
        } else source = source.substr(commentEnd + 2, source.length() - commentEnd);
    }
    //Section 2. Remove one-line comment.
    int indexOfComments = source.find("//");
    if (indexOfComments != std::string::npos)
        source = source.substr(0, indexOfComments); //Remove the rest of the line if // is detected.
    //Section 3. Remove multiline comment.
    indexOfComments = source.find("/*");
    bool startFound = indexOfComments != std::string::npos; //string::npos is the end of the string.
    if (startFound) {
        //Remove the rest of the line if /* is found unless it's closed with */. 
        //Otherwise, remove until the end of the line and add unclosed comment flag.
        int indexOfCommentsEnd = source.find("*/");
        bool endFound = indexOfCommentsEnd != std::string::npos;
        if (endFound) {
            source = source.substr(0, indexOfComments) + source.substr(indexOfCommentsEnd + 2);
            commentClosed = !commentClosed;
        } else {
            source = source.substr(0, indexOfComments);
            commentClosed = false;
        }
    }
    return {source, commentClosed};
}


/// @brief (2/4) Divides the source code into the sequence of sliced lexemes ready to be parsed.
/// @return The list of individual lexemes.
std::list<std::string> splitIntoComponents(std::string source) {
    //Splits the input string into the components
    //that can be parsed as individual tokens.
    
    return std::list<std::string>();
};

/// @brief (3/4) Parses the tokens into specified lexemes by mathing tokens, keywords and identifiers.
/// @return The sequence of configured lexemes.
std::list<Lexeme> tokenise(std::string source) {
    //This function tokenises the source code into a list of lexemes.
    std::list<Lexeme> lexemes; //Below is only the reference to the primary tokens.
    return lexemes;
}

/// @brief (4/4) Parses the lexemes into the hierarchical tree model of the tokens.
/// @return The statement pattern as an integer.
auto parseIntoPattern(std::list<Lexeme> lexemes) {
    int pattern{}; //The initial pattern of the code.

    return pattern;
};
