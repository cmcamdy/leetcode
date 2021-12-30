#-*- coding:utf-8 -*-
from pulp import *

Ingredients = ['A', 'B', 'C']
profits = {'A': 10, 'B': 8, 'C': 16}

Nickel = {'A': 3, 'B': 3, 'C': 2}
Aluminum = {'A': 4, 'B': 3, 'C': 7}
#创建问题实例，求最大极值
prob = LpProblem("The Whiskas Problem", LpMaximize)

#构建Lp变量字典，变量名以Ingr开头，如Ingr_CHICKEN，下界是0
ingredient_vars = LpVariable.dicts("Ingr",
                                   Ingredients,
                                   lowBound=0,
                                   upBound=None)
#添加目标方程
prob += lpSum([profits[i] * ingredient_vars[i] for i in Ingredients])

#添加约束条件
prob += lpSum([Nickel[i] * ingredient_vars[i] for i in Ingredients]) <= 200
prob += lpSum([Aluminum[i] * ingredient_vars[i] for i in Ingredients]) <= 300

#求解
prob.solve()
#查看解的状态
print("Status:", LpStatus[prob.status])
# #查看解
for v in prob.variables():
    print(v.name.split('_')[-1], "=", v.varValue)


