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
    print("css called")
    toreturn = static_file(fname,root='/home/docean/tmp/css')
    print("returning:"+str(toreturn))
    return toreturn

route('/css/<fname>','GET',css)

def home_page():
    return static_file('homepage8.html',root='/home/docean/tmp/static')

route('/','GET',home_page)

def time_page():
    zone_str = request.POST["zone"]

    #if 'show_dom' in request.POST:
    #    print('show DOM')

    zone = timezone(zone_str)
    curr_time = datetime.now(zone)

    if 'show_dow' in request.POST:
        nice_str = curr_time.strftime("%d/%m/%y %A %H:%M")
    else:
        nice_str = curr_time.strftime("%d/%m/%y %H:%M")


    return htmlify(nice_str,"Time in zone")


route('/time','POST',time_page)


run(debug=True)
