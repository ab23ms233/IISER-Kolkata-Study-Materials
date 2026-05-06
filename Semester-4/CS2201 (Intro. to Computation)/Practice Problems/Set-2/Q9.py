# QUESTION
# Without taking using input create a dictionary with some userid: password pairs as key:value pairs. 

# i) Now take a userid from the user (use input()). If this userid is in your dictionary, print, ask for password; if the password is also correct print “Welcome to the portal!”; otherwise (if userid or password is wrong) print “Invalid credentials!”

# ii) Create a service for password change. Take a userid from the user (use input()). If this userid is in your dictionary, ask for a new password (twice). If the provided passwords are the same (and different from the existing password), update the corresponding password in the dictionary. If the userid is not in your dictionary, print “Invalid username”.

user_password = {'ab23ms233':'nag43fay', 'ab23ms016':'sig25xux', 'arya_basak':'SineAlpha1'}
user = input("Enter User ID: ")

# If username is correct
if user in user_password:
    print("Choose 1 to enter password")
    print("Choose 2 to change password")
    choice = int(input())
    
    while True:
        password = input("Enter password: ")

        # If password is correct
        if user_password[user] == password:

            # Welcoming the user
            if choice == 1:
                print("Welcome to the portal!")

            # Change password
            elif choice == 2:
                while True:
                    new = input("Enter new password: ")
                    confirm = input("Confirm password: ")

                    if new != confirm:  # Passwords do not match
                        print("Passwords do not match")
                    elif new == user_password[user]:    # new and old passwords are the same
                        print("New password cannot be same as the previous one")
                    else:   # password changed
                        user_password[user] = new
                        print("Password changed successfully")
                        break  
            break
        
        else:   # if password is wrong
            print("Wrong Password")

# If username is wrong
else:
    print("Invalid UserId")
