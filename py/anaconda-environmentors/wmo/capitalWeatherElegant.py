#!/usr/bin/env python3

#*********************************************************************************#
#*********************************************************************************#
#                                                                                 #
# Retrieves the latest weather forecasting data for all capital cities in the     #
# world from WMO and stores it into a local CSV. Elegant.                       #
#                                                                                 #
#                                                                                 #
# Version Created on Wed Jan 25 12:09:59 2023                                     #
#                                                                                 #
# @author: Leo Ling                                                               #
#                                                                                 #
#*********************************************************************************#
#*********************************************************************************#

# tqdm is a loading bar to show progress.

from tqdm import tqdm

# pandas is a library for working with tabular data and writing data into CSVs.

import pandas as pd

#---------------------------------------------------------------------------------#
# Here, we fetch all the country names, city names and country IDs for all of the #
# cities in the WMO database. We store this information into a pandas DataFrame.  #
# These data are stored in an CSV file. A CSV file (i.e., character or comma      #
# separated values) is a type of file. Here, we read in a text file delimited by  #
# semicolons, instead of the default commas, and store the data into the DataFrame#
# variable cities. The link provided is from WMO, and one can find it from the WMO#
# website (https://worldweather.wmo.int/en/dataguide.html).                       #
#---------------------------------------------------------------------------------#

cities = pd.read_csv(
    "https://worldweather.wmo.int/en/json/full_city_list.txt", delimiter=';')

#---------------------------------------------------------------------------------#
# There are Country, City and CityId in the cities variable. To clean the data we #
# clear the elements that cannot be accessed. We do this as such. If there is no  #
# country, then there can't be a city. If there is no city, then we can't do      #
# anything because we're searching for capitals. If there is no CityId there is no#
# data so we can't do anything. Therefore, we use the dropna() method from pandas #
# to remove all rows with any N/A values.                                         #
#---------------------------------------------------------------------------------#

cities = cities.dropna()

#---------------------------------------------------------------------------------#
# Creates a new DataFrame with values of [] and with column labels of "Location", #
# "Weather", and "Date".                                                          #
#---------------------------------------------------------------------------------#

csv = pd.DataFrame([], columns=["Location", "Weather", "Date"])

#---------------------------------------------------------------------------------#
# The for loop turns cities into a dictionary with an orient of records. The      #
# orient feature in pandas, represented as an attribute of the method to_dict of  #
# a DataFrame, converts a DataFrame to a dictionary with the "style" of orient.   #
# For example, our data with and without orient looks as follows:                 #
# without orient="records"                                                        #
# {"Country":{...}, "City":{...}, "CityId":{...}}                                 #
# with orient="records"                                                           #
# [{"Country":..., "City":..., "CityId":...},...]                                 #
# We now begin our loop, with each loop having distinct country name, city name   #
# and city ID. So, variable i contains this tuple.                                #
#---------------------------------------------------------------------------------#

for i in tqdm(cities.to_dict(orient="records"), "Computing: "):

    #-----------------------------------------------------------------------------#
    # This loop sifts through all the cities, searching for the capitals. If a    #
    # city is not a capital, then we continue. If a city is a capital then we     #
    # use it's city ID to fetch the cities weather and ancillary data.            #
    # The string contained in pd.read_json(), i.e.,                               #
    # "https://worldweather.wmo.int/en/json/"+int(i['CityId'])+"_en.json"         #
    # formulates the link from the city id to the data. We then use pandas to     #
    # store this as a DataFrame in variable data. f string is a easy way to       #
    # concatenate values. The value inside of the braces({}) will be inserted into#
    # the string at the position of the first brace.                              #
    #-----------------------------------------------------------------------------#

    data = pd.read_json(
        f"https://worldweather.wmo.int/en/json/{int(i['CityId'])}_en.json")

    # Checks if the city is a capital.

    if(data["city"]["isCapital"]):

        # Gets the forecasts for the city.

        forecast = data["city"]["forecast"]["forecastDay"]

        # If the forecast doesn't exist, just set the values to invalid "weather"
        # and "forecastDate". These are the only values we use from forecast, so
        # those are the only ones we need to set to invalid we then add our
        # dictionary to forecast this prevents an index out of bounds error and
        # makes the code more succinct.

        if(not forecast):
            forecast.append({"weather": "invalid", "forecastDate": "invalid"})

        # Make a variable called dataList and reformat it to the format city, city
        # weather, and date of the forecast. This makes the data easier to work
        # with.

        dataList = [f"{i['Country']}, {i['City']}", forecast[0]
                    ["weather"], forecast[0]["forecastDate"]]

        # Get the length of the CSV. Since python starts indexing from 0, the
        # length of the CSV will exceed the bound by 1, in effect adding a row to
        # the DataFrame.

        csv.loc[len(csv)] = dataList

        # Write to capitalWeather.csv and set index to false which controls
        # whether or not DataFrame writes column numbers on the side.

        csv.to_csv("capitalWeatherElegant.csv", index=False)
