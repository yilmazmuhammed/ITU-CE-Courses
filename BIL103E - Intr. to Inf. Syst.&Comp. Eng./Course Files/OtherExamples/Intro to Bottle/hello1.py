from bottle import route, run

def get_hello_message(name):
    return "Hello, %s!" % name

route('/hello/<name>','GET',get_hello_message)
run()

