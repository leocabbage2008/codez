#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan 25 12:09:59 2023

@author: coder
"""

from tqdm import tqdm
import pandas as pd
# library for working with data sets

cities = pd.read_csv(
    "https://worldweather.wmo.int/en/json/full_city_list.txt", delimiter=';')
# csv(character or comma separated values) is a type of file, here we read in a
# text file instead of commas, the file is separated by a semicolon so we set the
# delimiter to semicolon to read in the data correctly. this is stored in the
# cities variable

cities = cities.dropna()
# There are Country, City and CityId. If there is no country, then there can't be a
# city. If there is no city, then we can't do anything because we're searching for
# capitals. If there is no CityId there is no data so we can't do anything.
# Therefore, we use the dropna() method from pandas to remove all rows with any
# N/A values

csv = pd.DataFrame([], columns=["Location", "Weather", "Date"])
# Creates a DataFrame with value of [] and with columns of "Location", "Weather",
# and "Date"

for i in tqdm(cities.to_dict(orient="records"), "Computing: "):
    # This turns cities into a dictionary with an orient of records
    # without orient="records"
    # {"Country":{...}, "City":{...}, "CityId":{...}}
    # with orient="records"
    # [{"Country":..., "City":..., "CityId":...},...]
    # makes a loop to loop through the city ID's, countries and cities
    # i contains this item

    data = pd.read_json(
        f"https://worldweather.wmo.int/en/json/{int(i['CityId'])}_en.json")
    # this f string is about equivalent to
    # "https://worldweather.wmo.int/en/json/"+int(i['CityId'])+"_en.json"
    # in short, it formulates the link from the id to get the data
    # we then use pandas to store this as a dataframe in variable data

    if(data["city"]["isCapital"]):
        # checks if the city is a capital

        forecast = data["city"]["forecast"]["forecastDay"]
        # gets the forecasts of the city

        if(not forecast):
            forecast.append({"weather": "invalid", "forecastDate": "invalid"})
        # if the forecast doesn't exist, just set the values to invalid
        # "weather" and "forecastDate" are the only values we use from forecast
        # so those are the only ones we need to set to invalid
        # we then add our dictionary to forecast
        # this prevents an index out of bounds error and makes the code more
        # succinct

        dataList = [f"{i['Country']}, {i['City']}", forecast[0]
                    ["weather"], forecast[0]["forecastDate"]]
        # makes a variable dataList and formats it to the csv
        # gets country and city, then the cities weather, and then gets the date of
        # forecast
        csv.loc[len(csv)] = dataList
        # gets the length of the csv. since computers start counting from 0, the
        # length of the csv will exceed the bound by 1, in effect adding a row to
        # the dataframe
        csv.to_csv("capitalWeather.csv", index=False)
        # writes to capitalWeather.csv and sets index to false which controls
        # whether DataFrame writes column numbers on the side
