def conversao_Celsius():
    print("*" * 10, "Conversão Fahrenheit-Celsius", "*" * 10)
    f=int(input("Digite graus Fahrenheit: \n"))
    c=(f-32)/1.8
    print(f"{c}ºC")
    main()
    
def conversao_Fahrenheit():
    print("*" * 10, "Conversão Celsius-Fahrenheit", "*" * 10)
    c=int(input("Digite graus Celsius: \n"))
    f=(c*1.8)+32
    print(f"{f}ºF")
    main()
    
def hello_world():
    print("*" * 10, "Hello World!", "*" * 10)
    main()
  
def imc():
    print("*" * 10, "IMC", "*" * 10)
    peso=float(input("Introduza o peso (kg):"))
    altura=float(input("Introduza a altura (metros):"))
    imc=peso/(altura*altura)
    if imc<18.5:
        print(f"O seu índice de {imc:.2f} está abaixo do normal")
        main()
    elif imc>18.4 or imc<25:
        print(f"O seu índice de {imc:.2f} está normal")
        main()
    elif imc>24.9 or imc<30:
        print(f"O seu índice de {imc:.2f} indica sobrepeso")
        main()
    elif imc>29.9 or imc<35:
        print(f"O seu índice de {imc:.2f} indica Obsidade grau I")
        main()
    elif imc>34.9 or imc<40:
        print(f"O seu índice de {imc:.2f} indica Obsidade grau II")
        main()
    elif imc>40:
        print(f"O seu índice de {imc:.2f} indica Obsidade grau III")
        main()
     
def par_impar():
    print("*" * 10, "Par-Ímpar", "*" * 10)
    n=int(input("Introduza um número: \n"))
    numero=n%2
    if numero == 0:
        print(f"O número {numero} é par")
        main()
    elif numero == 1:
        print(f"O número {numero} é ímpar")
        main()
    
def bissexto():
    print("*" * 10, "Ano Bissexto", "*" * 10)
    ano=int(input("Introduza um ano: \n"))
    if ano%400 == 0:
        print(f"{ano} é bissexto.")
        main()
    elif ano%100 == 0:
        print(f"{ano} não é bissexto.")
        main()
    elif ano%4==0:
        print(f"{ano} é bissexto.")
        main()
    else:
        print(f"{ano} não é bissexto.")
        main()

def fatorial():
    print("*" * 10, "Fatorial", "*" * 10)
    n=int(input("Introduza um número: \n"))
    contar=n
    total=1
    while contar > 1:
        total = total * contar
        contar -= 1
        print(f"Total: {total}")
    main()
        
def golos():
    print("*" * 10, "Totobola", "*" * 10)
    nome_casa=str(input("Nome da equipa da casa: \n"))
    nome_visitante=str(input("Nome da equipa visitante: \n"))
    golos_casa=int(input("Golos da equipa da casa: \n"))
    golos_visitante=int(input("Golos da equipa visitante: \n"))
    
    if golos_casa > golos_visitante:
        print(f"Vitória de {nome_casa} contra {nome_visitante} \npor {golos_casa} x {golos_visitante}")
        main()
    elif golos_casa < golos_visitante:
        print(f"Vitória de {nome_visitante} contra {nome_casa}\npor {golos_visitante} x {golos_casa}")
        main()
    else:
        print(f"Empate entre {nome_casa} contra {nome_visitante}\npor {golos_casa} x {golos_visitante}")
        main()
    
def pascoa():
    print("*" * 10, "Cálculo da Páscoa", "*" * 10)
    ano=int(input("Introduza o Ano: \n"))
    x=24
    y=5
    a=ano%19
    b=ano%4
    c=ano%7
    d=((19*a)+x)%30
    e=((2*b)+(4*c)+(6*d)+y)%7
    #calculos
    if (d+e)<10:
        dia=(d+e+22)
        print(f"{dia} de Março")
        main()
    else:   
        dia=(d+e-9)
        print(f"{dia} de Abril")
        main()
    
def soma():
    print("*" * 10, "Contagem 1-100", "*" * 10)
    i=0 
    soma=0
    while i < 100:
        soma+=1
        i+=1
        print(f"{soma}")
              
def cem():
    print("*" * 10, "Soma 1-100", "*" * 10)
    soma = 0
    for i in range (0,101,1):
        soma += i
        print(f"{soma}")
    main()
  

def main():
    print("#" * 50)
    print("#" * 23, "Menu", "#" * 23)
    print("#" * 50)
    
    while True:
        escolha = input("O que deseja fazer? ").strip().lower()
        if escolha == "celsius":
            conversao_Celsius()
        elif escolha == "fahrenheit":
            conversao_Fahrenheit()
        elif escolha == "hello":
            hello_world()
        elif escolha == "imc":
            imc()
        elif escolha == "par-impar":
            par_impar()
        elif escolha == "bissexto":
            bissexto()
        elif escolha == "fatorial":
            fatorial()
        elif escolha == "golos":
            golos()
        elif escolha == "pascoa":
            pascoa()
        elif escolha == "soma":
            soma()
        elif escolha == "cem":
            cem()
        elif escolha == "sair":
            break
        else:
            print("Opção inválida. Tente novamente. \n")

    
if __name__ == "__main__":
    main()
    
            
    
