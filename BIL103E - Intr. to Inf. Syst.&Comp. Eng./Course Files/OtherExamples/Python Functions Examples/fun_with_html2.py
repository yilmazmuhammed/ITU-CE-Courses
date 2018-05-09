# Usage:
# python fun_with_html2.py > page2.html

def htmlify(text):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>HELLO</title>
            </head>
            <body>
            """ + text + """
            </body>
        </html>
        
    """
    return page

#%%

print(htmlify("This is a web-page"))

