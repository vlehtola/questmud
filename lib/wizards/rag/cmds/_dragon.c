
cmd_dragon(str) {
        object s, p;
        string tmp;
        if(sscanf(str,"end %s",tmp) == 1) {
                p = find_player(tmp);
                p->end_dragon_shadow();
                return 1;
        }
        p = find_player(str);
        s = clone_object("/wizards/rag/misc/dragon_shadow");
        s->start(p);
        return 1;
}
