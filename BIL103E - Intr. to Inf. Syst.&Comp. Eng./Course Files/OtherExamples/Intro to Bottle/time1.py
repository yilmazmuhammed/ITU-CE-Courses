from bottle import route, run
from datetime import datetime
from pytz import timezone

def time(name):
    print("You asked for "+name)
    zone = timezone("Europe/"+name)
    return str(datetime.now(zone))

route('/time/<name>','GET',time)
run()

