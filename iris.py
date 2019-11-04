import pandas as pd
# import numpy as np
import matplotlib.pyplot as plt

dataframe=pd.read_csv(filepath_or_buffer='iris.csv')
dataframe.describe()
dataframe.head(10)
dataframe.info()

dataframe.hist()

x = dataframe["sepal_length"] 

plt.figure(figsize = (15, 7)) 
plt.hist(x, bins = 15, color = "blue", edgecolor="black") 
plt.title("Sepal Length Histogram") 
plt.xlabel("Sepal_Length_cm") 
plt.ylabel("Frequency")
plt.show() 

x = dataframe["sepal_width"] 
dd=dataframe[dataframe['species'] == "setosa"]
dd.boxplot()

plt.figure(figsize = (10, 7)) 
plt.hist(x, bins = 15, color = "blue", edgecolor="black") 
plt.title("Sepal Width Histogram") 
plt.xlabel("Sepal_Width_Cm") 
plt.ylabel("Frequency")
plt.show() 

dataframe.boxplot()

