from bottle import route, run, request, static_file
from datetime import datetime
from pytz import timezone


def htmlify(text,title):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>%(title)s</title>
            </head>
            <body>
            %(text)s
            </body>
        </html>

    """ % {'text':text,'title':title}
    return page


def css(fname):
    toreturn = static_file(fname,root='/home/docean/tmp/css')
    return toreturn

route('/css/<fname>','GET',css)


def home_page():
    return static_file('homepage6.html',root='/home/docean/tmp/static')

route('/','GET',home_page)


def time_page():
    zone_str = request.POST["zone"]
    zone = timezone(zone_str)
    curr_time = datetime.now(zone)
    return htmlify(str(curr_time),"Time in zone")

route('/time','POST',time_page)


run(debug=True)
