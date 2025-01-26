def count_words(text):
    """
    Count the number of words in the given text.
    
    Args:
    text (str): The input text to count words from.
    
    Returns:
    int: The number of words in the text.
    """
    # Split the text into words and count them
    words = text.split()
    return len(words)

def get_user_input():
    """
    Prompt the user to enter a sentence or paragraph.
    
    Returns:
    str: The user's input text.
    """
    return input("Please enter a sentence or paragraph: ")

def main():
    """
    Main function to run the Word Counter program.
    """
    print("Welcome to the Word Counter program!")
    
    while True:
        # Get user input
        user_text = get_user_input()
        
        # Check if the input is empty
        if not user_text.strip():
            print("Error: Empty input. Please try again.")
            continue
        
        # Count words
        word_count = count_words(user_text)
        
        # Display the result
        print(f"\nWord count: {word_count}")
        
        # Ask if the user wants to continue
        choice = input("\nDo you want to count words in another text? (yes/no): ").lower()
        if choice != 'yes':
            break
    
    print("Thank you for using the Word Counter program!")

# Run the program
if __name__ == "__main__":
    main()