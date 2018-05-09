from bottle import Bottle
from datetime import datetime


app = Bottle()


page_template = '''
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>World Time</title>
    <meta charset="utf-8" />
  </head>
  <body>
    %(content)s
  </body>
</html>
'''


def time_page():
    current_time = datetime.now()
    content_template = '<p>The current time is: %(time)s</p>'
    content = content_template % {'time': current_time.ctime()}
    return page_template % {'content': content}


app.route('/time', 'GET', time_page)

app.run()
