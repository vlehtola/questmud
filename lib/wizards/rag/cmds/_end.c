
status cmd_end(string str) {
        find_player(str)->end_dragon_shadow();
        find_player(str)->fix_stats();
        return 1;
}
