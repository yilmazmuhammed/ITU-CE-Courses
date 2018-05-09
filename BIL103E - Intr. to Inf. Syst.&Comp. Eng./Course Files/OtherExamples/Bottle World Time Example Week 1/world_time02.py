from bottle import Bottle
from datetime import datetime
from pytz import timezone


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


def home_page():
    content = '''
      <p>Show me the time in:</p>
      <ul>
        <li><a href="/time/Europe/Istanbul">Istanbul</a></li>
        <li><a href="/time/Pacific/Auckland">Auckland</a></li>
        <li><a href="/time/Europe/London">London</a></li>
        <li><a href="/time/Europe/Warsaw">Warsaw</a></li>
        <li><a href="/time/America/New_York">New York</a></li>
        <li><a href="/time/Asia/Tokyo">Tokyo</a></li>
      </ul>
    '''
    return page_template % {'content': content}


def time_page(area, city):
    zone_name = area + '/' + city
    zone = timezone(zone_name)
    current_time = datetime.now(tz=zone)
    content_template = '''
      <p>The current time in %(city)s is: %(time)s</p>
      <hr />
      <p>Go to the <a href="/">home page</a>.</p>
    '''
    content = content_template % {'city': city, 'time': current_time.ctime()}
    return page_template % {'content': content}


app.route('/', 'GET', home_page)
app.route('/time/<area>/<city>', 'GET', time_page)

app.run()
