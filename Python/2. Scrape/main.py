import requests
from bs4 import BeautifulSoup

# URL of the website you want to scrape
url = 'https://serenitystar.info/bonus/com-africa-8811/global-bb.php?c=4rz4ds0vz69z1&k=5760de68eade1cf5599d5d03fabc720c&country_code=ZA&carrier=-&country_name=South%20Africa&region=Gauteng&city=Pretoria&isp=Tertiary%20Education%20and%20Research%20Network%20of%20South%20Africa&lang=en&os=Windows%2010&osv=&browser=Chrome&browserv=129&brand=Desktop&model=Desktop&marketing_name=Desktop&tablet=4&rheight=768&rwidth=768&e=5'

# Send an HTTP request to the website
response = requests.get(url)

# Parse the HTML content
soup = BeautifulSoup(response.text, 'html.parser')

# Extract specific content, for example, all paragraph text
for paragraph in soup.find_all('p'):
    print(paragraph.text)
