from bottle import route, run, request, static_file
from datetime import datetime
from pytz import timezone, all_timezones


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


def time_page():

    html = """
            <form action="/" method="get">
                <input type="text" name="search" />
                <input type="text" name="asas" />
                <input type="submit" value="Search" />
            </form>
    """

    if 'search' in request.GET:
        search = request.GET['search']
    else:
        search = ''

    #html += 'You searched for '+search

    html += """
                <table>
                <tr>
                   <th>Name</th>
                   <th>Time</th>
                </tr>
            """

    for zonestring in all_timezones:
        if search.upper() in zonestring.upper():
            curr_time = datetime.now(timezone(zonestring))
            html += """
                    <tr>
                        <td>%s</td>
                        <td>%s</td>
                    </tr>
                    """ %(zonestring,curr_time)

    html += """</table>"""

    return htmlify(html,"Time in zone")


route('/','GET',time_page)


run(debug=True)
