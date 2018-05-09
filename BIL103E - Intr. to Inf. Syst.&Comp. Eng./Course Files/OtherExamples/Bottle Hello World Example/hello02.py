from bottle import Bottle


app = Bottle()


page_template = '''
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>Greetings</title>
    <meta charset="utf-8" />
  </head>
  <body>
    %(content)s
  </body>
</html>
'''


def hello_page():
    content = '<h1>Hello, world!</h1>'
    return page_template % {'content': content}


def goodbye_page():
    content = '<h1>Goodbye, cruel world!</h1>'
    return page_template % {'content': content}


app.route('/hello', 'GET', hello_page)
app.route('/goodbye', 'GET', goodbye_page)

app.run()
