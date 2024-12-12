import matplotlib.pyplot as plt
import requests

def fetch_data(start_date, end_date, currency):
    url = f"https://api.nbp.pl/api/exchangerates/rates/A/{currency}/{start_date}/{end_date}/"
    headers = {"Accept": "application/json"}
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Błąd podczas pobierania danych: {response.status_code}")
        return None

def monthly_averages(data):
    monthly_data = {}
    for rate in data["rates"]:
        date = rate["effectiveDate"]
        value = rate["mid"]
        month = date[5:7]
        if month not in monthly_data:
            monthly_data[month] = []
        monthly_data[month].append(value)
    
    monthly_averages = [sum(values) / len(values) for _, values in monthly_data.items()]
    return monthly_averages


def plot_inflation(eur, usd, ax, title):
    months = [k for k in range(1, 13)]
    averages_eur = [eur[month - 1] for month in months]
    averages_usd = [usd[month - 1] for month in months]

    ax.plot(months, averages_eur, marker='.', color='blue', label="EUR")
    ax.plot(months, averages_usd, marker='.', color='green', label="USD")
    ax.set_title(title)
    ax.set_xlabel("Miesiąc")
    ax.set_ylabel("Średni kurs (PLN)")
    ax.grid()
    ax.legend()

def predict_data(data_past, data_recent):
    predictions = []
    for i in range(len(data_recent)):
        prediction = (data_recent[i] + (data_recent[i] - data_past[i]) * 0.2 )
        if i != 0:
            prediction += (data_recent[i] - data_recent[i - 1]) * 0.2
        predictions.append(prediction)
    return predictions

eur_2022 = monthly_averages(fetch_data("2022-01-01", "2022-12-31", "EUR"))
usd_2022 = monthly_averages(fetch_data("2022-01-01", "2022-12-31", "USD"))
eur_2023 = monthly_averages(fetch_data("2023-01-01", "2023-12-31", "EUR"))
usd_2023 = monthly_averages(fetch_data("2023-01-01", "2023-12-31", "USD"))
prediction_eur = predict_data(eur_2022, eur_2023)
prediction_usd = predict_data(usd_2022, usd_2023)

fig, ax = plt.subplots(3, 1, figsize=(9, 9), tight_layout="True")
plot_inflation(eur_2022, usd_2022, ax[0], "Średni miesięczny kurs EUR i USD w 2022 roku")
plot_inflation(eur_2023,usd_2023, ax[1], "Średni miesięczny kurs EUR i USD w 2023 roku")
plot_inflation(prediction_eur, prediction_usd, ax[2], "Przewidywane kursy EUR i USD")

plt.show()