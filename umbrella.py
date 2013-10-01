#!/usr/bin/python

import requests
import os
r = requests.get('http://api.openweathermap.org/data/2.5/forecast?q=Zuerich,ch')
data = r.json()
rain = 0;
if data['list'][0]['rain']:
    data['list'][0]['rain']['3h']
else:
    data['list'][1]['rain']['3h']
if rain > 0:
    os.system('/home/pi/umbrella/umbrella -c')
else:
    os.system('/home/pi/umbrella/umbrella')
