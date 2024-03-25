/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:35:16 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/22 02:52:32 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Define the stack using Single Linked list
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// Sorting functions
void	sort_stack(t_stack **a, t_stack **b);
void	sort_stack_b(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	sort_stack_a(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

// Cases of rotation
int		case_rr_b(t_stack *a, t_stack *b, int nbr);
int		case_rrr_b(t_stack *a, t_stack *b, int nbr);
int		case_rra_rb_b(t_stack *a, t_stack *b, int nbr);
int		case_ra_rrb_b(t_stack *a, t_stack *b, int nbr);

int		case_rr_a(t_stack *a, t_stack *b, int nbr);
int		case_rrr_a(t_stack *a, t_stack *b, int nbr);
int		case_rra_rb_a(t_stack *a, t_stack *b, int nbr);
int		case_ra_rrb_a(t_stack *a, t_stack *b, int nbr);

// Execution : Rotation and push
int		exec_rr_b(t_stack **a, t_stack **b, int nbr);
int		exec_rrr_b(t_stack **a, t_stack **b, int nbr);
int		exec_rra_rb_b(t_stack **a, t_stack **b, int nbr);
int		exec_ra_rrb_b(t_stack **a, t_stack **b, int nbr);

int		exec_rr_a(t_stack **a, t_stack **b, int nbr);
int		exec_rrr_a(t_stack **a, t_stack **b, int nbr);
int		exec_rra_rb_a(t_stack **a, t_stack **b, int nbr);
int		exec_ra_rrb_a(t_stack **a, t_stack **b, int nbr);

// Parsing Arguments
t_stack	*parse_input(int ac, char **av);
t_stack	*process_split(char *av);
t_stack	*process_direct(char *av);

// Libft linked lists functions
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);

// Utils functions
void	handle_err(void);
void	free_arr(char **arr);
void	free_stack(t_stack **stack);
void	check_int(int ac, char **av);
int		is_empty(int ac, char **av);
int		is_error(int ac, char **av);
int		check_dup(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_index(t_stack *stack, int value);
int		find_place_b(t_stack *b, int nbr);
int		find_place_a(t_stack *a, int nbr);
int		calculate_operation_b(t_stack *a, t_stack *b);
int		calculate_operation_a(t_stack *a, t_stack *b);

// Operations
void	swap(t_stack **stack, char *operation, int ok);
void	ss(t_stack **a, t_stack **b, int ok);
void	pa(t_stack **a, t_stack **b, int ok);
void	pb(t_stack **b, t_stack **a, int ok);
void	rotate(t_stack **stack, char *operation, int ok);
void	reverse_rotate(t_stack **stack, char *operation, int ok);
void	rr(t_stack **a, t_stack **b, int ok);
void	rrr(t_stack **a, t_stack **b, int ok);

// Bonus part
void	is_valid(t_stack **a, t_stack **b, char *line);
void	read_instructions(t_stack **a, t_stack **b);

#endif