x = {}


def combination(x,sol):
    if(len(sol) < x):
        sol_A = sol + "0"
        combination(x,sol_A)

        sol_B = sol + "1"
        combination(x,sol_B)

    else:
        print(sol)



combination(x,"")