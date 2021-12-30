import random
class PSOMax:
    def __init__(self,
                 xList: list,
                 vList: list,
                 xmax: int = 5,
                 xmin: int = -2) -> None:
        self.xList = xList
        self.pBest = xList

        self.vList = vList
        self.gBest = -2
        self.c1, self.c2 = 2, 2
        self.xmax = xmax
        self.xmin = xmin
        self.init()
        self.printInfo()

    def runPSO(self):
        tmpBest = self.fun(self.gBest)
        for index in range(len(self.xList)):
            self.vList[index] += self.c1 * random.random() * (
                self.pBest[index] - self.xList[index]
            ) + self.c2 * random.random() * (self.gBest - self.xList[index])
            self.xList[index] += self.vList[index]

            # 保证是落在范围里
            while self.xList[index] > self.xmax or self.xList[
                    index] < self.xmin:
                if self.xList[index] > self.xmax:
                    self.xList[index] = 2 * self.xmax - self.xList[index]
                if self.xList[index] < self.xmin:
                    self.xList[index] = 2 * self.xmin - self.xList[index]

            tmp = self.fun(self.xList[index])
            # 更新 gbest pbest
            self.pBest[index] = self.xList[index] if tmp > self.fun(
                self.pBest[index]) else self.pBest[index]
            self.gBest = self.xList[index] if tmp > tmpBest else self.gBest
        # self.printInfo()

    def fun(self, x):
        # return x**3 - 5 * x**2 - 2 * x + 3
        return x**3 - 5 * x**2 - 2 * x + 3

    def init(self):

        for x in self.xList:
            self.gBest = x if self.fun(x) > self.fun(
                self.gBest) else self.gBest

    def printInfo(self):
        print("{}::self.gBest={},bestValue={}".format(self.__class__.__name__, self.gBest,
                                                      self.fun(self.gBest)))
        # print("self.pBest={}".format(self.pBest))
        # print("self.xList={}".format(self.xList))


class PSOMin:
    def __init__(self,
                 xList: list,
                 vList: list,
                 xmax: int = 5,
                 xmin: int = -2) -> None:
        self.xList = xList
        self.pBest = xList

        self.vList = vList
        self.gBest = -2
        self.c1, self.c2 = 2, 2
        self.xmax = xmax
        self.xmin = xmin
        self.init()
        self.printInfo()

    def runPSO(self):
        tmpBest = self.fun(self.gBest)
        for index in range(len(self.xList)):
            self.vList[index] += self.c1 * random.random() * (
                self.pBest[index] - self.xList[index]
            ) + self.c2 * random.random() * (self.gBest - self.xList[index])
            self.xList[index] += self.vList[index]

            # 保证是落在范围里
            while self.xList[index] > self.xmax or self.xList[
                    index] < self.xmin:
                if self.xList[index] > self.xmax:
                    self.xList[index] = 2 * self.xmax - self.xList[index]
                if self.xList[index] < self.xmin:
                    self.xList[index] = 2 * self.xmin - self.xList[index]

            tmp = self.fun(self.xList[index])
            # 更新 gbest pbest
            self.pBest[index] = self.xList[index] if tmp < self.fun(
                self.pBest[index]) else self.pBest[index]
            self.gBest = self.xList[index] if tmp < tmpBest else self.gBest
        # self.printInfo()

    def fun(self, x):
        # return x**3 - 5 * x**2 - 2 * x + 3
        return x**3 - 5 * x**2 - 2 * x + 3

    def init(self):
        for x in self.xList:
            self.gBest = x if self.fun(x) < self.fun(
                self.gBest) else self.gBest

    def printInfo(self):
        print("{}::self.gBest={},bestValue={}".format(self.__class__.__name__, self.gBest,
                                                      self.fun(self.gBest)))
        # print("self.pBest={}".format(self.pBest))
        # print("self.xList={}".format(self.xList))


if __name__ == '__main__':
    p = PSOMin(xList=[-2, 3, -1, 2],
               vList=[0.001, 0.001, 0.001, 0.001, 0.001],
               xmax=5,
               xmin=-2)
    for _ in range(100):
        p.runPSO()
    p.printInfo()
    p = PSOMax(xList=[-2, 3, -1, 2],
               vList=[0.001, 0.001, 0.001, 0.001, 0.001],
               xmax=5,
               xmin=-2)
    for _ in range(100):
        p.runPSO()
    p.printInfo()


