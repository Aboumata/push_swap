/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:06:05 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/30 17:06:08 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}					t_stack;

char				*get_next_line(int fd);
int					is_number(const char *str);
int					ps_atoi(const char *str, int *valid);
int					check_duplicate(t_stack *stack, int val);
int					count_strings(char **strings);
char				**split_args(int argc, char **argv, int *new_argc, int *needs_free);
void				print_opera(char *str);
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
void				sort_2(t_stack **stack);
void				sort_3(t_stack **stack);
void				sort_4_or_5(t_stack **stack_a, t_stack **stack_b);
t_stack				*search_smallest(t_stack *stack);
void				sort_small(t_stack **a, t_stack **b, int size);
void				quicksort(int *arr, int low, int high);
void				sort_large(t_stack **a, t_stack **b, int size);
int					find_max_value(t_stack *stack);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				stdin_operations(char *line, t_stack **a, t_stack **b);

#endif
