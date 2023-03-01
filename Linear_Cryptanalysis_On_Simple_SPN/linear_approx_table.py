import sys

# sbox from the tutorial
sbox = [0x8, 0x4, 0x2, 0x1, 0xc, 0x6, 0x3, 0xd, 0xa, 0x5, 0xe, 0x7, 0xf, 0xb, 0x9, 0x0]
# sbox = [0xf, 3, 0xa, 6, 4, 1, 0xb, 9, 0xe, 5, 0, 0xd, 2, 0xc, 7, 8]
# sbox = [0xe, 0x4, 0xd, 0x1, 0x2, 0xf, 0xb, 0x8, 0x3, 0xa,0x6, 0xc, 0x5, 0x9, 0x0, 0x7]
SIZE_SBOX = len(sbox)

# compute the linear approximation for a given "input = output" equations
def linearApprox(input_int, output_int):
    total = 0
    # range over the input
    for ii in range(SIZE_SBOX):
        # get input and output of our equations
        input_masked = ii & input_int
        output_masked = sbox[ii] & output_int
        # same result?
        if (bin(input_masked).count("1") - bin(output_masked).count("1")) % 2 == 0:
            total += 1 
    # get the number of results compared to 8/16
    result = total - (SIZE_SBOX//2)
    if result > 0:
        result = "+" + str(result)
    else:
        result = str(result)

    return result

def main():
    # rows
    sys.stdout.write("    | ")
    for i in range(SIZE_SBOX):
        sys.stdout.write(hex(i)[2:].rjust(3) + " ")
    print("")
    print(" " + "-" * (SIZE_SBOX * 4 + 4))
    for row in range(SIZE_SBOX):
        sys.stdout.write(hex(row)[2:].rjust(3) + " | ")
        # cols
        for col in range(SIZE_SBOX):
            # print the linear approx
            sys.stdout.write(linearApprox(row, col).rjust(3) + " ")

        print("")

if __name__ == "__main__":
    main()
