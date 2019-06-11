cmake_minimum_required(VERSION 3.14)
project(data_structure_c C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure_c main.c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h)
add_executable(circular_list_with_tail 01-linear-list/02-linked-list/02-circular-list/02-circular-list-with-tail/main.c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h 01-linear-list/02-linked-list/02-circular-list/02-circular-list-with-tail/circularlistwithtail.c 01-linear-list/02-linked-list/02-circular-list/02-circular-list-with-tail/circularlistwithtail.h)
add_executable(circular_list_josephus_problem ./01-linear-list/02-linked-list/51-josephus-problem/main.c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h 01-linear-list/02-linked-list/02-circular-list/02-circular-list-with-tail/circularlistwithtail.c 01-linear-list/02-linked-list/02-circular-list/02-circular-list-with-tail/circularlistwithtail.h)
add_executable(doubly_linked_list_without_sentinel_c 01-linear-list/02-linked-list/03-doubly-linked-list/01-doubly-linked-list-without-sentinel/main.c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h 01-linear-list/02-linked-list/03-doubly-linked-list/01-doubly-linked-list-without-sentinel/doublylinkedlist.h 01-linear-list/02-linked-list/03-doubly-linked-list/01-doubly-linked-list-without-sentinel/doublylinkedlist.c)
add_executable(singly_linked_list_with_sentinel_c 01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/main.c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h 01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.h 01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.c)
add_executable(singly_linked_list_polynomial 01-linear-list/02-linked-list/01-singly-linked-list/51-polynomial/main.c 01-linear-list/02-linked-list/01-singly-linked-list/51-polynomial/polynomial.h 01-linear-list/02-linked-list/01-singly-linked-list/51-polynomial/polynomial.c)
add_executable(stack_sequential_stack 01-linear-list/03-stack/01-sequential-stack/main.c 01-linear-list/03-stack/stack.h 01-linear-list/03-stack/01-sequential-stack/sequentialstack.h 01-linear-list/03-stack/01-sequential-stack/sequentialstack.c)
add_executable(stack_linked_stack
        01-linear-list/03-stack/02-linked-stack/main.c
        01-linear-list/03-stack/stack.h
        01-linear-list/03-stack/02-linked-stack/linkedstack.c
        01-linear-list/linearlist.h
        01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.h
        01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.c
        01-linear-list/03-stack/02-linked-stack/linkedstack.h)
add_executable(stack_static_list
        01-linear-list/02-linked-list/04-static-list/main.c
        01-linear-list/02-linked-list/04-static-list/staticlist.h
        01-linear-list/02-linked-list/04-static-list/staticlist.c
        )
add_executable(stack_double_list
        01-linear-list/03-stack/03-multiple-stack/01-double-stack/main.c
        01-linear-list/03-stack/03-multiple-stack/01-double-stack/doublestack.c
        01-linear-list/03-stack/03-multiple-stack/01-double-stack/doublestack.h
        )
add_executable(stack_match-brackets
        01-linear-list/03-stack/51-match-brackets/main.c
        01-linear-list/03-stack/02-linked-stack/linkedstack.c
        01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.c
        01-linear-list/03-stack/51-match-brackets/matchbrackets.c
        01-linear-list/03-stack/51-match-brackets/matchbrackets.h
        )
add_executable(stack_polynomial_airthmetic_single_num
        01-linear-list/03-stack/52-polynomial-airthmetic/main.c
        01-linear-list/03-stack/02-linked-stack/linkedstack.c
        01-linear-list/02-linked-list/01-singly-linked-list/01-singly-linked-list-with-sentinel/singlylinkedlist.c
        01-linear-list/03-stack/52-polynomial-airthmetic/polynomialairthmetic.c
        01-linear-list/03-stack/52-polynomial-airthmetic/polynomialairthmetic.h
        )
add_executable(stack_polynomial_airthmetic_double
        01-linear-list/03-stack/52-polynomial-airthmetic/main.c
        01-linear-list/03-stack/52-polynomial-airthmetic/linkedlist.c
        01-linear-list/03-stack/52-polynomial-airthmetic/linkedlist.h
        01-linear-list/03-stack/52-polynomial-airthmetic/polynomialairthmetic.c
        01-linear-list/03-stack/52-polynomial-airthmetic/polynomialairthmetic.h
        01-linear-list/03-stack/52-polynomial-airthmetic/infixtosuffix.c 01-linear-list/03-stack/52-polynomial-airthmetic/infixtosuffix.h 01-linear-list/03-stack/52-polynomial-airthmetic/linedlistforoperator.c 01-linear-list/03-stack/52-polynomial-airthmetic/linedlistforoperator.h)