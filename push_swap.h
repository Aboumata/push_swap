/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:38:54 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:38:57 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					is_number(const char *str);
int					ps_atoi(const char *str, int *valid);
int					check_duplicate(t_stack *stack, int val);
int					count_strings(char **strings);
char				**split_args(int argc, char **argv, int *new_argc);
void				swap_stack(t_stack **stack);
void				push_stack(t_stack **stack2, t_stack **stack1);
void				rotate_stack(t_stack **stack);
void				rev_rotate(t_stack **stack);
void				free_stack(t_stack **stack);
void				free_args(char **args);
void				free_error(t_stack **stack, char **args, int splitted);
int					stack_len(t_stack *stack);
int					index_val(t_stack *stack, int val);
int					is_sorted(t_stack *stack);
void				stack_add_back(t_stack **stack, int value);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_substr(const char *src, size_t start, size_t len);
char				**ft_split(char const *s, char c);
void				sort_sin(t_stack **stack);
void				sort_krad(t_stack **stack);
t_stack				*search_smallest(t_stack *stack);
void				sort_koz_smous(t_stack **stack_a, t_stack **stack_b);
void				index_num(t_stack *stack);
int					max_bits(t_stack *stack);
void				push_bits(t_stack **stack_a, t_stack **stack_b, int bit);
void				radix_algo(t_stack **stack_a, t_stack **stack_b);

#endif
