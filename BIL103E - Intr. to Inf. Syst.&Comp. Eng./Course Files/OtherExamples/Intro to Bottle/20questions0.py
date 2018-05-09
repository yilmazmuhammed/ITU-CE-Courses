from bottle import route, run, request
from random import randint

def htmlify(text,title):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>
                """ + title + """
                </title>
            </head>
            <body>
            """ + text + """
            </body>
        </html>

    """
    return page

THENUMBER = randint(0,20)

def home_page():
    html = """<p>Choose a number:</p>"""
    for number in range(0,21):
        html = html + """
        <br><a href="/guess?number=%d">%d</a>""" % (number,number)
    return htmlify(html,"20 questions")

def guess_page():
    guess = request.GET["number"]
    global THENUMBER
    guessi = int(guess)
    if guessi == THENUMBER:
        return htmlify("You guessed CORRECT! Have chocolate.","OK")
    elif guessi > THENUMBER:
        return htmlify("You guessed high.","high")
    else:
        return htmlify("You guessed low.","low")

route('/','GET',home_page)
route('/guess','GET',guess_page)
run(debug=True)








