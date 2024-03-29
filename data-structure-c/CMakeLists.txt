cmake_minimum_required(VERSION 3.14)
project(data_structure_c C)

set(CMAKE_C_STANDARD 99)

#add_executable(data_structure_c 01-linear-list/02-linked-list/linknode.h 01-linear-list/linearlist.h)
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
add_executable(recursion_fibonacci_recursion
        51-recursion/01-fibonacci-sequence/01-fibonacci-sequence-recursion/main.c
        51-recursion/01-fibonacci-sequence/01-fibonacci-sequence-recursion/fibonacci.c
        51-recursion/01-fibonacci-sequence/01-fibonacci-sequence-recursion/fibonacci.h
        )
add_executable(recursion_fibonacci_non_recursion
        51-recursion/01-fibonacci-sequence/02-fibonacci-sequence-non-recursion/main.c
        51-recursion/01-fibonacci-sequence/02-fibonacci-sequence-non-recursion/fibonacci.c
        51-recursion/01-fibonacci-sequence/02-fibonacci-sequence-non-recursion/fibonacci.h
        )
add_executable(queue_sequential_queue
        01-linear-list/04-queue/01-queue/01-sequential-queue/main.c
        01-linear-list/04-queue/01-queue/01-sequential-queue/sequentialqueue.c
        01-linear-list/04-queue/queue.h
        01-linear-list/04-queue/01-queue/01-sequential-queue/sequentialqueue.h)
add_executable(queue_linked_queue
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.c
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h
        01-linear-list/04-queue/01-queue/02-linked-queue/main.c
        01-linear-list/04-queue/queue.h
        )
add_executable(queue_circular_queue
        01-linear-list/04-queue/01-queue/03-circular-queue/01-circluar-queue-no-flag/circularqueue.c
        01-linear-list/04-queue/01-queue/03-circular-queue/01-circluar-queue-no-flag/circularqueue.h
        01-linear-list/04-queue/01-queue/03-circular-queue/01-circluar-queue-no-flag/main.c
        01-linear-list/04-queue/queue.h
        )
add_executable(queue_circular_queue_flag
        01-linear-list/04-queue/01-queue/03-circular-queue/02-circluar-queue-flag/circularqueue.c
        01-linear-list/04-queue/01-queue/03-circular-queue/02-circluar-queue-flag/circularqueue.h
        01-linear-list/04-queue/01-queue/03-circular-queue/02-circluar-queue-flag/main.c
        01-linear-list/04-queue/queue.h
        )
add_executable(queue_pascal_triangle
        01-linear-list/04-queue/queue.h
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.c
        01-linear-list/04-queue/51-pascal-triangle/pascaltriangle.c
        01-linear-list/04-queue/51-pascal-triangle/pascaltriangle.h
        01-linear-list/04-queue/51-pascal-triangle/main.c
        )
add_executable(queue_priority_queue
        01-linear-list/04-queue/01-queue/04-priority-queue/priorityqueue.h
        01-linear-list/04-queue/01-queue/04-priority-queue/priorityqueue.c
        01-linear-list/04-queue/01-queue/04-priority-queue/main.c
        01-linear-list/04-queue/queue.h
        )
#add_executable(tree_fundamental_tree_list
#        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/fundamentaltree.c
#        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/fundamentaltree.h
#        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/main.c
#        )
add_executable(tree_binary_tree_save
        02-nonlinear-list/02-tree/02-binary-tree/01-binary-tree-save/fundamentaltree.c
        02-nonlinear-list/02-tree/02-binary-tree/01-binary-tree-save/fundamentaltree.h
        02-nonlinear-list/02-tree/02-binary-tree/01-binary-tree-save/main.c
        )
add_executable(tree_binary_search_tree
        02-nonlinear-list/02-tree/02-binary-tree/05-binary-search-tree/binarysearchtree.c
        02-nonlinear-list/02-tree/02-binary-tree/05-binary-search-tree/binarysearchtree.h
        02-nonlinear-list/02-tree/02-binary-tree/05-binary-search-tree/main.c
        02-nonlinear-list/02-tree/02-binary-tree/05-binary-search-tree/treenodequeue.h
        02-nonlinear-list/02-tree/02-binary-tree/05-binary-search-tree/treenodequeue.c
        )
add_executable(matrix_ordinary_matrix
        02-nonlinear-list/01-matrix/01-ordinary-matrix/main.c
        02-nonlinear-list/01-matrix/01-ordinary-matrix/ordinarymatrix.c
        02-nonlinear-list/01-matrix/01-ordinary-matrix/ordinarymatrix.h
        )
add_executable(matrix_particular_matrix_upper_triangular
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/01-upper-triangular-matrix/main.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/01-upper-triangular-matrix/uppertriangularmatrix.h
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/01-upper-triangular-matrix/uppertriangularmatrix.c
        )
add_executable(matrix_particular_matrix_below_triangular
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/02-below-triangular-matrix/main.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/02-below-triangular-matrix/belowtriangularmatrix.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/02-below-triangular-matrix/belowtriangularmatrix.h
        )
add_executable(matrix_particular_matrix_three_diagonal
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/03-three-diagonal-matrix/main.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/03-three-diagonal-matrix/threediagonalmatrix.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/03-three-diagonal-matrix/threediagonalmatrix.h
        )
add_executable(matrix_particular_matrix_multi_diagonal
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/04-multi-diagonal-matrix/main.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/04-multi-diagonal-matrix/multidiagonalmatrix.c
        02-nonlinear-list/01-matrix/02-particular-matrix/01-symmetric-matrix/04-multi-diagonal-matrix/multidiagonalmatrix.h
        )
add_executable(string_bf_match
        02-nonlinear-list/03-string/01-string-match-algorithm/01-bf/bfmatch.h
        02-nonlinear-list/03-string/01-string-match-algorithm/01-bf/bfmatch.c
        02-nonlinear-list/03-string/01-string-match-algorithm/01-bf/main.c
        )
add_executable(string_rk_match
        02-nonlinear-list/03-string/01-string-match-algorithm/02-rk/rkmatch.h
        02-nonlinear-list/03-string/01-string-match-algorithm/02-rk/rkmatch.c
        02-nonlinear-list/03-string/01-string-match-algorithm/02-rk/main.c
        )
add_executable(string_bm_match
        02-nonlinear-list/03-string/01-string-match-algorithm/03-bm/bmmatch.h
        02-nonlinear-list/03-string/01-string-match-algorithm/03-bm/bmmatch.c
        02-nonlinear-list/03-string/01-string-match-algorithm/03-bm/main.c
        )
add_executable(string_kmp_match
        02-nonlinear-list/03-string/01-string-match-algorithm/04-kmp/kmpstring.c
        02-nonlinear-list/03-string/01-string-match-algorithm/04-kmp/kmpstring.h
        02-nonlinear-list/03-string/01-string-match-algorithm/04-kmp/main.c
        )
add_executable(tree_binary_recursive_print
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/01-binary-tree-recursive-print/binarytreerecursive.h
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/01-binary-tree-recursive-print/binarytreerecursive.c
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/01-binary-tree-recursive-print/main.c
        )
add_executable(tree_binary_non-recursive_pre_and_in_print
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/01-pre-and-in/binarytreenonrecursive.h
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/01-pre-and-in/binarytreenonrecursive.c
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/01-pre-and-in/main.c
        )
add_executable(tree_binary_non-recursive_post_print
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/02-post/binarytreenonrescursivepost.h
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/02-post/binarytreenonrescursivepost.c
        02-nonlinear-list/02-tree/02-binary-tree/02-binary-tree-traverse/02-binary-tree-non-recursive-print/02-post/main.c
        )
add_executable(tree_binary_threaded_inorder
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/01-inorder-thread/threadedbinarytreeinorder.c
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/01-inorder-thread/threadedbinarytreeinorder.h
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/01-inorder-thread/main.c
        )
add_executable(tree_binary_threaded_preorder
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/02-preorder-thread/threadbinarytreepreorder.c
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/02-preorder-thread/threadbinarytreepreorder.h
        02-nonlinear-list/02-tree/02-binary-tree/03-threaded-binary-tree/02-preorder-thread/main.c
        )
add_executable(tree_fundamental_tree_parent_pointer
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/01-parent-pointer/parentpointer.c
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/01-parent-pointer/parentpointer.h
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/01-parent-pointer/main.c
        )
add_executable(tree_fundamental_tree_child_link
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/02-child-link/childlink.h
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/02-child-link/childlink.c
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/02-child-link/main.c
        )
add_executable(tree_fundamental_tree_child_brother_link
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/childbrotherlist.h
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/childbrotherlist.c
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/main.c
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/linkedqueue.h
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/linkedqueue.c
        02-nonlinear-list/02-tree/01-fundamental-tree/01-fundamental-tree-storage/03-child-brother-list/treenode.h
        #        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h
        #        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.c
        #        01-linear-list/04-queue/01-queue/02-linked-queue/main.c
        #        01-linear-list/04-queue/queue.h
        )
#add_executable(tree_forest
#        02-nonlinear-list/02-tree/03-forest/01-forest-to-binary-tree/foresttotree.h
#        02-nonlinear-list/02-tree/03-forest/01-forest-to-binary-tree/foresttotree.c
#        02-nonlinear-list/02-tree/03-forest/01-forest-to-binary-tree/main.c
#        )
add_executable(tree_binary_confirm
        02-nonlinear-list/02-tree/02-binary-tree/04-binary-tree-confirm/binarytreeconfirm.h
        02-nonlinear-list/02-tree/02-binary-tree/04-binary-tree-confirm/binarytreeconfirm.c
        02-nonlinear-list/02-tree/02-binary-tree/04-binary-tree-confirm/main.c
        )
add_executable(tree_binary_search_self_balance_avl
        02-nonlinear-list/02-tree/02-binary-tree/06-self-balancing-binary-search-tree/01-avl/selfbalancetree.c
        02-nonlinear-list/02-tree/02-binary-tree/06-self-balancing-binary-search-tree/01-avl/selfbalancetree.h
        02-nonlinear-list/02-tree/02-binary-tree/06-self-balancing-binary-search-tree/01-avl/main.c
        02-nonlinear-list/02-tree/02-binary-tree/06-self-balancing-binary-search-tree/01-avl/stacktreenode.h
        02-nonlinear-list/02-tree/02-binary-tree/06-self-balancing-binary-search-tree/01-avl/stacktreenode.c
        )

add_executable(graph_storage_represention_adjacency_matrix
        02-nonlinear-list/05-graph/01-graph-storage-representation/01-adjacency-matrix/01-undirected-graph-with-weight-matrix/adjacencymatrix.h
        02-nonlinear-list/05-graph/01-graph-storage-representation/01-adjacency-matrix/01-undirected-graph-with-weight-matrix/adjacencymatrix.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/01-adjacency-matrix/01-undirected-graph-with-weight-matrix/main.c
        02-nonlinear-list/05-graph/graph.h
        )

add_executable(graph_storage_represention_adjacency_list
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/01-directed-graph-with-weight-list/adjacencylist.h
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/01-directed-graph-with-weight-list/adjacencylist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/01-directed-graph-with-weight-list/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_storage_represention_adjacency_multilist
        02-nonlinear-list/05-graph/01-graph-storage-representation/03-adjacency-multilist/01-undirected-graph-with-weight-multilist/adjacencymultilist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/03-adjacency-multilist/01-undirected-graph-with-weight-multilist/adjacencymultilist.h
        02-nonlinear-list/05-graph/01-graph-storage-representation/03-adjacency-multilist/01-undirected-graph-with-weight-multilist/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_storage_represention_adjacency_list_undirected
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_traverse_breadth_first
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/01-breadth-first/linkedqueue/linkedqueue.h
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/01-breadth-first/linkedqueue/linkedqueue.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/01-breadth-first/breadthfirsttraverse.c
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/01-breadth-first/breadthfirsttraverse.h
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/01-breadth-first/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_traverse_deapth_first
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/02-depth-first/depthfirsttraverse.h
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/02-depth-first/depthfirsttraverse.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h
        02-nonlinear-list/05-graph/02-graph-traverse-and-shortest-path/02-depth-first/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_search_breadth_first
        02-nonlinear-list/05-graph/03-graph-search/01-breadth-first-search/linkedqueue/linkedqueue.c
        02-nonlinear-list/05-graph/03-graph-search/01-breadth-first-search/linkedqueue/linkedqueue.h
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h
        02-nonlinear-list/05-graph/03-graph-search/01-breadth-first-search/breadthfirstsearch.h
        02-nonlinear-list/05-graph/03-graph-search/01-breadth-first-search/breadthfirstsearch.c
        02-nonlinear-list/05-graph/03-graph-search/01-breadth-first-search/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_search_deapth_first
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.c
        02-nonlinear-list/05-graph/01-graph-storage-representation/02-adjacency-list/02-undirected-graph-with-weight-list/udadjacentlist.h
        02-nonlinear-list/05-graph/03-graph-search/02-depth-first-search/depthfirstsearch.c
        02-nonlinear-list/05-graph/03-graph-search/02-depth-first-search/depthfirstsearch.h
        02-nonlinear-list/05-graph/03-graph-search/02-depth-first-search/main.c
        02-nonlinear-list/05-graph/graph.h
        )
add_executable(graph_minimum_spanning_tree_kruscal
        02-nonlinear-list/05-graph/04-minimum-spanning-tree/01-kruscal/kruscal.h
        02-nonlinear-list/05-graph/04-minimum-spanning-tree/01-kruscal/kruscal.c
        02-nonlinear-list/05-graph/04-minimum-spanning-tree/01-kruscal/main.c
        )
add_executable(set_union_find_set
        02-nonlinear-list/06-set/01-UFSet/ufset.c
        02-nonlinear-list/06-set/01-UFSet/ufset.h
        02-nonlinear-list/06-set/01-UFSet/main.c
        )
add_executable(tree_binary_tree_heap
        02-nonlinear-list/02-tree/02-binary-tree/07-heap/heap.h
        02-nonlinear-list/02-tree/02-binary-tree/07-heap/heap.c
        02-nonlinear-list/02-tree/02-binary-tree/07-heap/main.c
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.h
        01-linear-list/04-queue/01-queue/02-linked-queue/linkedqueue.c
        )