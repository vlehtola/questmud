inherit "obj/monster"; 
  string chat_str;
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("thing");
    call_other(this_object(), "set_level", 200);
    call_other(this_object(), "set_name", "sign");
    call_other(this_object(), "set_alias", "sign");
    call_other(this_object(), "set_short", "Living Roadblock/sign");
    call_other(this_object(), "set_long", "Sorry, the church has been closed due to repairs. Leb has also moved.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("stairs");
 
 if (!chat_str) {    
        chat_str = allocate(0);
        chat_str[0] =
          "Sign says: The church has been closed until repairs are finished, you can find an easier Leb-Kamar somewhere else now.\n";

 load_chat(30, chat_str);        

}
