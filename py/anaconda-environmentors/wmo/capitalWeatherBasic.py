#!/usr/bin/env python3

#*********************************************************************************#
#*********************************************************************************#
#                                                                                 #
# Retrieves the latest weather forecasting data for all capital cities in the     #
# world from WMO and stores it into a local CSV. Basic.                           #
#                                                                                 #
#                                                                                 #
# Version Created on Thu Feb  2 20:55:33 2023                                     #
#                                                                                 #
# @author: Leo Ling                                                               #
#                                                                                 #
# MINOR OPTIMIZATIONS:                                                            #
#   May use a state to see if already found capital in current country. This will #
#   speed it up considerably.                                                     #
#                                                                                 #
#   May use a state to detect if the forecastDate has already been found. This    #
#   will not speed it up considerably, but is there just for effect.              #
#                                                                                 #
#*********************************************************************************#
#*********************************************************************************#

# wget is an utility to download files from the internet

import wget

# os is a library for dealing with files and manipulating them

import os

# tqdm is a loading bar to show progress.

from tqdm import tqdm

#---------------------------------------------------------------------------------#
# os.remove removes the specified file. os.path.abspath returns the complete path #
# in the file system. This is required because os.remove does not recognize       #
# relative paths. We try to do this, if the file does not exist, i.e., throws and #
# OSError, then we continue.                                                      #
#---------------------------------------------------------------------------------#

try:
    os.remove(os.path.abspath("capitalWeatherBasic.csv"))
except OSError:
    pass

#---------------------------------------------------------------------------------#
# Makes a variable called full_city_list that will contain the country, city, and #
# ID of all the cities in the WMO database.                                       #
#---------------------------------------------------------------------------------#

full_city_list = []

#---------------------------------------------------------------------------------#
# open opens capitalWeatherBasic.csv in append mode and stores it in the variable #
# file. The default mode for open is 'r' so we need to explicitly to 'a'.         #
#---------------------------------------------------------------------------------#

file = open("capitalWeatherBasic.csv", 'a')

#---------------------------------------------------------------------------------#
# file.write() appends "Location,Weather,Date" to capitalWeatherBasic.csv. The \n #
# makes a new line.                                                               #
#---------------------------------------------------------------------------------#

file.write("Location,Weather,Date\n")

#---------------------------------------------------------------------------------#
# file.close() loses the file to save the changes. We will use this file later,   #
# but since we are adding lines every time we update and need to close anyways, we#
# might as well "save" here.                                                      #
#---------------------------------------------------------------------------------#

file.close()

#---------------------------------------------------------------------------------#
# wget.download uses wget to download the content of the specified URL as a text  #
# file. This file contains all the country names, city names, and country IDs. The#
# link provided is from WMO, and one can find it from the WMO website             #
# (https://worldweather.wmo.int/en/dataguide.html).                               #
#---------------------------------------------------------------------------------#

wget.download("https://worldweather.wmo.int/en/json/full_city_list.txt")

#---------------------------------------------------------------------------------#
# Here we open full_city_list.txt file as a file object named txt. The with       #
# keyword means that txt will be deleted after this block. This loop adds         #
# countries that satisfy the constraints to full_city_list.                       #
#---------------------------------------------------------------------------------#

with open("full_city_list.txt") as txt:

    #-----------------------------------------------------------------------------#
    # This reads in the txt variable and splits the content into an array if there#
    # is a \n, e.t.c. new line. We then loop through this array and stores the    #
    # looped line in the variable line.                                           #
    #-----------------------------------------------------------------------------#

    for line in txt.read().split("\n"):

        # This splits the line into an array if there is a ; and for each of the
        # elements in this array, removes the ". For example "word" turns into word
        # . This array is stored in the variable row.

        row = [item.replace('\"', '') for item in line.split(';')]

        # This line checks if there are 3 elements in row. This will get rid of the
        # very last line with the updated time. It then checks if the third element
        # in the row is a number with the .isdigit() method.

        if len(row) == 3 and row[2].isdigit():

            #---------------------------------------------------------------------#
            # Append a row to full_city_list as a new array. Array+Array=Array, so#
            # we need to put our row array inside a new one.                      #
            #---------------------------------------------------------------------#

            full_city_list += [row]

#---------------------------------------------------------------------------------#
# This line removes full_city_list.txt                                            #
#---------------------------------------------------------------------------------#

os.remove(os.path.abspath("full_city_list.txt"))

#---------------------------------------------------------------------------------#
# This for loop loops through full_city_list to seek the capitals from the WMO    #
# database. It then fetches the data and appends it to the CSV.                   #
#---------------------------------------------------------------------------------#

for i in tqdm(full_city_list, "Computing: "):

    #-----------------------------------------------------------------------------#
    # This loop sifts through all the cities, searching for the capitals. If a    #
    # city is not a capital, then we continue. If a city is a capital then we     #
    # use it's city ID to download the cities weather and ancillary data. The     #
    # string contained in wget.download(), i.e.,                                  #
    # "https://worldweather.wmo.int/en/json/"+int(i[2])+"_en.json"                #
    # formulates the link from the city id to the data. f string is a easy way to #
    # concatenate values. The value inside of the braces({}) will be inserted into#
    # the string at the position of the first brace. It saves this file as        #
    # city.txt for easy access.                                                   #
    #-----------------------------------------------------------------------------#

    wget.download(
        f"https://worldweather.wmo.int/en/json/{i[2]}_en.json", out="city.txt")

    # This sets the weather variable to "invalid" in case it's not found later.

    weather = "invalid"

    # This sets the date variable to "invalid" in case it's not found later.

    date = "invalid"

    # This sets the capital variable to False so that if it is found later it can
    # be set to True, otherwise we wouldn't need to do anything.

    capital = False

    # Initializes the variable lines to None so that we may be able to used it
    # outside of the with block.

    lines = None

    # This with block opens the city.txt as the variable txt.

    with open("city.txt") as txt:

        # Reads the city.txt file and splits it into arrays if there is a ','     #

        lines = txt.read().split(',')

    # This line removes the file city.txt. This is guaranteed to exist because we
    # just made it.

    os.remove(os.path.abspath("city.txt"))

    # This loop loops through the lines and checks if the line contains "isCapital"
    # and "true". This means that value is set to true because isCapital has its
    # own line. This was confirmed through looking at the format of a city's JSON
    # file. The line currently looped through is contained in the variable line.

    for line in lines:

        # This condition checks if the substring "isCapital" is in line and if    #
        # "true" is also in the line.                                             #

        if "isCapital" in line and "true" in line:

            # This line will set the variable capital to True to represent that   #
            # the current city is a capital.                                      #

            capital = True

            # The rest of the data doesn't matter in this loop

            break

    # If the current city is not a capital then we continue.

    if (not capital):

        # Passes through the current loop to the next row in full_city_list.

        continue

    # This loops through the array lines to find the forecastDate and weather.
    # The current line is contained in the variable line.

    for line in lines:

        # This assigns the split array of ':' without any double quotes to r. This
        # is a quick and dirty way to access the properties.

        r = [item.replace('\"', '') for item in line.split(':')]

        # Tries to access the properties and values of r.

        try:

            # The line we want to find looks like such.
            # ,"forecastDay":[{"forecastDate":"date",
            # Thus, we need the 2nd element, not the first. This is since
            # "forecastDate" will be after the first colon. If there are no colons
            # then we pass control to the except IndexError handler.

            if ("forecastDate" in r[1]):

                # This will set the date to r[2]. Since we know that the
                # "forecastDate" line will follow the previous format, there will
                # be three elements and the third one is the one the want.

                date = r[2]

            # The weather line will be in the following format.
            # ,"weather":"the weather",
            # We now check the first element to see if it contains weather.

            if (r[0] == "weather"):

                # Sets the weather to the element after the first colon. We do this
                # becaues we know the line follows the previous format.

                weather = r[1]

                # After we find the weather, no other data is required so we break.

                break

        # If the error is an IndexError, which is to be expected, then that doesn't
        # matter. If it is any other error it's important.

        except IndexError:

            # If it's an IndexError we may continue.

            pass

    # This opens the file capitalWeatherBasic.csv in append mode to append lines.

    file = open("capitalWeatherBasic.csv", 'a')

    # This matches the data to the capitalWeatherElegant.csv format.

    file.write('\"'+i[0]+', '+i[1]+'\"'+","+weather+","+date+"\n")

    # This closes/saves the file.

    file.close()
