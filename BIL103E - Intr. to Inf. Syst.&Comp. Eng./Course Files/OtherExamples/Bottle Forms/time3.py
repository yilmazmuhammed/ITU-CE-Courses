from bottle import route, run, request
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

homepagehtml = """
            <!doctype html>
            <html lang="en">
                <head>
                    <meta charset="utf-8" />
                    <title>Form test</title>
                </head>
                <body>

                    <p>Show the time in:</p>
                    <form action="/time" method="get">
                    <input type="text" name="group" />
                    <input type="text" name="zone" />
                    <input type="submit" value="Show" />
                    </form>

                </body>
            </html>
"""

def home_page():
    global homepagehtml
    return homepagehtml

route('/','GET',home_page)


def time_page():
    group_str = request.GET["group"]
    zone_str = request.GET["zone"]
    zone = timezone(group_str+"/"+zone_str)
    curr_time = datetime.now(zone)
    return htmlify(str(curr_time),"Time in zone")

route('/time','GET',time_page)


run(debug=True)
