umbrella
========

A tiny application that does display information if an umbrella is required today or not on a ilsoftltd oled display

The initial version of the application consists of two parts: 

1) a c++ command line tool umbrella 
 * Download and install https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/ 
 * Download and install https://github.com/ilsoftltd/colour-oled
 * use 'make umbrella' to compile this.
 * ./umbrella does display "the sun" 
 * ./umbrella -c does display "the umbrella"
   
2) a python tool to get the current 
 * Download and install http://docs.python-requests.org/en/latest/
 * Change the "q=Zuerich,ch" string in the python.py file to what ever location you want, that can be found using openweathermap.org api
 * configure a cronjob or similar to run this as often as you want. 