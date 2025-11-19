def fact (n):
    if n == 1:
        return 1
    return n * fact(n-1)

def mult (m, n):
    if n == 0:
        return 0
    return m + mult(m, n - 1)

def pot (ba, ex):
    if ex == 0:
        return 1
    return ba * pot(ba, ex - 1)

def soma (ma, mi):
    if ma == mi:
        return ma
    return ma + soma(ma - 1, mi)

def fibonacci (mes):
    
    if mes == 0:
        return 0
    elif mes == 1:
        return 1

    return fibonacci(mes - 1) + fibonacci(mes - 2)

def mover_caixa(n, orig, dest, aux=' '):
    if n== 1:
        print(f'Caixa {n} {orig} --> {dest}')
    else:
        mover_caixa(n-1, orig, aux, dest)
        print(f'Caixa {n} {orig} --> {dest}')
        mover_caixa(n-1, orig, aux, dest)
    

