// CSC 134 
// M3HW1 - Bronze 
// Colby Watts
// 19OCT2025

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

/**
 * @brief Runs a fixed-script chat bot simulation.
 * * This function handles the I/O, mimicking the structure and responses
 * of the original Python script using C++ strings and streams.
 */
void run_chatbot_simulation() {
    std::cout << "--- Simple Chat Bot Conversation ---\n";
    std::cout << "ChatBot: Hello! I am a very simple chat bot. What is your name?\n";
    
    // --- Interaction 1: Get Name ---
    std::string name;
    std::cout << "You: ";
    // Use getline to capture the entire input line, including spaces.
    if (!std::getline(std::cin, name) || name.empty()) {
        // Fallback case (mimics EOFError handling in Python)
        name = "User";
        std::cout << name << "\n";
    }

    // Bot Response 1: Acknowledgment and a new question
    std::cout << "ChatBot: Nice to meet you, " << name << ". How is your day going so far?\n";

    // --- Interaction 2: Get Mood ---
    std::string mood;
    std::cout << "You: ";
    if (!std::getline(std::cin, mood) || mood.empty()) {
        // Fallback case
        mood = "okay";
        std::cout << mood << "\n";
    }

    // Bot Response 2: Simple empathic statement (requires case-insensitive check)
    std::string lower_mood = mood;
    // Convert the input string to lowercase for case-insensitive checking
    std::transform(lower_mood.begin(), lower_mood.end(), lower_mood.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (lower_mood.find("good") != std::string::npos || 
        lower_mood.find("great") != std::string::npos || 
        lower_mood.find("fine") != std::string::npos) {
        std::cout << "ChatBot: That is wonderful! A good day makes everything better.\n";
    } else {
        std::cout << "ChatBot: I understand. Keep your head up, I hope the rest of your day improves.\n";
    }
    
    // Bot asks the final question
    std::cout << "ChatBot: I have to go now. What is one small thing you plan to do tomorrow?\n";

    // --- Interaction 3: Get Plan ---
    std::string plan;
    std::cout << "You: ";
    if (!std::getline(std::cin, plan) || plan.empty()) {
        // Fallback case
        plan = "sleep in";
        std::cout << plan << "\n";
    }

    // Bot Response 3: A closing statement and farewell
    std::cout << "ChatBot: " << plan << "... that sounds nice. Thanks for the quick chat.\n";
    std::cout << "ChatBot: Goodbye for now!\n";
    std::cout << "--- Conversation End ---\n";
}

int main() {
    // Note: The use of std::ios_base::sync_with_stdio(false); and 
    // std::cin.tie(NULL); is not strictly necessary for simple console I/O
    // but can improve performance in competitive programming contexts.
    
    run_chatbot_simulation();
    
    return 0;
}
