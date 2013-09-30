#!/usr/bin/python

import requests
import os
r = requests.get('http://api.openweathermap.org/data/2.5/forecast?q=Zuerich,ch')
data = r.json()
rain = data['list'][0]['rain']['3h']
if rain > 0: 
    os.system('/home/pi/umbrella/umbrella -c')
else:
    os.system('/home/pi/umbrella/umbrella')
