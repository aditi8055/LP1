import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix,classification_report
from sklearn.naive_bayes import GaussianNB
import seaborn as sns

df=pd.read_csv('PimaIndiansDiabetes.csv')
df.info()
df.head()
df.describe()

df.dropna()

#df.replace('0',7,inplace=True)
#df.drop(['Loan_ID'],1,inplace=True)

#df.Class = ['Yes' if each == '1' else 'No' for each in df.Class]
print(df.describe().to_string())

plt.figure(figsize=(14,8))
df.boxplot()
plt.show()

x=df[["TimesPregnant","GlucoseConcentration","BloodPrs","SkinThickness","Serum","BMI","DiabetesFunct","Age"]]
y=df["Class"]


X_train,X_test,Y_train,Y_test=train_test_split(x,y,test_size=0.2,random_state=42)

model=GaussianNB()
model.fit(X_train,Y_train)
y_pred=model.predict(X_test)

accuracy=accuracy_score(Y_test,y_pred)
print('Accuracy 1: ')
print(accuracy)

cm=confusion_matrix(Y_test,y_pred)
print( 'Confusion Matrix for Naive Bayes :')
print(cm)



# training a DescisionTreeClassifier 
from sklearn.tree import DecisionTreeClassifier 
dtree_model = DecisionTreeClassifier(max_depth = 2).fit(X_train, Y_train) 
dtree_predictions = dtree_model.predict(X_test) 
accuracy2=dtree_model.score(X_test,Y_test)
print('Accuracy 2: ')
print(accuracy2)
# creating a confusion matrix 
cm = confusion_matrix(Y_test, dtree_predictions)

print( 'Confusion Matrix for Decision Tree :')
print(cm)

f,ax= plt.subplots(figsize=(5,5))
sns.heatmap(cm,annot=True,linewidth=0.7,linecolor='cyan',fmt='.0f',ax=ax,cmap='BrBG')
plt.title('dtree cm')
plt.xlabel('y_pred')
plt.ylabel('y_test')
plt.show()

print(classification_report(Y_test,y_pred))

objects = ('NB', 'DecisionTree')
y_pos = np.arange(len(objects))
performance = [accuracy,accuracy2]

plt.bar(y_pos, performance, align='center', alpha=0.5,color='green',width=0.5)
plt.xticks(y_pos, objects)
plt.xlabel('Performance')
plt.title('Accuracy comparison')

plt.show()








