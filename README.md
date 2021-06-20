ft_split_median_aでrrの最適化が多分できる。

sort_fiveでssの最適化ができる。


	t_list mem;
	mem = *stack_a;
	while(mem.content != stack_a->next->content)
	{
		printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
		stack_a = stack_a->next;
	}
	printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);

	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
