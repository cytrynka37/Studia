import aiohttp
import asyncio
from private import OPENWEATHER_API_KEY

async def fetch_cat_fact():
    url = "https://catfact.ninja/fact"
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            if response.status == 200:
                data = await response.json()
                return data['fact']
            else:
                return "Nie udało się pobrać faktu o kotach."
            
async def fetch_weather(city):
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={OPENWEATHER_API_KEY}&units=metric"
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            if response.status == 200:
                data = await response.json()
                return f"miasto: {city}, temperatura: {data['main']['temp']}"
            else:
                return f"Nie udało się pobrać pogody dla {city}."

async def main():
    results = await asyncio.gather(
        fetch_weather("Wroclaw"),
        fetch_cat_fact()
    )
    
    for result in results:
        print(result)

asyncio.run(main())