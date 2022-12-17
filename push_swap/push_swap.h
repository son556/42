/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:17:01 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 21:39:30 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libftprintf2/ft_printf.h"
# include <stdio.h>

typedef struct s_DequeNode
{
	long long			data;
	int					idx;
	struct s_DequeNode	*flink;
	struct s_DequeNode	*rlink;
}	t_DequeNode;

typedef struct s_LinkedDeque
{
	int			count;
	t_DequeNode	*frontnode;
	t_DequeNode	*rearnode;
}	t_LinkedDeque;

typedef struct s_GreedyDeque
{
	int			max;
	int			min;
	int			mid;
}	t_greedy;

typedef struct s_command_list
{
	char					*command;
	struct s_command_list	*next;
}	t_cmd;

typedef struct s_least
{
	int	cmd_cnt;
	int	size_a;
	int	idx;
	int	idx_a;
	int	middle;
}	t_low;

long long		ft_aatoi(const char *str);
int				check_argv(int argc, char **argv);
void			ft_free(char **temp);
void			match_idx(t_LinkedDeque *deque_a, int *arr);
t_LinkedDeque	*create_deque(void);
t_DequeNode		*create_node(long long num);
t_DequeNode		*create_node_idx(long long data, int idx);
int				add_front_deque(t_LinkedDeque *deque, t_DequeNode *node);
int				add_rear_deque(t_LinkedDeque *deque, t_DequeNode *node);
int				delete_front(t_LinkedDeque *deque);
int				delete_rear(t_LinkedDeque *deque);
int				delete_deque(t_LinkedDeque *deque);
int				deque_size(t_LinkedDeque *deque);
t_LinkedDeque	*copy_deque(t_LinkedDeque *deque);
int				deque_data(t_LinkedDeque *deque, int idx);
t_cmd			*ft_cmdnew(char *content);
void			ft_cmdadd_back(t_cmd **cmd, char *content);
void			ft_cmdclear(t_cmd **lst);
void			display_cmd(t_cmd *cmd_lst);
int				ft_abs(int a);
int				push_pa(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				push_pb(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				push_sa(t_LinkedDeque *deque_a);
int				push_sb(t_LinkedDeque *deque_b);
int				push_ss(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				push_ra(t_LinkedDeque *deque_a);
int				push_rb(t_LinkedDeque *deque_b);
int				push_rr(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				push_rra(t_LinkedDeque *deque_a);
int				push_rrb(t_LinkedDeque *deque_b);
int				push_rrr(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				init_algorithm(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b);
int				sort_check_asc(t_LinkedDeque *deque);
void			find_pivot(t_LinkedDeque *deque_a, t_greedy *greedy);
t_cmd			*make_deque_b(t_LinkedDeque *a, t_LinkedDeque *b);
t_cmd			*make_b_cmd(t_LinkedDeque *a, t_LinkedDeque *b, t_greedy *g);
void			so_a(t_LinkedDeque *a, t_LinkedDeque *b, t_cmd *l);
void			act_c(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l);
void			complete_deque_a(t_LinkedDeque *a, t_greedy *g, t_cmd *l);
void			sort_a_3(t_LinkedDeque *a, t_cmd **cmd_lst);
void			merge_sort(int arr[], int start, int end);
void			sort_inm(t_LinkedDeque *a, t_cmd **cmd_lst);
void			sort_min(t_LinkedDeque *a, t_cmd **cmd_lst);
void			sort_mni(t_LinkedDeque *a, t_cmd **cmd_lst);
void			sort_nmi(t_LinkedDeque *a, t_cmd **cmd_lst);
void			sort_imn(t_LinkedDeque *a, t_cmd **cmd_lst);
void			c_2(t_LinkedDeque *a, t_LinkedDeque *b, t_cmd *l, t_low *c);
void			define_a(t_LinkedDeque *a, char *ar, t_cmd **cmd_lst);
#endif