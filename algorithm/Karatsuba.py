#version 2.7.6
def karatsuba(num1, num2):
    if (num1 < 10) or (num2 < 10):
        return num1*num2
    num1Str = str(num1)
    num2Str = str(num2)

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = maxLength / 2
    high1, low1= num1Str[:-splitPosition], num1Str[-splitPosition:]
    print high1, low1
    high2, low2= num2Str[:-splitPosition], num2Str[-splitPosition:]
    high1,low1,high2,low2 = int(high1),int(low1),int(high2),int(low2)
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2*10**(2*splitPosition)) + ((z1-z2-z0)*10**(splitPosition))+z0

print karatsuba(699422,36)