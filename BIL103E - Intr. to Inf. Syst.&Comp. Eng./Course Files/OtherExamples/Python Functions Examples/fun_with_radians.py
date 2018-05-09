from math import pi

def my_radians(degrees):
    result = pi * degrees / 180
    return result

#%%

print(my_radians(90))

#%%

for number in range(0,360,10):

    numberrad = my_radians(number)
    print(str(number) + " in radians: " + str(numberrad))
    
