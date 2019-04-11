/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** Contains env functions prototypes
*/

#ifndef ENV_HANDLING_H_
    #define ENV_HANDLING_H_
    void free_env(char **env);
    char **envdup(char **env);
    int get_env_size(char **env);
    char **enlarge_env(char **env);
    void display_not_found(char *binary);
    int find_env_var(char **env, char const *var);
    int get_var_len(char **args, int args_nbr);
    char *get_var_value(char **env, char const *var);
    int is_same_var(char const *variable, char const *reference);
    char *create_variable(char **args, int args_nbr);
    char *search_in_path(char *binary, char *path_var);
    char **edit_variable(char **env, int args_nbr, char **args, int *status);
#endif /* !ENV_HANDLING_H_ */