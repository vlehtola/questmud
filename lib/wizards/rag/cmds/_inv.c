
cmd_inv(str) {
        object p;
        object *ob;
        int i;
        p = find_player(str);

        ob = all_inventory(p);

        for ( i = 0; i < sizeof(ob); i++) {
                write(ob[i]->short()+" "+file_name(ob[i])+"\n");
        }
        return 1;
}
