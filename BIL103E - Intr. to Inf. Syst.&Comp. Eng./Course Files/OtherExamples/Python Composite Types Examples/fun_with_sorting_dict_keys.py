# In answer to a student question

album = {'title': 'Revolver', 'year': 1966,'studio': 'EMI'}

for key in sorted(album.keys()):
    print("%s: %s" % (key,album[key]) )
