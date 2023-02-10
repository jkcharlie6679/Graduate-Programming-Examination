while(1):
    try:
        number = int(input())
    except:
        exit()
    if number == 0:
        break
    answer = 1;
    for i in range (number+2, 2*number+1):
        answer *= i
    print(answer)

