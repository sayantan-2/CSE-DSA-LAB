class Term:
    def __init__(self, coefficient, exponent):
        self.coefficient = coefficient
        self.exponent = exponent
        self.next = None


def create_term(coefficient, exponent):
    return Term(coefficient, exponent)


def insert_term(head, coefficient, exponent):
    new_term = create_term(coefficient, exponent)

    if head is None:
        head = new_term
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_term

    return head


def print_polynomial(head):
    while head is not None:
        print(f"{head.coefficient}x^{head.exponent}", end=" ")
        if head.next is not None and head.next.coefficient >= 0:
            print("+", end=" ")
        head = head.next
    print()


def add_polynomials(poly1, poly2):
    result = None
    temp1 = poly1
    temp2 = poly2

    while temp1 is not None and temp2 is not None:
        if temp1.exponent > temp2.exponent:
            result = insert_term(result, temp1.coefficient, temp1.exponent)
            temp1 = temp1.next
        elif temp1.exponent < temp2.exponent:
            result = insert_term(result, temp2.coefficient, temp2.exponent)
            temp2 = temp2.next
        else:
            sum_coeff = temp1.coefficient + temp2.coefficient
            if sum_coeff != 0:
                result = insert_term(result, sum_coeff, temp1.exponent)
            temp1 = temp1.next
            temp2 = temp2.next

    while temp1 is not None:
        result = insert_term(result, temp1.coefficient, temp1.exponent)
        temp1 = temp1.next

    while temp2 is not None:
        result = insert_term(result, temp2.coefficient, temp2.exponent)
        temp2 = temp2.next

    return result


if __name__ == "__main__":
    poly1 = None
    poly2 = None

    num_terms1 = int(input("Enter the number of terms in Polynomial 1: "))
    print("Enter the terms for Polynomial 1 (coefficient exponent):")
    for _ in range(num_terms1):
        coeff, exp = map(int, input().split())
        poly1 = insert_term(poly1, coeff, exp)

    num_terms2 = int(input("Enter the number of terms in Polynomial 2: "))
    print("Enter the terms for Polynomial 2 (coefficient exponent):")
    for _ in range(num_terms2):
        coeff, exp = map(int, input().split())
        poly2 = insert_term(poly2, coeff, exp)

    print("Polynomial 1:", end=" ")
    print_polynomial(poly1)

    print("Polynomial 2:", end=" ")
    print_polynomial(poly2)

    sum_poly = add_polynomials(poly1, poly2)
    print("Sum of Polynomials:", end=" ")
    print_polynomial(sum_poly)
