import random
import string

# Lists of adjectives and nouns
adjectives = ["Happy", "Brave", "Clever", "Mighty", "Gentle", "Swift", "Wise", "Calm", "Bright", "Wild"]
nouns = ["Tiger", "Eagle", "Wizard", "Knight", "Panda", "Dragon", "Phoenix", "Wolf", "Dolphin", "Lion"]

def generate_username(include_numbers=False, include_special=False, max_length=None):
    """Generate a random username."""
    adj = random.choice(adjectives)
    noun = random.choice(nouns)
    username = adj + noun

    # Add numbers if required
    if include_numbers:
        number = str(random.randint(0, 999))
        username += number

    # Add special characters if required
    if include_special:
        special_chars = '!@#$%^&*'
        special = random.choice(special_chars)
        username += special

    # Ensure the username meets the max_length requirement
    if max_length and len(username) > max_length:
        # Reserve space for numbers and special characters if added
        reserved_length = (len(number) if include_numbers else 0) + (len(special) if include_special else 0)
        base_length = max_length - reserved_length
        base_username = adj[:base_length // 2] + noun[:base_length // 2]
        username = base_username + username[len(adj + noun):]

    return username

def save_usernames(usernames, filename="usernames.txt"):
    """Save generated usernames to a file."""
    with open(filename, 'w') as file:
        for username in usernames:
            file.write(username + '\n')
    print(f"Usernames saved to {filename}")

def get_user_preferences():
    """Get user preferences for username generation."""
    try:
        count = int(input("How many usernames would you like to generate? "))
        include_numbers = input("Include numbers? (y/n): ").lower() == 'y'
        include_special = input("Include special characters? (y/n): ").lower() == 'y'
        max_length = input("Maximum length (press Enter for no limit): ")
        max_length = int(max_length) if max_length else None
        return count, include_numbers, include_special, max_length
    except ValueError:
        print("Invalid input. Please enter a valid number.")
        return get_user_preferences()

def main():
    print("Welcome to the Random Username Generator!")
    count, include_numbers, include_special, max_length = get_user_preferences()

    usernames = set()
    while len(usernames) < count:
        username = generate_username(include_numbers, include_special, max_length)
        usernames.add(username)

    print("\nGenerated Usernames:")
    for username in usernames:
        print(username)

    save_option = input("\nDo you want to save these usernames to a file? (y/n): ").lower()
    if save_option == 'y':
        save_usernames(usernames)

if __name__ == "__main__":
    main()
