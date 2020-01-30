cmd_people() {
    object list;
    int i, a;
        
    list = users();
    write("There are now " + sizeof(list) + " players");
    for (i=0, a=0; i < sizeof(list); i++)
        if (list[i]->idle() >= 5 * 60)
            a++;
    if (a)
        write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    for(i=0; i<sizeof(list); i++) {
        string name;
        name = list[i]->query_real_name();
        if (!name)
            name = list[i]->query_name();
        if (!name)
            name = "logon";
        name = capitalize(name);
        if (list[i]->short() == 0)  
            name = "(" + name + ")";
        if (strlen(name) < 8)
            name = name + "\t";
        write(query_ip_number(list[i]) + "\t" + name + "\t" +
              list[i]->query_level() + "\t");
        a = list[i]->query_age();
        if (a / 43200 > 9)
            write(a / 43200 + " D");
        else if (a / 43200 > 0)
            write(a / 43200 + "  D");
        else if (a / 1800 > 9)

            write(a / 1800 + " h");
        else if (a / 1800 > 0)
            write(a / 1800 + "  h");
        else if (a / 30 > 9)
            write(a / 30 + " m");
        else
            write(a / 30 + "  m");
        if (list[i]->idle() >= 5 * 60)
            write(" I\t");
        else
            write("\t");
        if (environment(list[i]))
            write(file_name(environment(list[i])));
        write("\n");
    }
    return 1;
}

