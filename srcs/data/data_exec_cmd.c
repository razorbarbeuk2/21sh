/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAZOR <RAZOR@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:24:18 by RAZOR             #+#    #+#             */
/*   Updated: 2017/05/25 18:49:45 by RAZOR            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int 		data_check_special_caract_global(t_data *data, char *line_str, char **caract)
{
	int i;

	i = 0;
	(void)data;
	while (line_str[i])
	{
		if (line_str[i + 1])
		{

			if (line_str[i] == '<' && line_str[i + 1] != '<' && line_str[i + 1])
			{
				(*caract) = ft_strdup("<");
				return (1);
			}
			else if (line_str[i] == '>' && line_str[i + 1] != '>' && line_str[i + 1])
			{
				(*caract) = ft_strdup(">");
				return (1);
			}
			else if (line_str[i] == '|' && line_str[i + 1] != '|' && line_str[i + 1])
			{
				(*caract) = ft_strdup("|");
				return (1);
			}
			else if (line_str[i] == ';' && line_str[i + 1] != '|' && line_str[i + 1])
			{
				(*caract) = ft_strdup(";");
				return (1);
			}
		}
		else
			break ;
		i++;
	}
	return (0);
}

void		data_check_str_list_struct_cmd(t_data *data, char **line_str)
{
	t_cmd	*cmd_node;
	char 	*caract;
	char 	**tmp;
	int		i;
	//int		nbr;

	i = 0;
	tmp = NULL;
	caract = NULL;
	cmd_node = NULL;
	while(line_str[i])
	{
		if (!data_check_special_caract_global(data, line_str[i], &caract) && line_str[i])
		{
			i = data_create_list_struct_cmd(data, &line_str[i], &cmd_node);
			ft_putstr_fd("ok", data->sel->tty);
			ft_lstadd_back(&data->cmd, ft_lstnew(cmd_node, sizeof(t_cmd)));
		}
		else if (data_check_special_caract_global(data, line_str[i], &caract) && line_str[i])
		{
			tmp = data_split_to_tab(line_str[i], caract);
			return (data_check_str_list_struct_cmd(data, tmp));
		}
		else
			i++;
	}
}

void		exec_cmd_character(t_data *data)
{
	char 	*str;
	int		i;
	

	i = 0;
	str = NULL;
	str = convert_data_lst_tab(data);
	if (data->entry->line_str)
	{
		ft_free_char(data->entry->line_str);
		data->entry->line_str = NULL;
	}
	data->entry->line_str = data_clean_to_tab(data, str);
	data_check_str_list_struct_cmd(data, data->entry->line_str);
	print_list_cmd(data, data->cmd);
	return ;
}