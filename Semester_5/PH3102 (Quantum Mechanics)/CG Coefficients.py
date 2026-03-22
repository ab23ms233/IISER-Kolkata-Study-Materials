from typing import Any

def J_(state: list[int]) -> tuple[int, list[Any]]:
    """
    Caclulates the Clebsch-Gordan coeffcient and the new state obtained on operating the angular momentum lowering operator (J_) on a given state

    Parameters:
        state (list[int]): A list containing the quantum numbers [j, m]

    Returns:
        tuple[int, list[Any]]: A tuple containing the Clebsch-Gordan coefficient and the new state [j, m-1]  

    Raises:
        ValueError: If the input state does not contain exactly two elements
        TypeError: If either j or m is not an integer
    """
    if len(state) != 2:
        raise ValueError("State must be a list of two integers [j, m]")
    if all(not isinstance(x, int) for x in state):
        raise TypeError("Both j and m must be integers")
    
    j = state[0]
    m = state[1]
    new_state = [j, m-1]

    CG = (j*(j+1) - m*(m-1))**(0.5)

    return (CG, new_state)


j1 = int(input("Enter j1: "))
j2 = int(input("Enter j2: "))

J = j1+j2

for i in range(J, -J, -1):
    state = [J, i]
    CG, new_state = J_(state)
    CG = round(CG, 2)
    print(f"J_|{state[0]}, {state[1]}> = {CG}|{new_state[0], new_state[1]}>")
