q0, q1, q2, q3, q4, q5 = "q0", "q1", "q2", "q3", "q4", "q5"
atual = q0
final = [q1, q3]
cod = "bbba"

for char in cod:
    if atual == q0:
        if char == "a":
            atual = q1
        elif char == "b":
            atual = q2
    elif atual == q1:
        if char == "a":
            atual = q1
        elif char == "b":
            atual = q1
    elif atual == q2:
        if char == "a":
            atual = q3
        elif char == "b":
            atual = q4
    elif atual == q3:
        if char == "a":
            atual = q1
        elif char == "b":
            atual = q3
    elif atual == q4:
        if char == "a":
            atual = q3
        elif char == "b":
            atual = q5
    elif atual == q5:
        if char == "b":
            atual = q5
        elif char == "a":
            atual = q5

if atual in final:
    print("Str Aceita")
else:
    print("Str não aceita")
