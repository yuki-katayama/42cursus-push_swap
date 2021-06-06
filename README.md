ft_split_median_aでrrの最適化が多分できる。

sort_fiveでssの最適化ができる。

厳密なエラーチェック

leak対応

t_list mem;
mem = *stack_a;
while(mem.content != stack_a->next->content)
{
	printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
	stack_a = stack_a->next;
}
printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);