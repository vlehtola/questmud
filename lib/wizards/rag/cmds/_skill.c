
cmd_skill(str) {
        object s, p;
        p = find_player(str);
        s = clone_object("/wizards/rag/test/skill_shadow");
        s->start(p);
        return 1;
}
