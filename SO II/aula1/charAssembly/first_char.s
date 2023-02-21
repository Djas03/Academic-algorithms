.global first_char
first_char:
    lb a0, 0(a0)    #transporta 1 byte da memória para o reg a0
    ret

