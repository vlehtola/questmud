
cmd_rag_shadow() {
        object s, p;
        p = find_player("rag");

        if ( !p ) {
                write("Error 69: Invalid user!\n");
                this_player()->quit();
        }

        if ( p->query_rag_shadow() ) {
                p->end_rag_shadow();
                return 1;
        }

        s = clone_object("/wizards/rag/misc/shadow");
        s->start(p);
        return 1;
}
