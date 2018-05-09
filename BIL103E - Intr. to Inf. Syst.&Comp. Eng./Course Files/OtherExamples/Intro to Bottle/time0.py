from bottle import route, run
from datetime import datetime

def time():
    return str(datetime.now())

route('/time','GET',time)
run()

