from bottle import route, run
from random import randrange


def htmlify(content):
    page = """
    <!DOCTYPE html>
    <html>
        <head>
            <title>Random Numbers</title>
            <meta charset="utf-8" />
        </head>
        <body>
            """ + content + """
        </body>
    </html>
    """
    return page


def coin_page():
    num = randrange(1, 3)
    if num == 1:
        content = '<p>Heads</p>'
    else:
        content = '<p>Tails</p>'
    return htmlify(content)


def die_page():
    num = randrange(1, 7)
    content = '<p>' + str(num) + '</p>'
    return htmlify(content)


def dice2_page():
    num1 = randrange(1, 7)
    num2 = randrange(1, 7)
    content = '<p>' + str(num1) + ' - ' + str(num2) + '</p>'
    return htmlify(content)


def dice5_page():
    num1 = randrange(1, 7)
    num2 = randrange(1, 7)
    num3 = randrange(1, 7)
    num4 = randrange(1, 7)
    num5 = randrange(1, 7)
    content = '<p>' + str(num1) + ' - ' + str(num2) + ' - ' + \
              str(num3) + ' - ' + str(num4) + ' - ' + str(num5) + '</p>'
    return htmlify(content)

    # change to:
    #
    # i = 0
    # while i < 5:
    #     num = randrange(1, 7)
    #     dice = dice + [num]
    #     i = i + 1
    # content = ''
    # for die in dice:
    #     content = content + ' - ' + str(die)
    # content = '<p>' + content[3:] + '</p>'
    # return htmlify(content)
    #
    # and then parameterize for n to get the function below


def dice_page(n):
    limit = int(n)
    dice = []
    i = 0
    while i < limit:
        num = randrange(1, 7)
        dice = dice + [num]
        i = i + 1
    content = ''
    for die in dice:
        content = content + ' - ' + str(die)
    content = '<p>' + content[3:] + '</p>'
    return htmlify(content)


def setup_routing():
    route('/', 'GET', coin_page)
    route('/coin', 'GET', coin_page)
    route('/die', 'GET', die_page)
    route('/dice2', 'GET', dice2_page)
    route('/dice5', 'GET', dice5_page)
    route('/dice/<n>', 'GET', dice_page)


setup_routing()
run()
