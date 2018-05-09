from pytz import timezone
from datetime import datetime

for zone_name in ['Europe/Istanbul','Pacific/Auckland','Europe/London']:
   zone = timezone(zone_name)
   zone_datetime = datetime.now(zone)
   print("The time in " + str(zone) + " is " + zone_datetime.ctime())
