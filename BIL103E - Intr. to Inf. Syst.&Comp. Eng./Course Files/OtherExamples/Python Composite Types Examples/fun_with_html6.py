# The only difference with fun_with_html5.py
# is that the htmlify function uses % formatting
# with dicts
#
#%%

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

html = htmlify("Hello world","Boo")

#%%

def save_text_to_file(text,filename):
    f = open(filename,"w")
    print(text,file=f)
    f.close()

#%%

def factors_of_num(the_number):
    factors = []
    for possible_factor in range(1,the_number+1):
        factor2 = the_number/possible_factor
        if round(factor2,0)==factor2:
            factors = factors + [possible_factor]
    return factors

test1 = factors_of_num(12)
#print(test1)
assert(test1[0]==1)
assert(test1[1]==2)
assert(test1[2]==3)
assert(test1[3]==4)
assert(test1[4]==6)
assert(test1[5]==12)
assert(len(test1)==6)

#%%

def is_prime(the_number):
    factors = factors_of_num(the_number)
#    print(the_number,"-->",factors)
    if len(factors)==2:
        return True
    else:
        return False

assert(is_prime(3))
assert(is_prime(5))
assert(is_prime(11))
assert(is_prime(23))
assert(is_prime(83))
assert(not is_prime(12))
#assert(not is_prime(100))
#assert(not is_prime(100000))

#%%

def python_list_to_html_list(the_list):
    s = "<ul>"
    for item in the_list:
        s = s + "<li>" + str(item) + "</li>"
    s = s + "</ul>"
    return s

#print(python_list_to_html_list([5,6,7]))

#%%

prime_numbers = []

for num in range(1,100):
#    print(num,"-->")
    if is_prime(num):
        prime_numbers = prime_numbers + [num]
#        print("prime")
#    else:
#        print("not prime")

html_primes = python_list_to_html_list(prime_numbers)

html_primes_with_intro = "<p>A list of primes less than 100:</p>" + html_primes

save_text_to_file(htmlify(html_primes_with_intro,"A full list of primes"),"primes.html")

