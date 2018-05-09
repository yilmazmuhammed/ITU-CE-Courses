from bottle import route, run

def get_hello_message():
    return "Hello, world!"

route('/hello','GET',get_hello_message)
run()

