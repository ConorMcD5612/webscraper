from bs4 import BeautifulSoup
import requests
import sys
import time
import subprocess
import os
import json

#how many countries the website has 
MAX_COUNTRIES = 250

#take in a command line arguement for how many countries that you wan't to read in
if len(sys.argv) != 2:
    sys.exit("please enter a number (0-250) for the first arguement")
elif not sys.argv[1].isdigit():
    sys.exit("Must be a number (0-250)")
elif not range(250):
    sys.exit("needs to be between 0-250")
else:
    countryAmount = int(sys.argv[1])


url = 'https://www.scrapethissite.com/pages/simple/'
response = requests.get(url)

soup = BeautifulSoup(response.content, 'html.parser')
countries = soup.find_all('div', class_='country')



#store country data in array 
countryData = []
for country in countries[:countryAmount]:
    
    name = country.find('h3', class_='country-name').text.strip()
    capital = country.find('span', class_='country-capital').get_text()
    population = int(country.find('span', class_='country-population').text)
    area = country.find('span', class_='country-area').get_text()
    
    countryData.append({
        'name':name,
        'population': population,
        'area': area,
        'capital': capital
    })
    


#run c++ file and give it the country data 
countryJSON = json.dumps(countryData)
data, temp = os.pipe()


os.write(temp, bytes(countryJSON, 'utf-8'))
os.close(temp)

#compile/execute file with jsoncpp dependency 
startTime = time.time()
s = subprocess.check_output("g++ main.cpp -o main -ljsoncpp;./main", stdin = data, shell = True)

endTime = time.time()

#print c++ and time
print(s.decode('utf-8'))
print(f"How long it took c++ file to compile and run: {endTime - startTime}")
    

