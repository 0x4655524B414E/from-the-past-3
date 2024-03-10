if __name__ == "__main__":
    f = float(input())
    i = int(input())
    sep = str(input())
    string = str(input())
    print(f)
    print(i)
    if int(f) == i:
        print(f)
    separated_list = list(i for i in string.split(sep=sep))
    print(separated_list)
    print(separated_list.sort(reverse=False))
    mid_val = separated_list[len(separated_list) // 2]
    print(mid_val)
    """
    For the setup, you will

    take an input from user and convert it into a floating number named f.
    take an input from user and convert it into a integter number named i.
    take an input from user named sep. That will work as a separator value later.
    take an input from user named string.

After the input operations, you must

    print f.
    print i.
    convert f to an integer and print if converted number and i are equal.
    separate string by using sep as the separator and assign it to a list named separated_list.
    print separated_list.
    sort and print separated_list.
    assign middle element of the separated_list to a variable named mid_val and print it.
    
    Input Format
    
    floating number
    
    integer number
    
    separator
    
    string
    
    Constraints
    
    Seperators can be one of the following characters '.,;:!?+-*/'.
    
    """
    f = input()  # input takes float in a string type
    f = float(f)  # conversion to float
    i = input()  # input takes integer in a string type
    i = int(i)  # conversion to int
    sep = input()  # separator from user
    string = input()  # gets a string (will be separated)

    print(f)
    print(i)
    f = int(f)  # omits the floating part
    print(f == i)
    separated_list = string.split(sep)  # split according to separator and return list
    print(separated_list)
    separated_list.sort()  # sort the list in ascending order (one may reverse if the descending order is wanted)
    print(separated_list)
    mid_val = separated_list[len(separated_list) // 2]  # perform the division and omit the remainder.
    print(mid_val)