from bottle import Bottle


app = Bottle()


def hello_page():
    return '<h1>Hello, world!</h1>'


def goodbye_page():
    return '<h1>Goodbye, cruel world!</h1>'


app.route('/hello', 'GET', hello_page)
app.route('/goodbye', 'GET', goodbye_page)

app.run()
