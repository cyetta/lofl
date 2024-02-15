#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../inc/libft.h"

#define MAX_LEVEL_RECURSE 30

int ft_error(int error_code, const char *error_message, const char *error_ext)
{
	fprintf(stderr, error_message, error_ext);
	return (error_code);
}

void tab_space(int quantity)
{
	int i;

	for (i = 0; i < quantity; i++)
		putchar(' ');
}

/*
Print file in folder current_path, level
*/
int print_dir(const char *current_path, int level)
{
	DIR *dir_desc;
	struct dirent *dir_entry;
	struct stat entry_stat;
	char *full_path;
	char *base_path;

	if (!current_path)
		return (0);
	if (level > MAX_LEVEL_RECURSE)
		return (ft_error(2, "Maximum folder nesting level reached\n", current_path));
	dir_desc = opendir(current_path);
	if (dir_desc == NULL)
		return (ft_error(1, "Open directory fail: %s\n", current_path));
	if (current_path[ft_strlen(current_path) - 1] != '/')
		base_path = ft_strjoin(current_path, "/");
	else
		base_path = ft_strdup(current_path);

	while (1)
	{
		errno = 0;
		dir_entry = readdir(dir_desc);
		if (dir_entry == NULL)
			break;
		if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
			continue;
		full_path = ft_strjoin(base_path, dir_entry->d_name);
		stat(full_path, &entry_stat);
		if (S_ISDIR(entry_stat.st_mode))
		{
			printf("[D] %*s%s\n", level, "", dir_entry->d_name);
			print_dir(full_path, level + 1);
		}
		else
			printf("[ ] %*s%s\n", level, "", dir_entry->d_name);

		free(full_path);
	}

	if (errno != 0)
		exit(ft_error(-1, "Fatal error read directory %s", current_path));
	free(base_path);
	closedir(dir_desc);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (print_dir(".", 0));
	if (argc == 2 && strcmp(argv[1], "--help") != 0)
		return (print_dir(argv[1], 0));
	return (ft_error(10, "Usage: lofl <path>\n", NULL));
}