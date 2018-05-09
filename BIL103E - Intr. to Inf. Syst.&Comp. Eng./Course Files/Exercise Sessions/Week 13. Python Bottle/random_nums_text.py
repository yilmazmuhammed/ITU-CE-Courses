from bottle import route, run
from random import randrange


def coin_page():
    num = randrange(1, 3)
    if num == 1:
        return 'Heads'
    else:
        return 'Tails'


def die_page():
    num = randrange(1, 7)
    return str(num)


def dice2_page():
    num1 = randrange(1, 7)
    num2 = randrange(1, 7)
    return str(num1) + ' - ' + str(num2)


def dice5_page():
    num1 = randrange(1, 7)
    num2 = randrange(1, 7)
    num3 = randrange(1, 7)
    num4 = randrange(1, 7)
    num5 = randrange(1, 7)
    return str(num1) + ' - ' + str(num2) + ' - ' + \
           str(num3) + ' - ' + str(num4) + ' - ' + str(num5)


def dice_page(n):
    limit = int(n)
    dice = []
    i = 0
    while i < limit:
        num = randrange(1, 7)
        dice = dice + [num]
        i = i + 1
    result = ''
    for die in dice:
        result = result + ' - ' + str(die)
    return result[3:]


def setup_routing():
    route('/', 'GET', coin_page)
    route('/coin', 'GET', coin_page)
    route('/die', 'GET', die_page)
    route('/dice2', 'GET', dice2_page)
    route('/dice5', 'GET', dice5_page)
    route('/dice/<n>', 'GET', dice5_page)


setup_routing()
run()
