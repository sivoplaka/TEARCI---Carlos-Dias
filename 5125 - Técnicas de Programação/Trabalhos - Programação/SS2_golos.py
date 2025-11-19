print("#" * 20, "Resultado", "#" * 20)
nome_equipa_casa=str(input("Nome da equipa da casa: \n"))
nome_equipa_visitante=str(input("Nome da equipa visitante: \n"))
equipa_casa=int(input("Golos da equipa da casa: \n"))
equipa_visitante=int(input("Golos da equipa visitante: \n"))

if (equipa_casa>equipa_visitante):
    print(f"Vitória de {nome_equipa_casa} contra {nome_equipa_visitante}, \ncom uma vitória de {equipa_casa} - {equipa_visitante}.")
elif (equipa_casa<equipa_visitante):
    print(f"Vitória de {nome_equipa_visitante} contra {nome_equipa_casa},, \ncom uma vitória de {equipa_casa} - {equipa_visitante}.")
else:  
    print(f"Empate a {equipa_casa} - {equipa_visitante} entre \n{nome_equipa_casa} e {nome_equipa_visitante}.")