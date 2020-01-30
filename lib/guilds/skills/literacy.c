#define OFFENSIVE_RESOLVE "/guilds/obj/offensive_resolve"
#define SCROLL_D "/guilds/mage/objects/scroll_daemon"
object scroll, owner;
get_time() {
    return 3; //tuned by Moonstar, 18.3.2003. Previous was return 2
}
ep_cost() { return 3; }
query_type() { return "neutral"; }

resolve_skill(str) {
        string tmp, tgt, spell_words;
        object target, spell;
        int effect;
        int sp_cost;
    if(!str) { write("Usage: use literacy at <scroll> <target>\n"); return 1; }
    if(sscanf(str, "%s %s", tmp, tgt) != 2) {
     write("Usage: use literacy at <scroll> <target>\n");
     return 1;
    }
    effect = this_player()->query_int();
    scroll = present(tmp, this_player());
    target = lower_case(tgt);
    sp_cost = this_player()->query_sp_boost(1);
    if(this_player()->query_sp() < sp_cost*2 + this_player()->query_level()*10) { write("You don't have enough spell points.\n"); return 1; }
    if(!scroll) { write("You don't have a scroll.\n"); return 1; }
    if(!scroll->query_scroll()) { write("This scroll works only at scrolls.\n"); return 1; }
    if(!scroll->query_read()) { write("Maybe you should scribble something on the scroll before reading it.\n"); return 1; }
    owner = scroll->query_owner();
    if(owner != this_player()->query_name()) { write("You can't understand anything from the scroll.\n"); return 1; }
    spell_words = scroll->query_word1()+" "+scroll->query_word2()+" "+scroll->query_word3()+" at "+lower_case(tgt);
    if(scroll->query_word3() == "blt" || scroll->query_word3() == "strm") {
                write("You read the scroll at "+tgt+".\n");
                say(this_player()->query_name()+" starts to read the scroll.\n");
                SCROLL_D->reduce_maker(this_player()->query_name());

// Tuned by Celtron. reduce sp before boost

                this_player()->reduce_sp(sp_cost*2 + this_player()->query_level()*10);
                call_other("/guilds/obj/offensive_resolve", "offensive_resolve", scroll->query_word3(),scroll->query_word2(),scroll->query_word1(),effect,tgt,this_player());
                destruct(scroll);
                this_player()->fix_weight();
                return 1;
        }
        if(file_size("/guilds/spells/essence/_"+scroll->query_word1()+"_"+scroll->query_word2()+"_"+scroll->query_word3()+".c") != -1) {
                    write("You read the scroll at "+tgt+".\n");
                    say(this_player()->query_name()+" starts to read the scroll.\n");
                    SCROLL_D->reduce_maker(this_player()->query_name());
                    call_other("/guilds/spells/essence/_"+scroll->query_word1()+"_"+scroll->query_word2()+"_"+scroll->query_word3()+".c","resolve",effect,tgt,this_player());
                   destruct(scroll);
                   this_player()->fix_weight();

                return 1;
        }
                write("You read the scroll but nothing happens.\n");
                say(this_player()->query_name()+" reads a scroll but nothing happens.\n");
                destruct(scroll);
                this_player()->fix_weight();
                SCROLL_D->reduce_maker(this_player()->query_name());
    return 1;
}

fail_skill(target) {
    write("You fail to read the scroll.\n");
    say(capitalize(this_player()->query_name()) + " fails to read the scroll.\n");
}

