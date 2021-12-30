import random
# import pprint

class Gridworld:
    def __init__(self, width, rewards, links, gamma) -> None:
        self.grid = [[random.random() * (wi + 1) for wi in range(width)]
                     for w in range(width)]
        self.width = width
        self.rewards = rewards
        for key, value in self.rewards.items():
            assert len(value) is width, "width error!"
        self.jumpPoints = links.keys()
        self.links = links
        self.gamma = gamma

    def randomPolicyCalculate(self):
        for i in range(self.width):
            for j in range(self.width):
                re = self.rewards["L"][i][j] + self.rewards["U"][i][
                    j] + self.rewards["R"][i][j] + self.rewards["D"][i][j]
                # 跳跃边
                if (i, j) in self.jumpPoints:
                    toPoint = self.links[(i, j)]
                    self.grid[i][j] = (
                        re + self.gamma *
                        (4 * self.grid[toPoint[0]][toPoint[1]])) / 4
                # 四个角
                elif i == 0 and j == 0:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i + 1][j] + self.grid[i][j + 1] +
                         2 * self.grid[i][j])) / 4
                elif i == 0 and j == self.width - 1:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i + 1][j] + self.grid[i][j - 1] +
                         2 * self.grid[i][j])) / 4
                elif i == self.width - 1 and j == 0:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i][j + 1] +
                         2 * self.grid[i][j])) / 4
                elif i == self.width - 1 and j == self.width - 1:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i][j - 1] +
                         2 * self.grid[i][j])) / 4
                # 四条边
                elif i == 0:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i + 1][j] + self.grid[i][j - 1] +
                         self.grid[i][j + 1] + self.grid[i][j])) / 4
                elif i == self.width - 1:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i][j - 1] +
                         self.grid[i][j + 1] + self.grid[i][j])) / 4
                elif j == 0:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i + 1][j] +
                         self.grid[i][j + 1] + self.grid[i][j])) / 4
                elif j == self.width - 1:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i + 1][j] +
                         self.grid[i][j - 1] + self.grid[i][j])) / 4
                # 内部点
                else:
                    self.grid[i][j] = (
                        re + self.gamma *
                        (self.grid[i - 1][j] + self.grid[i + 1][j] +
                         self.grid[i][j - 1] + self.grid[i][j + 1])) / 4

    def optimalPolicyCalculate(self):
        for i in range(self.width):
            for j in range(self.width):
                re = self.rewards["L"][i][j] + self.rewards["U"][i][
                    j] + self.rewards["R"][i][j] + self.rewards["D"][i][j]
                # 跳跃边
                if (i, j) in self.jumpPoints:
                    # 四边一样，因此不用改
                    toPoint = self.links[(i, j)]
                    self.grid[i][j] = (
                        re + self.gamma *
                        (4 * self.grid[toPoint[0]][toPoint[1]])) / 4
                # 四个角
                elif i == 0 and j == 0:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["U"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i + 1][j],
                    )
                elif i == 0 and j == self.width - 1:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["R"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i + 1][j],
                    )
                elif i == self.width - 1 and j == 0:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] + self.gamma * self.grid[i][j],
                    )
                elif i == self.width - 1 and j == self.width - 1:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["D"][i][j] + self.gamma * self.grid[i][j],
                    )
                # 四条边
                elif i == 0:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i + 1][j],
                    )
                elif i == self.width - 1:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] + self.gamma * self.grid[i][j],
                    )
                elif j == 0:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i + 1][j],
                    )
                elif j == self.width - 1:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] + self.gamma * self.grid[i][j],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                    )
                # 内部点
                else:
                    self.grid[i][j] = max(
                        self.rewards["L"][i][j] +
                        self.gamma * self.grid[i][j - 1],
                        self.rewards["U"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                        self.rewards["R"][i][j] +
                        self.gamma * self.grid[i][j + 1],
                        self.rewards["D"][i][j] +
                        self.gamma * self.grid[i - 1][j],
                    )

    def show(self):
        # import pprint
        # pprint.pprint(self.grid)
        for index in range(self.width):
            print(self.grid[index])
        # print(self.grid)
        # for key, value in self.rewards.items():
        #     print(key)
        #     pprint.pprint(value)
        # pprint.pprint('key={}\nvalue={}'.format(key, value))


if __name__ == '__main__':
    # 四个方向的reward
    rewardL = [[-1, 10, 0, 5, 0], [-1, 0, 0, 0, 0], [-1, 0, 0, 0, 0],
               [-1, 0, 0, 0, 0], [-1, 0, 0, 0, 0]]
    rewardU = [[-1, 10, -1, 5, -1], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
    rewardR = [[0, 10, 0, 5, -1], [0, 0, 0, 0, -1], [0, 0, 0, 0, -1],
               [0, 0, 0, 0, -1], [0, 0, 0, 0, -1]]
    rewardD = [[0, 10, 0, 5, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0], [-1, -1, -1, -1, -1]]
    rewards = {"L": rewardL, "U": rewardU, "R": rewardR, "D": rewardD}
    links = {(0, 1): (4, 1), (0, 3): (2, 3)}
    g = Gridworld(width=5, rewards=rewards, links=links, gamma=0.9)
    # before train
    g.show()
    # g.calculate()
    for index in range(10000):
        g.randomPolicyCalculate()
        # g.optimalPolicyCalculate()
    print("after randomPolicyCalculate train")
    g.show()
    for index in range(10000):
        # g.randomPolicyCalculate()
        g.optimalPolicyCalculate()
    print("after optimalPolicyCalculate train")
    g.show()