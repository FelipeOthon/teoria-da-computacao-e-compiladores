q0, q1, q2, q3 = "q0", "q1", "q2", "q3"
atual = q0
final = [q0, q1, q3]

cod = "ababa"

for char in cod:
    if atual == q0:
        if char == "a":
          atual = q1
        elif char == "b":
          atual = q0
    elif atual == q1:
        if char == "a":
          atual = q2
        elif char == "b":
          atual = q3
    elif atual == q3:
        if char == "b":
          atual = q3
        elif char == "a":
          atual = q1
    elif atual == q2:
        if char == "a":
          atual = q2
        elif char == "b":
          atual = q2


if atual in final:
  print("Aceita")
else:
  print("NÃ£o aceita")