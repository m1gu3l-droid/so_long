int	end(t_map *game)
{
	if (game->map)
		ft_free_map(&game->map);
	if (game->map_back)
		ft_free_map(&game->map_back);
	free_sprite(game);
	free_player(game);
	ft_printf("Game Over!\nMoves: %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	ft_new_dir(t_map *game, int e)
{
	t_player	*ptemp;

	ptemp = game->player;
	if (game->moves < 9999)
	{
		game->moves += 1;
		ft_update_score(game);
	}
	while (ptemp)
	{
		g->next_dir = e;
		ptemp = ptemp->next;
	}
}	

int	control_key(int key, t_map *game)
{
	if ((key == KEY_ESC) && !game->dying)
	{
		ft_printf("\nBye!\n");
		end(game);
	}
	if ((key == KEY_W || key == KEY_UP) && !game->dying && game->next_dir != N)
		ft_new_dir(g, N);
	if ((key == KEY_S || key == KEY_DOWN) && !game->dying && game->next_dir != S)
		ft_new_dir(g, S);
	if ((key == KEY_A || key == KEY_LEFT) && !game->dying && game->next_dir != W)
		ft_new_dir(g, W);
	if ((key == KEY_D || key == KEY_RIGHT) && !game->dying && game->next_dir != E)
		ft_new_dir(g, E);
	return (0);
}
