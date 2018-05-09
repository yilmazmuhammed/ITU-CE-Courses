# Usage:
# python fun_with_html3.py 

def htmlify(text,title):
    page = """
        <!doctype html>
        <html lang="en">
            <head>
                <meta charset="utf-8" />
                <title>
                """ + title + """
                </title>
            </head>
            <body>
            """ + text + """
            </body>
        </html>
        
    """
    return page

#%%
    
def save_text_to_file(text,filename):
    f = open(filename,"w")
    print(text,file=f)
    f.close()

#%%

for i in range(0,30):
    text = "My fan page devoted to the number " + str(i)
    title = "All about the number " + str(i)
    html = htmlify(text,title)
    filename = str(i) + "fun.html"
    save_text_to_file(htmlify,filename)

