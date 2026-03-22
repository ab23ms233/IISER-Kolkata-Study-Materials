# QUESTION
# Consider a ball dropping from a height ‘h’ (value, in cms, taken as input from the user). Each time the ball hits the ground, it bounces up half the immediate previous height it was at. That is after it is dropped from height h, it hits the ground and bounces up height h/2, drops down again, hits the ground, and bounces up height h/4, and so on. Write a program that prints these heights h, h/2, h/4…n times, where n is taken as input from the user. However, if the height reaches 0.05 cm, you should stop immediately. Also, you should print these heights as floating-point numbers using formatted output.

height = int(input("Enter height: "))

while height > 0.05:
    print(height)
    height /= 2
