
cmd_where(str) {
        object ob;

        if ( !str ) return 1;

        ob = find_player(lower_case(str));

        if ( !ob ) return 1;

        write(file_name(environment(ob))+"\n");
        return 1;
}
