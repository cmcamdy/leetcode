class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        '''
            1.先判断正负号
            2.将倍数转化成二进制
            3.注意int 和long之间的转化
        '''
        sign = 1 if (dividend > 0 and divisor > 0) or (dividend < 0
                                                       and divisor < 0) else -1
        a = abs(dividend)
        b = abs(divisor)

        time_bit_cnt = 0  #除法时，最高的bit位
        while a >= b:
            time_bit_cnt += 1
            b <<= 1

        time = 0
        while time_bit_cnt > 0:  #bit从左往右
            time_bit_cnt -= 1
            b >>= 1

            if a >= b:  #当前bit位，每次减1
                time += (1 << time_bit_cnt)
                a -= b

        if sign < 0:
            time = 0 - time
        return time if -(1 << 31) <= time <= (1 << 31) - 1 else (1 << 31) - 1