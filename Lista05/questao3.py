q0, q1 = "q0", "q1"
atual = q0
final = [q0]

cod = "1010"

for char in cod:
    if atual == q0:
        if char == "1":
          atual = q0
        elif char == "0":
          atual = q1
    elif atual == q1:
        if char == "1":
          atual = q1
        elif char == "0":
          atual = q0
if atual in final:
  print("Aceita")
else:
  print("Não aceita")