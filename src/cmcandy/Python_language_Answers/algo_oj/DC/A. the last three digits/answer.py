def last_three_nums(m, n):

    if n == 1:
        return m
    else:
        tmp = n // 2
        return ((last_three_nums(m, tmp) % 1000) *
                (last_three_nums(m, n - tmp) % 1000)) % 1000


if __name__ == '__main__':
    with open('input.txt', 'r+') as f:
        for line in f.readlines():
            para = line.split(' ')
            m, n = int(para[0]), int(para[1])
            print(last_three_nums(m, n))
