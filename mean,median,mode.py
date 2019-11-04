# -*- coding: utf-8 -*-
"""
Created on Sun Nov  3 19:24:34 2019

@author: Arti
"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df= pd.read_csv("zoo.csv",quotechar="'")

#print(df.head())


print('sum of water need:')
print(df['water_need'].sum())

print('mean of water need:')
mean=df['water_need'].mean()
print(mean)

print('median of water need:')
median=df['water_need'].median()
print(median)

print('std dev of water need:')
std=df['water_need'].std()
print(std)

print('min of water need:')
print(df['water_need'].min())

print('max of water need:')
print(df['water_need'].max())

print('min index of water need:')
print(df['water_need'].idxmin())

print('var of water need:')
var=df['water_need'].var()
print(var)


df.hist()


objects = ('mean', 'median','std d','var')
y_pos = np.arange(len(objects))
performance = [mean,median,std,var]

plt.bar(y_pos, performance, align='center', alpha=0.5,color='green',width=0.5)
plt.xticks(y_pos, objects)
plt.xlabel('Performance')
plt.title('comparison')

plt.show()

df.boxplot()
